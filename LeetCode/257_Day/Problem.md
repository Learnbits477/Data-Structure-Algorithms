# [2778. Sum of Squares of Special Elements](https://leetcode.com/problems/sum-of-squares-of-special-elements/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 83.6%](https://img.shields.io/badge/Acceptance-83.6%25-orange?style=for-the-badge)
![Submissions: 153.6K+](https://img.shields.io/badge/Submissions-153.6K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topics:-Array-blue?style=for-the-badge)
![Topic: Enumeration](https://img.shields.io/badge/Enumeration-blue?style=for-the-badge)
![Topic: Simulation](https://img.shields.io/badge/Simulation-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Math-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Divisibility Invariant & Sum of Squares:**
> 1. **Index-Length Divisibility**:
>    Given a 1-indexed array of length $n$, an element at position $i \in [1, n]$ is *special* if and only if $n \pmod i == 0$.
> 2. **0-Indexed Translation**:
>    In standard 0-indexed languages like C++, element $nums[j]$ corresponds to 1-based index $i = j + 1$. Thus, the divisibility check becomes $n \pmod{j + 1} == 0$.
> 3. **Bounded Direct Accumulation**:
>    Since $n \le 50$ and $nums[i] \le 50$, the maximum sum of squares cannot exceed $50 \times 50^2 = 125{,}000$, fitting safely within a standard 32-bit signed integer. A single $\mathcal{O}(n)$ pass computes the answer directly.

---

## 🧩 Problem Description

You are given a **1-indexed** integer array `nums` of length `n`.

An element `nums[i]` of `nums` is called **special** if `i` divides `n`, i.e. `n % i == 0`.

Return the *sum of the squares of all special elements of* `nums`.

---

## 📌 Examples

**Example 1:**

```text
Input: nums = [1,2,3,4]
Output: 21
Explanation:
There are exactly 3 special elements in nums:
- nums[1] since 1 divides 4 (4 % 1 == 0)
- nums[2] since 2 divides 4 (4 % 2 == 0)
- nums[4] since 4 divides 4 (4 % 4 == 0)
Hence, the sum of the squares of all special elements is:
nums[1] * nums[1] + nums[2] * nums[2] + nums[4] * nums[4]
= 1 * 1 + 2 * 2 + 4 * 4
= 1 + 4 + 16 = 21.
```

**Example 2:**

```text
Input: nums = [2,7,1,19,18,3]
Output: 63
Explanation:
There are exactly 4 special elements in nums:
- nums[1] since 1 divides 6 (6 % 1 == 0)
- nums[2] since 2 divides 6 (6 % 2 == 0)
- nums[3] since 3 divides 6 (6 % 3 == 0)
- nums[6] since 6 divides 6 (6 % 6 == 0)
Hence, the sum of the squares of all special elements is:
nums[1] * nums[1] + nums[2] * nums[2] + nums[3] * nums[3] + nums[6] * nums[6]
= 2 * 2 + 7 * 7 + 1 * 1 + 3 * 3
= 4 + 49 + 1 + 9 = 63.
```

---

## 📐 Constraints

- $1 \le n == nums.\text{length} \le 50$
- $1 \le nums[i] \le 50$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

*Where $n$ is the length of `nums`. Checking the divisibility condition for each index requires a single linear scan in $\mathcal{O}(n)$ time and constant $\mathcal{O}(1)$ extra memory.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../256_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../258_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
