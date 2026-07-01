# [155. Max Sum Subarray by Removing at Most One Element](https://www.geeksforgeeks.org/problems/max-sum-subarray-by-removing-at-most-one-element/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 32.53%](https://img.shields.io/badge/Accuracy-32.53%25-green?style=for-the-badge)
![Submissions: 27K+](https://img.shields.io/badge/Submissions-27K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an array `arr[]`, find the maximum sum of a non-empty subarray. You are allowed to skip at most one element in the subarray.

> [!NOTE]
> After skipping the element, the subarray must still be non-empty.

---

## 📌 Examples

### Example 1
**Input:**
```text
arr[] = [1, 2, 3, -4, 5]
```
**Output:**
```text
11
```
**Explanation:**
We can get maximum sum subarray by skipping -4.

### Example 2
**Input:**
```text
arr[] = [-2, -3, 4, -1, -2, 1, 5, -3]
```
**Output:**
```text
9
```
**Explanation:**
We can get maximum sum subarray by skipping -2 as `[4, -1, 1, 5]` sums to 9, which is the maximum achievable sum.

---

## 📐 Constraints

- $$1 \le \text{arr.size()} \le 10^6$$
- $$-10^3 \le \text{arr}[i] \le 10^3$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n)$$ |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Arrays](https://img.shields.io/badge/Arrays-3498DB?style=for-the-badge)
![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-8E44AD?style=for-the-badge)
![Data Structures](https://img.shields.io/badge/Data%20Structures-E67E22?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../154_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../156_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
