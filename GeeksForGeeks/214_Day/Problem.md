# 214. [Count Subsequences Divisible by n](https://www.geeksforgeeks.org/problems/number-of-subsequences-in-a-string-divisible-by-n5947/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 47.51%](https://img.shields.io/badge/Acceptance-47.51%25-green?style=for-the-badge)
![Submissions: 10K+](https://img.shields.io/badge/Submissions-10K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Dynamic%20Programming-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given a numeric string `s` containing only digits and an integer `n`, count the number of non-empty subsequences of `s` whose numeric value is divisible by `n`. 

Return the answer modulo $10^9 + 7$.

---

## 📌 Examples

**Example 1:**
```text
Input: s = "1234", n = 4
Output: 4
Explanation: The subsequences 4, 12, 24 and 124 are divisible by 4.
```

**Example 2:**
```text
Input: s = "330", n = 6
Output: 4
Explanation: The subsequences 30, 30, 330 and 0 are divisible by 6.
```

---

## 📐 Constraints

- $1 \le |s| \times n \le 10^6$
- String `s` contains only digits (`'0'` – `'9'`).
- $1 \le n \le 10^6$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(|s| \times n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../213_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../215_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
