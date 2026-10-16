# [2916. Subarrays Distinct Element Sum of Squares II](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 29.8%](https://img.shields.io/badge/Acceptance-29.8%25-orange?style=for-the-badge)
![Submissions: 26.2K+](https://img.shields.io/badge/Submissions-26.2K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Hash%20Table-blue?style=for-the-badge)
![Topic: Binary Indexed Tree](https://img.shields.io/badge/Binary%20Indexed%20Tree-blue?style=for-the-badge)
![Topic: Segment Tree](https://img.shields.io/badge/Segment%20Tree-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Dynamic Segment Tree with Algebraic Range Squares:**
> 1. **Right-to-Left Incremental Extension**:
>    Let $d_i$ denote the number of distinct elements in subarray $nums[i..j]$ for a fixed right boundary $j$.
>    When advancing the right endpoint from $j - 1$ to $j$, if $nums[j]$ last appeared at index $last$, then $nums[j]$ is a newly discovered distinct value for all starting positions $i \in [last + 1, j]$.
>    Consequently, every $d_i$ in that interval increases by $+1$:
>    $$d_i \leftarrow d_i + 1, \quad \forall i \in [last + 1, j]$$
> 2. **Algebraic Expansion of Squared Sums**:
>    When adding $+1$ to a set of values $d_i$, each individual squared term transforms as:
>    $$(d_i + 1)^2 = d_i^2 + 2d_i + 1$$
>    Summing over a range $[L, R]$ of length $len = R - L + 1$:
>    $$\sum (d_i + 1)^2 = \sum d_i^2 + 2 \sum d_i + len$$
> 3. **Segment Tree with Lazy Propagation**:
>    By maintaining both the sum of linear terms ($\sum d_i$) and the sum of squared terms ($\sum d_i^2$) in each segment tree node, we can support $\mathcal{O}(\log n)$ range updates and immediate $\mathcal{O}(1)$ prefix aggregation at each step.

---

## 🧩 Problem Description

You are given a **0-indexed** integer array `nums`.

The **distinct count** of a subarray of `nums` is defined as:
- Let `nums[i..j]` be a subarray of `nums` consisting of all the indices from `i` to `j` such that `0 <= i <= j < nums.length`. Then the number of distinct values in `nums[i..j]` is called the distinct count of `nums[i..j]`.

Return the **sum of the squares of distinct counts of all subarrays** of `nums`.

Since the answer may be very large, return it **modulo** $10^9 + 7$.

A **subarray** is a contiguous non-empty sequence of elements within an array.

---

## 📌 Examples

**Example 1:**

```text
Input: nums = [1, 2, 1]
Output: 15
Explanation:
Six possible subarrays are:
- [1]: 1 distinct value (1^2 = 1)
- [2]: 1 distinct value (1^2 = 1)
- [1]: 1 distinct value (1^2 = 1)
- [1, 2]: 2 distinct values (2^2 = 4)
- [2, 1]: 2 distinct values (2^2 = 4)
- [1, 2, 1]: 2 distinct values (2^2 = 4)
The sum of the squares of the distinct counts is 1 + 1 + 1 + 4 + 4 + 4 = 15.
```

**Example 2:**

```text
Input: nums = [2, 2]
Output: 3
Explanation:
Three possible subarrays are:
- [2]: 1 distinct value (1^2 = 1)
- [2]: 1 distinct value (1^2 = 1)
- [2, 2]: 1 distinct value (1^2 = 1)
The sum of the squares of the distinct counts is 1 + 1 + 1 = 3.
```

---

## 📐 Constraints

- $1 \le nums.length \le 10^5$
- $1 \le nums[i] \le 10^5$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \log n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

*Each of the $n$ elements triggers at most one range update of interval size up to $n$ in the Segment Tree. A tree of size $4n$ maintains $\sum d_i$ and $\sum d_i^2$ with lazy propagation in $\mathcal{O}(\log n)$ time per step.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../261_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../263_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
