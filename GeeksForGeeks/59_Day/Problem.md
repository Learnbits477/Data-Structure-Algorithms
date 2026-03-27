# [Chocolates Pickup](https://www.geeksforgeeks.org/problems/chocolates-pickup/1)

## Problem Statement

You are given a 2D matrix `grid[][]` of size `n*m`, where each cell `grid[i][j]` represents the number of chocolates available at position `(i, j)`.

Two robots are collecting chocolates from this grid:
- **Robot 1** starts at the top-left corner `(0, 0)`
- **Robot 2** starts at the top-right corner `(0, m - 1)`

Your task is to determine the maximum total number of chocolates both robots can collect while following these rules:
1. From a cell `(i, j)`, robots can move to cell `(i + 1, j - 1)`, `(i + 1, j)`, or `(i + 1, j + 1)`.
2. When a robot visits a cell, it collects all the chocolates there.
3. If both robots land on the same cell, the chocolates in that cell are collected only once.
4. Robots cannot move outside the boundaries of the grid.
5. Both robots must continue moving until they reach the bottom row of the grid.

### Example
**Input:** `grid[][] = [[4, 1, 2], [3, 6, 1], [1, 6, 6], [3, 1, 2]]`  
**Output:** `32`  
**Explanation:** 
- Robot 1 path: `(0, 0) -> (1, 0) -> (2, 1) -> (3, 0)`, chocolates: `4 + 3 + 6 + 3 = 16`.
- Robot 2 path: `(0, 2) -> (1, 1) -> (2, 2) -> (3, 2)`, chocolates: `2 + 6 + 6 + 2 = 16`.
- Total: `16 + 16 = 32`.

### Constraints
- `2 ≤ n, m ≤ 70`
- `0 ≤ grid[i][j] ≤ 100`
