# [158. Substrings with more 1's than 0's](https://www.geeksforgeeks.org/problems/count-the-substring--170645/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 57.87%](https://img.shields.io/badge/Accuracy-57.87%25-green?style=for-the-badge)
![Submissions: 21K+](https://img.shields.io/badge/Submissions-21K%2B-blue?style=for-the-badge)
![Points: 8](https://img.shields.io/badge/Points-8-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a binary string `s` consisting only of `0`s and `1`s. Calculate the number of substrings that have strictly more `1`s than `0`s.

---

## 📌 Examples

### Example 1
**Input:**
```text
s = "011"
```
**Output:**
```text
4
```
**Explanation:**
There are 4 substrings which have more `1`s than `0`s:
1. `"011"` (two 1s, one 0)
2. `"1"` (at index 1)
3. `"11"` (two 1s, zero 0s)
4. `"1"` (at index 2)

### Example 2
**Input:**
```text
s = "0000"
```
**Output:**
```text
0
```
**Explanation:**
There is no substring with more `1`s than `0`s.

---

## 📐 Constraints

- $$1 < |s| \le 6 \times 10^4$$
- The string `s` consists only of `'0'` and `'1'`.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(|s|)$$ |
| 💾 Auxiliary Space | $$O(|s|)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Strings](https://img.shields.io/badge/Strings-3498DB?style=for-the-badge)
![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-8E44AD?style=for-the-badge)
![Data Structures](https://img.shields.io/badge/Data%20Structures-F39C12?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../157_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../159_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
