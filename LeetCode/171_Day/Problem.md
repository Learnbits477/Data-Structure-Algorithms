# [3312. Sorted GCD Pair Queries](https://leetcode.com/problems/sorted-gcd-pair-queries/description/?envType=daily-question&envId=2026-07-07)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 33.6%](https://img.shields.io/badge/Acceptance-33.6%25-blue?style=for-the-badge)
![Submissions: 35K](https://img.shields.io/badge/Submissions-35K-brightgreen?style=for-the-badge)
![Topic: Number Theory](https://img.shields.io/badge/Topic-Number%20Theory-orange?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given an integer array `nums` of length `n` and an integer array `queries`.

Let `gcdPairs` denote an array obtained by calculating the GCD of all possible pairs `(nums[i], nums[j])`, where `0 <= i < j < n`, and then sorting these values in ascending order.

For each query `queries[i]`, you need to find the element at index `queries[i]` in `gcdPairs`.

Return an integer array `answer`, where `answer[i]` is the value at `gcdPairs[queries[i]]` for each query.

The term `gcd(a, b)` denotes the greatest common divisor of `a` and `b`.

---

## 📌 Examples

### Example 1
**Input:**
```text
nums = [2, 3, 4], queries = [0, 2, 2]
```
**Output:**
```text
[1, 2, 2]
```
**Explanation:**
- `gcdPairs = [gcd(2, 3), gcd(2, 4), gcd(3, 4)] = [1, 2, 1]`.
- After sorting in ascending order, `gcdPairs = [1, 1, 2]`.
- The answer at requested indices is `[gcdPairs[0], gcdPairs[2], gcdPairs[2]] = [1, 2, 2]`.

### Example 2
**Input:**
```text
nums = [4, 4, 2, 1], queries = [5, 3, 1, 0]
```
**Output:**
```text
[4, 2, 1, 1]
```
**Explanation:**
- `gcdPairs` sorted in ascending order is `[1, 1, 1, 2, 2, 4]`.
- For `queries = [5, 3, 1, 0]`, the answer is `[gcdPairs[5], gcdPairs[3], gcdPairs[1], gcdPairs[0]] = [4, 2, 1, 1]`.

### Example 3
**Input:**
```text
nums = [2, 2], queries = [0, 0]
```
**Output:**
```text
[2, 2]
```
**Explanation:**
- `gcdPairs = [2]`.
- The answer is `[gcdPairs[0], gcdPairs[0]] = [2, 2]`.

---

## 📐 Constraints

- $$2 \le n == nums.length \le 10^5$$
- $$1 \le nums[i] \le 5 \times 10^4$$
- $$1 \le queries.length \le 10^5$$
- $$0 \le queries[i] < \frac{n \times (n - 1)}{2}$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n + M \log M + q \log M)$$ where $$M = \max(nums)$$ |
| 💾 Auxiliary Space | $$O(M)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-1ABC9C?style=for-the-badge)
![Math](https://img.shields.io/badge/Math-2ECC71?style=for-the-badge)
![Number Theory](https://img.shields.io/badge/Number%20Theory-3498DB?style=for-the-badge)
![Binary Search](https://img.shields.io/badge/Binary%20Search-E74C3C?style=for-the-badge)
![Prefix Sum](https://img.shields.io/badge/Prefix%20Sum-9B59B6?style=for-the-badge)

</div>

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../170_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../172_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
