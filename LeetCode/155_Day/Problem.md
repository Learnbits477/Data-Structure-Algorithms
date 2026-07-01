# [2812. Find the Safest Path in a Grid](https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 49.5%](https://img.shields.io/badge/Acceptance-49.5%25-blue?style=for-the-badge)
![Submissions: 241K](https://img.shields.io/badge/Submissions-241K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given a $0$-indexed 2D matrix `grid` of size $n \times n$, where $(r, c)$ represents:
- A cell containing a thief if `grid[r][c] = 1`
- An empty cell if `grid[r][c] = 0`

You are initially positioned at cell $(0, 0)$. In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

The **safeness factor** of a path on the grid is defined as the minimum Manhattan distance from any cell in the path to any thief in the grid.

Return the *maximum safeness factor of all paths leading to cell* $(n - 1, n - 1)$.

An adjacent cell of cell $(r, c)$, is one of the cells $(r, c + 1)$, $(r, c - 1)$, $(r + 1, c)$, and $(r - 1, c)$ if it exists.

The Manhattan distance between two cells $(a, b)$ and $(x, y)$ is equal to $|a - x| + |b - y|$, where $|val|$ denotes the absolute value of $val$.

---

## 📌 Examples

### Example 1
**Input:**
```text
grid = [[1,0,0],[0,0,0],[0,0,1]]
```
**Output:**
```text
0
```
**Explanation:**
All paths from $(0, 0)$ to $(n - 1, n - 1)$ go through the thieves in cells $(0, 0)$ and $(n - 1, n - 1)$.

### Example 2
**Input:**
```text
grid = [[0,0,1],[0,0,0],[0,0,0]]
```
**Output:**
```text
2
```
**Explanation:**
The safest path has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell $(0, 2)$ is cell $(0, 0)$. The distance between them is $|0 - 0| + |0 - 2| = 2$.
It can be shown that there are no other paths with a higher safeness factor.

### Example 3
**Input:**
```text
grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
```
**Output:**
```text
2
```
**Explanation:**
The safest path has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell $(0, 3)$ is cell $(1, 2)$. The distance between them is $|0 - 1| + |3 - 2| = 2$.
- The closest cell of the path to the thief at cell $(3, 0)$ is cell $(3, 2)$. The distance between them is $|3 - 3| + |0 - 2| = 2$.
It can be shown that there are no other paths with a higher safeness factor.

---

## 📐 Constraints

- $$1 \le \text{grid.length} = n \le 400$$
- $$\text{grid}[i]\text{.length} = n$$
- $$\text{grid}[i][j] \in \{0, 1\}$$
- There is at least one thief in the grid.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n^2 \log n)$$ |
| 💾 Auxiliary Space | $$O(n^2)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-3498DB?style=for-the-badge)
![Binary Search](https://img.shields.io/badge/Binary%20Search-F1C40F?style=for-the-badge)
![Breadth-First Search](https://img.shields.io/badge/Breadth--First%20Search-9B59B6?style=for-the-badge)
![Union-Find](https://img.shields.io/badge/Union--Find-E67E22?style=for-the-badge)
![Heap (Priority Queue)](https://img.shields.io/badge/Heap%20(Priority%20Queue)-2ECC71?style=for-the-badge)
![Matrix](https://img.shields.io/badge/Matrix-34495E?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../154_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../156_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
