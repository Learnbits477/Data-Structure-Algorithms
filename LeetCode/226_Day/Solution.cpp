#include <bits/stdc++.h>
using namespace std;

#ifndef TREE_NODE_DEF
#define TREE_NODE_DEF
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

class Solution {
private:
    int matchingCount = 0;

    // Helper function: Post-order traversal returning {subtreeSum, subtreeCount}
    pair<int, int> postOrder(TreeNode* node) {
        // Base Case: null node contributes 0 sum and 0 count
        if (node == nullptr) {
            return {0, 0};
        }

        // Step 1: Recursively aggregate sum and count from left and right subtrees
        pair<int, int> leftSubtree = postOrder(node->left);
        pair<int, int> rightSubtree = postOrder(node->right);

        int leftSum = leftSubtree.first;
        int leftCount = leftSubtree.second;
        int rightSum = rightSubtree.first;
        int rightCount = rightSubtree.second;

        // Step 2: Compute current subtree sum and count
        int currSum = leftSum + rightSum + node->val;
        int currCount = leftCount + rightCount + 1;

        // Step 3: Check if node value equals the floor average of its subtree
        int avg = currSum / currCount;
        if (node->val == avg) {
            matchingCount++;
        }

        // Step 4: Return current subtree aggregate {sum, count} to parent
        return {currSum, currCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        matchingCount = 0;
        postOrder(root);
        return matchingCount;
    }
};
