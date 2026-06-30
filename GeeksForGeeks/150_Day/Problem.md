# [150. Count Matching Subsequences](https://www.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 57.65%](https://img.shields.io/badge/Accuracy-57.65%25-green?style=for-the-badge)
![Submissions: 54K+](https://img.shields.io/badge/Submissions-54K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)
![Company: Accolite](https://img.shields.io/badge/Company-Accolite-red?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given two strings, `s1` and `s2`, count the number of subsequences of string `s1` equal to string `s2`.

Return the total count modulo $10^9 + 7$.

---

## 📌 Examples

### Example 1
**Input:**
```text
s1 = "geeksforgeeks", s2 = "gks"
```
**Output:**
```text
4
```
**Explanation:**
We can pick characters from `s1` as a subsequence from indices:
1. `[0, 3, 4]` $\to$ `g`, `k`, `s`
2. `[0, 3, 12]` $\to$ `g`, `k`, `s`
3. `[0, 11, 12]` $\to$ `g`, `k`, `s`
4. `[8, 11, 12]` $\to$ `g`, `k`, `s`

So total 4 subsequences of `s1` are equal to `s2`.

### Example 2
**Input:**
```text
s1 = "problemoftheday", s2 = "geek"
```
**Output:**
```text
0
```
**Explanation:**
No subsequence of string `s1` is equal to string `s2`.

---

## 📐 Constraints

- $$1 \le s1.size(), s2.size() \le 10^3$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(|s1| \times |s2|)$$ |
| 💾 Auxiliary Space | $$O(|s1| \times |s2|)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-8E44AD?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)
![Strings](https://img.shields.io/badge/Strings-FF5722?style=for-the-badge)
![Data Structures](https://img.shields.io/badge/Data%20Structures-3498DB?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../149_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../151_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
