# [157. Ways to Increase LCS by One](https://www.geeksforgeeks.org/problems/count-ways-to-increase-lcs-length-of-two-strings-by-one2236/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 42.31%](https://img.shields.io/badge/Accuracy-42.31%25-green?style=for-the-badge)
![Submissions: 6K+](https://img.shields.io/badge/Submissions-6K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given two strings `s1` and `s2` consisting of lowercase English letters of length `n1` and `n2` respectively, find the number of ways to insert exactly one character into string `s1` such that the length of the Longest Common Subsequence (LCS) of both strings increases by exactly 1.

---

## 📌 Examples

### Example 1
**Input:**
```text
s1 = "abab", s2 = "abc"
```
**Output:**
```text
3
```
**Explanation:**
The LCS length of the given two strings is 2. There are 3 valid insertions in `s1` which increase the LCS length to 3:
1. `"abcab"` -> LCS = 3
2. `"abacb"` -> LCS = 3
3. `"ababc"` -> LCS = 3

### Example 2
**Input:**
```text
s1 = "abcabc", s2 = "abcd"
```
**Output:**
```text
4
```
**Explanation:**
The LCS length of the given two strings is 3. There are 4 valid insertions in `s1` which increase the LCS length to 4:
1. `"abcdabc"` -> LCS = 4
2. `"abcadcb"` -> LCS = 4
3. `"abcabdc"` -> LCS = 4
4. `"abcabcd"` -> LCS = 4

---

## 📐 Constraints

- $$1 \le n1, n2 \le 100$$
- The strings consist of lowercase English letters.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n1 \cdot n2)$$ |
| 💾 Auxiliary Space | $$O(n1 \cdot n2)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-8E44AD?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)
![Strings](https://img.shields.io/badge/Strings-3498DB?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../156_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../158_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
