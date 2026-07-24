# [3514. Number of Unique XOR Triplets II](https://leetcode.com/problems/number-of-unique-xor-triplets-ii/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance Rate: 47.4%](https://img.shields.io/badge/Acceptance%20Rate-47.4%25-orange?style=for-the-badge)
![Biweekly Contest 154](https://img.shields.io/badge/Contest-Biweekly%20154-blue?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given an integer array `nums`.

A XOR triplet is defined as the XOR of three elements `nums[i] XOR nums[j] XOR nums[k]` where `i <= j <= k`.

Return the number of unique XOR triplet values from all possible triplets `(i, j, k)`.

---

## 📌 Examples

### Example 1
**Input:** 
```text
nums = [1, 3]
```
**Output:** 
```text
2
```
**Explanation:** 
The possible XOR triplet values are:
- `(0, 0, 0) → 1 XOR 1 XOR 1 = 1`
- `(0, 0, 1) → 1 XOR 1 XOR 3 = 3`
- `(0, 1, 1) → 1 XOR 3 XOR 3 = 1`
- `(1, 1, 1) → 3 XOR 3 XOR 3 = 3`

The unique XOR values are `{1, 3}`. Thus, the output is `2`.

### Example 2
**Input:** 
```text
nums = [6, 7, 8, 9]
```
**Output:** 
```text
4
```
**Explanation:** 
The possible XOR triplet values are `{6, 7, 8, 9}`. Thus, the output is `4`.

---

## 📐 Constraints

- $1 \le nums.length \le 1500$
- $1 \le nums[i] \le 1500$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $O(N^2)$ |
| 💾 Auxiliary Space | $O(N^2)$ or $O(1)$ (using a constant-sized array) |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-3498DB?style=for-the-badge)
![Math](https://img.shields.io/badge/Math-9B59B6?style=for-the-badge)
![Bit Manipulation](https://img.shields.io/badge/Bit%20Manipulation-2ECC71?style=for-the-badge)
![Enumeration](https://img.shields.io/badge/Enumeration-E67E22?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../177_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../179_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
