# [180. Print Binary Tree levels in sorted order](https://www.geeksforgeeks.org/problems/print-binary-tree-levels-in-sorted-order3241/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 46.62%](https://img.shields.io/badge/Accuracy-46.62%25-blue?style=for-the-badge)
![Submissions: 15K+](https://img.shields.io/badge/Submissions-15K%2B-purple?style=for-the-badge)
![Topic: Tree](https://img.shields.io/badge/Tree-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-blueviolet?style=for-the-badge)
![Topic: Queue](https://img.shields.io/badge/Queue-brightgreen?style=for-the-badge)
![Topic: Priority Queue](https://img.shields.io/badge/Priority--Queue-red?style=for-the-badge)

---

## 🧩 Problem Description

Given an integer array `arr[]` representing the nodes of a Complete Binary Tree in level order traversal, return the nodes at each level in sorted ascending order.

For every level of the binary tree, sort the values present at that level independently and return the resulting levels as a 2D array, where the $i$-th row contains the sorted values of the $i$-th level.

---

## 📌 Examples

**Example 1:**
- **Input:** `arr[]` = `[7, 6, 5, 4, 3, 2, 1]`
- **Output:** `[[7], [5, 6], [1, 2, 3, 4]]`
- **Explanation:** The complete binary tree formed from the given level order traversal is:
  ```
          7
        /   \
       6     5
      / \   / \
     4   3 2   1
  ```
  The nodes at each level after sorting are:
  - Level 0: `[7]`
  - Level 1: `[5, 6]` (sorted from `[6, 5]`)
  - Level 2: `[1, 2, 3, 4]` (sorted from `[4, 3, 2, 1]`)

**Example 2:**
- **Input:** `arr[]` = `[7, 16, 1, 4, 13]`
- **Output:** `[[7], [1, 16], [4, 13]]`
- **Explanation:** The complete binary tree formed from the given level order traversal is:
  ```
          7
        /   \
      16     1
      / \
     4   13
  ```
  The nodes at each level after sorting are:
  - Level 0: `[7]`
  - Level 1: `[1, 16]` (sorted from `[16, 1]`)
  - Level 2: `[4, 13]` (sorted from `[4, 13]`)

---

## 📐 Constraints
- $1 \le \text{arr.size()} \le 10^4$
- $1 \le \text{arr}[i] \le 10^9$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n \log n)$ |
| **Auxiliary Space** | $O(n)$ |

---

## 🏷️ Topic Tags
- Sorting
- Queue
- Tree
- Priority-queue

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../179_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../181_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
