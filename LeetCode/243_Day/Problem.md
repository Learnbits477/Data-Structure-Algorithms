# [1190. Reverse Substrings Between Each Pair of Parentheses](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 72.5%](https://img.shields.io/badge/Acceptance-72.5%25-orange?style=for-the-badge)
![Submissions: 357.8K+](https://img.shields.io/badge/Submissions-357.8K%2B-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/Topic-String-blue?style=for-the-badge)
![Topic: Stack](https://img.shields.io/badge/Stack-blue?style=for-the-badge)
![Topic: Two Pointers](https://img.shields.io/badge/Two%20Pointers-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given a string `s` that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should **not** contain any brackets.

---

## 📌 Examples

**Example 1:**

```text
Input: s = "(abcd)"
Output: "dcba"
```

**Example 2:**

```text
Input: s = "(u(love)i)"
Output: "iloveu"
Explanation:
The substring "love" is reversed first, then the whole string is reversed.
```

**Example 3:**

```text
Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation:
First, we reverse the substring "oc", then "etco", and finally, the whole string.
```

---

## 📐 Constraints

- $1 \le \text{s.length} \le 2000$
- `s` only contains lower case English characters and parentheses `'('` and `')'`.
- It is guaranteed that all parentheses are balanced.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../242_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../244_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
