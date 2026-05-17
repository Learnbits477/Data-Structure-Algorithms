# [1306. Jump Game III](https://leetcode.com/problems/jump-game-iii/description/?envType=daily-question&envId=2026-05-03)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

--- 
## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 67.0%](https://img.shields.io/badge/Acceptance-67.0%25-blue?style=for-the-badge)
![Submissions: 455K+](https://img.shields.io/badge/Submissions-455K+-purple?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Depth-First Search](https://img.shields.io/badge/Topic-Depth--First%20Search-blue?style=for-the-badge)
![Topic: Breadth-First Search](https://img.shields.io/badge/Topic-Breadth--First%20Search-blue?style=for-the-badge)

---

## 🧩 Problem Description
Given an array of non-negative integers `arr`, you are initially positioned at `start` index of the array. When you are at index `i`, you can jump to `i + arr[i]` or `i - arr[i]`, check if you can reach any index with value 0.

Notice that you cannot jump outside of the array at any time.

---

## 📌 Examples

**Example 1:**
- **Input:** `arr = [4,2,3,0,3,1,2]`, `start = 5`
- **Output:** `true`
- **Explanation:** 
  All possible ways to reach at index 3 with value 0 are: 
  - `index 5 -> index 4 -> index 1 -> index 3`
  - `index 5 -> index 6 -> index 4 -> index 1 -> index 3`

**Example 2:**
- **Input:** `arr = [4,2,3,0,3,1,2]`, `start = 0`
- **Output:** `true`
- **Explanation:** 
  One possible way to reach at index 3 with value 0 is:
  - `index 0 -> index 4 -> index 1 -> index 3`

**Example 3:**
- **Input:** `arr = [3,0,2,1,2]`, `start = 2`
- **Output:** `false`
- **Explanation:** 
  There is no way to reach at index 1 with value 0.

---

## 📐 Constraints
- $$1 \le \text{arr.length} \le 5 \times 10^4$$
- $$0 \le \text{arr}[i] < \text{arr.length}$$
- $$0 \le \text{start} < \text{arr.length}$$

---

## ⏱️ Expected Complexities
| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $$O(n)$$ |
| **Auxiliary Space** | $$O(n)$$ |

---

## 🏷️ Topic Tags
`Array`, `Depth-First Search`, `Breadth-First Search`

--- 

<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../109_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../111_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
