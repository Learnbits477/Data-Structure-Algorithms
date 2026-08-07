# [192. Friends Pairing Problem](https://www.geeksforgeeks.org/problems/friends-pairing-problem5425/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 25.04%](https://img.shields.io/badge/Accuracy-25.04%25-blue?style=for-the-badge)
![Submissions: 135K+](https://img.shields.io/badge/Submissions-135K+-purple?style=for-the-badge)
![Topic: Modular Arithmetic Recursion](https://img.shields.io/badge/Topic-DP%20%26%20Recursion-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given `n` friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

---

## 📌 Examples

**Example 1:**
- **Input:** `n = 3`
- **Output:** `4`
- **Explanation:** 
  - `{1}, {2}, {3}` : All single
  - `{1}, {2,3}` : 2 and 3 paired but 1 is single.
  - `{1,2}, {3}` : 1 and 2 are paired but 3 is single.
  - `{1,3}, {2}` : 1 and 3 are paired but 2 is single.
  - Note that `{1,2}` and `{2,1}` are considered same.

**Example 2:**
- **Input:** `n = 2`
- **Output:** `2`
- **Explanation:**
  - `{1}, {2}` : All single.
  - `{1,2}` : 1 and 2 are paired.

**Example 3:**
- **Input:** `n = 1`
- **Output:** `1`

---

## 📐 Constraints

- $1 \le n \le 18$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../191_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../193_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
