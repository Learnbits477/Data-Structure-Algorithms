# [2913. Subarrays Distinct Element Sum of Squares I](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 80.9%](https://img.shields.io/badge/Acceptance-80.9%25-orange?style=for-the-badge)
![Submissions: 65.8K+](https://img.shields.io/badge/Submissions-65.8K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Hash%20Table-blue?style=for-the-badge)
![Topic: Binary Indexed Tree](https://img.shields.io/badge/Binary%20Indexed%20Tree-blue?style=for-the-badge)
![Topic: Segment Tree](https://img.shields.io/badge/Segment%20Tree-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Incremental Distinct Tracking across Subarray Expansions:**
> 1. **Subarray Enumeration**:
>    Every contiguous subarray is uniquely determined by its starting index $i$ and ending index $j$, where $0 \le i \le j < n$. For $n \le 100$, there are at most $\frac{n(n + 1)}{2} \le 5050$ total subarrays.
> 2. **Incremental Distinct Counting**:
>    When fixing the starting boundary $i$ and expanding the right boundary $j$ from $i$ to $n - 1$, the distinct count non-decreases: each new element $nums[j]$ increases the count of distinct values if and only if it has not yet been encountered in $nums[i..j-1]$.
> 3. **Instant Quadratic Accumulation**:
>    Using a compact frequency table or boolean lookup table sized up to $\max(nums) \le 100$, each expansion step takes $\mathcal{O}(1)$ time. Accumulating $\text{distinct}^2$ directly into the running total yields an optimal $\mathcal{O}(n^2)$ solution.

---

## 🧩 Problem Description

You are given a **0-indexed** integer array `nums`.

The **distinct count** of a subarray of `nums` is defined as:
- Let `nums[i..j]` be a subarray of `nums` consisting of all the indices from `i` to `j` such that `0 <= i <= j < nums.length`. Then the number of distinct values in `nums[i..j]` is called the distinct count of `nums[i..j]`.

Return the *sum of the squares of distinct counts of all subarrays of* `nums`.

A **subarray** is a contiguous non-empty sequence of elements within an array.

---

## 📌 Examples

**Example 1:**

```text
Input: nums = [1, 2, 1]
Output: 15
Explanation:
Six possible subarrays are:
- [1]: 1 distinct value (score = 1^2 = 1)
- [2]: 1 distinct value (score = 1^2 = 1)
- [1]: 1 distinct value (score = 1^2 = 1)
- [1, 2]: 2 distinct values (score = 2^2 = 4)
- [2, 1]: 2 distinct values (score = 2^2 = 4)
- [1, 2, 1]: 2 distinct values (score = 2^2 = 4)
The sum of the squares of the distinct counts is 1 + 1 + 1 + 4 + 4 + 4 = 15.
```

**Example 2:**

```text
Input: nums = [1, 1]
Output: 3
Explanation:
Three possible subarrays are:
- [1]: 1 distinct value (score = 1^2 = 1)
- [1]: 1 distinct value (score = 1^2 = 1)
- [1, 1]: 1 distinct value (score = 1^2 = 1)
The sum of the squares of the distinct counts is 1 + 1 + 1 = 3.
```

---

## 📐 Constraints

- $1 \le nums.length \le 100$
- $1 \le nums[i] \le 100$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n^2)$ |
| **Auxiliary Space** | $\mathcal{O}(\max(nums))$ or $\mathcal{O}(n)$ |

*Enumerating all pairs $(i, j)$ with an incremental distinct count requires $\mathcal{O}(n^2)$ total operations. Space is bounded by the boolean presence buffer of size $101$.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../260_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../262_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
