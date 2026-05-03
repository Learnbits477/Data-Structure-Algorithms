# [796. Rotate String](https://leetcode.com/problems/rotate-string/)

<div align="center">
  <img src="https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=black" alt="Platform">
  <img src="https://img.shields.io/badge/Difficulty-Easy-00B01C?style=for-the-badge" alt="Difficulty: Easy">
  <img src="https://img.shields.io/badge/Topics-String-blue?style=for-the-badge" alt="Topics: String">
  <img src="https://img.shields.io/badge/Daily%20Question-2026--05--03-00838F?style=for-the-badge" alt="Daily Question">
</div>

---

## 🧩 Problem Statement

Given two strings `s` and `goal`, return `true` if and only if `s` can become `goal` after some number of shifts on `s`.

A **shift** on `s` consists of moving the leftmost character of `s` to the rightmost position.

- For example, if `s = "abcde"`, then it will be `"bcdea"` after one shift.

---

## 📌 Examples

**Example 1:**
```text
Input: s = "abcde", goal = "cdeab"
Output: true
Explanation: 
- Shift 1: "bcdea"
- Shift 2: "cdeab" (Match found!)
```

**Example 2:**
```text
Input: s = "abcde", goal = "abced"
Output: false
```

---

## 📐 Constraints

| Parameter | Bound |
| :--- | :--- |
| `s.length, goal.length` | `1 ≤ length ≤ 100` |
| `Characters` | Lowercase English letters |

---

## 🔗 Related Files

| File | Description |
| :--- | :--- |
| [Approach.md](Approach.md) | String concatenation logic & complexity |
| [Solution.cpp](Solution.cpp) | Optimized C++ solution |
| [Main.cpp](Main.cpp) | Test driver with sample test cases |
