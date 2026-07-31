# [179. Max Sum Square Sub-Matrix of Size k](https://www.geeksforgeeks.org/problems/max-sum-square-sub-matrix-of-size-k/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 50.41%](https://img.shields.io/badge/Accuracy-50.41%25-blue?style=for-the-badge)
![Submissions: 14K+](https://img.shields.io/badge/Submissions-14K%2B-purple?style=for-the-badge)
![Company: Adobe](https://img.shields.io/badge/Company-Adobe-red?style=for-the-badge)

---

## 🧩 Problem Description

Given a $n \times n$ grid `mat[][]` of integers where values can be negative, find the maximum sum among all possible $k \times k$ sub-grids.

---

## 📌 Examples

**Example 1:**
- **Input:** $k = 3$, `mat[][]` =
  ```
  [[1, 2, -1, 4],
   [-8, -3, 4, 2],
   [3, 8, 10, -8],
   [-4, -1, 1, 7]]
  ```
- **Output:** `20`
- **Explanation:** The $3 \times 3$ sub-grid highlighted below has the maximum sum of 20:
  ```
  [[-3, 4, 2],
   [8, 10, -8],
   [-1, 1, 7]]
  ```
  Sum = $-3 + 4 + 2 + 8 + 10 - 8 - 1 + 1 + 7 = 20$.

**Example 2:**
- **Input:** $k = 1$, `mat[][]` = `[[4]]`
- **Output:** `4`
- **Explanation:** Only one $1 \times 1$ sub-grid exists with sum 4.

---

## 📐 Constraints
- $1 \le n \le 1000$
- $1 \le k \le n$
- $-1000 \le mat[i][j] \le 1000$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n^2)$ |
| **Auxiliary Space** | $O(n^2)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../178_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../180_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
