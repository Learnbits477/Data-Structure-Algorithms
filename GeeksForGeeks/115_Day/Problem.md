# [115. 1s Surrounded by 0s](https://www.geeksforgeeks.org/problems/1s-surrounded-by-0s/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 50.93%](https://img.shields.io/badge/Acceptance-50.93%25-blue?style=for-the-badge)
![Submissions: 92K+](https://img.shields.io/badge/Submissions-92K%2B-purple?style=for-the-badge)

---

## 🧩 Problem Description

Given an $n \times m$ binary matrix `grid[][]`, find the total count of all cells containing $1$ that are unable to move out of the grid through a path of adjacent $1$s.

Adjacency means you can only move in four directions: **Up, Down, Left, and Right**. Diagonal moves are not allowed.

Assume that the space immediately outside the grid is an open path. Any $1$ located directly on the outer boundary of the grid (first row, last row, first column, or last column) can immediately step out, and any $1$ connected to it can follow and also step out of the grid.

---

## 📌 Examples

### Example 1

**Input:**
```text
grid[][] = [[0, 0, 0, 0],
            [1, 0, 1, 0],
            [0, 1, 1, 0],
            [0, 0, 0, 0]]
```
**Output:** `3`  
**Explanation:**  
The $1$ at `(1, 0)` is on the left boundary, so it can immediately step out.  
The $1$s at `(1, 2)`, `(2, 1)`, and `(2, 2)` are surrounded by $0$s and cannot reach any boundary cell to escape. Thus, there are $3$ such cells.

### Example 2

**Input:**
```text
grid[][] = [[1, 1, 0, 0, 0, 1],
            [0, 1, 1, 0, 1, 0],
            [0, 0, 0, 1, 1, 0],
            [0, 0, 0, 1, 1, 0],
            [0, 1, 0, 1, 0, 0],
            [1, 1, 0, 0, 0, 1]]
```
**Output:** `6`  
**Explanation:**  
The $1$s at `(2, 3)`, `(2, 4)`, `(3, 3)`, `(3, 4)`, `(4, 3)`, and `(4, 1)` cannot reach any boundary $1$s to step out.

---

## 📐 Constraints

- $1 \le n, m \le 500$
- $0 \le grid[i][j] \le 1$

---

## ⏱️ Expected Complexities

| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $$O(n \times m)$$ |
| **Auxiliary Space** | $$O(n \times m)$$ |

---

## 🏷️ Topic Tags

- `Graph`
- `Depth First Search`
- `Breadth First Search`
- `Algorithms`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../114_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../116_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
