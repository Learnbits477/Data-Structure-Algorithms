# 201. [Min Product Subset](https://www.geeksforgeeks.org/problems/max-and-min-products3347/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 28.61%](https://img.shields.io/badge/Accuracy-28.61%25-blue?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Topics:-Arrays-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an integer array `arr[]`, find the minimum possible product that can be obtained by multiplying the elements of any non-empty subset of the array.

---

## 📌 Examples

### Example 1
**Input:**
```text
arr[] = [1, 2, 3]
```
**Output:**
```text
1
```
**Explanation:**
The possible subset products are 1, 2, 3, 2, 3, 6, and 6. The minimum product is 1, obtained by selecting the subset `[1]`.

### Example 2
**Input:**
```text
arr[] = [4, -2, 5]
```
**Output:**
```text
-40
```
**Explanation:**
The minimum product is -40, obtained by selecting the subset `[4, -2, 5]`.

---

## 📐 Constraints

- $1 \le \text{arr.size()} \le 10$
- $-10 \le \text{arr}[i] \le 10$

---

## ⏱️ Expected Complexities

| Time Complexity | Auxiliary Space |
| :-------------: | :-------------: |
| $O(N)$          | $O(1)$          |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../200_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../202_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
