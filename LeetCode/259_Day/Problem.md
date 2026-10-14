# [3727. Maximum Alternating Sum of Squares](https://leetcode.com/problems/maximum-alternating-sum-of-squares/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 75.8%](https://img.shields.io/badge/Acceptance-75.8%25-orange?style=for-the-badge)
![Submissions: 202.8K+](https://img.shields.io/badge/Submissions-202.8K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Squaring Invariance & Greedy Alternating Partition:**
> 1. **Index Parity Allocation**:
>    For any rearranged array of length $n$, the alternating sum formula assigns a positive sign ($+$) to $\lceil n / 2 \rceil$ elements situated at even indices ($0, 2, 4, \dots$) and a negative sign ($-$) to $\lfloor n / 2 \rfloor$ elements at odd indices ($1, 3, 5, \dots$).
> 2. **Non-Negativity of Squares**:
>    Because $x^2 \ge 0$ for all real integers $x$, every squared value is strictly non-negative. Initial negative numbers contribute identically to positive numbers with the same absolute value.
> 3. **Greedy Extremal Assignment**:
>    To maximize $(\sum \text{positive squares}) - (\sum \text{negative squares})$, we must greedily assign the $\lceil n / 2 \rceil$ largest squares to positive positions and the $\lfloor n / 2 \rfloor$ smallest squares to negative positions.

---

## 🧩 Problem Description

You are given an integer array `nums`. You may rearrange the elements in any order.

The alternating score of an array `arr` is defined as:

$$\text{score} = arr[0]^2 - arr[1]^2 + arr[2]^2 - arr[3]^2 + \dots$$

Return an integer denoting the maximum possible alternating score of `nums` after rearranging its elements.

---

## 📌 Examples

**Example 1:**

```text
Input: nums = [1,2,3]
Output: 12
Explanation:
A possible rearrangement for nums is [2,1,3], which gives the maximum alternating score among all possible rearrangements.
The alternating score is calculated as:
score = 2^2 - 1^2 + 3^2 = 4 - 1 + 9 = 12
```

**Example 2:**

```text
Input: nums = [1,-1,2,-2,3,-3]
Output: 16
Explanation:
A possible rearrangement for nums is [-3,-1,-2,1,3,2], which gives the maximum alternating score among all possible rearrangements.
The alternating score is calculated as:
score = (-3)^2 - (-1)^2 + (-2)^2 - (1)^2 + (3)^2 - (2)^2 = 9 - 1 + 4 - 1 + 9 - 4 = 16
```

---

## 📐 Constraints

- $1 \le nums.\text{length} \le 10^5$
- $-4 \times 10^4 \le nums[i] \le 4 \times 10^4$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \log n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

*Where $n$ is the length of `nums`. Sorting squares in-place requires $\mathcal{O}(n \log n)$ time and $\mathcal{O}(1)$ auxiliary space. An optimal Quickselect partition can achieve $\mathcal{O}(n)$ average time.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../258_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../260_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
