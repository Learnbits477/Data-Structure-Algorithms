# [170. Numbers with Given Digit Sum](https://www.geeksforgeeks.org/problems/count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum0733/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 26.33%](https://img.shields.io/badge/Accuracy-26.33%25-green?style=for-the-badge)
![Submissions: 15K+](https://img.shields.io/badge/Submissions-15K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)
![Company: Amazon](https://img.shields.io/badge/Company-Amazon-black?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given two integers `n` and `sum`, determine the number of `n`-digit positive integers whose digits add up to `sum`.

An `n`-digit number cannot have leading zeros; that is, the first digit must be between $1$ and $9$.
If there exist no `n`-digit number with sum of digits equal to the given sum, return `-1`.

---

## 📌 Examples

### Example 1
**Input:**
```text
n = 2, sum = 2
```
**Output:**
```text
2
```
**Explanation:**
The valid 2-digit numbers whose digits sum to 2 are `11` and `20`.

### Example 2
**Input:**
```text
n = 1, sum = 10
```
**Output:**
```text
-1
```
**Explanation:**
A single-digit number can only have a digit sum between 0 and 9.

### Example 3
**Input:**
```text
n = 2, sum = 10
```
**Output:**
```text
9
```
**Explanation:**
The 2-digit numbers whose digits add up to 10 are: `19`, `28`, `37`, `46`, `55`, `64`, `73`, `82`, `91`.

---

## 📐 Constraints

- $$1 \le n \le 9$$
- $$1 \le sum \le 81$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n \times sum)$$ |
| 💾 Auxiliary Space | $$O(n \times sum)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-1ABC9C?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)
![Mathematical](https://img.shields.io/badge/Mathematical-3498DB?style=for-the-badge)

</div>

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../169_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../171_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
