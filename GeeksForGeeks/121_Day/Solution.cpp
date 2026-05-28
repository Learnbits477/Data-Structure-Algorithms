#include <bits/stdc++.h>
using namespace std;

// Node structure is declared for compilation context.
// In GFG, this is pre-defined.
#ifndef NODE_STRUCT
#define NODE_STRUCT
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
#endif

class Solution {
private:
    // Helper function for depth-first traversal to calculate sums by horizontal distance
    void solve(Node* root, int hd, map<int, int>& mp) {
        // Base case: if current node is null, terminate recursion
        if (root == nullptr) {
            return;
        }

        // Step 2: Traverse the Binary Tree
        // Add the current node's value to its corresponding horizontal distance key
        mp[hd] += root->data;

        // Traverse left child with HD decreased by 1
        solve(root->left, hd - 1, mp);
        // Traverse right child with HD increased by 1
        solve(root->right, hd + 1, mp);
    }

public:
    vector<int> verticalSum(Node* root) {
        // Step 1: Initialize State Variables
        map<int, int> mp;
        vector<int> res;

        // Start traversing from the root node with HD = 0
        solve(root, 0, mp);

        // Step 3: Collect and Return Results
        // Extract sums from the map, which is naturally sorted by horizontal distance (keys)
        for (auto const& [hd, sum] : mp) {
            res.push_back(sum);
        }

        return res;
    }
};
