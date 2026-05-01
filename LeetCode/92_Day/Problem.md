# [3225. Maximum Score From Grid Operations](https://leetcode.com/problems/maximum-score-from-grid-operations/description/)

<div align="center">
  <img src="https://img.shields.io/badge/LeetCode-3225-FFA116?style=for-the-badge&logo=leetcode&logoColor=white" alt="LeetCode 3225">
  <img src="https://img.shields.io/badge/Difficulty-Hard-E53935?style=for-the-badge" alt="Difficulty: Hard">
  <img src="https://img.shields.io/badge/Topic-Dynamic%20Programming-7B1FA2?style=for-the-badge" alt="DP">
  <img src="https://img.shields.io/badge/Topic-Prefix%20Sum-1565C0?style=for-the-badge" alt="Prefix Sum">
  <img src="https://img.shields.io/badge/Daily-2026--04--29-1565C0?style=for-the-badge" alt="Daily 2026-04-29">
</div>

---

## 🧩 Problem Statement

You are given a **2D matrix** `grid` of size `n × n`.  
Initially, all cells are **white**.

In one operation you can select any cell `(i, j)` and color **black** all cells in column `j` **from row 0 down to row i** (inclusive).

> The **grid score** is the sum of `grid[i][j]` for every **white** cell `(i, j)` that has **at least one horizontally adjacent black cell**.

Return the **maximum score** achievable after any number of operations.

---

## 📌 Examples

**Example 1:**
```
Input : grid = [[0,0,0,0,0],
                [0,0,3,0,0],
                [0,1,0,0,0],
                [5,0,0,3,0],
                [0,0,0,0,2]]
Output: 11
Explanation: Color column 1 down to row 3, column 4 down to row 4.
             Score = grid[3][0] + grid[1][2] + grid[3][3] = 5 + 3 + 3 = 11.
```

**Example 2:**
```
Input : grid = [[10,9, 0, 0,15],
                [ 7,1, 0, 8, 0],
                [ 5,20,0,11, 0],
                [ 0,0, 0, 1, 2],
                [ 8,12,1,10, 3]]
Output: 94
Explanation: Operate on columns 1,2,3 down to rows 1,4,0.
             Score = 10+7+5+20+12+8+11+1+10+... = 94.
```

---

## 📐 Constraints

| Parameter      | Bound                     |
|:---------------|:--------------------------|
| `n`            | `1 ≤ n ≤ 100`             |
| Grid size      | `n × n`                   |
| `grid[i][j]`   | `0 ≤ grid[i][j] ≤ 10⁹`   |

---

## 🔗 Related Files

| File | Description |
|:-----|:------------|
| [Approach.md](Approach.md) | DP algorithm with Mermaid diagram |
| [Solution.cpp](Solution.cpp) | Optimized O(n³) C++ solution |
| [Main.cpp](Main.cpp) | Test driver with sample cases |
