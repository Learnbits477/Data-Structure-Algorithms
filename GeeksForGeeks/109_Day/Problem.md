# [109. Not a subset sum](https://www.geeksforgeeks.org/problems/smallest-number-subset1220/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

--- 
## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 45.92%](https://img.shields.io/badge/Accuracy-45.92%25-blue?style=for-the-badge)
![Submissions: 84K+](https://img.shields.io/badge/Submissions-84K+-purple?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)

---

## 🧩 Problem Description
Given a array `arr[]` of positive integers, find the smallest positive integer such that it cannot be represented as the sum of elements of any subset of the given array set.

## 📌 Examples
**Example 1:**
- **Input:** `arr[] = [3, 1, 2]`
- **Output:** `7`
- **Explanation:** 
  - Subsets of `[1, 2, 3]` and their sums:
    - `[]` -> 0
    - `[1]` -> 1
    - `[2]` -> 2
    - `[1, 2]` -> 3
    - `[3]` -> 3
    - `[1, 3]` -> 4
    - `[2, 3]` -> 5
    - `[1, 2, 3]` -> 6
  - Smallest positive integer not present is 7.

**Example 2:**
- **Input:** `arr[] = [3, 10, 9, 6, 20, 28]`
- **Output:** `1`
- **Explanation:** 1 is the smallest positive number for which no subset is there with sum 1.

--- 

## 📐 Constraints
- $$1 \le \text{arr.size()} \le 10^5$$
- $$1 \le \text{arr}[i] \le 10^3$$

---

## ⏱️ Expected Complexities
| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $$O(n \log n)$$ |
| **Auxiliary Space** | $$O(1)$$ |

---

## 🏷️ Topic Tags
`Array`, `Greedy`, `Sorting`

--- 

<div align="center">
<h3>Happy Coding! 🚀</h2>
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
