# [1345. Jump Game IV](https://leetcode.com/problems/jump-game-iv/description/?envType=daily-question&envId=2026-05-03)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

--- 
## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 49.5%](https://img.shields.io/badge/Acceptance-49.5%25-blue?style=for-the-badge)
![Submissions: 424K](https://img.shields.io/badge/Submissions-424K-purple?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Topic-Hash--Table-blue?style=for-the-badge)
![Topic: Breadth-First Search](https://img.shields.io/badge/Topic-Breadth--First%20Search-blue?style=for-the-badge)

---

## 🧩 Problem Description
Given an array of integers `arr`, you are initially positioned at the first index of the array.

In one step you can jump from index `i` to index:
- `i + 1` where: `i + 1 < arr.length`.
- `i - 1` where: `i - 1 >= 0`.
- `j` where: `arr[i] == arr[j]` and `i != j`.

Return the *minimum number of steps* to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

---

## 📌 Examples

**Example 1:**
- **Input:** `arr = [100,-23,-23,404,100,23,23,23,3,404]`
- **Output:** `3`
- **Explanation:** You need three jumps from index `0 --> 4 --> 3 --> 9`. Note that index 9 is the last index of the array.

**Example 2:**
- **Input:** `arr = [7]`
- **Output:** `0`
- **Explanation:** Start index is the last index. You do not need to jump.

**Example 3:**
- **Input:** `arr = [7,6,9,6,9,6,9,7]`
- **Output:** `1`
- **Explanation:** You can jump directly from index 0 to index 7 which is last index of the array.

---

## 📐 Constraints
- $$1 \le \text{arr.length} \le 5 \times 10^4$$
- $$-10^8 \le \text{arr}[i] \le 10^8$$

---

## ⏱️ Expected Complexities
| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $$O(n)$$ |
| **Auxiliary Space** | $$O(n)$$ |

---

## 🏷️ Topic Tags
`Array`, `Hash Table`, `Breadth-First Search`

--- 

<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../110_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../112_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
