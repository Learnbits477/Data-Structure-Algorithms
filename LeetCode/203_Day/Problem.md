# 3471. [Find the Largest Almost Missing Integer](https://leetcode.com/problems/find-the-largest-almost-missing-integer/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 46.7%](https://img.shields.io/badge/Acceptance-46.7%25-brightgreen?style=for-the-badge)
![Submissions: 243.5K](https://img.shields.io/badge/Submissions-243.5K-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Array,_Hash_Table-blue?style=for-the-badge)

## 🧩 Problem Description
You are given an integer array `nums` and an integer `k`.

An integer `x` is **almost missing** from `nums` if `x` appears in exactly one subarray of size `k` within `nums`.

Return the **largest** almost missing integer from `nums`. If no such integer exists, return `-1`.

A **subarray** is a contiguous sequence of elements within an array.

## 📌 Examples

**Example 1:**
```text
Input: nums = [3,9,2,1,7], k = 3
Output: 7
Explanation:
1 appears in 2 subarrays of size 3: [9, 2, 1] and [2, 1, 7].
2 appears in 3 subarrays of size 3: [3, 9, 2], [9, 2, 1], [2, 1, 7].
3 appears in 1 subarray of size 3: [3, 9, 2].
7 appears in 1 subarray of size 3: [2, 1, 7].
9 appears in 2 subarrays of size 3: [3, 9, 2], and [9, 2, 1].
We return 7 since it is the largest integer that appears in exactly one subarray of size k.
```

**Example 2:**
```text
Input: nums = [3,9,7,2,1,7], k = 4
Output: 3
Explanation:
1 appears in 2 subarrays of size 4: [9, 7, 2, 1], [7, 2, 1, 7].
2 appears in 3 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1], [7, 2, 1, 7].
3 appears in 1 subarray of size 4: [3, 9, 7, 2].
7 appears in 3 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1], [7, 2, 1, 7].
9 appears in 2 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1].
We return 3 since it is the largest and only integer that appears in exactly one subarray of size k.
```

**Example 3:**
```text
Input: nums = [0,0], k = 1
Output: -1
Explanation:
There is no integer that appears in only one subarray of size 1.
```

## 📐 Constraints
- $1 \le \text{nums.length} \le 50$
- $0 \le \text{nums}[i] \le 50$
- $1 \le k \le \text{nums.length}$

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time** | $\mathcal{O}(n)$ |
| **Space** | $\mathcal{O}(n)$ |
---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../202_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../204_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
