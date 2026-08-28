# 3734. [Lexicographically Smallest Palindromic Permutation Greater Than Target](https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 48.4%](https://img.shields.io/badge/Acceptance-48.4%25-green?style=for-the-badge)
![Submissions: 58.1K](https://img.shields.io/badge/Submissions-58.1K-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Two%20Pointers-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-String-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Greedy-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Counting-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Enumeration-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given two strings `s` and `target`, each of length $n$, consisting of lowercase English letters.

Return the **lexicographically smallest** string that is both a **palindromic permutation** of `s` and **strictly greater** than `target`. If no such permutation exists, return an empty string `""`.

> - A **permutation** of a string is a string formed by rearranging its letters.
> - A string is **palindromic** if it reads the same forward and backward.
> - A string `a` is **lexicographically strictly greater** than a string `b` (of the same length) if in the first position where `a` and `b` differ, string `a` has a letter that appears later in the alphabet than the corresponding letter in `b`.

---

## 📌 Examples

**Example 1:**
```text
Input: s = "baba", target = "abba"
Output: "baab"
Explanation:
The palindromic permutations of s (in lexicographical order) are "abba" and "baab".
The lexicographically smallest permutation that is strictly greater than target is "baab".
```

**Example 2:**
```text
Input: s = "baba", target = "bbaa"
Output: ""
Explanation:
The palindromic permutations of s (in lexicographical order) are "abba" and "baab".
None of them is lexicographically strictly greater than target. Therefore, the answer is "".
```

**Example 3:**
```text
Input: s = "abc", target = "abb"
Output: ""
Explanation:
s has no palindromic permutations. Therefore, the answer is "".
```

**Example 4:**
```text
Input: s = "aac", target = "abb"
Output: "aca"
Explanation:
The only palindromic permutation of s is "aca".
"aca" is strictly greater than target. Therefore, the answer is "aca".
```

---

## 📐 Constraints

- $1 \le n == \text{s.length} == \text{target.length} \le 300$
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
<a href="../212_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../214_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
