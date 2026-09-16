# [1621. Number of Sets of K Non-Overlapping Line Segments](https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 53.3%](https://img.shields.io/badge/Acceptance-53.3%25-orange?style=for-the-badge)
![Submissions: 37.7K+](https://img.shields.io/badge/Submissions-37.7K%2B-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Combinatorics](https://img.shields.io/badge/Combinatorics-blue?style=for-the-badge)
![Topic: Prefix Sum](https://img.shields.io/badge/Prefix%20Sum-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given `n` points on a 1-D plane, where the $i$-th point (from $0$ to $n-1$) is at $x = i$, find the number of ways we can draw exactly `k` **non-overlapping** line segments such that each segment covers two or more points.

The endpoints of each segment must have **integral coordinates**. The `k` line segments do not have to cover all `n` points, and they **are allowed to share endpoints**.

Return the number of ways we can draw `k` non-overlapping line segments. Since this number can be huge, return it **modulo** $10^9 + 7$.

---

## 📌 Examples

**Example 1:**

```text
Input: n = 4, k = 2
Output: 5
Explanation:
The 5 different ways are:
- {(0,2), (2,3)}
- {(0,1), (1,3)}
- {(0,1), (2,3)}
- {(1,2), (2,3)}
- {(0,1), (1,2)}
```

**Example 2:**

```text
Input: n = 3, k = 1
Output: 3
Explanation:
The 3 ways are:
- {(0,1)}
- {(0,2)}
- {(1,2)}
```

**Example 3:**

```text
Input: n = 30, k = 7
Output: 796297179
Explanation:
The total number of possible ways to draw 7 line segments is 3796297200.
Taking this number modulo 10^9 + 7 gives 796297179.
```

---

## 📐 Constraints

- $2 \le n \le 1000$
- $1 \le k \le n - 1$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(k)$ or $\mathcal{O}(n \cdot k)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../231_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../233_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
