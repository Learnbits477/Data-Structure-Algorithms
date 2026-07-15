# [3658. GCD of Odd and Even Sums](https://leetcode.com/problems/gcd-of-odd-and-even-sums/?envType=daily-question&envId=2026-07-12)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 85.7%](https://img.shields.io/badge/Acceptance-85.7%25-blue?style=for-the-badge)
![Submissions: 126.8K](https://img.shields.io/badge/Submissions-126.8K-brightgreen?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Topic-Math-orange?style=for-the-badge)
![Topic: Number Theory](https://img.shields.io/badge/Topic-Number%20Theory-purple?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given an integer `n`. Your task is to compute the GCD (greatest common divisor) of two values:

- `sumOdd`: the sum of the smallest `n` positive odd numbers.
- `sumEven`: the sum of the smallest `n` positive even numbers.

Return the GCD of `sumOdd` and `sumEven`.

---

## 📌 Examples

### Example 1
**Input:**
```text
n = 4
```
**Output:**
```text
4
```
**Explanation:**
- Sum of the first 4 odd numbers `sumOdd = 1 + 3 + 5 + 7 = 16`
- Sum of the first 4 even numbers `sumEven = 2 + 4 + 6 + 8 = 20`
- Hence, $\text{GCD}(sumOdd, sumEven) = \text{GCD}(16, 20) = 4$.

### Example 2
**Input:**
```text
n = 5
```
**Output:**
```text
5
```
**Explanation:**
- Sum of the first 5 odd numbers `sumOdd = 1 + 3 + 5 + 7 + 9 = 25`
- Sum of the first 5 even numbers `sumEven = 2 + 4 + 6 + 8 + 10 = 30`
- Hence, $\text{GCD}(sumOdd, sumEven) = \text{GCD}(25, 30) = 5$.

---

## 📐 Constraints

- $$1 \le n \le 1000$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(1)$$ |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Math](https://img.shields.io/badge/Math-2ECC71?style=for-the-badge)
![Number Theory](https://img.shields.io/badge/Number%20Theory-9B59B6?style=for-the-badge)

</div>

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../168_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../170_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
