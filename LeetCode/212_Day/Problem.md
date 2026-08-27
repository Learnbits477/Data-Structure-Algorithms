# 3720. [Lexicographically Smallest Permutation Greater Than Target](https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 32.6%](https://img.shields.io/badge/Acceptance-32.6%25-green?style=for-the-badge)
![Submissions: 62.2K](https://img.shields.io/badge/Submissions-62.2K-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Hash%20Table-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-String-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Greedy-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Counting-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Enumeration-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given two strings `s` and `target`, both having length $n$, consisting of lowercase English letters.

Return the **lexicographically smallest permutation** of `s` that is **strictly greater** than `target`. If no permutation of `s` is lexicographically strictly greater than `target`, return an empty string `""`.

> A string `a` is **lexicographically strictly greater** than a string `b` (of the same length) if in the first position where `a` and `b` differ, string `a` has a letter that appears later in the alphabet than the corresponding letter in `b`.

---

## 📌 Examples

**Example 1:**
```text
Input: s = "abc", target = "bba"
Output: "bca"
Explanation:
The permutations of s (in lexicographical order) are "abc", "acb", "bac", "bca", "cab", and "cba".
The lexicographically smallest permutation that is strictly greater than target is "bca".
```

**Example 2:**
```text
Input: s = "leet", target = "code"
Output: "eelt"
Explanation:
The permutations of s (in lexicographical order) are "eelt", "eetl", "elet", "elte", "etel", "etle", "leet", "lete", "ltee", "teel", "tele", and "tlee".
The lexicographically smallest permutation that is strictly greater than target is "eelt".
```

**Example 3:**
```text
Input: s = "baba", target = "bbaa"
Output: ""
Explanation:
The permutations of s (in lexicographical order) are "aabb", "abab", "abba", "baab", "baba", and "bbaa".
None of them is lexicographically strictly greater than target. Therefore, the answer is "".
```

---

## 📐 Constraints
- $1 \le \text{s.length} == \text{target.length} \le 300$
- `s` and `target` consist of only lowercase English letters.

---

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \times \Sigma)$ where $\Sigma = 26$ |
| **Auxiliary Space** | $\mathcal{O}(\Sigma)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../211_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../213_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
