# [149. N-Digit Numbers with Increasing Digits](https://www.geeksforgeeks.org/problems/n-digit-numbers-with-digits-in-increasing-order5903/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 49.66%](https://img.shields.io/badge/Accuracy-49.66%25-green?style=for-the-badge)
![Submissions: 27K+](https://img.shields.io/badge/Submissions-27K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an integer $n$, return all the $n$-digit numbers in increasing order, such that their digits are in strictly increasing order (from left to right).

Single-digit numbers ($n = 1$) are considered to be in strictly increasing order.

---

## 📌 Examples

### Example 1
**Input:**
```text
n = 1
```
**Output:**
```text
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
```
**Explanation:**
Single-digit numbers are considered to be in strictly increasing order.

### Example 2
**Input:**
```text
n = 2
```
**Output:**
```text
[12, 13, 14, 15, 16, 17, 18, 19, 23, 24, 25, 26, 27, 28, 29, 34, 35, 36, 37, 38, 39, 45, 46, 47, 48, 49, 56, 57, 58, 59, 67, 68, 69, 78, 79, 89]
```
**Explanation:**
For $n = 2$, the digits must be strictly increasing. Hence, numbers like $12, 13, \dots, 89$ are returned. Values like $11$ or $21$ are invalid.

### Example 3
**Input:**
```text
n = 15
```
**Output:**
```text
[]
```
**Explanation:**
No such number can exist because we have only $9$ non-zero digits ($1$ to $9$). To maintain strictly increasing digits without leading zeros, any number of length $n > 9$ is impossible.

---

## 📐 Constraints

- $$1 \le n \le 10^5$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n \times \binom{9}{n})$$ |
| 💾 Auxiliary Space | $$O(n)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Recursion](https://img.shields.io/badge/Recursion-007ACC?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)
![Backtracking](https://img.shields.io/badge/Backtracking-FF5722?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../148_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../150_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
