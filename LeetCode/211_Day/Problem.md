# 2904. [Shortest and Lexicographically Smallest Beautiful String](https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 52.1%](https://img.shields.io/badge/Acceptance-52.1%25-green?style=for-the-badge)
![Submissions: 142K](https://img.shields.io/badge/Submissions-142K-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-String-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Sliding%20Window-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given a binary string `s` and a positive integer `k`.

A substring of `s` is **beautiful** if the number of `1`'s in it is exactly `k`.

Let `len` be the length of the **shortest** beautiful substring.

Return the **lexicographically smallest** beautiful substring of string `s` with length equal to `len`. If `s` doesn't contain a beautiful substring, return an empty string `""`.

> A string `a` is **lexicographically larger** than a string `b` (of the same length) if in the first position where `a` and `b` differ, `a` has a character strictly larger than the corresponding character in `b`.

---

## 📌 Examples

**Example 1:**
```text
Input: s = "100011001", k = 3
Output: "11001"
Explanation: 
There are multiple beautiful substrings containing exactly 3 ones:
- "100011" (length 6)
- "00011001" (length 8)
- "0011001" (length 7)
- "011001" (length 6)
- "11001" (length 5)
The shortest length is 5, and the lexicographically smallest is "11001".
```

**Example 2:**
```text
Input: s = "1011", k = 2
Output: "11"
Explanation: 
The beautiful substrings containing exactly 2 ones are:
- "101" (length 3)
- "011" (length 3)
- "11" (length 2)
The shortest length is 2, and the lexicographically smallest is "11".
```

**Example 3:**
```text
Input: s = "000", k = 1
Output: ""
Explanation: There are no beautiful substrings in this example.
```

---

## 📐 Constraints
- $1 \le \text{s.length} \le 100$
- $1 \le k \le \text{s.length}$
- `s[i]` is either `'0'` or `'1'`.

---

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n^2)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../210_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../212_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
