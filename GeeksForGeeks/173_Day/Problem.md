# [173. Mountain Subarray Queries](https://www.geeksforgeeks.org/problems/mountain-subarray-problem/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 46.22%](https://img.shields.io/badge/Accuracy-46.22%25-green?style=for-the-badge)
![Submissions: 14K+](https://img.shields.io/badge/Submissions-14K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)
![Company: Amazon](https://img.shields.io/badge/Company-Amazon-black?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an array `arr[]` and a list of queries. For each query `[l, r]`, find whether the subarray `arr[l...r]` is a mountain array. 

A subarray is called a mountain array if there exists an index `k` ($$l \le k \le r$$) such that:
$$arr[l] \le arr[l + 1] \le \dots \le arr[k] \ge arr[k + 1] \ge \dots \ge arr[r]$$

- Elements of a Mountain subarray are first non-decreasing and then non-increasing.
- A subarray that is entirely non-decreasing or entirely non-increasing is also considered a mountain.

---

## 📌 Examples

### Example 1
**Input:** 
```text
arr[] = [2, 3, 2, 4, 4, 6, 3, 2]
queries[][] = [[0, 2], [1, 3]]
```
**Output:** 
```text
[true, false]
```
**Explanation:** 
- For query `[0, 2]`, the subarray is `[2, 3, 2]`. The elements first increase and then decrease, so it forms a mountain.
- For query `[1, 3]`, the subarray is `[3, 2, 4]`. The elements decrease and then increase, so it does not form a mountain.

### Example 2
**Input:** 
```text
arr[] = [2, 2, 2, 2]
queries[][] = [[0, 2], [1, 3]]
```
**Output:** 
```text
[true, true]
```
**Explanation:** 
All subarrays of the given array are mountains since flat arrays (entirely non-decreasing/non-increasing) are also considered mountains.

---

## 📐 Constraints

- $$1 \le arr.size(), queries.size() \le 10^5$$
- $$1 \le arr[i] \le 10^6$$
- $$0 \le l \le r < arr.size()$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n + q)$$ |
| 💾 Auxiliary Space | $$O(n)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Arrays](https://img.shields.io/badge/Arrays-3498DB?style=for-the-badge)

</div>

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../172_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../174_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
