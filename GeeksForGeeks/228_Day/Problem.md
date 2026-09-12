# 228. [Max Product Subsequence of Size K](https://www.geeksforgeeks.org/problems/maximum-product4633/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 22.49%](https://img.shields.io/badge/Accuracy-22.49%25-orange?style=for-the-badge)
![Submissions: 4K+](https://img.shields.io/badge/Submissions-4K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an array `arr[]` of integers and an integer `k`, find a subsequence of size `k` whose product is maximum among all possible subsequences of size `k`. 

Return the **maximum product** that can be obtained.

---

## 📌 Examples

**Example 1:**

```text
Input: arr[] = [1, 2, 0, 3], k = 2
Output: 6
Explanation: Subsequence containing elements {2, 3} gives maximum product: 2 * 3 = 6.
```

**Example 2:**

```text
Input: arr[] = [1, 2, -1, -3, -6, 4], k = 4
Output: 144
Explanation: Subsequence containing {2, -3, -6, 4} gives maximum product: 2 * (-3) * (-6) * 4 = 144.
```

**Example 3:**

```text
Input: arr[] = [-5, -4, -3, -2, -1], k = 3
Output: -6
Explanation: All elements are negative and k is odd. The maximum product is obtained by choosing the 3 largest numbers: (-3) * (-2) * (-1) = -6.
```

---

## 📐 Constraints

- $1 \le \text{arr.size()} \le 30$
- $-10 \le \text{arr}[i] \le 10$
- $1 \le k \le \text{arr.size()}$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \log n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

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
