# [183. Split Array into Minimum Subsets](https://www.geeksforgeeks.org/problems/split-array-into-minimum-subsets/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 88.63%](https://img.shields.io/badge/Accuracy-88.63%25-blue?style=for-the-badge)
![Submissions: 2K+](https://img.shields.io/badge/Submissions-2K%2B-purple?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Topics:-Arrays-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-orange?style=for-the-badge)
![Topic: Hash](https://img.shields.io/badge/Hash-brightgreen?style=for-the-badge)

---

## 🧩 Problem Description

Given an array `arr[]` of distinct positive numbers. Split the array into the minimum number of subsets (or subsequences) such that each subset contains consecutive numbers.

---

## 📌 Examples

**Example 1:**
- **Input:** `arr[] = [100, 56, 5, 6, 102, 58, 101, 57, 7, 103, 59]`
- **Output:** `3`
- **Explanation:** 
  `[5, 6, 7]`, `[56, 57, 58, 59]`, and `[100, 101, 102, 103]` are $3$ subsequences/subsets in which numbers are consecutive.

**Example 2:**
- **Input:** `arr[] = [10, 100, 105]`
- **Output:** `3`
- **Explanation:** 
  `[10]`, `[100]`, and `[105]` are $3$ subsets in which numbers are consecutive.

---

## 📐 Constraints

- $1 \le arr.size() \le 10^5$
- $0 \le arr[i] \le 10^9$
- All elements in `arr[]` are distinct positive integers.

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../182_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../184_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
