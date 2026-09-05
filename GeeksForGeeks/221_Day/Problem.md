# 221. [Longest Subsequence with Adjacent Diff as 1](https://www.geeksforgeeks.org/problems/longest-sub-sequence-such-that-difference-between-adjacents-is-one2558/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 29.43%](https://img.shields.io/badge/Accuracy-29.43%25-orange?style=for-the-badge)
![Submissions: 58K+](https://img.shields.io/badge/Submissions-58K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Company](https://img.shields.io/badge/Company-Flipkart-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Arrays%20%7C%20Dynamic%20Programming-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an array `arr[]` with `n` elements. Find the length of the longest subsequence such that the absolute difference between adjacent elements in the subsequence is one.

A **subsequence** is a sequence derived from the array by deleting some or no elements without changing the order of the remaining elements.

---

## 📌 Examples

**Example 1:**
```text
Input: arr[] = [10, 9, 4, 5, 4, 8, 6]
Output: 3
Explanation: 
Longest subsequences with difference 1 are:
- [10, 9, 8]
- [4, 5, 4]
- [4, 5, 6]
Each has a length of 3.
```

**Example 2:**
```text
Input: arr[] = [1, 2, 3, 2, 3, 7, 2, 1]
Output: 7
Explanation: 
Longest subsequence with difference 1 is [1, 2, 3, 2, 3, 2, 1].
The absolute difference between every pair of consecutive elements is 1.
The length of this subsequence is 7.
```

---

## 📐 Constraints

- $1 \le \text{arr.size()} \le 10^6$
- $1 \le \text{arr}[i] \le 10^6$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../220_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../222_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
