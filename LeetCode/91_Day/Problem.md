# [2033. Minimum Operations to Make a Uni-Value Grid](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/?envType=daily-question&envId=2026-03-30)

<div align="center">
  <img src="https://img.shields.io/badge/LeetCode-2033-orange?style=for-the-badge&logo=leetcode" alt="LeetCode 2033">
  <img src="https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge" alt="Medium">
  <img src="https://img.shields.io/badge/Topic-Sorting%20%7C%20Math-blue?style=for-the-badge" alt="Topics">
</div>

---

## Problem Statement

You are given a **2D integer grid** of size `m x n` and an integer `x`. In one operation, you can **add** `x` to or **subtract** `x` from any element in the grid.

A **uni-value grid** is a grid where all the elements of it are **equal**.

Return the **minimum number of operations** to make the grid uni-value. If it is **not possible**, return `-1`.

---

## Examples

**Example 1:**

![Example 1](https://assets.leetcode.com/uploads/2021/09/21/gridtxt.png)

```
Input:  grid = [[2,4],[6,8]], x = 2
Output: 4
Explanation: We can make every element equal to 4 by doing the following:
  - Add x to 2 once.
  - Subtract x from 6 once.
  - Subtract x from 8 twice.
A total of 4 operations were used.
```

**Example 2:**

```
Input:  grid = [[1,5],[2,3]], x = 1
Output: 5
Explanation: We can make every element equal to 3.
```

**Example 3:**

```
Input:  grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.
```

---

## Constraints

| Parameter         | Range                     |
|-------------------|---------------------------|
| `m`               | `m == grid.length`        |
| `n`               | `n == grid[i].length`     |
| Grid dimensions   | `1 ≤ m, n ≤ 10⁵`         |
| Total cells       | `1 ≤ m * n ≤ 10⁵`        |
| Values            | `1 ≤ x, grid[i][j] ≤ 10⁴`|

---

## Related Files

- [Approach & Explanation](Approach.md)
- [C++ Solution](Solution.cpp)
- [Test Driver](Main.cpp)
