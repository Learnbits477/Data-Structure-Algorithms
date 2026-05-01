# [396. Rotate Function](https://leetcode.com/problems/rotate-function/description/?envType=daily-question&envId=2026-03-30)

<div align="center">
  <img src="https://img.shields.io/badge/LeetCode-396-FFA116?style=for-the-badge&logo=leetcode&logoColor=white" alt="LeetCode 396">
  <img src="https://img.shields.io/badge/Difficulty-Medium-F9A825?style=for-the-badge" alt="Difficulty: Medium">
  <img src="https://img.shields.io/badge/Topic-Math%20%7C%20Array-7B1FA2?style=for-the-badge" alt="Math Array">
  <img src="https://img.shields.io/badge/Daily-2026--03--30-1565C0?style=for-the-badge" alt="Daily 2026-03-30">
</div>

---

## 🧩 Problem Statement

You are given an integer array `nums` of length `n`.

Assume `arrk` to be an array obtained by rotating `nums` by `k` positions **clock-wise**.  
We define the rotation function `F` on `nums` as:

```
F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n-1) * arrk[n-1]
```

Return the **maximum value** of `F(0), F(1), ..., F(n-1)`.

> The test cases are generated so that the answer fits in a **32-bit integer**.

---

## 📌 Examples

**Example 1:**
```
Input : nums = [4, 3, 2, 6]
Output: 26

F(0) = (0×4) + (1×3) + (2×2) + (3×6) = 0  +  3  +  4 + 18 = 25
F(1) = (0×6) + (1×4) + (2×3) + (3×2) = 0  +  4  +  6 +  6 = 16
F(2) = (0×2) + (1×6) + (2×4) + (3×3) = 0  +  6  +  8 +  9 = 23
F(3) = (0×3) + (1×2) + (2×6) + (3×4) = 0  +  2  + 12 + 12 = 26  ← MAX

Answer: max(25, 16, 23, 26) = 26
```

**Example 2:**
```
Input : nums = [100]
Output: 0

F(0) = 0 × 100 = 0
```

---

## 🔄 What is a Clockwise Rotation?

```
Original : [4, 3, 2, 6]

k=1  →  rotate right by 1  →  [6, 4, 3, 2]
         (last element moves to front)

k=2  →  rotate right by 2  →  [2, 6, 4, 3]

k=3  →  rotate right by 3  →  [3, 2, 6, 4]
```

---

## 📐 Constraints

| Parameter  | Bound                    |
|:-----------|:-------------------------|
| `n`        | `1 ≤ n ≤ 10⁵`            |
| `nums[i]`  | `-100 ≤ nums[i] ≤ 100`   |
| Answer     | Fits in a 32-bit integer |

---

## 🔗 Related Files

| File | Description |
|:-----|:------------|
| [Approach.md](Approach.md) | Mathematical derivation, recurrence & Mermaid diagram |
| [Solution.cpp](Solution.cpp) | Optimized O(N) C++ solution |
| [Main.cpp](Main.cpp) | Test driver with 5 sample test cases |
