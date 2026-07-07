# [3754. Concatenate Non-Zero Digits and Multiply by Sum I](https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 60.9%](https://img.shields.io/badge/Acceptance-60.9%25-blue?style=for-the-badge)
![Submissions: 108K](https://img.shields.io/badge/Submissions-108K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given an integer $n$.

Form a new integer $x$ by concatenating all the non-zero digits of $n$ in their original order. If there are no non-zero digits, $x = 0$.

Let $sum$ be the sum of digits in $x$.

Return an integer representing the value of $x \times sum$.

---

## 📌 Examples

### Example 1
**Input:**
```text
n = 10203004
```
**Output:**
```text
12340
```
**Explanation:**
- The non-zero digits are 1, 2, 3, and 4. Thus, $x = 1234$.
- The sum of digits is $sum = 1 + 2 + 3 + 4 = 10$.
- Therefore, the answer is $x \times sum = 1234 \times 10 = 12340$.

### Example 2
**Input:**
```text
n = 1000
```
**Output:**
```text
1
```
**Explanation:**
- The non-zero digit is 1, so $x = 1$ and $sum = 1$.
- Therefore, the answer is $x \times sum = 1 \times 1 = 1$.

---

## 📐 Constraints

- $$0 \le n \le 10^9$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(\log_{10} n)$$ |
| 💾 Auxiliary Space | $$O(1)$$ or $$O(\log_{10} n)$$ for string storage |

---

## 🏷️ Topic Tags

<div align="center">

![Math](https://img.shields.io/badge/Math-3498DB?style=for-the-badge)
![Simulation](https://img.shields.io/badge/Simulation-F39C12?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../160_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../162_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
