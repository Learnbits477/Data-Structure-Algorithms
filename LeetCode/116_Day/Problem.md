# [1752. Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata:

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 56.1%](https://img.shields.io/badge/Acceptance-56.1%25-blue?style=for-the-badge)
![Submissions: 1.6M](https://img.shields.io/badge/Submissions-1.6M-purple?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)

### 🏢 Companies:
 ![Amazon](https://img.shields.io/badge/Amazon-FF9900?style=flat-square&logo=amazon&logoColor=white)
 ![Microsoft](https://img.shields.io/badge/Microsoft-0078D4?style=flat-square&logo=microsoft&logoColor=white)
 ![Adobe](https://img.shields.io/badge/Adobe-FF0000?style=flat-square&logo=adobe&logoColor=white)
 ![Goldman Sachs](https://img.shields.io/badge/Goldman%20Sachs-7393B3?style=flat-square&logoColor=white)

---

## 🧩 Problem Description

Given an array `nums`, return `true` if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return `false`.

There may be duplicates in the original array.

**Note:** An array $A$ rotated by $x$ positions results in an array $B$ of the same length such that $B[i] = A[(i+x) \% A.\text{length}]$ for every valid index $i$.

---

## 📌 Examples

### Example 1

**Input:**
```text
nums = [3,4,5,1,2]
```
**Output:** `true`  
**Explanation:** `[1,2,3,4,5]` is the original sorted array.
You can rotate the array by $x = 2$ positions to begin on the element of value $3$: `[3,4,5,1,2]`.

### Example 2

**Input:**
```text
nums = [2,1,3,4]
```
**Output:** `false`  
**Explanation:** There is no sorted array once rotated that can make `nums`.

### Example 3

**Input:**
```text
nums = [1,2,3]
```
**Output:** `true`  
**Explanation:** `[1,2,3]` is the original sorted array.
You can rotate the array by $x = 0$ positions (i.e. no rotation) to make `nums`.

---

## 📐 Constraints

- $1 \le \text{nums.length} \le 100$
- $1 \le \text{nums}[i] \le 100$

---

## ⏱️ Expected Complexities

| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(1)$ |

---

## 🏷️ Topic Tags

- `Array`
- `Algorithms`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../115_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../117_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
