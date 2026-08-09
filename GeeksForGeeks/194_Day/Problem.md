# 194. [Largest Zigzag Sequence](https://www.geeksforgeeks.org/problems/largest-zigzag-sequence5416/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 42.24%](https://img.shields.io/badge/Accuracy-42.24%25-blue?style=for-the-badge)
![Submissions: 8K+](https://img.shields.io/badge/Submissions-8K+-purple?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a square matrix `mat[][]` of size $n \times n$. A zigzag sequence starts from the top and ends at the bottom. Two consecutive elements of the sequence cannot belong to the same column.

Return the maximum sum of such a zigzag sequence.

---

## 📌 Examples

**Example 1:**
- **Input:** `mat[][] = [[3, 1, 2], [4, 8, 5], [6, 9, 7]]`
- **Output:** `18`
- **Explanation:** One optimal zigzag sequence is: $3 \rightarrow 8 \rightarrow 7$, where the sum $= 3 + 8 + 7 = 18$. (Row 0, Col 0) $\rightarrow$ (Row 1, Col 1) $\rightarrow$ (Row 2, Col 2).

**Example 2:**
- **Input:** `mat[][] = [[1, 2, 4], [3, 9, 6], [11, 3, 15]]`
- **Output:** `28`
- **Explanation:** One optimal zigzag sequence is: $4 \rightarrow 9 \rightarrow 15$, where the sum $= 4 + 9 + 15 = 28$. (Row 0, Col 2) $\rightarrow$ (Row 1, Col 1) $\rightarrow$ (Row 2, Col 2).

---

## 📐 Constraints

- $1 \le n \le 100$
- $1 \le mat[i][j] \le 1000$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n^2)$ |
| **Auxiliary Space** | $O(n)$ |

---

## 🏷️ Topic Tags

- `Dynamic Programming`
- `Matrix`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../193_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../195_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
