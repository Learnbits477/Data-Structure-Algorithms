# [3525. Find X Value of Array II](https://leetcode.com/problems/find-x-value-of-array-ii/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 48.9%](https://img.shields.io/badge/Acceptance-48.9%25-orange?style=for-the-badge)
![Submissions: 20.4K+](https://img.shields.io/badge/Submissions-20.4K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topics:-Array-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Math-blue?style=for-the-badge)
![Topic: Segment Tree](https://img.shields.io/badge/Segment%20Tree-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given an array of positive integers `nums` and a positive integer `k`. You are also given a 2D array `queries`, where `queries[i] = [index_i, value_i, start_i, x_i]`.

You are allowed to perform an operation once on `nums`, where you can remove any suffix from `nums` such that `nums` remains non-empty.

The **x-value** of `nums` for a given $x$ is defined as the number of ways to perform this operation so that the product of the remaining elements leaves a remainder of $x$ modulo $k$.

For each query in `queries` you need to determine the **x-value** of `nums` for $x_i$ after performing the following actions:
1. Update `nums[index_i]` to `value_i`. **Only this step persists for the rest of the queries.**
2. Remove the prefix `nums[0..(start_i - 1)]` (where `nums[0..(-1)]` will be used to represent the empty prefix).

Return an array `result` of size `queries.length` where `result[i]` is the answer for the $i^{\text{th}}$ query.

- A **prefix** of an array is a subarray that starts from the beginning of the array and extends to any point within it.
- A **suffix** of an array is a subarray that starts at any point within the array and extends to the end of the array.
- Note that the prefix and suffix to be chosen for the operation can be empty.
- Note that **x-value** has a different definition in this version compared to version I.

---

## 📌 Examples

**Example 1:**

```text
Input: nums = [1, 2, 3, 4, 5], k = 3, queries = [[2, 2, 0, 2], [3, 3, 3, 0], [0, 1, 0, 1]]
Output: [2, 2, 2]
Explanation:
For query 0:
  - nums becomes [1, 2, 2, 4, 5], and the empty prefix is removed.
  - Active elements: [1, 2, 2, 4, 5].
  - Suffix removals yielding product % 3 == 2:
    * Remove suffix [2, 4, 5] -> leaves [1, 2], product = 2 == 2 mod 3.
    * Remove empty suffix -> leaves [1, 2, 2, 4, 5], product = 80 == 2 mod 3.
  - Total ways = 2.

For query 1:
  - nums becomes [1, 2, 2, 3, 5], and prefix [1, 2, 2] is removed.
  - Active elements: [3, 5].
  - Suffix removals yielding product % 3 == 0:
    * Remove empty suffix -> leaves [3, 5], product = 15 == 0 mod 3.
    * Remove suffix [5] -> leaves [3], product = 3 == 0 mod 3.
  - Total ways = 2.

For query 2:
  - nums becomes [1, 2, 2, 3, 5], and the empty prefix is removed.
  - Active elements: [1, 2, 2, 3, 5].
  - Suffix removals yielding product % 3 == 1:
    * Remove suffix [2, 2, 3, 5] -> leaves [1], product = 1 == 1 mod 3.
    * Remove suffix [3, 5] -> leaves [1, 2, 2], product = 4 == 1 mod 3.
  - Total ways = 2.
```

**Example 2:**

```text
Input: nums = [1, 2, 4, 8, 16, 32], k = 4, queries = [[0, 2, 0, 2], [0, 2, 0, 1]]
Output: [1, 0]
Explanation:
For query 0:
  - nums becomes [2, 2, 4, 8, 16, 32].
  - Only removing suffix [2, 4, 8, 16, 32] leaves [2] with product 2 == 2 mod 4.
  - Total ways = 1.

For query 1:
  - nums becomes [2, 2, 4, 8, 16, 32].
  - No suffix removal produces a remaining prefix whose product is 1 mod 4.
  - Total ways = 0.
```

**Example 3:**

```text
Input: nums = [1, 1, 2, 1, 1], k = 2, queries = [[2, 1, 0, 1]]
Output: [5]
Explanation:
nums becomes [1, 1, 1, 1, 1]. All 5 non-empty prefix products are 1, leaving remainder 1 mod 2.
```

---

## 📐 Constraints

- $1 \le \text{nums}[i] \le 10^9$
- $1 \le \text{nums.length} \le 10^5$
- $1 \le k \le 5$
- $1 \le \text{queries.length} \le 2 \times 10^4$
- $\text{queries}[i] = [\text{index}_i, \text{value}_i, \text{start}_i, x_i]$
- $0 \le \text{index}_i \le \text{nums.length} - 1$
- $1 \le \text{value}_i \le 10^9$
- $0 \le \text{start}_i \le \text{nums.length} - 1$
- $0 \le x_i \le k - 1$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(k \cdot (n + q \log n))$ |
| **Auxiliary Space** | $\mathcal{O}(n \cdot k)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../237_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../239_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
