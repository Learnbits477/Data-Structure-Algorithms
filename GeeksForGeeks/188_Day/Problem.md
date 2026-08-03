# [188. Max Sum Subarray of Size at least K](https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 37.64%](https://img.shields.io/badge/Accuracy-37.64%25-blue?style=for-the-badge)
![Submissions: 63K+](https://img.shields.io/badge/Submissions-63K+-purple?style=for-the-badge)
![Topic: Sliding Window](https://img.shields.io/badge/Topics:-Sliding_Window-blue?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Arrays-brightgreen?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic_Programming-purple?style=for-the-badge)
![Companies: Facebook | Paytm | Myntra](https://img.shields.io/badge/Companies:-Facebook%20%7C%20Paytm%20%7C%20Myntra-orange?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an array `arr[]` and an integer `k`, find the maximum sum among all contiguous subarrays having a length greater than or equal to `k`.

---

## 📌 Examples

**Example 1:**
- **Input:** `arr[] = [1, -2, 2, -3]`, `k = 3`
- **Output:** `1`
- **Explanation:** The sub-array of length at least 3 that produces greatest sum is `[1, -2, 2]` with sum `1`.

**Example 2:**
- **Input:** `arr[] = [1, 1, 1, 1, 1, 1]`, `k = 2`
- **Output:** `6`
- **Explanation:** The sub-array of length at least 2 that produces greatest sum is `[1, 1, 1, 1, 1, 1]` with sum `6`.

**Example 3:**
- **Input:** `arr[] = [-4, -2, 1, -3]`, `k = 2`
- **Output:** `-1`
- **Explanation:** The sub-array of length at least 2 that produces greatest sum is `[-2, 1]` with sum `-1`.

---

## 📐 Constraints

- $1 \le arr.size() \le 10^5$
- $-10^4 \le arr[i] \le 10^4$
- $1 \le k \le arr.size()$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../187_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../189_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
