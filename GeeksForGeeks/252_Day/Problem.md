# 252. [Longest Increasing Path in Matrix](https://www.geeksforgeeks.org/problems/longest-increasing-path-in-a-matrix/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 44.5%](https://img.shields.io/badge/Accuracy-44.5%25-orange?style=for-the-badge)
![Submissions: 18K+](https://img.shields.io/badge/Submissions-18K%2B-blue?style=for-the-badge)
![Points: 8](https://img.shields.io/badge/Points-8-orange?style=for-the-badge)
![Company: D-E-Shaw](https://img.shields.io/badge/Company-D--E--Shaw-red?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Matrix](https://img.shields.io/badge/Matrix-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Directed Acyclic Graph (DAG) & Memoized DFS:**
> 1. **Implicit DAG Formulation**:
>    Because every step in a valid path requires moving to a strictly greater value ($a_i > a_{i-1}$), no sequence of moves can ever loop back to a previously visited cell. Thus, the grid forms a Directed Acyclic Graph (DAG) with cells as vertices and valid ascending moves as directed edges.
> 2. **Optimal Substructure**:
>    The longest increasing path starting from cell $(i, j)$ is simply $1$ plus the maximum longest increasing path among all valid strictly larger 4-directional neighbors.
> 3. **Memoization Eliminates Redundancy**:
>    Computing each cell's maximum path once and storing it in a 2D lookup table ensures that every cell and directed edge is processed at most once, reducing exponential exploration to strictly linear $\mathcal{O}(n \times m)$ complexity.

---

## 🧩 Problem Description

Given a matrix with $n$ rows and $m$ columns. Your task is to find the length of the longest path in with the following constraints:
1. The values in path are strictly increasing. For example, if a path of length $k$ has values $a_1, a_2, a_3, \dots, a_k$, then for every $i \in [2, k]$, the condition $a_i > a_{i-1}$ must hold.
2. No cell should be revisited in the path.
3. From each cell, you can move in any of the four directions: left, right, up, or down.
4. You are not allowed to move diagonally or move outside the boundary.

---

## 📌 Examples

**Example 1:**

```text
Input: n = 3, m = 3, matrix[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: 5
Explanation: One such path is 1 -> 2 -> 3 -> 6 -> 9, where each number is strictly greater than the previous.
Another valid maximum path is 1 -> 4 -> 7 -> 8 -> 9 of length 5.
```

**Example 2:**

```text
Input: n = 3, m = 3, matrix[][] = [[3, 4, 5], [6, 2, 6], [2, 2, 1]]
Output: 4
Explanation: One of the longest increasing paths is 3 -> 4 -> 5 -> 6 of length 4.
```

---

## 📐 Constraints

- $1 \le n, m \le 1000$
- $0 \le \text{matrix}[i][j] \le 2^{30}$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \times m)$ |
| **Auxiliary Space** | $\mathcal{O}(n \times m)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../251_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../253_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
