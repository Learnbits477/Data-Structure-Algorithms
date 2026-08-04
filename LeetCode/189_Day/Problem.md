# [3731. Find Missing Elements](https://leetcode.com/problems/find-missing-elements/description/)

---

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 83.9%](https://img.shields.io/badge/Acceptance-83.9%25-blue?style=for-the-badge)
![Hash Table](https://img.shields.io/badge/Topic-Hash%20Table-blue?style=for-the-badge)
![Array](https://img.shields.io/badge/Array-brightgreen?style=for-the-badge)

---

## 🧩 Problem Description
You are given an integer array `nums` consisting of unique integers.

Originally, `nums` contained every integer within a certain range. However, some integers might have gone missing from the array.

The smallest and largest integers of the original range are still present in `nums`.

Return a sorted list of all the missing integers in this range. If no integers are missing, return an empty list.

---

## 📌 Examples

**Example 1:**
- **Input:** `nums = [1,4,2,5]`
- **Output:** `[3]`
- **Explanation:** The smallest integer is 1 and the largest is 5, so the full range should be `[1,2,3,4,5]`. Among these, only 3 is missing.

**Example 2:**
- **Input:** `nums = [7,8,6,9]`
- **Output:** `[]`
- **Explanation:** The smallest integer is 6 and the largest is 9, so the full range is `[6,7,8,9]`. All integers are already present, so no integer is missing.

**Example 3:**
- **Input:** `nums = [5,1]`
- **Output:** `[2,3,4]`
- **Explanation:** The smallest integer is 1 and the largest is 5, so the full range should be `[1,2,3,4,5]`. The missing integers are 2, 3, and 4.

---

## 📐 Constraints
- $2 \le nums.length \le 100$
- $1 \le nums[i] \le 100$
- All elements in `nums` are unique.

---

## ⏱️ Expected Complexities
| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $O(N + (max\_val - min\_val))$ |
| **Auxiliary Space** | $O(N)$ or $O(1)$ lookup storage |

---

## 🏷️ Topic Tags
`Array`, `Hash Table`, `Sorting`

--- 

<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../188_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../190_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
