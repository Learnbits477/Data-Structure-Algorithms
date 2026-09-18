#include <bits/stdc++.h>
using namespace std;

#ifndef NODE_STRUCT
#define NODE_STRUCT
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
#endif

class Solution {
private:
    void inorder(Node* root, int &prev, int &minDiff) {
        if (!root) return;

        // Step: 01 - Recursively process left subtree
        inorder(root->left, prev, minDiff);

        // Step: 02 - Process current node against previous in-order node
        if (prev != -1) {
            minDiff = min(minDiff, root->data - prev);
        }
        prev = root->data;

        // Step: 03 - Recursively process right subtree
        inorder(root->right, prev, minDiff);
    }

public:
    int absolute_diff(Node *root) {
        int prev = -1;
        int minDiff = INT_MAX;
        inorder(root, prev, minDiff);
        return minDiff;
    }

    // Platform alias overload
    int absDiff(Node *root) {
        return absolute_diff(root);
    }

    // LeetCode compatibility alias
    int getMinimumDifference(Node *root) {
        return absolute_diff(root);
    }
};
