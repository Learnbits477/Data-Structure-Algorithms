# [Tricky Subset Problem](https://www.geeksforgeeks.org/problems/tricky-subset-problem1557/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 37.44%](https://img.shields.io/badge/Accuracy-37.44%25-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Topics:-Greedy-blue?style=for-the-badge)

---

## 🧩 Problem Description

There are $n$ children standing in a queue, each assigned a number `arr[i]`. The teacher writes $s$ on a paper and gives it to the first child.
Each child writes the sum of all numbers already on the paper and `arr[i]`, then passes it to the next child.

Return `true` if $x$ can be formed by adding some of the numbers written on the paper; else return `false`.

---

## 📌 Examples

### Example 1
**Input:**
```text
arr[] = [1, 2, 4, 2], s = 1, x = 7
```
**Output:**
```text
true
```
**Explanation:**
- The first student gets 1 on paper and writes 2 ($1 + 1 = 2$).
- The second student gets [1, 2] and writes 5 ($(1 + 2) + 2 = 5$).
- The third student gets [1, 2, 5] and writes 12 ($(1 + 2 + 5) + 4 = 12$).
- The fourth student gets [1, 2, 5, 12] and writes 22 ($(1 + 2 + 5 + 12) + 2 = 22$).
- The final sequence of numbers on the paper is `1, 2, 5, 12, 22`.
- Using `2` and `5` we can form `7` ($2 + 5 = 7$).

### Example 2
**Input:**
```text
arr[] = [51, 88], s = 100, x = 500
```
**Output:**
```text
false
```
**Explanation:**
- The first student gets 100 on paper and writes 151 ($100 + 51 = 151$).
- The second student gets [100, 151] and writes 339 ($(100 + 151) + 88 = 339$).
- The final sequence of numbers on the paper is `100, 151, 339`.
- Using these numbers we cannot form `500`.

---

## 📐 Constraints

- $1 \le \text{arr.size()} \le 10^5$
- $1 \le \text{arr}[i] \le 10^9$
- $1 \le s \le 10^9$
- $0 \le x \le 10^9$ (or up to $10^{18}$)

---

## ⏱️ Expected Complexities

| Time Complexity | Auxiliary Space |
| :-------------: | :-------------: |
| $O(N)$          | $O(N)$          |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../198_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../200_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
