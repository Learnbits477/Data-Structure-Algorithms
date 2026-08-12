# [Length of Longest Subarray With at Most K Frequency](https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2026-08-12)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 57.3%](https://img.shields.io/badge/Acceptance-57.3%25-blue?style=for-the-badge)
![Submissions: 363.7K+](https://img.shields.io/badge/Submissions-363.7K+-orange?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Array-blue?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Hash_Table-blue?style=for-the-badge)
![Topic: Sliding Window](https://img.shields.io/badge/Sliding_Window-blue?style=for-the-badge)

---

## 🧩 Problem Description
You are given an integer array `nums` and an integer `k`.

The **frequency** of an element `x` is the number of times it occurs in an array.

An array is called **good** if the frequency of each element in this array is less than or equal to `k`.

Return the length of the **longest good subarray** of `nums`.

A **subarray** is a contiguous non-empty sequence of elements within an array.

---

## 📌 Examples

### Example 1
**Input**:
```text
nums = [1,2,3,1,2,3,1,2], k = 2
```
**Output**:
```text
6
```
**Explanation**:
The longest possible good subarray is `[1,2,3,1,2,3]` since the values 1, 2, and 3 occur at most twice in this subarray. Note that the subarrays `[2,3,1,2,3,1]` and `[3,1,2,3,1,2]` are also good.
It can be shown that there are no good subarrays with length more than 6.

### Example 2
**Input**:
```text
nums = [1,2,1,2,1,2,1,2], k = 1
```
**Output**:
```text
2
```
**Explanation**:
The longest possible good subarray is `[1,2]` since the values 1 and 2 occur at most once in this subarray. Note that the subarray `[2,1]` is also good.
It can be shown that there are no good subarrays with length more than 2.

### Example 3
**Input**:
```text
nums = [5,5,5,5,5,5,5], k = 4
```
**Output**:
```text
4
```
**Explanation**:
The longest possible good subarray is `[5,5,5,5]` since the value 5 occurs 4 times in this subarray.
It can be shown that there are no good subarrays with length more than 4.

---

## 📐 Constraints
- $$1 \le nums.length \le 10^5$$
- $$1 \le nums[i] \le 10^9$$
- $$1 \le k \le nums.length$$

---

## ⏱️ Expected Complexities
| Time Complexity | Auxiliary Space |
| :--- | :--- |
| $\mathcal{O}(n)$ | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../196_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../198_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
