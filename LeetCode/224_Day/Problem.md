# 3870. [Count Commas in Range](https://leetcode.com/problems/count-commas-in-range/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 72.3%](https://img.shields.io/badge/Acceptance-72.3%25-green?style=for-the-badge)
![Submissions: 81.7K+](https://img.shields.io/badge/Submissions-81.7K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Math-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given an integer `n`.

Return the total number of commas used when writing all integers from $[1, n]$ (inclusive) in standard number formatting.

In standard formatting:
- A comma is inserted after every three digits from the right.
- Numbers with fewer than 4 digits contain no commas.

---

## 📌 Examples

**Example 1:**
```text
Input: n = 1002
Output: 3
Explanation: The numbers "1,000", "1,001", and "1,002" each contain one comma, giving a total of 3.
```

**Example 2:**
```text
Input: n = 998
Output: 0
Explanation: All numbers from 1 to 998 have fewer than four digits. Therefore, no commas are used.
```

---

## 📐 Constraints

- $1 \le n \le 10^5$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(1)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../223_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../225_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
