# 245. [Steps by Knight](https://www.geeksforgeeks.org/problems/steps-by-knight5927/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 37.32%](https://img.shields.io/badge/Accuracy-37.32%25-orange?style=for-the-badge)
![Submissions: 140K+](https://img.shields.io/badge/Submissions-140K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Company: Flipkart](https://img.shields.io/badge/Companies:-Flipkart-red?style=for-the-badge)
![Company: Amazon](https://img.shields.io/badge/Amazon-red?style=for-the-badge)
![Company: Microsoft](https://img.shields.io/badge/Microsoft-red?style=for-the-badge)
![Company: Goldman Sachs](https://img.shields.io/badge/Goldman%20Sachs-red?style=for-the-badge)
![Topic: Graph](https://img.shields.io/badge/Topic-Graph-blue?style=for-the-badge)
![Topic: BFS](https://img.shields.io/badge/BFS-blue?style=for-the-badge)
![Topic: Queue](https://img.shields.io/badge/Queue-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Breadth-First Search (BFS) on Unweighted Grid Graphs:**
> 1. **Shortest Path in Unweighted Graph**:
>    Every legal move made by a Knight has an equal edge weight of $1$. In any graph with uniform edge weights, **Breadth-First Search (BFS)** is mathematically proven to discover the shortest path to every node first.
> 2. **State Space Representation**:
>    The $n \times n$ chessboard represents an implicit undirected graph with $V = n^2$ vertices (cells) and up to $8 \cdot n^2$ edges.
> 3. **Level-Order Expansion**:
>    By expanding level-by-level (where level $k$ contains all chessboard cells reachable in exactly $k$ knight moves), the first time the target cell $(x_t, y_t)$ is generated or popped, the current level count is strictly the minimum possible steps.
> 4. **Pruning & Visited Tracking**:
>    To avoid redundant cycles and infinite loops, a 2D boolean array `visited[n + 1][n + 1]` ensures each cell enters the BFS queue at most once.

---

---

## 🧩 Problem Description

Given a square chessboard of size $n \times n$, the initial position `knightPos` and target position `targetPos` of a Knight are given. Find the minimum number of moves required for the Knight to reach `targetPos`. If the knight cannot reach the target, return $-1$.

A Knight moves in an L-shape, covering 2 cells in one direction and 1 cell perpendicular to it. From $(x, y)$, it can move to:
$$(x \pm 2, y \pm 1) \quad \text{and} \quad (x \pm 1, y \pm 2)$$

This gives at most $8$ possible moves from any position:
1. $(x + 2, y + 1)$
2. $(x + 2, y - 1)$
3. $(x - 2, y + 1)$
4. $(x - 2, y - 1)$
5. $(x + 1, y + 2)$
6. $(x + 1, y - 2)$
7. $(x - 1, y + 2)$
8. $(x - 1, y - 2)$

> **Note:** The positions are given using **1-based indexing**.

---

## 📌 Examples

**Example 1:**

```text
Input: n = 3, knightPos[] = [3, 3], targetPos[] = [1, 2]
Output: 1
Explanation:
Knight takes 1 step to reach from (3, 3) to (1, 2) via move (-2, -1).
```

**Example 2:**

```text
Input: n = 6, knightPos[] = [1, 3], targetPos[] = [5, 1]
Output: 2
Explanation:
Knight takes 2 steps to reach from (1, 3) to (5, 1):
Step 1: (1, 3) -> (3, 2)
Step 2: (3, 2) -> (5, 1)
```

---

## 📐 Constraints

- $1 \le n \le 1000$
- $2 \le \text{knightPos.size}(), \text{targetPos.size}() \le 2$
- $1 \le \text{knightPos}[i], \text{targetPos}[i] \le n$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n^2)$ |
| **Auxiliary Space** | $\mathcal{O}(n^2)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../244_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../246_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
