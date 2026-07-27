# [181. Construct a Full Binary Tree](https://www.geeksforgeeks.org/problems/construct-a-full-binary-tree--170648/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 74.63%](https://img.shields.io/badge/Accuracy-74.63%25-blue?style=for-the-badge)
![Submissions: 23K+](https://img.shields.io/badge/Submissions-23K%2B-purple?style=for-the-badge)
![Topic: Tree](https://img.shields.io/badge/Tree-blue?style=for-the-badge)
![Topic: Traversal](https://img.shields.io/badge/Traversal-brightgreen?style=for-the-badge)

---

## 🧩 Problem Description

Given two arrays `pre[]` and `preMirror[]` of size $n$ containing unique elements, where `pre[]` represents the preorder traversal of a full binary tree and `preMirror[]` represents the preorder traversal of its mirror tree, construct the original full binary tree using these traversals.

> [!NOTE]
> A general binary tree cannot be uniquely constructed using these two traversals. However, a **full binary tree** (where every node has either $0$ or $2$ children) can be constructed uniquely from the given traversals without any ambiguity.

---

## 📌 Examples

**Example 1:**
- **Input:** `pre[]` = `[0, 1, 2]`, `preMirror[]` = `[0, 2, 1]`
- **Output:** `[0, 1, 2]`
- **Explanation:** The tree will look like:
  ```
         0
       /   \
      1     2
  ```
  The preorder traversal of this tree is `[0, 1, 2]`.

**Example 2:**
- **Input:** `pre[]` = `[1, 2, 4, 5, 3, 6, 7]`, `preMirror[]` = `[1, 3, 7, 6, 2, 5, 4]`
- **Output:** `[1, 2, 4, 5, 3, 6, 7]`
- **Explanation:** The tree will look like:
  ```
         1
       /   \
      2     3
     / \   / \
    4   5 6   7
  ```
  The preorder traversal of this tree is `[1, 2, 4, 5, 3, 6, 7]`.

---

## 📐 Constraints

- $1 \le n \le 10^5$
- $0 \le pre[i], preMirror[i] \le 10^9$
- All elements in `pre[]` and `preMirror[]` are unique.
- The inputs are guaranteed to form a valid full binary tree.

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(n)$ |

---

## 🏷️ Topic Tags

- Tree
- Traversal
- Recursion
- Hash

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../180_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../182_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
