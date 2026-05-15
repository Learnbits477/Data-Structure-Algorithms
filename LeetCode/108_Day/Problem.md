# [153. Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 54.2%](https://img.shields.io/badge/Acceptance-54.2%25-blue?style=for-the-badge)
![Submissions: 5.6M](https://img.shields.io/badge/Submissions-5.6M-purple?style=for-the-badge)
![Topics: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topics: Binary Search](https://img.shields.io/badge/Topic-Binary%20Search-blue?style=for-the-badge)

---

## 🧩 Problem Description
Suppose an array of length $n$ sorted in ascending order is rotated between $1$ and $n$ times. For example, the array `nums = [0,1,2,4,5,6,7]` might become:
- `[4,5,6,7,0,1,2]` if it was rotated $4$ times.
- `[0,1,2,4,5,6,7]` if it was rotated $7$ times.

Notice that rotating an array `[a[0], a[1], a[2], ..., a[n-1]]` $1$ time results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array `nums` of **unique** elements, return *the minimum element of this array*.

You must write an algorithm that runs in $O(\log n)$ time.

---

## 📌 Examples
**Example 1:**
- **Input:** `nums = [3,4,5,1,2]`
- **Output:** `1`
- **Explanation:** The original array was `[1,2,3,4,5]` rotated 3 times.

**Example 2:**
- **Input:** `nums = [4,5,6,7,0,1,2]`
- **Output:** `0`
- **Explanation:** The original array was `[0,1,2,4,5,6,7]` and it was rotated 4 times.

**Example 3:**
- **Input:** `nums = [11,13,15,17]`
- **Output:** `11`
- **Explanation:** The original array was `[11,13,15,17]` and it was rotated 4 times.

---
## 📐 Constraints
- $$n == nums.length$$
- $$1 \le n \le 5000$$
- $$-5000 \le nums[i] \le 5000$$
- All the integers of `nums` are **unique**.
- `nums` is sorted and rotated between $1$ and $n$ times.

---

## ⏱️ Expected Complexities
| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $O(\log n)$ |
| **Space Complexity** | $O(1)$ |

---
## 🏷️ Topic Tags
- `Array`
- `Binary Search`

---

<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../107_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../109_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
