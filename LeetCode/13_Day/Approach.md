# Approach: Convert to Sorted Array and Rebuild

The problem asks us to balance a given Binary Search Tree (BST). A balanced BST is one where the depth of the two subtrees of every node never differs by more than 1.

## Intuition

A BST has a property that its **inorder traversal** yields the node values in sorted ascending order.
If we have a sorted array of values, we can easily construct a balanced BST by:
1.  Picking the middle element of the array as the root.
2.  Recursively building the left subtree from the left half of the array.
3.  Recursively building the right subtree from the right half of the array.

This ensures that the tree is height-balanced because we are distributing the nodes as evenly as possible between the left and right subtrees at each step.

## Algorithm

1.  **Inorder Traversal**: Traverse the given BST in an inorder manner (Left -> Root -> Right) and store the values in a vector/list. This gives us a sorted list of values.
2.  **Build Balanced BST**: Use a recursive function `buildHelper(start, end)`:
    *   Find the `mid` index: `mid = start + (end - start) / 2`.
    *   Create a new tree node with the value at `sortedArr[mid]`.
    *   Recursively call `buildHelper(start, mid - 1)` for the left child.
    *   Recursively call `buildHelper(mid + 1, end)` for the right child.
    *   Return the root of this newly constructed subtree.

## Complexity Analysis

*   **Time Complexity**: O(N), where N is the number of nodes.
    *   Inorder traversal takes O(N).
    *   Building the tree takes O(N) as we visit each element once to create a node.
*   **Space Complexity**: O(N).
    *   We need O(N) space to store the sorted values in the array.
    *   The recursion stack for building the tree will take O(log N) space (since the resulting tree is balanced), and the inorder traversal stack can take up to O(N) in the worst case (if the original tree is skewed).

## Code Structure

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> sortedArr;
    
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        sortedArr.push_back(root->val);
        inorder(root->right);
    }
    
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
```
