# [3336. Find the Number of Subsequences With Equal GCD](https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/description/?envType=daily-question&envId=2026-07-14)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 50.3%](https://img.shields.io/badge/Acceptance-50.3%25-blue?style=for-the-badge)
![Submissions: 40.1K](https://img.shields.io/badge/Submissions-40.1K-brightgreen?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-orange?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given an integer array `nums`.

Your task is to find the number of pairs of non-empty subsequences `(seq1, seq2)` of `nums` that satisfy the following conditions:

1. The subsequences `seq1` and `seq2` are **disjoint**, meaning no index of `nums` is common between them.
2. The **GCD** of the elements of `seq1` is equal to the **GCD** of the elements of `seq2`.

Return the total number of such pairs.

Since the answer may be very large, return it modulo $10^9 + 7$.

---

## 📌 Examples

### Example 1
**Input:**
```text
nums = [1, 2, 3, 4]
```
**Output:**
```text
10
```
**Explanation:**
The subsequence pairs which have the GCD of their elements equal to 1 are:
- `([1], [2])`, `([1], [3])`, `([1], [4])`
- `([2], [3])`, `([3], [4])`
- `([1, 2], [3])`, `([1, 3], [2])`, `([1, 4], [2, 3])`
- `([2, 4], [3])`, `([3, 4], [1, 2])` (and so on)
Total of 10 pairs.

### Example 2
**Input:**
```text
nums = [10, 20, 30]
```
**Output:**
```text
2
```
**Explanation:**
The subsequence pairs which have the GCD of their elements equal to 10 are:
- `([10], [20, 30])` (indices: `{0}` and `{1, 2}`)
- `([20, 30], [10])` (indices: `{1, 2}` and `{0}`)

### Example 3
**Input:**
```text
nums = [1, 1, 1, 1]
```
**Output:**
```text
50
```

---

## 📐 Constraints

- $$1 \le nums.length \le 200$$
- $$1 \le nums[i] \le 200$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n \cdot M^2)$$ where $$M = \max(nums[i])$$ |
| 💾 Auxiliary Space | $$O(n \cdot M^2)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-1ABC9C?style=for-the-badge)
![Math](https://img.shields.io/badge/Math-2ECC71?style=for-the-badge)
![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-3498DB?style=for-the-badge)
![Number Theory](https://img.shields.io/badge/Number%20Theory-9B59B6?style=for-the-badge)

</div>

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../167_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../169_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
