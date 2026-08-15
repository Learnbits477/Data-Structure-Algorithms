# 200. [Numbers Without d as Digit](https://www.geeksforgeeks.org/problems/count-numbers2004/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 41.88%](https://img.shields.io/badge/Accuracy-41.88%25-blue?style=for-the-badge)
![Topic: Mathematical](https://img.shields.io/badge/Topics:-Mathematical-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given a number $n$, count the numbers from $1$ to $n$ that don’t contain digit $d$ in their decimal representation.

---

## 📌 Examples

### Example 1
**Input:**
```text
n = 25, d = 3
```
**Output:**
```text
22
```
**Explanation:**
From 1 to 25, the numbers 3, 13, and 23 contain the digit 3, so the answer is $25 - 3 = 22$.

### Example 2
**Input:**
```text
n = 5, d = 3
```
**Output:**
```text
4
```
**Explanation:**
From 1 to 5, only 3 contains the digit 3, so the count of numbers without digit 3 is $4$.

---

## 📐 Constraints

- $0 \le n \le 10^9$
- $0 \le d \le 9$

---

## ⏱️ Expected Complexities

| Time Complexity | Auxiliary Space |
| :-------------: | :-------------: |
| $O(\log n)$     | $O(1)$          |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../199_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../201_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
