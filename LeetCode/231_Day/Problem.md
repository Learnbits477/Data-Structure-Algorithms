# [2472. Maximum Number of Non-overlapping Palindrome Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 47.5%](https://img.shields.io/badge/Acceptance-47.5%25-orange?style=for-the-badge)
![Submissions: 66.9K+](https://img.shields.io/badge/Submissions-66.9K%2B-blue?style=for-the-badge)
![Topic: Two Pointers](https://img.shields.io/badge/Topic-Two%20Pointers-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/String-blue?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given a string `s` and a positive integer `k`.

Select a set of **non-overlapping substrings** from the string `s` that satisfy the following conditions:
- The length of each substring is **at least `k`**.
- Each substring is a **palindrome**.

Return the **maximum number of substrings** in an optimal selection.

A **substring** is a contiguous sequence of characters within a string.

---

## 📌 Examples

**Example 1:**

```text
Input: s = "abaccdbbd", k = 3
Output: 2
Explanation:
We can select the substrings "aba" and "dbbd".
Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
It can be shown that we cannot find a selection with more than two valid substrings.
```

**Example 2:**

```text
Input: s = "adbcda", k = 2
Output: 0
Explanation:
There is no palindrome substring of length at least 2 in the string.
```

---

## 📐 Constraints

- $1 \le k \le s.\text{length} \le 2000$
- `s` consists of lowercase English letters.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \cdot k)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../230_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../232_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
