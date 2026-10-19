# [2089. Find Target Indices After Sorting Array](https://leetcode.com/problems/find-target-indices-after-sorting-array/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 80.9%](https://img.shields.io/badge/Acceptance-80.9%25-brightgreen?style=for-the-badge)
![Submissions: 462.9K+](https://img.shields.io/badge/Submissions-462.9K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Array-blue?style=for-the-badge)
![Topic: Binary Search](https://img.shields.io/badge/Binary%20Search-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Rank Counting Invariant (Solving Without Sorting):**
> 1. **Index Determination via Order Statistics**:
>    In any non-decreasingly sorted permutation of an array, the starting index of any element equal to `target` is determined entirely by the **number of elements strictly less than `target`** (`lessCount`).
> 2. **Contiguous Index Placement**:
>    All occurrences of `target` will cluster consecutively. If there are `targetCount` copies of `target`, their 0-indexed positions in the sorted array will span the contiguous range:
>    $$[\text{lessCount}, \text{lessCount} + \text{targetCount} - 1]$$
> 3. **Optimal $\mathcal{O}(n)$ Single-Pass Complexity**:
>    By simply counting elements smaller than and equal to `target` in a single linear scan, we bypass comparison sorting entirely, achieving optimal $\mathcal{O}(n)$ time and $\mathcal{O}(1)$ auxiliary space.

---

## 🧩 Problem Description

You are given a **0-indexed** integer array `nums` and a target element `target`.

A **target index** is an index $i$ such that `nums[i] == target`.

Return *a list of the target indices of `nums` after sorting `nums` in **non-decreasing** order*. If there are no target indices, return an **empty list**. The returned list must be sorted in **increasing** order.

---

## 📌 Examples

**Example 1:**

```text
Input: nums = [1, 2, 5, 2, 3], target = 2
Output: [1, 2]
Explanation:
After sorting, nums is [1, 2, 2, 3, 5].
The indices where nums[i] == 2 are 1 and 2.
```

**Example 2:**

```text
Input: nums = [1, 2, 5, 2, 3], target = 3
Output: [3]
Explanation:
After sorting, nums is [1, 2, 2, 3, 5].
The index where nums[i] == 3 is 3.
```

**Example 3:**

```text
Input: nums = [1, 2, 5, 2, 3], target = 5
Output: [4]
Explanation:
After sorting, nums is [1, 2, 2, 3, 5].
The index where nums[i] == 5 is 4.
```

---

## 📐 Constraints

- $1 \le nums.length \le 100$
- $1 \le nums[i], target \le 100$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

*By counting the frequencies of elements smaller than and equal to `target` in a single linear pass of `nums`, we construct the resulting index list in $\mathcal{O}(n)$ time without comparison-based sorting ($\mathcal{O}(n \log n)$).*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../264_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../266_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
