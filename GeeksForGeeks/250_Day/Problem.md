# 250. [Perimeter of Shapes in Binary Matrix](https://www.geeksforgeeks.org/problems/find-perimeter-of-shapes/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 73.86%](https://img.shields.io/badge/Accuracy-73.86%25-orange?style=for-the-badge)
![Submissions: 6K+](https://img.shields.io/badge/Submissions-6K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topic: Matrix](https://img.shields.io/badge/Topic-Matrix-blue?style=for-the-badge)
![Topic: Geometric](https://img.shields.io/badge/Geometric-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Boundary Edge Counting & Shared Side Cancellation:**
> 1. **Cell Boundary Contribution**:
>    A single square cell of value $1$ has $4$ sides. Each side contributes $1$ unit to the total perimeter if and only if that side is **exposed** — meaning it borders the exterior of the matrix boundary or touches an adjacent $0$ cell.
> 2. **Shared Edge Cancellation**:
>    When two cells containing $1$ are orthogonally adjacent, they share a common side. This single connection eliminates $2$ outer boundary edges ($1$ from each cell).
>    - Total perimeter $= 4 \times (\text{count of 1s}) - 2 \times (\text{count of adjacent 1-1 pairs})$.

---

## 🧩 Problem Description

Given a binary matrix `mat[][]` of size $n \times m$, where each cell contains either $0$ or $1$, find the total perimeter of all figures formed by cells containing $1$s. Two cells are considered adjacent if they share a common side.

A single cell containing $1$ has a perimeter of $4$, whereas two adjacent cells containing $1$ (i.e., `11`) together have a perimeter of $6$.

---

## 📌 Examples

**Example 1:**

```text
Input: mat[][] = [[0, 1, 0, 0, 0], 
                  [1, 1, 1, 0, 0], 
                  [1, 0, 0, 0, 0]]
Output: 12

Explanation:
The five cells containing 1 form a connected shape:
- (0, 1): 3 exposed sides
- (1, 0): 2 exposed sides
- (1, 1): 1 exposed side
- (1, 2): 3 exposed sides
- (2, 0): 3 exposed sides
Total perimeter = 3 + 2 + 1 + 3 + 3 = 12.
```

**Example 2:**

```text
Input: mat[][] = [[1, 0], 
                  [1, 1]]
Output: 8

Explanation:
The three cells containing 1 have 2 shared boundaries:
- (0, 0) and (1, 0) share 1 side
- (1, 0) and (1, 1) share 1 side
Total perimeter = 3 * 4 - 2 * 2 = 12 - 4 = 8.
```

---

## 📐 Constraints

- $1 \le n, m \le 1000$
- $\text{mat}[i][j] \in \{0, 1\}$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \times m)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../249_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../251_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
