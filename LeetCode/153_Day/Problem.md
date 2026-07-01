# [1967. Number of Strings That Appear as Substrings in Word](https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 80.5%](https://img.shields.io/badge/Acceptance-80.5%25-blue?style=for-the-badge)
![Submissions: 120.3K](https://img.shields.io/badge/Submissions-120.3K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an array of strings `patterns` and a string `word`, return the *number of strings in `patterns` that exist as a **substring** in `word`*.

A **substring** is a contiguous sequence of characters within a string.

---

## 📌 Examples

### Example 1

**Input:** `patterns = ["a","abc","bc","d"]`, `word = "abc"`  
**Output:** `3`  
**Explanation:** 
- `"a"` appears as a substring in `"abc"`.
- `"abc"` appears as a substring in `"abc"`.
- `"bc"` appears as a substring in `"abc"`.
- `"d"` does not appear as a substring in `"abc"`.
- Total matching patterns: 3.

### Example 2

**Input:** `patterns = ["a","b","c"]`, `word = "aaaaabbbbb"`  
**Output:** `2`  
**Explanation:** 
- `"a"` appears as a substring in `"aaaaabbbbb"`.
- `"b"` appears as a substring in `"aaaaabbbbb"`.
- `"c"` does not appear as a substring in `"aaaaabbbbb"`.
- Total matching patterns: 2.

### Example 3

**Input:** `patterns = ["a","a","a"]`, `word = "ab"`  
**Output:** `3`  
**Explanation:** Each of the patterns appears as a substring in `"ab"`.

---

## 📐 Constraints

- $$1 \le patterns.length \le 100$$
- $$1 \le patterns[i].length \le 100$$
- $$1 \le word.length \le 100$$
- `patterns[i]` and `word` consist of lowercase English letters.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :--- |
| 🕐 Time | $$O(m \cdot l \cdot w)$$ where $$m$$ is the number of patterns, $$l$$ is the maximum length of a pattern, and $$w$$ is the length of `word`. |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![String](https://img.shields.io/badge/String-0A9EDC?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../152_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../154_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
