# [Largest BST](https://www.geeksforgeeks.org/problems/largest-bst/1)

**Difficulty:** Medium
**Accuracy:** 29.73%
**Submissions:** 197K+
**Points:** 4

You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.

**Note:** A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.

## Examples:

**Example 1:**
**Input:** root = [5, 2, 4, 1, 3]
**Output:** 3
**Explanation:** The following sub-tree is a BST of size 3 (nodes 2, 1, 3).

**Example 2:**
**Input:** root = [6, 7, 3, N, 2, 2, 4]
**Output:** 3
**Explanation:** The following sub-tree is a BST of size 3 (nodes 3, 2, 4).

## Constraints:
- 1 ≤ number of nodes ≤ 10^5
- 1 ≤ node->data ≤ 10^5
