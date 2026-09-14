# 230. [Find Shortest Safe Route in a Matrix](https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 50.58%](https://img.shields.io/badge/Accuracy-50.58%25-orange?style=for-the-badge)
![Submissions: 41K+](https://img.shields.io/badge/Submissions-41K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: DFS](https://img.shields.io/badge/DFS-blue?style=for-the-badge)
![Topic: Graph](https://img.shields.io/badge/Graph-blue?style=for-the-badge)
![Topic: BFS](https://img.shields.io/badge/BFS-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given a 2D matrix `mat[][]` of size $n \times m$, where each cell is either `0` (landmine) or `1` (safe), find the **minimum number of steps** required to travel from **any cell in the leftmost column** (column $0$) to **any cell in the rightmost column** (column $m - 1$).

You can move only in **four directions**: up, down, left, and right.

A cell is **unsafe** if it contains a landmine or is directly adjacent (up, down, left, or right) to a landmine, and such cells **must be avoided**.

Return `-1` if no safe path exists.

---

## 📌 Examples

**Example 1:**

```text
Input: mat[][] = [
  [1, 0, 1, 1, 1],
  [1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1],
  [1, 1, 1, 0, 1],
  [1, 1, 1, 1, 0]
]
Output: 6
Explanation: We can see that the length of the shortest safe route from column 0 to column 4 is 6.
One such route is: (2,0) -> (2,1) -> (2,2) -> (1,2) -> (1,3) -> (1,4).
```

**Example 2:**

```text
Input: mat[][] = [
  [1, 1, 1, 1, 1],
  [1, 1, 0, 1, 1],
  [1, 1, 1, 1, 1]
]
Output: -1
Explanation: Landmine at (1,2) marks (0,2), (1,2), (2,2), (1,1), (1,3) as unsafe.
Since all cells in column 2 are unsafe, there is no possible path from first column to last column.
```

---

## 📐 Constraints

- $1 \le n, m \le 10^3$
- $0 \le \text{mat}[i][j] \le 1$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \times m)$ |
| **Auxiliary Space** | $\mathcal{O}(n \times m)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../229_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../231_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
