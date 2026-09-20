# 236. [Largest Subsquare Surrounded by X](https://www.geeksforgeeks.org/problems/largest-subsquare-surrounded-by-x0558/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 50.31%](https://img.shields.io/badge/Accuracy-50.31%25-orange?style=for-the-badge)
![Submissions: 39K+](https://img.shields.io/badge/Submissions-39K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Company: D-E-Shaw](https://img.shields.io/badge/Company-D--E--Shaw-red?style=for-the-badge)
![Topic: Matrix](https://img.shields.io/badge/Topic-Matrix-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given a square matrix `mat[][]` of size $n \times n$, where each cell contains either `'X'` or `'O'`. Find the size of the largest square submatrix whose boundary is completely surrounded by `'X'`.

The cells inside the submatrix can contain either `'X'` or `'O'`. Only the four sides (boundary edges) of the submatrix must contain `'X'`.

Return the side length of the largest such square submatrix.

> **Note:**
> - A square of size $1$ is valid if its only cell is `'X'`.
> - If no such square submatrix exists, return $0$.

---

## 📌 Examples

**Example 1:**

```text
Input: mat[][] = 
[['X', 'X', 'X', 'O'],
 ['X', 'O', 'X', 'X'],
 ['X', 'X', 'X', 'O'],
 ['X', 'O', 'X', 'X']]
Output: 3
Explanation:
Here, the input represents a matrix of size 4 x 4.
The square submatrix starting at (0, 0) and ending at (2, 2) has size 3 x 3:
Row 0: X X X
Row 1: X O X
Row 2: X X X
All four boundary sides are composed entirely of 'X'.
Therefore, the size of that matrix is 3.
```

**Example 2:**

```text
Input: mat[][] = 
[['X', 'X'],
 ['X', 'X']]
Output: 2
Explanation:
The largest square submatrix surrounded by 'X' is the whole input matrix of size 2 x 2.
```

---

## 📐 Constraints

- $1 \le n \le 1000$
- $\text{mat.size()} == n$
- $\text{mat}[i]\text{.size()} == n$
- $\text{mat}[i][j] \in \{'X', 'O'\}$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n^3)$ |
| **Auxiliary Space** | $\mathcal{O}(n^2)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../235_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../237_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
