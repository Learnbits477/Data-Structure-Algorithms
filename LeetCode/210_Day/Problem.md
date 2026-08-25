# 3718. [Smallest Missing Multiple of K](https://leetcode.com/problems/smallest-missing-multiple-of-k/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 64.9%](https://img.shields.io/badge/Acceptance-64.9%25-green?style=for-the-badge)
![Submissions: 95.5K](https://img.shields.io/badge/Submissions-95.5K-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Array-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Hash%20Table-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an integer array `nums` and an integer `k`, return the **smallest positive multiple of `k`** that is missing from `nums`.

A **multiple of `k`** is any positive integer divisible by `k` (i.e., $k, 2k, 3k, 4k, \dots$).

---

## 📌 Examples

**Example 1:**
```text
Input: nums = [8, 2, 3, 4, 6], k = 2
Output: 10
Explanation:
The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the smallest multiple missing from nums is 10.
```

**Example 2:**
```text
Input: nums = [1, 4, 7, 10, 15], k = 5
Output: 5
Explanation:
The multiples of k = 5 are 5, 10, 15, 20... and the smallest multiple missing from nums is 5.
```

---

## 📐 Constraints
- $1 \le \text{nums.length} \le 100$
- $1 \le \text{nums}[i] \le 100$
- $1 \le k \le 100$

---

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time** | $\mathcal{O}(n + \frac{\max(\text{nums})}{k})$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---


<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../209_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../211_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
