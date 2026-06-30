# [152. k Times Appearing Adjacent Two 1's](https://www.geeksforgeeks.org/problems/count-binary-strings1944/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 54.99%](https://img.shields.io/badge/Accuracy-54.99%25-green?style=for-the-badge)
![Submissions: 12K+](https://img.shields.io/badge/Submissions-12K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given two integers $n$ and $k$, count the number of binary strings of length $n$ where adjacent $1$s appear exactly $k$ times.

Since the answer can be huge, return it modulo $10^9+7$.

---

## 📌 Examples

### Example 1
**Input:**
```text
n = 3, k = 2
```
**Output:**
```text
1
```
**Explanation:**
Possible string is `"111"` where $2$ adjacent $1$s appear.

### Example 2
**Input:**
```text
n = 5, k = 2
```
**Output:**
```text
6
```
**Explanation:**
Possible strings are `"00111"`, `"10111"`, `"01110"`, `"11100"`, `"11101"` and `"11011"`.

---

## 📐 Constraints

- $$1 \le n, k \le 10^3$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n^2)$$ |
| 💾 Auxiliary Space | $$O(n \times k)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-8E44AD?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../151_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../153_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
