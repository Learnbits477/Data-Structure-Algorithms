# [2540. Minimum Common Value](https://leetcode.com/problems/minimum-common-value/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

--- 
## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 59.0%](https://img.shields.io/badge/Acceptance-59.0%25-blue?style=for-the-badge)
![Submissions: 585.8K](https://img.shields.io/badge/Submissions-585.8K-purple?style=for-the-badge)
![Topic: Two Pointers](https://img.shields.io/badge/Topic-Two%20Pointers-blue?style=for-the-badge)

---

## 🧩 Problem Description
Given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst `nums1` and `nums2`, return `-1`.

Note that an integer is said to be common to `nums1` and `nums2` if both arrays have at least one occurrence of that integer.

---

## 📌 Examples

**Example 1:**
- **Input:** `nums1 = [1,2,3]`, `nums2 = [2,4]`
- **Output:** `2`
- **Explanation:** The smallest element common to both arrays is `2`, so we return `2`.

**Example 2:**
- **Input:** `nums1 = [1,2,3,6]`, `nums2 = [2,3,4,5]`
- **Output:** `2`
- **Explanation:** There are two common elements in the array `2` and `3` out of which `2` is the smallest, so `2` is returned.

---

## 📐 Constraints
- $$1 \le \text{nums1.length}, \text{nums2.length} \le 10^5$$
- $$1 \le \text{nums1}[i], \text{nums2}[j] \le 10^9$$
- Both `nums1` and `nums2` are sorted in non-decreasing order.

---

## ⏱️ Expected Complexities
| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $$O(N + M)$$ |
| **Auxiliary Space** | $$O(1)$$ |

> Where $N$ is the size of `nums1` and $M$ is the size of `nums2`.

---

## 🏷️ Topic Tags
`Array`, `Two Pointers`, `Binary Search`, `Hash Table`

--- 

<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../111_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../113_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
