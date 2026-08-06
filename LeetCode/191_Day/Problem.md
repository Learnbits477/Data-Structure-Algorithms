# [191. Smallest Divisible Digit Product I](https://leetcode.com/problems/smallest-divisible-digit-product-i/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-green?style=for-the-badge)
![Topics: Math, Enumeration](https://img.shields.io/badge/Topics-Math%20%7C%20Enumeration-blue?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given two integers `n` and `t`. Return the smallest number greater than or equal to `n` such that the product of its digits is divisible by `t`.

---

## 📌 Examples

**Example 1:**
- **Input:** `n = 10`, `t = 2`
- **Output:** `10`
- **Explanation:** The digit product of 10 is $1 \times 0 = 0$, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.

**Example 2:**
- **Input:** `n = 15`, `t = 3`
- **Output:** `16`
- **Explanation:** The digit product of 16 is $1 \times 6 = 6$, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.

---

## 📐 Constraints

- $1 \le n \le 100$
- $1 \le t \le 10$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(1)$ (since $n \le 100$ and we iterate at most 10 times) |
| **Auxiliary Space** | $O(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../190_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../192_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
