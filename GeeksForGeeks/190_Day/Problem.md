# [190. Subarrays with Sum in Range](https://www.geeksforgeeks.org/problems/count-the-number-of-subarrays/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 48.76%](https://img.shields.io/badge/Accuracy-48.76%25-blue?style=for-the-badge)
![Submissions: 17K+](https://img.shields.io/badge/Submissions-17K+-purple?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Arrays-brightgreen?style=for-the-badge)
![Topic: Sliding Window](https://img.shields.io/badge/Sliding_Window-blue?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an integer array `arr[]` and two integers `l` and `r`, find the number of contiguous subarrays whose sum lies in the range `[l, r]` (inclusive).

A subarray is a contiguous sequence of elements within the array.

---

## 📌 Examples

**Example 1:**
- **Input:** `l = 3`, `r = 8`, `arr[] = [1, 4, 6]`
- **Output:** `3`
- **Explanation:** The subarrays are `[1, 4]` (sum 5), `[4]` (sum 4), and `[6]` (sum 6). All these sums are within the range `[3, 8]`. Therefore, the answer is `3`.

**Example 2:**
- **Input:** `l = 4`, `r = 13`, `arr[] = [2, 3, 5, 8]`
- **Output:** `6`
- **Explanation:** The subarrays are `[2, 3]` (sum 5), `[2, 3, 5]` (sum 10), `[3, 5]` (sum 8), `[5]` (sum 5), `[5, 8]` (sum 13), and `[8]` (sum 8). Therefore, the answer is `6`.

---

## 📐 Constraints

- $1 \le arr.size() \le 10^5$
- $1 \le arr[i] \le 10^4$
- $1 \le l \le r \le 10^9$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../189_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../191_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
