# 210. [Minimum Moves to Sort Permutation](https://www.geeksforgeeks.org/problems/morning-assembly3038/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 50.15%](https://img.shields.io/badge/Acceptance-50.15%25-green?style=for-the-badge)
![Submissions: 4K+](https://img.shields.io/badge/Submissions-4K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Hash-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Dynamic%20Programming-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Arrays-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an array `arr[]` containing integers from $1$ to $n$ exactly once (a permutation of $1 \dots n$), sort the array in ascending order.

In one operation, you can pick any element and move it either to the **beginning** or to the **end** of the array.

Return the **minimum number of operations** required to sort the array.

---

## 📌 Examples

**Example 1:**
```text
Input: arr[] = [2, 1, 3]
Output: 1
Explanation: Move 1 to the beginning to get [1, 2, 3].
```

**Example 2:**
```text
Input: arr[] = [4, 3, 1, 2]
Output: 2
Explanation: Move 3 to the end to get [1, 2, 4, 3]. Then move 4 to the end to get [1, 2, 3, 4].
```

---

## 📐 Constraints
- $1 \le \text{arr.size()} \le 10^5$
- $1 \le \text{arr}[i] \le \text{arr.size()}$
- All elements in `arr[]` are distinct (permutation of $1$ to $n$).

---

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

## 🏷️ Topic Tags
- `Hash`
- `Dynamic Programming`
- `Arrays`

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
