# [154. Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 45.0%](https://img.shields.io/badge/Acceptance-45.0%25-blue?style=for-the-badge)
![Submissions: 1.4M](https://img.shields.io/badge/Submissions-1.4M-purple?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Binary Search](https://img.shields.io/badge/Topic-Binary%20Search-blue?style=for-the-badge)

---

## 🧩 Problem Description
Suppose an array of length `n` sorted in ascending order is rotated between `1` and `n` times. For example, the array `nums = [0,1,4,4,5,6,7]` might become:
- `[4,5,6,7,0,1,4]` if it was rotated 4 times.
- `[0,1,4,4,5,6,7]` if it was rotated 7 times.

Notice that rotating an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array `nums` that **may contain duplicates**, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.

---

## 📌 Examples
**Example 1:**
- **Input:** `nums = [1,3,5]`
- **Output:** `1`

**Example 2:**
- **Input:** `nums = [2,2,2,0,1]`
- **Output:** `0`

---

## 📐 Constraints
- $$n == \text{nums.length}$$
- $$1 \le n \le 5000$$
- $$-5000 \le \text{nums}[i] \le 5000$$
- `nums` is sorted and rotated between `1` and `n` times.

---

## ⏱️ Expected Complexities
| Complexity | Average | Worst Case |
| :--- | :--- | :--- |
| **Time Complexity** | $$O(\log n)$$ | $$O(n)$$ |
| **Auxiliary Space** | $$O(1)$$ | $$O(1)$$ |

---

## 🏷️ Topic Tags
`Array`, `Binary Search`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../108_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../110_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
