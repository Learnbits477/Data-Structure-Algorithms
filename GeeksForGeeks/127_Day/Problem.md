# [Subarray Frequency Count Queries](https://www.geeksforgeeks.org/problems/count-frequency-of-an-element-in-a-given-range/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 63.19%](https://img.shields.io/badge/Accuracy-63.19%25-green?style=for-the-badge)
![Submissions: 2K+](https://img.shields.io/badge/Submissions-2K+-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-red?style=for-the-badge)

## 🧩 Problem Description
Given an array `arr[]` of `n` integers and a 2D array `queries[][]` representing `q` queries, where each `queries[i]` consists of three integers: `l`, `r`, and `x`. For each query determine how many times the element `x` appears in the `arr[]` from index `l` to `r` (both inclusive).

Return a list of integers where the `i`-th value represents the answer to the `i`-th query.

## 📌 Examples

**Example 1:**
> **Input:** `arr[] = [1, 2, 1, 3, 1, 2, 3]`, `queries[][] = [[0, 4, 1], [2, 5, 2], [1, 6, 3], [0, 6, 5]]`
> **Output:** `[3, 1, 2, 0]`
> **Explanation:**
> - query `[0, 4, 1]` -> Subarray = `[1, 2, 1, 3, 1]`, `1` appears `3` times
> - query `[2, 5, 2]` -> Subarray = `[1, 3, 1, 2]`, `2` appears `1` time
> - query `[1, 6, 3]` -> Subarray = `[2, 1, 3, 1, 2, 3]`, `3` appears `2` times
> - query `[0, 6, 5]` -> Subarray = `[1, 2, 1, 3, 1, 2, 3]`, `5` appears `0` times

**Example 2:**
> **Input:** `arr[] = [11, 21, 51, 101, 11, 51]`, `queries[][] = [[0, 4, 11], [2, 5, 51]]`
> **Output:** `[2, 2]`
> **Explanation:**
> - query `[0, 4, 11]` -> Subarray = `[11, 21, 51, 101, 11]`, `11` appears `2` times
> - query `[2, 5, 51]` -> Subarray = `[51, 101, 11, 51]`, `51` appears `2` times

## 📐 Constraints
- $$1 \le arr.size(), queries.size() \le 10^5$$
- $$1 \le arr[i], queries[i][2] \le 10^5$$
- $$0 \le queries[i][0] \le queries[i][1] < arr.size()$$

## ⏱️ Expected Complexities
| Complexity | Time |
|:---:|:---:|
| **Time** | $$O(n \log n + q \log k)$$ |
| **Auxiliary Space** | $$O(n)$$ |

## 🏷️ Topic Tags
`Binary Search`, `Map`, `Data Structures`, `Algorithms`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../126_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../128_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
