# [1658. Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 41.1%](https://img.shields.io/badge/Acceptance-41.1%25-orange?style=for-the-badge)
![Submissions: 607.2K+](https://img.shields.io/badge/Submissions-607.2K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Hash%20Table-blue?style=for-the-badge)
![Topic: Sliding Window](https://img.shields.io/badge/Sliding%20Window-blue?style=for-the-badge)
![Topic: Prefix Sum](https://img.shields.io/badge/Prefix%20Sum-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given an integer array `nums` and an integer `x`. In one operation, you can either remove the leftmost or the rightmost element from the array `nums` and subtract its value from `x`. Note that this modifies the array for future operations.

Return the **minimum number of operations** to reduce `x` to **exactly 0** if it is possible, otherwise, return `-1`.

---

## 📌 Examples

**Example 1:**

```text
Input: nums = [1, 1, 4, 2, 3], x = 5
Output: 2
Explanation:
The optimal solution is to remove the last two elements [2, 3] to reduce x to zero:
5 - 3 = 2, then 2 - 2 = 0.
Total operations = 2.
```

**Example 2:**

```text
Input: nums = [5, 6, 7, 8, 9], x = 4
Output: -1
Explanation:
All elements are strictly greater than x = 4, so it is impossible to reduce x to zero.
```

**Example 3:**

```text
Input: nums = [3, 2, 20, 1, 1, 3], x = 10
Output: 5
Explanation:
The optimal solution is to remove the last three elements [1, 1, 3] (sum = 5) and the first two elements [3, 2] (sum = 5) for 5 operations in total.
```

---

## 📐 Constraints

- $1 \le \text{nums.length} \le 10^5$
- $1 \le \text{nums}[i] \le 10^4$
- $1 \le x \le 10^9$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../238_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../240_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
