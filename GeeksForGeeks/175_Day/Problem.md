# [175. Maximum Reachable Index Difference](https://www.geeksforgeeks.org/problems/maximum-reachable-index-difference/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 48.14%](https://img.shields.io/badge/Accuracy-48.14%25-orange?style=for-the-badge)
![Submissions: 12K+](https://img.shields.io/badge/Submissions-12K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a string `s` containing lowercase English alphabets.

Start from any index containing the character `'a'` and perform jump operations.
In each jump operation, move to any index on the right side whose character is the immediate next letter of the current character in the alphabet (i.e., `'a'` to `'b'`, `'b'` to `'c'`, `'c'` to `'d'`, and so on). 
Continue performing jumps until no further jump is possible.
Find the maximum possible difference between the starting index and the ending index. If it is not possible to choose a starting index, return `-1`.

---

## 📌 Examples

### Example 1
**Input:** 
```text
s = "aaabcb"
```
**Output:** 
```text
5
```
**Explanation:** 
Start at index 0 (`'a'`), jump to index 5 (`'b'`). Difference = 5 - 0 = 5.

### Example 2
**Input:** 
```text
s = "xynjir"
```
**Output:** 
```text
-1
```
**Explanation:** 
The string does not contain any character `'a'`. So, the answer is -1.

### Example 3
**Input:** 
```text
s = "abcbzzd"
```
**Output:** 
```text
6
```
**Explanation:** 
Start from index 0 (`'a'`). Jump to index 1 (`'b'`) because `'b'` is the next alphabet character. Jump to index 2 (`'c'`) because `'c'` is the next character after `'b'`. Jump to index 6 (`'d'`) because `'d'` is the next character after `'c'`. Difference = 6 - 0 = 6.

---

## 📐 Constraints

- $1 \le |s| \le 10^5$
- `s` consists of lowercase English letters.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $O(n)$ |
| 💾 Auxiliary Space | $O(1)$ |

---

## 🏷️ Topic Tags

<div align="center">

![Strings](https://img.shields.io/badge/Strings-3498DB?style=for-the-badge)
![Greedy](https://img.shields.io/badge/Greedy-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../174_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../176_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
