#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
private:
    // Helper function to find root-to-target path as a string of 'L' and 'R'
    bool findPath(Node* root, int target, string& path) {
        if (!root) return false;
        if (root->data == target) return true;

        // Try Left subtree
        path.push_back('L');
        if (findPath(root->left, target, path)) return true;
        path.pop_back();

        // Try Right subtree
        path.push_back('R');
        if (findPath(root->right, target, path)) return true;
        path.pop_back();

        return false;
    }

public:
    int NumberOfTurns(struct Node* root, int first, int second) {
        if (!root || first == second) return -1;

        // Step 1: Find paths from root to both nodes
        string path1 = "", path2 = "";
        if (!findPath(root, first, path1) || !findPath(root, second, path2)) {
            return -1;
        }

        // Step 2: Identify LCA by removing common prefix
        int i = 0;
        while (i < (int)path1.length() && i < (int)path2.length() && path1[i] == path2[i]) {
            i++;
        }

        string s1 = path1.substr(i);
        string s2 = path2.substr(i);

        // Step 3: Case A - One node is the ancestor of the other
        if (s1.empty() || s2.empty()) {
            string s = s1.empty() ? s2 : s1;
            int turns = 0;
            for (size_t j = 0; j + 1 < s.length(); j++) {
                if (s[j] != s[j + 1]) {
                    turns++;
                }
            }
            return (turns == 0) ? -1 : turns;
        }

        // Step 4: Case B - LCA is distinct from both nodes
        int turns = 1; // 1 turn at LCA

        // Count direction changes going up from first node to LCA
        for (size_t j = 0; j + 1 < s1.length(); j++) {
            if (s1[j] != s1[j + 1]) {
                turns++;
            }
        }

        // Count direction changes going down from LCA to second node
        for (size_t j = 0; j + 1 < s2.length(); j++) {
            if (s2[j] != s2[j + 1]) {
                turns++;
            }
        }

        return turns;
    }

    // Additional alias for lower camelCase compatibility
    int numberOfTurns(struct Node* root, int first, int second) {
        return NumberOfTurns(root, first, second);
    }
};
