/**
 * Balanced Binary Tree
 * https://leetcode.com/problems/balanced-binary-tree/description/
 */

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root).second;
    }
    
private:
    pair<int, bool> isBalancedHelper(TreeNode* root) {
        if (root == nullptr) return {0, true};
        
        auto leftSubtree = isBalancedHelper(root->left);
        auto rightSubtree = isBalancedHelper(root->right);
        
        int height = max(leftSubtree.first, rightSubtree.first) + 1;
        bool isBalanced = leftSubtree.second && rightSubtree.second && abs(leftSubtree.first - rightSubtree.first) <= 1;
        
        return {height, isBalanced};
    }
};

// Helper function to create a new node
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

// Driver code to test the solution
int main() {
    Solution sol;

    // Example 1: root = [3,9,20,null,null,15,7]
    TreeNode* root1 = newNode(3);
    root1->left = newNode(9);
    root1->right = newNode(20);
    root1->right->left = newNode(15);
    root1->right->right = newNode(7);

    if (sol.isBalanced(root1)) {
        cout << "Example 1: True (Balanced)" << endl;
    } else {
        cout << "Example 1: False (Unbalanced)" << endl;
    }

    // Example 2: root = [1,2,2,3,3,null,null,4,4]
    TreeNode* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(2);
    root2->left->left = newNode(3);
    root2->left->right = newNode(3);
    root2->left->left->left = newNode(4);
    root2->left->left->right = newNode(4);

    if (sol.isBalanced(root2)) {
        cout << "Example 2: True (Balanced)" << endl;
    } else {
        cout << "Example 2: False (Unbalanced)" << endl;
    }

    // Example 3: root = []
    TreeNode* root3 = nullptr;
    if (sol.isBalanced(root3)) {
        cout << "Example 3: True (Balanced)" << endl;
    } else {
        cout << "Example 3: False (Unbalanced)" << endl;
    }

    // Clean up memory (optional for this simple test)
    delete root1->right->right;
    delete root1->right->left;
    delete root1->right;
    delete root1->left;
    delete root1;

    // ... clean up root2 ...
    
    return 0;
}
