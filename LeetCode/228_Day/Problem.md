# 3414. [Maximum Score of Non-overlapping Intervals](https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 40.2%](https://img.shields.io/badge/Acceptance-40.2%25-orange?style=for-the-badge)
![Submissions: 18.9K+](https://img.shields.io/badge/Submissions-18.9K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Binary Search](https://img.shields.io/badge/Binary%20Search-blue?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given a 2D integer array `intervals`, where `intervals[i] = [li, ri, weighti]`. Interval `i` starts at position $l_i$ and ends at $r_i$, and has a weight of $\text{weight}_i$. 

You can choose **up to 4 non-overlapping intervals**. The **score** of the chosen intervals is defined as the total sum of their weights.

Return the **lexicographically smallest** array of at most 4 indices from `intervals` with **maximum score**, representing your choice of non-overlapping intervals.

> **Note:**
> - Two intervals are said to be **non-overlapping** if they do not share any points. In particular, intervals sharing a left or right boundary (i.e. $r_A = l_B$) are considered **overlapping**.
> - An array of indices $A$ is lexicographically smaller than $B$ if at the first position where they differ, $A[i] < B[i]$, or if $A$ is a proper prefix of $B$.

---

## 📌 Examples

**Example 1:**

```text
Input: intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]]
Output: [2,3]
Explanation:
You can choose the intervals with indices 2, and 3 with respective weights of 5, and 3. Total score = 5 + 3 = 8.
```

**Example 2:**

```text
Input: intervals = [[5,8,1],[6,7,7],[4,7,3],[9,10,6],[7,8,2],[11,14,3],[3,5,5]]
Output: [1,3,5,6]
Explanation:
You can choose the intervals with indices 1, 3, 5, and 6 with respective weights of 7, 6, 3, and 5. Total score = 7 + 6 + 3 + 5 = 21.
```

---

## 📐 Constraints

- $1 \le \text{intervals.length} \le 5 \times 10^4$
- $\text{intervals}[i].\text{length} == 3$
- $\text{intervals}[i] = [l_i, r_i, \text{weight}_i]$
- $1 \le l_i \le r_i \le 10^9$
- $1 \le \text{weight}_i \le 10^9$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(N \log N)$ |
| **Auxiliary Space** | $\mathcal{O}(N)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../227_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../229_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
