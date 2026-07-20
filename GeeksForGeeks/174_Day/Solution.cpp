#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* children[256];
        int freq;
        
        TrieNode() {
            freq = 0;
            for (int i = 0; i < 256; i++) {
                children[i] = nullptr;
            }
        }
        
        ~TrieNode() {
            for (int i = 0; i < 256; i++) {
                if (children[i]) {
                    delete children[i];
                }
            }
        }
    };

    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (unsigned char c : word) {
            if (curr->children[c] == nullptr) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
            curr->freq++;
        }
    }

    string getShortestUniquePrefix(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        string prefix = "";
        for (unsigned char c : word) {
            prefix += c;
            curr = curr->children[c];
            if (curr->freq == 1) {
                break;
            }
        }
        return prefix;
    }

public:
    // Signature 1: vector of strings
    vector<string> findPrefixes(vector<string>& arr) {
        TrieNode* root = new TrieNode();
        for (const string& word : arr) {
            insert(root, word);
        }

        vector<string> result;
        result.reserve(arr.size());
        for (const string& word : arr) {
            result.push_back(getShortestUniquePrefix(root, word));
        }

        delete root; // Automatically deletes all children recursively
        return result;
    }

    // Signature 2: string array
    vector<string> findPrefixes(string arr[], int n) {
        vector<string> temp(arr, arr + n);
        return findPrefixes(temp);
    }
};
