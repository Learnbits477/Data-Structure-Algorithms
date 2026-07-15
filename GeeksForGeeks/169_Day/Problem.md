# [169. Longest Bitonic Subarray](https://www.geeksforgeeks.org/problems/maximum-length-bitonic-subarray5730/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 38.09%](https://img.shields.io/badge/Accuracy-38.09%25-green?style=for-the-badge)
![Submissions: 15K+](https://img.shields.io/badge/Submissions-15K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)
![Company: Microsoft](https://img.shields.io/badge/Company-Microsoft-black?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an array `arr[]` of size `n` containing positive integers, return the maximum length of the bitonic subarray.

A subarray `arr[i...j]` is considered bitonic if its elements first monotonically increase, and then monotonically decrease. Formally, there exists an index `k` (where $i \le k \le j$) such that:

$$arr[i] \le arr[i+1] \le \dots \le arr[k]$$
$$arr[k] \ge arr[k+1] \ge \dots \ge arr[j]$$

---

## 📌 Examples

### Example 1
**Input:**
```text
arr[] = [12, 4, 78, 90, 45, 23]
```
**Output:**
```text
5
```
**Explanation:**
The longest bitonic subarray is `[4, 78, 90, 45, 23]`. It starts increasing at `4`, peaks at `90`, and decreases to `23`, giving a length of `5`.

### Example 2
**Input:**
```text
arr[] = [10, 20, 30, 40]
```
**Output:**
```text
4
```
**Explanation:**
The array `[10, 20, 30, 40]` is strictly increasing with no decreasing part, so the longest bitonic subarray is the entire array itself, giving a length of `4`.

### Example 3
**Input:**
```text
arr[] = [10, 10, 10, 10]
```
**Output:**
```text
4
```
**Explanation:**
The array `[10, 10, 10, 10]` is both non-decreasing and non-increasing. We can choose any peak index (e.g., $k = 0$ or $k = 3$) to satisfy the conditions, giving a length of `4`.

---

## 📐 Constraints

- $$1 \le n \le 10^6$$
- $$1 \le arr[i] \le 10^6$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n)$$ |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Arrays](https://img.shields.io/badge/Arrays-1ABC9C?style=for-the-badge)
![Data Structures](https://img.shields.io/badge/Data%20Structures-2ECC71?style=for-the-badge)

</div>

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../168_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../170_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
