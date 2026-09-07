# 223. [Minimum Elements Outside Subsequences](https://www.geeksforgeeks.org/problems/minimum-number-of-elements-which-are-not-part-of-increasing-or-decreasing-subsequence2617/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 51.06%](https://img.shields.io/badge/Accuracy-51.06%25-orange?style=for-the-badge)
![Submissions: 3K+](https://img.shields.io/badge/Submissions-3K%2B-blue?style=for-the-badge)
![Points: 8](https://img.shields.io/badge/Points-8-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Dynamic%20Programming%20%7C%20Arrays-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an array `arr[]` of size `n`, partition its elements into a strictly increasing subsequence and a strictly decreasing subsequence. 

Each element can belong to at most one of these subsequences, and some elements may remain unused.

Determine the **minimum number of elements** that cannot be included in either subsequence.

---

## 📌 Examples

**Example 1:**
```text
Input: arr = [7, 8, 1, 2, 4, 6, 3, 5, 2, 1, 8, 7]
Output: 2
Explanation: 
One possible increasing subsequence is: [1, 2, 4, 5, 8]. 
One possible decreasing subsequence is: [7, 6, 3, 2, 1]. 
The remaining elements are 8 and 7, so the minimum number of unselected elements is 2.
```

**Example 2:**
```text
Input: arr = [1, 4, 2, 3, 3, 2, 4]
Output: 0
Explanation: 
One possible increasing subsequence is: [1, 2, 3, 4]. 
One possible decreasing subsequence is: [4, 3, 2]. 
All elements are included in one of the two subsequences.
```

---

## 📐 Constraints

- $1 \le n \le 100$
- $1 \le \text{arr}[i] \le 100$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n^3)$ |
| **Auxiliary Space** | $\mathcal{O}(n^3)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../222_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../224_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
