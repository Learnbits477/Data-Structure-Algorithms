# [171. Max Absolute Diff of Two Subarrays](https://www.geeksforgeeks.org/problems/max-absolute-difference4114/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 40.92%](https://img.shields.io/badge/Accuracy-40.92%25-green?style=for-the-badge)
![Submissions: 8K+](https://img.shields.io/badge/Submissions-8K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)
![Company: Google](https://img.shields.io/badge/Company-Google-black?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an array of integers `arr[]`, find two non-overlapping contiguous sub-arrays such that the absolute difference between the sum of two sub-arrays is maximum.

---

## 📌 Examples

### Example 1
**Input:**
```text
arr[] = [-2, -3, 4, -1, -2, 1, 5, -3]
```
**Output:**
```text
12
```
**Explanation:**
Two subarrays are `[-2, -3]` (sum = `-5`) and `[4, -1, -2, 1, 5]` (sum = `7`). The absolute difference is `|(-5) - 7| = 12`.

### Example 2
**Input:**
```text
arr[] = [2, -1, -2, 1, -4, 2, 8]
```
**Output:**
```text
16
```
**Explanation:**
Two subarrays are `[-1, -2, 1, -4]` (sum = `-6`) and `[2, 8]` (sum = `10`). The absolute difference is `|(-6) - 10| = 16`.

---

## 📐 Constraints

- $$2 \le arr.size() \le 10^5$$
- $$-10^3 \le arr[i] \le 10^3$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n)$$ |
| 💾 Auxiliary Space | $$O(n)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Arrays](https://img.shields.io/badge/Arrays-1ABC9C?style=for-the-badge)
![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-2ECC71?style=for-the-badge)
![Kadane](https://img.shields.io/badge/Kadane-3498DB?style=for-the-badge)

</div>

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../170_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../172_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
