# [1464. Maximum Product of Two Elements in an Array](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/?envType=daily-question&envId=2026-07-22)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 84.0%](https://img.shields.io/badge/Acceptance-84.0%25-blue?style=for-the-badge)
![Submissions: 644.8K](https://img.shields.io/badge/Submissions-644.8K-purple?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-blueviolet?style=for-the-badge)
![Topic: Heap](https://img.shields.io/badge/Heap-brightgreen?style=for-the-badge)

---

## 🧩 Problem Description

Given the array of integers `nums`, you will choose two different indices `i` and `j` of that array. Return the maximum value of `(nums[i]-1)*(nums[j]-1)`.

---

## 📌 Examples

**Example 1:**
- **Input:** `nums` = `[3, 4, 5, 2]`
- **Output:** `12`
- **Explanation:** If you choose the indices `i=1` and `j=2` (indexed from 0), you will get the maximum value, that is, `(nums[1]-1)*(nums[2]-1)` = `(4-1)*(5-1)` = `3*4` = `12`.

**Example 2:**
- **Input:** `nums` = `[1, 5, 4, 5]`
- **Output:** `16`
- **Explanation:** Choosing the indices `i=1` and `j=3` (indexed from 0), you will get the maximum value of `(5-1)*(5-1)` = `16`.

**Example 3:**
- **Input:** `nums` = `[3, 7]`
- **Output:** `12`
- **Explanation:** Choosing the indices `i=0` and `j=1` (indexed from 0), you will get `(3-1)*(7-1)` = `2*6` = `12`.

---

## 📐 Constraints

- $2 \le \text{nums.length} \le 500$
- $1 \le \text{nums}[i] \le 10^3$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(1)$ |

---

## 🏷️ Topic Tags

- Array
- Sorting
- Heap (Priority Queue)

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../180_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../182_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
