# 940. [Distinct Subsequences II](https://leetcode.com/problems/distinct-subsequences-ii/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 46.2%](https://img.shields.io/badge/Acceptance-46.2%25-green?style=for-the-badge)
![Submissions: 132K+](https://img.shields.io/badge/Submissions-132K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-String%20%7C%20Dynamic%20Programming-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given a string `s`, return the number of **distinct non-empty subsequences** of `s`. Since the answer may be very large, return it **modulo** $10^9 + 7$.

A **subsequence** of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters (i.e., `"ace"` is a subsequence of `"abcde"` while `"aec"` is not).

---

## 📌 Examples

**Example 1:**
```text
Input: s = "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
```

**Example 2:**
```text
Input: s = "aba"
Output: 6
Explanation: The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba".
```

**Example 3:**
```text
Input: s = "aaa"
Output: 3
Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
```

---

## 📐 Constraints

- $1 \le s.\text{length} \le 2000$
- `s` consists of lowercase English letters.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../222_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../224_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
