# [187. Sequences where Adjacent Divide](https://www.geeksforgeeks.org/problems/count-in-array2138/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 57.69%](https://img.shields.io/badge/Accuracy-57.69%25-blue?style=for-the-badge)
![Submissions: 2K+](https://img.shields.io/badge/Submissions-2K+-purple?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topics:-Dynamic_Programming-blue?style=for-the-badge)
![Topic: Modular Arithmetic](https://img.shields.io/badge/Modular_Arithmetic-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given two positive integers `n` and `m`. Find the number of arrays of size `n` that can be formed such that:

1. Each element is in the range `[1, m]`.
2. All adjacent elements are such that one of them divides the other, i.e., element $A_i$ divides $A_{i+1}$ or $A_{i+1}$ divides $A_i$.

---

## 📌 Examples

**Example 1:**
- **Input:** `n = 3`, `m = 3`
- **Output:** `17`
- **Explanation:** 
  The possible arrays are:
  `[1, 1, 1]`, `[1, 1, 2]`, `[1, 1, 3]`, `[1, 2, 1]`, `[1, 2, 2]`, `[1, 3, 1]`, `[1, 3, 3]`, `[2, 1, 1]`, `[2, 1, 2]`, `[2, 1, 3]`, `[2, 2, 1]`, `[2, 2, 2]`, `[3, 1, 1]`, `[3, 1, 2]`, `[3, 1, 3]`, `[3, 3, 1]`, and `[3, 3, 3]`.

**Example 2:**
- **Input:** `n = 1`, `m = 10`
- **Output:** `10`
- **Explanation:** 
  The possible arrays are:
  `[1]`, `[2]`, `[3]`, `[4]`, `[5]`, `[6]`, `[7]`, `[8]`, `[9]`, and `[10]`.

---

## 📐 Constraints

- $1 \le n \le 11$
- $1 \le m \le 11$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n \cdot m \cdot \log m)$ |
| **Auxiliary Space** | $O(n \cdot m)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../186_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../188_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
