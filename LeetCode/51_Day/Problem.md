# [3212. Count Submatrices With Equal Frequency of X and Y](https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/?envType=daily-question&envId=2026-03-06)

**Difficulty:** Medium

## Problem Description

Given a 2D character matrix `grid`, where `grid[i][j]` is either `'X'`, `'Y'`, or `'.'`, return the number of submatrices that contain:

1. `grid[0][0]`
2. an equal frequency of `'X'` and `'Y'`.
3. at least one `'X'`.

## Examples

**Example 1:**

**Input:** `grid = [["X","Y","."],["Y",".","."]]`  
**Output:** `3`  
**Explanation:**  
The submatrices starting at `grid[0][0]` that meet the criteria are:
- `grid[0..0][0..1]` (contains one 'X' and one 'Y')
- `grid[0..1][0..1]` (contains one 'X' and one 'Y')
- `grid[0..1][0..2]` (contains one 'X' and one 'Y')

**Example 2:**

**Input:** `grid = [["X","X"],["X","Y"]]`  
**Output:** `0`  
**Explanation:**  
No submatrix has an equal frequency of `'X'` and `'Y'`.

**Example 3:**

**Input:** `grid = [[".","."],[".","."]]`  
**Output:** `0`  
**Explanation:**  
No submatrix has at least one `'X'`.

## Constraints

- `1 <= grid.length, grid[i].length <= 1000`
- `grid[i][j]` is either `'X'`, `'Y'`, or `'.'`.
