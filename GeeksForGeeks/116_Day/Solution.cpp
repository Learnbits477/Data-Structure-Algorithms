#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    int transformHelper(Node* root) {
        // Step 1: Base Case for Null Nodes
        if (!root) {
            return 0;
        }

        // Step 2: Recursive Subtree Summation
        int leftSum = transformHelper(root->left);
        int rightSum = transformHelper(root->right);

        // Step 3: Update Current Node Value
        int oldVal = root->data;
        root->data = leftSum + rightSum;

        // Step 4: Return Subtree Total Sum
        return root->data + oldVal;
    }

public:
    void toSumTree(Node *root) {
        transformHelper(root);
    }
};
