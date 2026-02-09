#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    TreeNode* balanceBST(TreeNode* root) {
        // Create a vector to store the inorder traversal of the BST
        vector<int> inorder;
        inorderTraversal(root, inorder);

        int size = inorder.size();

        // Construct and return the balanced BST
        return createBalancedBST(inorder, 0, size - 1);
    }

private:
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        // Perform an inorder traversal to store the elements in sorted order
        if (root == nullptr) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    TreeNode* createBalancedBST(const vector<int>& inorder, int start,
                                int end) {
        // Base case: if the start index is greater than the end index, return
        // nullptr
        if (start > end) return nullptr;

        // Find the middle element of the current range
        int mid = start + (end - start) / 2;

        // Recursively construct the left and right subtrees
        TreeNode* leftSubtree = createBalancedBST(inorder, start, mid - 1);
        TreeNode* rightSubtree = createBalancedBST(inorder, mid + 1, end);

        // Create a new node with the middle element and attach the subtrees
        return new TreeNode(inorder[mid], leftSubtree, rightSubtree);
    }
};

// Helper function to print tree level order (for verification)
void printTree(TreeNode* root) {
    if (!root) {
        cout << "[]" << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    cout << "[";
    bool first = true;
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (!first) cout << ",";
        if (curr) {
            cout << curr->val;
            q.push(curr->left);
            q.push(curr->right);
        } else {
            cout << "null";
        }
        first = false;
    }
    cout << "]" << endl;
}

// Helper to calculate height
int height(TreeNode* node) {
    if (node == nullptr)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

// Helper to check if balanced
bool isBalanced(TreeNode* root) {
    if (root == nullptr)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}


int main() {
    Solution sol;
    
    // Example 1: root = [1,null,2,null,3,null,4,null,null]
    // Constructing the skewed tree manually
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    
    cout << "Original tree height: " << height(root) << endl;
    
    TreeNode* newRoot = sol.balanceBST(root);
    
    cout << "Balanced tree height: " << height(newRoot) << endl;
    cout << "Is Balanced: " << (isBalanced(newRoot) ? "Yes" : "No") << endl;
    
    // Basic output check (Level Order)
    // Note: Output might vary slightly depending on interpretation of 'balanced', 
    // but height difference property must hold.
    // printTree(newRoot); 
    
    return 0;
}
