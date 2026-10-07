# 253. [Max Path Sum Between Two Leaves](https://www.geeksforgeeks.org/problems/maximum-path-sum/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 18.39%](https://img.shields.io/badge/Accuracy-18.39%25-orange?style=for-the-badge)
![Submissions: 212K+](https://img.shields.io/badge/Submissions-212K%2B-blue?style=for-the-badge)
![Points: 8](https://img.shields.io/badge/Points-8-orange?style=for-the-badge)
![Company: Accolite](https://img.shields.io/badge/Topics:-Accolite-red?style=for-the-badge)
![Company: Amazon](https://img.shields.io/badge/Amazon-red?style=for-the-badge)
![Company: Microsoft](https://img.shields.io/badge/Microsoft-red?style=for-the-badge)
![Company: OYO Rooms](https://img.shields.io/badge/OYO%20Rooms-red?style=for-the-badge)
![Company: FactSet](https://img.shields.io/badge/FactSet-red?style=for-the-badge)
![Company: Directi](https://img.shields.io/badge/Directi-red?style=for-the-badge)
![Company: Facebook](https://img.shields.io/badge/Facebook-red?style=for-the-badge)
![Topic: Tree](https://img.shields.io/badge/Topic-Tree-blue?style=for-the-badge)
![Topic: Binary Tree](https://img.shields.io/badge/Binary%20Tree-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Bottom-Up Post-Order Traversal & Junction Evaluation:**
> 1. **Leaf-to-Leaf Path Geometry**:
>    A valid path must start strictly at one leaf node and terminate strictly at another leaf node. Hence, the Lowest Common Ancestor (LCA) of those two leaves serves as the "apex" / junction node of that path.
> 2. **Subtree Return Value vs. Global Maximum**:
>    - For any subtree rooted at `node`, a parent node can only extend a path downwards through **one** branch. Thus, the helper function must return $\max(\text{leftBranch}, \text{rightBranch}) + \text{node}\to\text{data}$.
>    - Only when a node possesses **both** non-null left and right children can a valid leaf-to-leaf path turn through it:
>      $$\text{PathSum} = \text{leftBranch} + \text{rightBranch} + \text{node}\to\text{data}$$
>      This candidate path updates the global maximum result.
> 3. **Deficit / Boundary Guard**:
>    If the tree contains fewer than 2 leaf nodes (e.g., an empty tree, a single node, or a linear degenerate chain where every node has at most one child), no leaf-to-leaf path can ever be formed. In such cases, the problem mandates returning `-1`.

---

## 🧩 Problem Description

Given the root of a binary tree, where each node contains an integer value, find the maximum possible path sum between any two leaf nodes. If the tree has fewer than two leaf nodes, return `-1`.

A **leaf node** is a node with no children (both left and right pointers are `NULL`).
A **path between two leaf nodes** is a sequence of unique adjacent nodes that connects one leaf node to another leaf node without revisiting any node.

---

## 📌 Examples

**Example 1:**

```text
Input: root = [3, 4, 5, -10, 4, N, N]
Output: 16
Explanation:
The leaf nodes are -10, 4 (right child of 4), and 5.
Possible paths between leaf nodes are:
-10 -> 4 -> 3 -> 5 = -10 + 4 + 3 + 5 = 2
-10 -> 4 -> 4 = -10 + 4 + 4 = -2
4 -> 4 -> 3 -> 5 = 4 + 4 + 3 + 5 = 16
Hence, the maximum path sum is obtained from the path 4 -> 4 -> 3 -> 5, giving 16.
```

**Example 2:**

```text
Input: root = [-15, 5, 6, -8, 1, 3, 9, 2, -3, N, N, N, N, N, 0, N, N, N, N, 4, -1, N, N, 10]
Output: 27
Explanation:
The leaf nodes are 2, -3, 1, 4, and 10.
Some possible paths between leaves are:
2 -> -8 -> 5 -> 1 = 2 + (-8) + 5 + 1 = 0
-3 -> -8 -> 5 -> 1 = -3 + (-8) + 5 + 1 = -5
2 -> -8 -> 5 -> -15 -> 6 -> 3 = 2 + (-8) + 5 + (-15) + 6 + 3 = -7
1 -> 5 -> -15 -> 6 -> 9 -> 0 -> 4 = 1 + 5 + (-15) + 6 + 9 + 0 + 4 = 10
3 -> 6 -> 9 -> 0 -> -1 -> 10 = 3 + 6 + 9 + 0 + (-1) + 10 = 27
Hence, the maximum path sum is obtained from the path 3 -> 6 -> 9 -> 0 -> -1 -> 10, giving 27.
```

**Example 3:**

```text
Input: root = [3, 4, 1, -10, 4, N, N]
Output: 12
Explanation:
The leaf nodes are -10, 4 (right child of 4), and 1.
Possible paths between leaf nodes are:
-10 -> 4 -> 4 = -10 + 4 + 4 = -2
-10 -> 4 -> 3 -> 1 = -10 + 4 + 3 + 1 = -2
4 -> 4 -> 3 -> 1 = 4 + 4 + 3 + 1 = 12
Hence, the maximum path sum is obtained from the path 4 -> 4 -> 3 -> 1, giving 12.
```

---

## 📐 Constraints

- $0 \le \text{size of binary tree} \le 10^4$
- $-10^3 \le \text{node.data} \le 10^3$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(h)$ |

*Where $n$ represents the total number of nodes in the binary tree and $h$ is the maximum height of the tree (call stack recursion).*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../252_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../254_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
