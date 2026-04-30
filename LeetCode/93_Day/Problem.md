# [3742. Maximum Path Score in a Grid](https://leetcode.com/problems/maximum-path-score-in-a-grid/description/)

<div align="center">
  <img src="https://img.shields.io/badge/LeetCode-3742-FFA116?style=for-the-badge&logo=leetcode&logoColor=white" alt="LeetCode 3742">
  <img src="https://img.shields.io/badge/Difficulty-Medium-F9A825?style=for-the-badge" alt="Difficulty: Medium">
  <img src="https://img.shields.io/badge/Topic-Dynamic%20Programming-7B1FA2?style=for-the-badge" alt="DP">
  <img src="https://img.shields.io/badge/Daily-2026--04--30-1565C0?style=for-the-badge" alt="Daily 2026-04-30">
</div>

---

## 🧩 Problem Statement

You are given an `m × n` grid where each cell contains one of the values `0`, `1`, or `2`.  
You are also given an integer `k`.

You start from the **top-left corner** `(0, 0)` and want to reach the **bottom-right corner** `(m-1, n-1)` by moving only **right** or **down**.

Each cell contributes a specific **score** and incurs an associated **cost** based on its value:

| Cell Value | Score | Cost |
|:----------:|:-----:|:----:|
| `0` | +0 | 0 |
| `1` | +1 | 1 |
| `2` | +2 | 1 |

Return the **maximum score** achievable without exceeding a total cost of `k`, or `-1` if no valid path exists.

> **Note:** If you reach the last cell but the total cost **exceeds `k`**, the path is **invalid**.

---

## 📌 Examples

**Example 1:**
```
Input : grid = [[0, 1],
                [2, 0]], k = 1

Output: 2

Path:
  (0,0) → value 0 → score 0, cost 0  (total: score=0, cost=0)
  (1,0) → value 2 → score 2, cost 1  (total: score=2, cost=1)
  (1,1) → value 0 → score 0, cost 0  (total: score=2, cost=1) ✅

Maximum possible score = 2
```

**Example 2:**
```
Input : grid = [[0, 1],
                [1, 2]], k = 1

Path (0,0)→(0,1)→(1,1): cost = 0 + 1 + 1 = 2 > k ❌
Path (0,0)→(1,0)→(1,1): cost = 0 + 1 + 1 = 2 > k ❌

Output: -1  (no valid path exists)
```

---

## 🗺️ Grid Visualization (Example 1)

```
        col 0   col 1
row 0 [ 0(S) ] [ 1   ]
row 1 [ 2    ] [ 0(E) ]

S = Start (0,0)    E = End (1,1)

Optimal path: S → ↓ → →
  ┌───────┬───────┐
  │  0    │  1    │  ← row 0
  ├───────┼───────┤
  │  2 ★  │  0 ★  │  ← row 1   (★ = visited)
  └───────┴───────┘

Score gained: 2 (at cell (1,0)) + 0 (at cell (1,1)) = 2
Cost incurred: 1 (at cell (1,0)) + 0 (at cell (1,1)) = 1 ≤ k ✅
```

---

## 📐 Constraints

| Parameter    | Bound                  |
|:-------------|:-----------------------|
| `m`, `n`     | `1 ≤ m, n ≤ 200`       |
| `k`          | `0 ≤ k ≤ 10³`          |
| `grid[i][j]` | `0 ≤ grid[i][j] ≤ 2`   |
| Starting cell | `grid[0][0] == 0`     |

---

## 🔗 Related Files

| File | Description |
|:-----|:------------|
| [Approach.md](Approach.md) | DP algorithm with Mermaid diagram & dry run |
| [Solution.cpp](Solution.cpp) | Optimized O(m·n·k) C++ solution |
| [Main.cpp](Main.cpp) | Test driver with 5 sample test cases |
