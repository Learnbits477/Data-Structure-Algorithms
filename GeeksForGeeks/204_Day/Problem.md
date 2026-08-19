# 204. [Triplets with Sum in Range](https://www.geeksforgeeks.org/problems/triplets-with-sum-with-given-range/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 30.77%](https://img.shields.io/badge/Acceptance-30.77%25-green?style=for-the-badge)
![Submissions: 19K+](https://img.shields.io/badge/Submissions-19K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Sorting-blue?style=for-the-badge)
![Company](https://img.shields.io/badge/Company-Microsoft-black?style=for-the-badge)

## 🧩 Problem Description

Given an array `arr[]` and a range `[l, r]`, the task is to count the number of triplets `(i, j, k)` with `i < j < k` having a sum in the range `[l, r]`, i.e., $l \le arr[i] + arr[j] + arr[k] \le r$.

## 📌 Examples

**Example 1:**
```text
Input: arr = [8, 3, 5, 2], l = 7, r = 11
Output: 1
Explanation: There is only one triplet [2, 3, 5] having sum 10 in range [7, 11].
```

**Example 2:**
```text
Input: arr = [5, 1, 4, 3, 2], l = 2, r = 7
Output: 2
Explanation: There are two triplets having sum in range: [1, 4, 2] (sum 7) and [1, 3, 2] (sum 6).
```

## 📐 Constraints
- $1 \le \text{arr.size()} \le 10^3$
- $1 \le \text{arr}[i] \le 10^3$
- $1 \le l \le r \le 10^9$

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time** | $\mathcal{O}(n^2)$ |
| **Space** | $\mathcal{O}(1)$ |
---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../203_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../205_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
