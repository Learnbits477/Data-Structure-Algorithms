# [Find Position of Set Bit](https://www.geeksforgeeks.org/problems/find-position-of-set-bit3706/1)

<div align="center">
  <img src="https://img.shields.io/badge/Platform-GeeksForGeeks-2F8D46?style=for-the-badge&logo=geeksforgeeks&logoColor=white" alt="Platform">
  <img src="https://img.shields.io/badge/Difficulty-Basic-success?style=for-the-badge" alt="Difficulty: Basic">
  <img src="https://img.shields.io/badge/Accuracy-49.62%25-E53935?style=for-the-badge" alt="Accuracy: 49.62%">
  <img src="https://img.shields.io/badge/Submissions-82K%2B-1565C0?style=for-the-badge" alt="Submissions: 82K+">
  <img src="https://img.shields.io/badge/Points-1-6A1B9A?style=for-the-badge" alt="Points: 1">
</div>

---

## 🧩 Problem Statement

Given an integer `n`, determine the **position of the only set bit (1)** in its binary representation. The position is counted starting from **1 at the least significant bit (LSB)**.

- If `n` contains **exactly one** set bit, return its position.
- If `n` contains **no set bits** or **more than one** set bit, return **`-1`**.

---

## 📌 Examples

**Example 1:**
```text
Input: n = 2
Output: 2
Explanation: 2 is represented as "10" in binary. It has only one set bit, which is at position 2.
```

**Example 2:**
```text
Input: n = 5
Output: -1
Explanation: 5 is represented as "101" in binary. It has two set bits; therefore, the output is -1.
```

**Example 3:**
```text
Input: n = 1
Output: 1
Explanation: 1 is represented as "1" in binary. It has one set bit at position 1.
```

---

## 📐 Constraints

| Parameter | Bound                |
|:----------|:---------------------|
| `n`       | `0 ≤ n ≤ 10^8`        |

---

## 🔗 Related Files

| File | Description |
|:-----|:------------|
| [Approach.md](Approach.md) | Bit manipulation logic & visualization |
| [Solution.cpp](Solution.cpp) | Optimized O(1) Bitwise solution |
| [Main.cpp](Main.cpp) | Test driver with sample test cases |
