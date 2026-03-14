# [GeeksForGeeks - Top View of Binary Tree](https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1)

**Difficulty:** Medium
**Accuracy:** 38.43%
**Submissions:** 438K+
**Points:** 4
**Average Time:** 45m

### Problem Statement

You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

**Note:**
- Return the nodes from the leftmost node to the rightmost node.
- If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 

### Examples:

**Example 1:**

**Input:** root = [1, 2, 3]
**Output:** [2, 1, 3]
**Explanation:** The Green colored nodes represents the top view in the below Binary tree.
*(Image not available but structure is 1 as root, 2 as left child, 3 as right child)*
 
**Example 2:**

**Input:** root = [10, 20, 30, 40, 60, 90, 100]
**Output:** [40, 20, 10, 30, 100]
**Explanation:** The Green colored nodes represents the top view in the below Binary tree.
*(Structure typically represents 10 as root, 20 left, 30 right, 40 left of 20, 60 right of 20, 90 left of 30, 100 right of 30)*

### Constraints:
- `1 ≤ number of nodes ≤ 10^5`
- `1 ≤ node->data ≤ 10^5`
