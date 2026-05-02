# [788. Rotated Digits](https://leetcode.com/problems/rotated-digits/)

<div align="center">
  <img src="https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=black" alt="Platform">
  <img src="https://img.shields.io/badge/Difficulty-Medium-F9A825?style=for-the-badge" alt="Difficulty: Medium">
  <img src="https://img.shields.io/badge/Topics-Math-blue?style=for-the-badge" alt="Topics: Math">
  <img src="https://img.shields.io/badge/Daily%20Question-2026--05--02-00838F?style=for-the-badge" alt="Daily Question">
</div>

---

## 🧩 Problem Statement

An integer `x` is **good** if after rotating each digit individually by 180 degrees, we get a valid number that is **different from x**. Each digit must be rotated — we cannot choose to leave it alone.

A number is **valid** if each digit remains a digit after rotation:
- `0`, `1`, and `8` rotate to themselves.
- `2` and `5` rotate to each other.
- `6` and `9` rotate to each other.
- The rest of the numbers (`3`, `4`, `7`) do **not** rotate to any other number and become invalid.

Given an integer `n`, return the **number of good integers** in the range `[1, n]`.

---

## 📌 Examples

**Example 1:**
```text
Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10]: 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
```

**Example 2:**
```text
Input: n = 1
Output: 0
```

**Example 3:**
```text
Input: n = 2
Output: 1
```

---

## 📐 Constraints

| Parameter | Bound                |
|:----------|:---------------------|
| `n`       | `1 ≤ n ≤ 10^4`       |

---

## 🔗 Related Files

| File | Description |
|:-----|:------------|
| [Approach.md](Approach.md) | Digit analysis & rotation logic |
| [Solution.cpp](Solution.cpp) | Optimized O(N log N) C++ solution |
| [Main.cpp](Main.cpp) | Test driver with sample test cases |
