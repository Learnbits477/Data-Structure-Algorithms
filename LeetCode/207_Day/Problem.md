# 3622. [Check Divisibility by Digit Sum and Product](https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-green?style=for-the-badge)
![Acceptance: 73.0%](https://img.shields.io/badge/Acceptance-73.0%25-green?style=for-the-badge)
![Submissions: 137.5K](https://img.shields.io/badge/Submissions-137.5K-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Math-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Number_Theory-blue?style=for-the-badge)

## 🧩 Problem Description

You are given a positive integer `n`. Determine whether `n` is divisible by the sum of the following two values:
1. The **digit sum** of `n` (the sum of its digits).
2. The **digit product** of `n` (the product of its digits).

Return `true` if `n` is divisible by this combined sum; otherwise, return `false`.

## 📌 Examples

### Example 1:
```text
Input: n = 99
Output: true
Explanation: 
- Digit Sum = 9 + 9 = 18
- Digit Product = 9 * 9 = 81
- Combined Sum = 18 + 81 = 99
Since 99 is divisible by 99 (99 % 99 == 0), the output is true.
```

### Example 2:
```text
Input: n = 23
Output: false
Explanation: 
- Digit Sum = 2 + 3 = 5
- Digit Product = 2 * 3 = 6
- Combined Sum = 5 + 6 = 11
Since 23 is not divisible by 11 (23 % 11 != 0), the output is false.
```

## 📐 Constraints
- $1 \le n \le 10^6$

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time** | $\mathcal{O}(\log_{10} n)$ |
| **Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../206_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../208_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
