# 196. [Largest Odd Squares with Limited 1s](https://www.geeksforgeeks.org/problems/largest-square-in-a-binary-matrix-with-at-most-k-1s-for-multiple-queries/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 49.41%](https://img.shields.io/badge/Accuracy-49.41%25-blue?style=for-the-badge)
![Submissions: 11K+](https://img.shields.io/badge/Submissions-11K+-purple?style=for-the-badge)
![Topic: Matrix](https://img.shields.io/badge/Topic-Matrix-brightgreen?style=for-the-badge)
![Company: Directi](https://img.shields.io/badge/Company-Directi-blue?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a binary matrix `mat[][]` of size `n * m` and an integer `k`, process a list of queries `queries[][]`. Each query contains coordinates `[i, j]` of the center of a square.

For every query, find the side length of the largest odd-sized square centered at cell `(i, j)` such that the square contains at most `k` ones.
A square centered at `(i, j)` expands outward symmetrically in all four directions by the same number of cells, so its side length is always odd.

---

## 📌 Examples

**Example 1:**
- **Input:** `mat[][]` = `[[1, 0, 1, 0, 0], [1, 0, 1, 1, 1], [1, 1, 1, 1, 1], [1, 0, 0, 1, 0]]`, `queries[][]` = `[[1, 2]]`, `k` = `9`
- **Output:** `[3]`
- **Explanation:** The largest odd-sized square centered at `(1, 2)` is the $3 \times 3$ square spanning rows 0 to 2 and columns 1 to 3. It contains 6 ones, which is at most `k = 9`. Hence, the answer is 3.

**Example 2:**
- **Input:** `mat[][]` = `[[1, 1, 1], [1, 1, 1], [1, 1, 1]]`, `queries[][]` = `[[1, 1], [2, 2]]`, `k` = `9`
- **Output:** `[3, 1]`
- **Explanation:**
  - For query `(1, 1)`, the largest valid square is the entire $3 \times 3$ matrix, which contains 9 ones. Hence, the answer is 3.
  - For query `(2, 2)`, no expansion is possible without going outside the matrix, so only the $1 \times 1$ square centered at `(2, 2)` is valid. Hence, the answer is 1.

---

## 📐 Constraints

- $1 \le mat.size(), mat[0].size() \le 500$
- $1 \le queries.size() \le 10^4$
- $0 \le queries[q][0] < mat.size()$
- $0 \le queries[q][1] < mat[0].size()$
- $0 \le k \le mat.size() \times mat[0].size()$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n \times m + q \times \log(\min(n, m)))$ |
| **Auxiliary Space** | $O(n \times m)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../195_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../197_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
