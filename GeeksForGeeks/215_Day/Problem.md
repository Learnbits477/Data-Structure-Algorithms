# 215. [Marks from Ranks](https://www.geeksforgeeks.org/problems/find-marks-from-ranks/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 34.67%](https://img.shields.io/badge/Accuracy-34.67%25-green?style=for-the-badge)
![Submissions: 6K+](https://img.shields.io/badge/Submissions-6K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Arrays-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Searching-blue?style=for-the-badge)

---

## 🧩 Problem Description

Consider an input where all marks obtained are divided into intervals of consecutive numbers represented as `l[]` and `r[]` where `l[i]` and `r[i]` represent the starting and ending marks (inclusive) of the $i$-th interval.

The intervals are sorted in increasing order and do not overlap.

The rank of a mark is defined by its position among all valid marks in increasing order, with the smallest mark assigned rank 1, the next smallest rank 2, and so on.

Given an array `rank[]`, for each value in `rank[]`, find the corresponding mark and return as an array.

---

## 📌 Examples

**Example 1:**
```text
Input: l[] = [1, 6, 14], r[] = [3, 9, 15], rank[] = [2, 5, 8]
Output: [2, 7, 14]
Explanation: The valid marks are 1, 2, 3, 6, 7, 8, 9, 14, 15. 
Their corresponding ranks are 1 to 9 as there are 9 distinct marks. 
Therefore, rank 2 corresponds to mark 2, rank 5 corresponds to mark 7, and rank 8 corresponds to mark 14.
```

**Example 2:**
```text
Input: l[] = [5, 10], r[] = [7, 12], rank[] = [1, 4, 6]
Output: [5, 10, 12]
Explanation: The valid marks are 5, 6, 7, 10, 11, 12. 
Their corresponding ranks are 1 to 6 in increasing order. 
Hence, rank 1 corresponds to mark 5, rank 4 corresponds to mark 10, and rank 6 corresponds to mark 12.
```

---

## 📐 Constraints

- $1 \le l.\text{size}(), l[i], r.\text{size}(), r[i], rank.\text{size}(), rank[i] \le 10^5$
- $l[i] \le r[i]$ for all valid $i$.
- $r[i] < l[i+1]$ for all $0 \le i < n - 1$ (intervals are strictly increasing and non-overlapping).

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n + q \log n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../214_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../216_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
