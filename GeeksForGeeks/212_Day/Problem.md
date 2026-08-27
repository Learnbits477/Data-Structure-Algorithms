# 212. [Largest Rectangle with Column Swaps](https://www.geeksforgeeks.org/problems/find-the-largest-rectangle-of-1s-with-swapping-of-columns-allowed0243/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 62.88%](https://img.shields.io/badge/Acceptance-62.88%25-green?style=for-the-badge)
![Submissions: 8K+](https://img.shields.io/badge/Submissions-8K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Arrays-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Matrix-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given a binary matrix `mat[][]` of size $n \times m$ containing only $0$s and $1$s, any pair of columns may be swapped any number of times. Return the maximum area of a rectangle consisting entirely of $1$'s that can be formed after performing the column swaps.

---

## 📌 Examples

**Example 1:**
```text
Input: mat[][] = [[0, 1, 0, 1, 0], 
                  [0, 1, 0, 1, 1], 
                  [1, 1, 0, 1, 0]]
Output: 6
Explanation: After swapping the 2nd and 3rd columns (or reordering columns appropriately), the largest rectangle of 1s has an area of 6.
```

**Example 2:**
```text
Input: mat[][] = [[0, 1, 1, 0, 0], 
                  [1, 1, 1, 0, 1], 
                  [1, 1, 1, 0, 1], 
                  [1, 1, 1, 1, 1]]
Output: 12
Explanation: After swapping the 4th and 5th columns (or grouping columns with tallest bars), the largest rectangle of 1s has an area of 12.
```

---

## 📐 Constraints
- $1 \le n, m \le 10^3$
- $0 \le mat[i][j] \le 1$
- $mat.rows = n$
- $mat.cols = m$

---

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \times (n + m))$ |
| **Auxiliary Space** | $\mathcal{O}(n \times m)$ |


---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../211_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../213_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
