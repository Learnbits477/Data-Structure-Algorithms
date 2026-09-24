# [3550. Smallest Index With Digit Sum Equal to Index](https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 81.5%](https://img.shields.io/badge/Acceptance-81.5%25-orange?style=for-the-badge)
![Submissions: 98.2K+](https://img.shields.io/badge/Submissions-98.2K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Math-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given an integer array `nums`.

Return the **smallest index** $i$ such that the sum of the digits of `nums[i]` is equal to $i$.

If no such index exists, return `-1`.

---

## 📌 Examples

**Example 1:**

```text
Input: nums = [1, 3, 2]
Output: 2
Explanation:
For nums[2] = 2, the sum of digits is 2, which is equal to index i = 2.
Thus, the output is 2.
```

**Example 2:**

```text
Input: nums = [1, 10, 11]
Output: 1
Explanation:
For nums[1] = 10, the sum of digits is 1 + 0 = 1, which is equal to index i = 1.
For nums[2] = 11, the sum of digits is 1 + 1 = 2, which is equal to index i = 2.
Since index 1 is the smallest, the output is 1.
```

**Example 3:**

```text
Input: nums = [1, 2, 3]
Output: -1
Explanation:
Since no index satisfies the condition, the output is -1.
```

---

## 📐 Constraints

- $1 \le \text{nums.length} \le 100$
- $0 \le \text{nums}[i] \le 1000$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \cdot \log_{10}(\max(\text{nums})))$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../239_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../241_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
