# Approach for Largest BST

## Problem Statement

Given a binary tree, find the size of the largest sub-tree which is also a Binary Search Tree (BST).

## Approach

We can solve this problem using a post-order traversal (bottom-up approach). For each node, we need to determine if the subtree rooted at this node is a BST, and if so, what its size is.

To do this most efficiently in O(N) time without any class/struct overhead, we use a single recursive function that returns the size of the valid BST and passes the minimum value, maximum value, and maximum BST size found so far by reference.

### Recursive Step

For any node:

1. Recursively get the size, min, and max info from the left and right subtrees.
2. The current subtree is a valid BST if:
   - The left subtree is a BST (did not return -1).
   - The right subtree is a BST (did not return -1).
   - The current node's value is strictly greater than the maximum value in the left subtree.
   - The current node's value is strictly lesser than the minimum value in the right subtree.

If it is a valid BST:

- We update the `minVal` and `maxVal` references for the current subtree: `minVal = min(node.val, left.minVal)` and `maxVal = max(node.val, right.maxVal)`.
- We compute its size `currentSize = leftSize + rightSize + 1`.
- We update the global `maxSize` reference to keep track of the largest BST.
- We return `currentSize`.

If it is not a valid BST:

- It cannot form a BST with any of its ancestors, so we simply return `-1`.

### Base Case

An empty tree is a BST of size 0, and we return 0 directly.

## Complexity

- **Time Complexity:** O(N) where N is the number of nodes in the given binary tree. We visit every node exactly once.
- **Space Complexity:** O(H) where H is the height of the tree. This space is required for the recursive call stack. In the worst case (skewed tree), H = N.
