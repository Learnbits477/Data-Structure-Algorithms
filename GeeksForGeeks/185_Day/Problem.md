# [185. Game of Subsets](https://www.geeksforgeeks.org/problems/game-of-subsets/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 66.87%](https://img.shields.io/badge/Accuracy-66.87%25-blue?style=for-the-badge)
![Submissions: 21K+](https://img.shields.io/badge/Submissions-21K%2B-purple?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topics:-Dynamic_Programming-blue?style=for-the-badge)
![Topic: Bit Magic](https://img.shields.io/badge/Bit_Magic-orange?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an integer array `arr[]`, count the number of different subsets whose product can be represented as a product of one or more distinct prime numbers. Two subsets are considered different if the set of chosen array indices are not the same.

Return the count modulo $10^9 + 7$.

---

## 📌 Examples

**Example 1:**
- **Input:** `arr[] = [1, 2, 3, 4]`
- **Output:** `6`
- **Explanation:** 
  The subsets are:
  - `[2]`, product = $2 = 2$
  - `[3]`, product = $3 = 3$
  - `[1, 2]`, product = $2 = 2$
  - `[1, 3]`, product = $3 = 3$
  - `[2, 3]`, product = $6 = 2 \times 3$
  - `[1, 2, 3]`, product = $6 = 2 \times 3$
  
  All these products can be expressed as a product of one or more distinct prime numbers. Hence, the count is `6`.
  Note that `[4]` or any other subset with `4` are not chosen because products containing `4` have repeated prime factor $2$.

**Example 2:**
- **Input:** `arr[] = [2, 2, 3]`
- **Output:** `5`
- **Explanation:** 
  Since subsets formed using different indices are considered different, the chosen subsets are:
  - `[2]` (using the first `2`)
  - `[2]` (using the second `2`)
  - `[3]`
  - `[2, 3]` (using the first `2`)
  - `[2, 3]` (using the second `2`)
  
  Each subset has a product that can be expressed as a product of one or more distinct prime numbers. Therefore, the answer is `5`.

---

## 📐 Constraints

- $1 \le arr.size() \le 10^5$
- $1 \le arr[i] \le 30$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n \log n)$ |
| **Auxiliary Space** | $O(n)$ |

---

## 🏷️ Topic Tags

- Dynamic Programming
- Bit Magic
- Mathematics

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../184_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../186_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
