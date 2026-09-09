# 225. [Max Digit Sum Number in 1 to n](https://www.geeksforgeeks.org/problems/biggest-integer-having-maximum-digit-sum1704/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 25.24%](https://img.shields.io/badge/Accuracy-25.24%25-orange?style=for-the-badge)
![Submissions: 4K+](https://img.shields.io/badge/Submissions-4K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Mathematics%20%7C%20Numbers-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given a number `n`, find a number in the range from `1` to `n` such that its digit sum is maximum. If there are multiple such numbers, return the largest of them.

---

## 📌 Examples

**Example 1:**
```text
Input: n = 48
Output: 48
Explanation: There are two numbers with maximum digit sum = 12. The numbers are 48 (4 + 8 = 12) and 39 (3 + 9 = 12). Since 48 > 39, 48 is the answer.
```

**Example 2:**
```text
Input: n = 90
Output: 89
Explanation: 89 gives us the largest digit sum (8 + 9 = 17) in the range from 1 to 90. Hence the answer is 89.
```

---

## 📐 Constraints

- $1 \le n \le 10^9$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(m)$ where $m$ is the number of digits in $n$ |
| **Auxiliary Space** | $\mathcal{O}(m)$ where $m$ is the number of digits in $n$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../224_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../226_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
