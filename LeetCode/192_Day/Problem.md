# [192. Smallest Divisible Digit Product II](https://leetcode.com/problems/smallest-divisible-digit-product-ii/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Topics: Math, String, Backtracking, Greedy, Number Theory](https://img.shields.io/badge/Topics-Math%20%7C%20String%20%7C%20Greedy%20%7C%20Number%20Theory-blue?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given a string `num` which represents a positive integer, and an integer `t`.

A number is called **zero-free** if none of its digits are `0`.

Return a string representing the smallest zero-free number greater than or equal to `num` such that the product of its digits is divisible by `t`. If no such number exists, return `"-1"`.

---

## 📌 Examples

**Example 1:**
- **Input:** `num = "1234"`, `t = 256`
- **Output:** `"1488"`
- **Explanation:** The smallest zero-free number that is greater than or equal to 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.

**Example 2:**
- **Input:** `num = "12355"`, `t = 50`
- **Output:** `"12355"`
- **Explanation:** 12355 is already zero-free and has the product of its digits divisible by 50, with the product of its digits equal to 150.

**Example 3:**
- **Input:** `num = "11111"`, `t = 26`
- **Output:** `"-1"`
- **Explanation:** No number greater than or equal to 11111 has the product of its digits divisible by 26 because 26 has a prime factor 13, which cannot be formed by single-digit products.

---

## 📐 Constraints

- $2 \le \text{num.length} \le 2 \times 10^5$
- `num` consists only of digits in the range `['0', '9']`.
- `num` does not contain leading zeros.
- $1 \le t \le 10^{14}$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(\text{num.length} + \log(t))$ |
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
