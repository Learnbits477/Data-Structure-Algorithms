# [Total Number of Spanning Trees in a Graph](https://www.geeksforgeeks.org/problems/total-number-of-spanning-trees-in-a-graph/1)

<div align="center">

| [Problem.md](./Problem.md) | [Approach.md](./Approach.md) | [Solution.cpp](./Solution.cpp) | [Main.cpp](./Main.cpp) | [Theorem_Logic.md](./Theorem_Logic.md) |
| :--- | :--- | :--- | :--- | :--- |

</div>

---

**Difficulty:** `Hard`  
**Accuracy:** `65.81%`  
**Total Submissions:** `3K+`

---

## Problem Description

Given a connected undirected graph with **n** vertices and **m** edges, where each edge is represented as `edges[i] = [u, v]` indicating an edge between vertices `u` and `v`. Determine the total number of distinct spanning trees that can be formed from the graph.

> [!NOTE]
> A spanning tree is a subgraph of the given graph that includes all **n** vertices, has exactly **n-1** edges, is connected, and contains no cycles. Every connected undirected graph always has at least one spanning tree.

---

## Examples

### Example 1
**Input:**  
`n = 6`, `edges = [[0, 3], [0, 1], [1, 2], [1, 5], [3, 4]]`  
**Output:**  
`1`  
**Explanation:**  
The graph has 6 vertices and 5 edges, and it is connected, so it is already a tree ($m = n-1$). A tree has only one spanning tree, which is the graph itself.

### Example 2
**Input:**  
`n = 3`, `edges = [[0, 1], [0, 2], [1, 2]]`  
**Output:**  
`3`  
**Explanation:**  
There are exactly 3 possible spanning trees for the given graph (formed by removing one edge at a time from the triangle).

### Example 3
**Input:**  
`n = 1`, `edges = []`  
**Output:**  
`1`  
**Explanation:**  
With 1 vertex, a spanning tree needs 0 edges. The graph already satisfies this.

---

## Constraints

- $1 \le n \le 10$
- $n - 1 \le m \le \frac{n \times (n-1)}{2}$
- $0 \le edges[i][0], edges[i][1] \le n-1$

---

<div align="center" style="font-size: x-large; font-weight: bold; color: blue;">

Happy Coding! 🚀

</div>
