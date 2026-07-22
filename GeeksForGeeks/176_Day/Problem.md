# [176. Minimum Deletions to Make Sorted](https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-to-make-a-sorted-sequence3248/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-green?style=for-the-badge)
![Accuracy: 49.53%](https://img.shields.io/badge/Accuracy-49.53%25-orange?style=for-the-badge)
![Submissions: 13K+](https://img.shields.io/badge/Submissions-13K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an array `arr[]`, find the minimum number of elements to delete so that the remaining elements form a **strictly increasing** sequence in the same order.

---

## 📌 Examples

### Example 1
**Input:** 
```text
arr[] = [5, 6, 1, 7, 4]
```
**Output:** 
```text
2
```
**Explanation:** 
Removing `1` and `4` leaves `[5, 6, 7]` which is strictly increasing.

### Example 2
**Input:** 
```text
arr[] = [1, 1, 1]
```
**Output:** 
```text
2
```
**Explanation:** 
Removing any `2` elements leaves `[1]` which is strictly increasing.

---

## 📐 Constraints

- $1 \le n \le 10^5$
- $1 \le arr[i] \le 10^5$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $O(n \log n)$ |
| 💾 Auxiliary Space | $O(n)$ |

---

## 🏷️ Topic Tags

<div align="center">

![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-3498DB?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../175_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../177_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
