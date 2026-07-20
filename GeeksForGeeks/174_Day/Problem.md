# [174. Shortest Unique Prefix for Every Word](https://www.geeksforgeeks.org/problems/shortest-unique-prefix-for-every-word/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 50.02%](https://img.shields.io/badge/Accuracy-50.02%25-green?style=for-the-badge)
![Submissions: 22K+](https://img.shields.io/badge/Submissions-22K%2B-blue?style=for-the-badge)
![Points: 8](https://img.shields.io/badge/Points-8-yellow?style=for-the-badge)
![Company: Microsoft](https://img.shields.io/badge/Company-Microsoft-black?style=for-the-badge)
![Company: Google](https://img.shields.io/badge/Google-black?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an array of strings `arr[]`, find the shortest prefix of each string that uniquely identifies it among all strings in the array. A prefix is unique if it is not a prefix of any other string in the array.

> **Note:** No string in the given array is a prefix of another string.

---

## 📌 Examples

### Example 1
**Input:** 
```text
arr[] = ["zebra", "dog", "duck", "dove"]
```
**Output:** 
```text
z dog du dov
```
**Explanation:** 
- `z` uniquely identifies `"zebra"`.
- `"dog"` has a prefix `d` which is shared with `"duck"` and `"dove"`. The next character `o` is shared with `"dove"`. So we need `"dog"` to uniquely identify it.
- `"duck"` shares `d` with `"dog"` and `"dove"`. The next character `u` is unique, so `"du"` is the prefix.
- `"dove"` shares `d` and `o` with `"dog"`. The next character `v` is unique, so `"dov"` is the prefix.

### Example 2
**Input:** 
```text
arr[] = ["geeksgeeks", "geeksquiz", "geeksforgeeks"]
```
**Output:** 
```text
geeksg geeksq geeksf
```
**Explanation:** 
- `"geeksgeeks"` has a common prefix `"geeks"` with the other two words. The next character `g` makes it unique. Thus, `"geeksg"`.
- `"geeksquiz"` prefix `"geeksq"` uniquely identifies it.
- `"geeksforgeeks"` prefix `"geeksf"` uniquely identifies it.

---

## 📐 Constraints

- $1 \le \text{length of arr}, \text{length of each word} \le 1000$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $O(n \times \text{length of each word})$ |
| 💾 Auxiliary Space | $O(n \times \text{length of each word})$ |

---

## 🏷️ Topic Tags

<div align="center">

![Trie](https://img.shields.io/badge/Trie-3498DB?style=for-the-badge)
![Advanced Data Structure](https://img.shields.io/badge/Advanced_Data_Structure-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../173_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../175_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
