# [1260. Shift 2D Grid](https://leetcode.com/problems/shift-2d-grid/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-green?style=for-the-badge)
![Acceptance: 69.3%](https://img.shields.io/badge/Acceptance-69.3%25-blue?style=for-the-badge)
![Topics: Array](https://img.shields.io/badge/Array-orange?style=for-the-badge)
![Topics: Matrix](https://img.shields.io/badge/Matrix-orange?style=for-the-badge)
![Topics: Simulation](https://img.shields.io/badge/Simulation-orange?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a 2D `grid` of size `m x n` and an integer `k`. You need to shift the grid `k` times.

In one shift operation:
- Element at `grid[i][j]` moves to `grid[i][j + 1]`.
- Element at `grid[i][n - 1]` moves to `grid[i + 1][0]`.
- Element at `grid[m - 1][n - 1]` moves to `grid[0][0]`.

Return the 2D grid after applying shift operation `k` times.

---

## 📌 Examples

### Example 1
![grid1](https://assets.leetcode.com/uploads/2019/11/05/e1.png)
**Input:** 
```text
grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
```
**Output:** 
```text
[[9,1,2],[3,4,5],[6,7,8]]
```

### Example 2
![grid2](https://assets.leetcode.com/uploads/2019/11/05/e2.png)
**Input:** 
```text
grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
```
**Output:** 
```text
[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
```

### Example 3
**Input:** 
```text
grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
```
**Output:** 
```text
[[1,2,3],[4,5,6],[7,8,9]]
```

---

## 📐 Constraints

- $m == \text{grid.length}$
- $n == \text{grid[i].length}$
- $1 \le m \le 50$
- $1 \le n \le 50$
- $-1000 \le \text{grid[i][j]} \le 1000$
- $0 \le k \le 100$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $O(m \times n)$ |
| 💾 Auxiliary Space | $O(m \times n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../113_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../175_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
