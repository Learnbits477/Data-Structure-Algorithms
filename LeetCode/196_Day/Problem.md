# 196. [Smallest Missing Integer Greater Than Sequential Prefix Sum](https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 39.6%](https://img.shields.io/badge/Acceptance-39.6%25-blue?style=for-the-badge)
![Submissions: 180K](https://img.shields.io/badge/Submissions-180K-purple?style=for-the-badge)
![Topic: Array & Hash Table](https://img.shields.io/badge/Topic-Array%20%26%20Hash%20Table-brightgreen?style=for-the-badge)
![Company: Amazon, Google, Meta](https://img.shields.io/badge/Company-Amazon%2C%20Google%2C%20Meta-blue?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given a 0-indexed array of integers `nums`.

A prefix `nums[0..i]` is sequential if, for all `1 <= j <= i`, `nums[j] = nums[j - 1] + 1`. In particular, the prefix consisting only of `nums[0]` is sequential.

Return the smallest integer `x` missing from `nums` such that `x` is greater than or equal to the sum of the longest sequential prefix.

---

## 📌 Examples

**Example 1:**
- **Input:** `nums = [1,2,3,2,5]`
- **Output:** `6`
- **Explanation:** The longest sequential prefix of `nums` is `[1,2,3]` with a sum of 6. 6 is not in the array, therefore 6 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.

**Example 2:**
- **Input:** `nums = [3,4,5,1,12,14,13]`
- **Output:** `15`
- **Explanation:** The longest sequential prefix of `nums` is `[3,4,5]` with a sum of 12. 12, 13, and 14 belong to the array while 15 does not. Therefore 15 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.

---

## 📐 Constraints

- $1 \le nums.length \le 50$
- $1 \le nums[i] \le 50$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../195_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../197_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
