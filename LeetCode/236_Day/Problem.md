# [3498. Reverse Degree of a String](https://leetcode.com/problems/reverse-degree-of-a-string/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 88.9%](https://img.shields.io/badge/Acceptance-88.9%25-orange?style=for-the-badge)
![Submissions: 87.3K+](https://img.shields.io/badge/Submissions-87.3K%2B-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/Topic-String-blue?style=for-the-badge)
![Topic: Simulation](https://img.shields.io/badge/Simulation-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given a string `s`, calculate its reverse degree.

The reverse degree is calculated as follows:
- For each character, multiply its position in the reversed alphabet (`'a'` = 26, `'b'` = 25, ..., `'z'` = 1) with its position in the string (1-indexed).
- Sum these products for all characters in the string.

Return the reverse degree of `s`.

---

## 📌 Examples

**Example 1:**

```text
Input: s = "abc"
Output: 148
Explanation:
Letter | Index in Reversed Alphabet | Index in String | Product
'a'    | 26                         | 1               | 26 * 1 = 26
'b'    | 25                         | 2               | 25 * 2 = 50
'c'    | 24                         | 3               | 24 * 3 = 72

The reversed degree is 26 + 50 + 72 = 148.
```

**Example 2:**

```text
Input: s = "zaza"
Output: 160
Explanation:
Letter | Index in Reversed Alphabet | Index in String | Product
'z'    | 1                          | 1               | 1 * 1 = 1
'a'    | 26                         | 2               | 26 * 2 = 52
'z'    | 1                          | 3               | 1 * 3 = 3
'a'    | 26                         | 4               | 26 * 4 = 104

The reverse degree is 1 + 52 + 3 + 104 = 160.
```

---

## 📐 Constraints

- $1 \le |s| \le 1000$
- `s` contains only lowercase English letters.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(|s|)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../235_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../237_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
