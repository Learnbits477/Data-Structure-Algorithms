# 217. [Count Palindromic Strings with Constraints](https://www.geeksforgeeks.org/problems/number-of-palindromic-strings2706/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 34.38%](https://img.shields.io/badge/Accuracy-34.38%25-green?style=for-the-badge)
![Submissions: 5K+](https://img.shields.io/badge/Submissions-5K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Strings%20%7C%20Combinatorics-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given two integers `n` and `k`, consider an alphabet consisting of the first `k` lowercase English letters. Find the number of palindromic strings whose length is less than or equal to `n`, such that:
1. Every character in the string belongs to the given alphabet.
2. No character appears more than twice in the string.

> **Note:** Since the answer can be very large, return it modulo $10^9 + 7$.

---

## 📌 Examples

**Example 1:**
```text
Input: n = 3, k = 2
Output: 6
Explanation: The possible strings are:
- Length 1: "a", "b"
- Length 2: "aa", "bb"
- Length 3: "aba", "bab"
Total valid palindromic strings = 2 + 2 + 2 = 6.
```

**Example 2:**
```text
Input: n = 4, k = 3
Output: 18
Explanation: The possible strings are:
- Length 1: "a", "b", "c" (3 strings)
- Length 2: "aa", "bb", "cc" (3 strings)
- Length 3: "aba", "aca", "bab", "bcb", "cac", "cbc" (6 strings)
- Length 4: "abba", "acca", "baab", "bccb", "caac", "cbbc" (6 strings)
Total valid palindromic strings = 3 + 3 + 6 + 6 = 18.
```

---

## 📐 Constraints

- $1 \le k \le 26$
- $1 \le n \le 52$
- $n \le 2 \times k$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(k^2)$ or $\mathcal{O}(n + k)$ |
| **Auxiliary Space** | $\mathcal{O}(k)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../216_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../218_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
