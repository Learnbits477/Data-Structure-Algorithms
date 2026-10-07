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
    int maxPathSumUtil(Node* node, int& res, int& leafCount) {
        // Step: 01 - Return base value for empty subtree
        if (!node) return 0;

        // Step: 02 - Handle leaf node by updating leaf count and returning node data
        if (!node->left && !node->right) {
            leafCount++;
            return node->data;
        }

        // Step: 03 - Recursively compute maximum downward paths from left and right subtrees
        int leftSum = node->left ? maxPathSumUtil(node->left, res, leafCount) : 0;
        int rightSum = node->right ? maxPathSumUtil(node->right, res, leafCount) : 0;

        // Step: 04 - Evaluate complete leaf-to-leaf path if both children are present
        if (node->left && node->right) {
            res = max(res, leftSum + rightSum + node->data);
            return max(leftSum, rightSum) + node->data;
        }

        // Step: 05 - Propagate path through the single existing child
        return node->left ? (leftSum + node->data) : (rightSum + node->data);
    }

    int countLeaves(Node* node) {
        // Step: 01 - Return zero for null subtree
        if (!node) return 0;

        // Step: 02 - Identify leaf node condition
        if (!node->left && !node->right) return 1;

        // Step: 03 - Aggregate leaves from both subtrees
        return countLeaves(node->left) + countLeaves(node->right);
    }

    int maxPathSumTwoPassHelper(Node* node, int& res) {
        // Step: 01 - Return base value for empty subtree
        if (!node) return 0;

        // Step: 02 - Return data for leaf node
        if (!node->left && !node->right) return node->data;

        // Step: 03 - Recurse on available child branches
        int leftSum = node->left ? maxPathSumTwoPassHelper(node->left, res) : 0;
        int rightSum = node->right ? maxPathSumTwoPassHelper(node->right, res) : 0;

        // Step: 04 - Update candidate maximum when both subtrees exist
        if (node->left && node->right) {
            res = max(res, leftSum + rightSum + node->data);
            return max(leftSum, rightSum) + node->data;
        }

        // Step: 05 - Return downward path extending through single child
        return node->left ? (leftSum + node->data) : (rightSum + node->data);
    }

public:
    int maxPathSum(Node* root) {
        // Step: 01 - Handle edge case for null root
        if (!root) return -1;

        // Step: 02 - Initialize tracking variables for maximum path and leaf counter
        int res = INT_MIN;
        int leafCount = 0;

        // Step: 03 - Execute single-pass post-order traversal to calculate optimal leaf-to-leaf path
        maxPathSumUtil(root, res, leafCount);

        // Step: 04 - Validate requirement of having at least two leaf nodes
        if (leafCount < 2) return -1;

        // Step: 05 - Return optimal leaf-to-leaf path sum
        return res;
    }

    int maxPathSumTwoPass(Node* root) {
        // Step: 01 - Validate presence of at least two leaves prior to path calculation
        if (!root || countLeaves(root) < 2) return -1;

        // Step: 02 - Initialize global maximum path tracker
        int res = INT_MIN;

        // Step: 03 - Execute recursive tree traversal
        maxPathSumTwoPassHelper(root, res);

        // Step: 04 - Return final computed maximum path sum
        return res;
    }
};
