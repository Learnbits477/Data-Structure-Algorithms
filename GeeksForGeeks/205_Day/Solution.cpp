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
    int postOrder(Node* root, int& maxDiffVal) {
        // Step 2: Base cases for null and leaf nodes
        if (!root) return INT_MAX;
        if (!root->left && !root->right) return root->data;

        // Step 3: Recursively find minimum values in left and right subtrees
        int leftMin = postOrder(root->left, maxDiffVal);
        int rightMin = postOrder(root->right, maxDiffVal);

        // Step 4: Update max difference with minimum descendant
        int minDescendant = min(leftMin, rightMin);
        maxDiffVal = max(maxDiffVal, root->data - minDescendant);

        // Step 5: Return minimum value in the current subtree
        return min(root->data, minDescendant);
    }

public:
    int maxDiff(Node* root) {
        // Step 1: Initialize max difference and start post-order traversal
        int maxDiffVal = INT_MIN;
        postOrder(root, maxDiffVal);
        return maxDiffVal;
    }
};
