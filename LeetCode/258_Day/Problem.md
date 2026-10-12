# [2897. Apply Operations on Array to Maximize Sum of Squares](https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 49.2%](https://img.shields.io/badge/Acceptance-49.2%25-orange?style=for-the-badge)
![Submissions: 24.2K+](https://img.shields.io/badge/Submissions-24.2K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)
![Topic: Bit Manipulation](https://img.shields.io/badge/Bit%20Manipulation-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Math-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Bit Conservation & Majorization Convexity:**
> 1. **Column-wise Bit Conservation**:
>    The operation updates $(nums[i], nums[j]) \to (nums[i] \text{ AND } nums[j], nums[i] \text{ OR } nums[j])$. For every individual bit position $b \in [0, 30]$, if one number has bit $b$ set and the other does not, the set bit is transferred directly to the OR operand. Thus, the total number of set bits at position $b$ across the entire array is invariant.
> 2. **Convexity of Squares ($f(t) = t^2$)**:
>    Because $(x \text{ AND } y) + (x \text{ OR } y) = x + y$ and $(x \text{ AND } y)^2 + (x \text{ OR } y)^2 \ge x^2 + y^2$, concentrating set bits into as few numbers as possible strictly maximizes the sum of their squares.
> 3. **Greedy Top-$k$ Reconstruction**:
>    By repeatedly applying the operation, we can sort each bit column independently. The largest possible number will capture as many available set bits as possible; the second largest will take the remaining bits, and so on. To maximize the sum of $k$ squares, we greedily build the $k$ largest elements directly from the bit frequency counts.

---

## 🧩 Problem Description

You are given a **0-indexed** integer array `nums` and a positive integer `k`.

You can do the following operation on the array **any number of times**:
- Choose any two distinct indices `i` and `j` and simultaneously update the values of `nums[i]` to `(nums[i] AND nums[j])` and `nums[j]` to `(nums[i] OR nums[j])`. Here, `OR` denotes the bitwise OR operation, and `AND` denotes the bitwise AND operation.

You have to choose `k` elements from the final array and calculate the sum of their squares.

Return the *maximum sum of squares you can achieve*.

Since the answer can be very large, return it **modulo** $10^9 + 7$.

---

## 📌 Examples

**Example 1:**

```text
Input: nums = [2,6,5,8], k = 2
Output: 261
Explanation:
We can perform the following operations:
- Choose i = 0 and j = 3: nums[0] = (2 AND 8) = 0, nums[3] = (2 OR 8) = 10. Resulting nums = [0, 6, 5, 10].
- Choose i = 2 and j = 3: nums[2] = (5 AND 10) = 0, nums[3] = (5 OR 10) = 15. Resulting nums = [0, 6, 0, 15].
We choose elements 15 and 6 from the final array.
The sum of squares is 15^2 + 6^2 = 225 + 36 = 261.
It can be shown that this is the maximum value obtainable.
```

**Example 2:**

```text
Input: nums = [4,5,4,7], k = 3
Output: 90
Explanation:
We do not need to apply any operations.
We can choose elements 7, 5, and 4 with sum of squares:
7^2 + 5^2 + 4^2 = 49 + 25 + 16 = 90.
It can be shown that this is the maximum value obtainable.
```

---

## 📐 Constraints

- $1 \le k \le nums.\text{length} \le 10^5$
- $1 \le nums[i] \le 10^9$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \log(\max(nums)))$ |
| **Auxiliary Space** | $\mathcal{O}(\log(\max(nums))) \approx \mathcal{O}(1)$ |

*Where $n$ is the length of `nums`. Since $nums[i] \le 10^9 < 2^{30}$, we only need to inspect $30$ bit positions, taking $\mathcal{O}(30n) \approx \mathcal{O}(n)$ time and $\mathcal{O}(30) = \mathcal{O}(1)$ auxiliary memory.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../257_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../259_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
