# 234. [Minimum Absolute Difference In BST](https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 56.22%](https://img.shields.io/badge/Accuracy-56.22%25-orange?style=for-the-badge)
![Submissions: 36K+](https://img.shields.io/badge/Submissions-36K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: Binary Search Tree](https://img.shields.io/badge/Topic-Binary%20Search%20Tree-blue?style=for-the-badge)
![Topic: Tree](https://img.shields.io/badge/Tree-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given the root of a **Binary Search Tree (BST)** containing $n$ ($n > 1$) nodes, find the minimum absolute difference between the values of any two different nodes in the tree.

Return the minimum absolute difference.

---

## 📌 Examples

**Example 1:**

```text
Input: root[] = [50, 30, 70, 20, N, 60, 80]
Output: 10
Explanation:
The in-order sorted traversal of the BST is: [20, 30, 50, 60, 70, 80]
Differences between adjacent nodes:
|30 - 20| = 10
|50 - 30| = 20
|60 - 50| = 10
|70 - 60| = 10
|80 - 70| = 10
The minimum absolute difference is 10.
```

**Example 2:**

```text
Input: root[] = [60, 30, 90, 10]
Output: 20
Explanation:
The in-order sorted traversal of the BST is: [10, 30, 60, 90]
Differences between adjacent nodes:
|30 - 10| = 20
|60 - 30| = 30
|90 - 60| = 30
The minimum absolute difference is 20.
```

---

## 📐 Constraints

- $2 \le n \le 10^5$ (size of binary tree)
- $0 \le \text{node.data} \le 10^6$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(h)$ |

> Where $h$ is the height of the Binary Search Tree ($\mathcal{O}(\log n)$ for balanced BST, $\mathcal{O}(n)$ for skewed BST).

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../233_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../235_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
