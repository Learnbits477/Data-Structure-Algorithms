# 208. [Geek in a Maze](https://www.geeksforgeeks.org/problems/geek-in-a-maze--170637/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 49.51%](https://img.shields.io/badge/Acceptance-49.51%25-green?style=for-the-badge)
![Submissions: 10K+](https://img.shields.io/badge/Submissions-10K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Graph-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Breadth--First%20Search-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Shortest%20Path-blue?style=for-the-badge)

## 🧩 Problem Description

Given a maze `mat[][]` of size $n \times m$, where each cell is either:
- `'.'` representing an empty cell, or
- `'#'` representing an obstacle.

Find the number of distinct empty cells that Geek can visit starting from the cell `(r, c)`.

Geek can move **up**, **down**, **left**, or **right** to an adjacent non-obstacle cell inside the maze.
- On any path, Geek can make at most `u` upward moves and `d` downward moves.
- There is **no limit** on the number of left or right moves.
- If the starting cell is an obstacle, return `0`.

> **Note:** There can be multiple valid paths starting from `(r, c)`. A cell is counted if it can be reached via *at least one* valid path that respects the move limits.

---

## 📌 Examples

**Example 1:**
```text
Input: r = 1, c = 0, u = 1, d = 1, mat = [['.', '.', '.'], 
                                          ['.', '#', '.'], 
                                          ['#', '.', '.']]
Output: 5
Explanation: 
Geek starts from (1, 0) and can follow paths such as:
(1, 0) -> (0, 0) -> (0, 1) -> (0, 2) -> (1, 2)
The cells (1, 1) and (2, 0) are obstacles and cannot be visited.
Cell (2, 2) requires 2 downward moves (d=1 limit), so it cannot be reached.
Hence, Geek can visit 5 distinct empty cells: (1,0), (0,0), (0,1), (0,2), (1,2).
```

**Example 2:**
```text
Input: r = 2, c = 1, u = 2, d = 2, mat = [['.', '.', '.'], 
                                          ['.', '#', '.'], 
                                          ['.', '.', '.']]
Output: 8
Explanation: 
Geek starts from (2, 1) and follows the path:
(2, 1) -> (2, 2) -> (1, 2) -> (0, 2) -> (0, 1) -> (0, 0) -> (1, 0) -> (2, 0)
The cell (1, 1) is an obstacle.
Geek can visit all 8 empty cells within 2 upward and 2 downward moves.
```

**Example 3:**
```text
Input: r = 2, c = 1, u = 1, d = 0, mat = [['.', '.', '.'], 
                                          ['.', '#', '.'], 
                                          ['.', '.', '.']]
Output: 5
Explanation: 
The paths followed are:
- (2, 1) -> (2, 0) -> (1, 0)
- (2, 1) -> (2, 2) -> (1, 2)
Total reachable cells = 5.
```

---

## 📐 Constraints
- $1 \le n, m \le 10^3$
- $0 \le r < n$
- $0 \le c < m$
- $0 \le u, d \le 10^6$
- `mat[i][j]` is either `'.'` or `'#'`

---

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time** | $\mathcal{O}(n \times m)$ |
| **Space** | $\mathcal{O}(n \times m)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../207_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../209_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
