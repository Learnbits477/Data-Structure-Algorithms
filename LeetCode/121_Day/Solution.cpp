#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        int best_index;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            best_index = -1;
        }
    };

    // Helper function to update the best index at a node based on length and container order
    void updateNode(TrieNode* node, int wordIdx, const vector<string>& wordsContainer) {
        if (node->best_index == -1) {
            node->best_index = wordIdx;
        } else {
            int currentBestIdx = node->best_index;
            // Update node if the current word has a strictly smaller length.
            // Tie-breaking (earlier index) is handled by left-to-right insertion sequence.
            if (wordsContainer[wordIdx].length() < wordsContainer[currentBestIdx].length()) {
                node->best_index = wordIdx;
            }
        }
    }

    // Insert a word into the Trie in reverse order (to match suffixes as prefixes)
    void insert(TrieNode* root, const string& word, int wordIdx, const vector<string>& wordsContainer) {
        TrieNode* curr = root;
        // Update root node (represents empty suffix)
        updateNode(curr, wordIdx, wordsContainer);

        // Traverse characters from end to beginning
        for (int i = (int)word.length() - 1; i >= 0; i--) {
            int charIdx = word[i] - 'a';
            if (curr->children[charIdx] == nullptr) {
                curr->children[charIdx] = new TrieNode();
            }
            curr = curr->children[charIdx];
            updateNode(curr, wordIdx, wordsContainer);
        }
    }

    // Search for the longest common suffix of query by matching prefix of reversed query
    int search(TrieNode* root, const string& query) {
        TrieNode* curr = root;
        // Traverse characters of the query from end to beginning
        for (int i = (int)query.length() - 1; i >= 0; i--) {
            int charIdx = query[i] - 'a';
            if (curr->children[charIdx] == nullptr) {
                break;
            }
            curr = curr->children[charIdx];
        }
        return curr->best_index;
    }

    // Helper function to free Trie memory and prevent leaks
    void freeTrie(TrieNode* root) {
        if (root == nullptr) {
            return;
        }
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != nullptr) {
                freeTrie(root->children[i]);
            }
        }
        delete root;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // Step 1: Initialize State Variables
        TrieNode* root = new TrieNode();

        // Step 2: Traverse and Build the Trie
        // Build the suffix Trie by inserting reversed strings from wordsContainer
        for (int i = 0; i < (int)wordsContainer.size(); i++) {
            insert(root, wordsContainer[i], i, wordsContainer);
        }

        // Step 3: Collect and Return Results
        // Match suffixes of each query and find the corresponding best indexes
        int queryCount = wordsQuery.size();
        vector<int> ans(queryCount);
        for (int i = 0; i < queryCount; i++) {
            ans[i] = search(root, wordsQuery[i]);
        }

        // Clean up memory
        freeTrie(root);

        return ans;
    }
};
