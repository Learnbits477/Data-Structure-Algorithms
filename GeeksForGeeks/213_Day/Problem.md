# 213. [Minimum Cost Selection](https://www.geeksforgeeks.org/problems/buying-vegetables0016/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 50.75%](https://img.shields.io/badge/Acceptance-50.75%25-green?style=for-the-badge)
![Submissions: 11K+](https://img.shields.io/badge/Submissions-11K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Dynamic%20Programming-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an $n \times 3$ matrix `mat[][]`, where each row represents the costs of three available choices at a shop, select exactly one choice from each row such that the same choice is not selected in two adjacent rows.

Return the minimum total cost required.

---

## 📌 Examples

**Example 1:**
```text
Input: mat[][] = [[1, 50, 50], [50, 50, 50], [1, 50, 50]]
Output: 52
Explanation: One optimal selection is:
- Row 1: Choice 1 (Cost = 1)
- Row 2: Choice 2 (Cost = 50)
- Row 3: Choice 1 (Cost = 1)
Total cost = 1 + 50 + 1 = 52.
```

**Example 2:**
```text
Input: mat[][] = [[1, 4, 1], [3, 2, 2], [3, 2, 3]]
Output: 5
Explanation: One optimal selection is:
- Row 1: Choice 1 (Cost = 1)
- Row 2: Choice 2 (Cost = 2)
- Row 3: Choice 3 (Cost = 2)
Total cost = 1 + 2 + 2 = 5.
```

---

## 📐 Constraints

- $1 \le n \le 10^5$
- $3 \le mat[0].size() \le 3$
- $1 \le mat[i][j] \le 100$
- $mat.rows = n$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../212_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../214_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
