# [156. Subset with Sum Divisible by m](https://www.geeksforgeeks.org/problems/subset-with-sum-divisible-by-m2546/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 22.41%](https://img.shields.io/badge/Accuracy-22.41%25-green?style=for-the-badge)
![Submissions: 21K+](https://img.shields.io/badge/Submissions-21K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an array `arr[]` of positive integers and a value `k`. Return true if the sum of any non-empty subset of the given array is divisible by `k` otherwise, return false.

---

## 📌 Examples

### Example 1
**Input:**
```text
arr[] = [3, 1, 7, 5], k = 6
```
**Output:**
```text
true
```
**Explanation:**
If we take the subset `{7, 5}` then sum will be 12 which is divisible by 6.

### Example 2
**Input:**
```text
arr[] = [1, 2, 6], k = 5
```
**Output:**
```text
false
```
**Explanation:**
All possible subsets of the given set are `{1}`, `{2}`, `{6}`, `{1, 2}`, `{2, 6}`, `{1, 6}` and `{1, 2, 6}`. There is no subset whose sum is divisible by 5.

---

## 📐 Constraints

- $$1 \le \text{arr.size()}, k \le 10^3$$
- $$1 \le \text{arr}[i] \le 10^3$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n \cdot k)$$ |
| 💾 Auxiliary Space | $$O(k)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-8E44AD?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)
![Arrays](https://img.shields.io/badge/Arrays-3498DB?style=for-the-badge)
![Data Structures](https://img.shields.io/badge/Data%20Structures-E67E22?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../155_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../157_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
