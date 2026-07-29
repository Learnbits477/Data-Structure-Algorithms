# [3518. Smallest Palindromic Rearrangement II](https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/description/?envType=daily-question&envId=2026-07-18)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 23.4%](https://img.shields.io/badge/Acceptance-23.4%25-blue?style=for-the-badge)
![Submissions: 53.1K](https://img.shields.io/badge/Submissions-53.1K-purple?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Topics:-Hash_Table-blue?style=for-the-badge)
![Topic: Combinatorics](https://img.shields.io/badge/Combinatorics-orange?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Math-brightgreen?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/String-cyan?style=for-the-badge)
![Topic: Counting](https://img.shields.io/badge/Counting-violet?style=for-the-badge)

---

## 🧩 Problem Description

You are given a palindromic string `s` and an integer `k`.

Return the $k$-th lexicographically smallest palindromic permutation of `s`. If there are fewer than `k` distinct palindromic permutations, return an empty string `""`.

> **Note:** Different rearrangements that yield the same palindromic string are considered identical and are counted once.

---

## 📌 Examples

**Example 1:**
- **Input:** `s = "abba"`, `k = 2`
- **Output:** `"baab"`
- **Explanation:** 
  The two distinct palindromic rearrangements of `"abba"` are `"abba"` and `"baab"`.
  Lexicographically, `"abba"` comes before `"baab"`. Since $k = 2$, the output is `"baab"`.

**Example 2:**
- **Input:** `s = "aa"`, `k = 2`
- **Output:** `""`
- **Explanation:** 
  There is only one palindromic rearrangement: `"aa"`.
  The output is an empty string since $k = 2$ exceeds the number of possible rearrangements.

**Example 3:**
- **Input:** `s = "bacab"`, `k = 1`
- **Output:** `"abcba"`
- **Explanation:** 
  The two distinct palindromic rearrangements of `"bacab"` are `"abcba"` and `"bacab"`.
  Lexicographically, `"abcba"` comes before `"bacab"`. Since $k = 1$, the output is `"abcba"`.

---

## 📐 Constraints

- $1 \le s.length \le 10^4$
- `s` consists of lowercase English letters.
- `s` is guaranteed to be palindromic.
- $1 \le k \le 10^6$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(n)$ |

---

## 🏷️ Topic Tags

- Hash Table
- Math
- String
- Combinatorics
- Counting

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../182_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../184_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
