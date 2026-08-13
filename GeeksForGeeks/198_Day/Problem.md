# [Longest Path in a Directed Acyclic Graph](https://www.geeksforgeeks.org/problems/longest-path-in-a-directed-acyclic-graph/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 50.21%](https://img.shields.io/badge/Accuracy-50.21%25-blue?style=for-the-badge)
![Topic: Graph](https://img.shields.io/badge/Topics:-Graph-Dynamic%20Programmingblue?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given a weighted Directed Acyclic Graph (DAG) with $V$ vertices numbered from $0$ to $V - 1$, represented by an adjacency list or an edge list `edges[][]`, where `edges[i] = [u, v, w]` denotes a directed edge from $u$ to $v$ with weight $w$, and a source vertex `src`.

Return the distance array, where the value at index $i$ represents the longest distance from `src` to vertex $i$.
If a vertex is unreachable from `src`, store `INT_MIN` for that vertex. The driver code will automatically display `INT_MIN` as `INF`.

---

## 📌 Examples

### Example 1
**Input:**
```text
V = 4, src = 0
edges[][] = [[0, 1, 1], [0, 2, 1], [1, 2, 5], [3, 1, 2], [3, 2, -1]]
```
**Output:**
```text
[0, 1, 6, INF]
```
**Explanation:**
- The longest distance of vertex $1$ from $0$ is $1$ (via edge $0 \to 1$ with weight $1$).
- The longest distance of vertex $2$ from $0$ is $6$ (via path $0 \to 1 \to 2$ with weight $1 + 5 = 6$).
- Vertex $3$ is unreachable from $0$, so its distance is `INF`.

### Example 2
**Input:**
```text
V = 5, src = 1
edges[][] = [[0, 1, 1], [0, 2, 2], [1, 4, 4], [3, 2, -1], [4, 2, 3], [4, 3, 6]]
```
**Output:**
```text
[INF, 0, 9, 10, 4]
```
**Explanation:**
- Vertex $0$ is not reachable from vertex $1$, so its distance is `INF`.
- Vertex $1$ is the source, so its distance is $0$.
- Path to $4$: $1 \to 4$ (weight $4$).
- Path to $2$: $1 \to 4 \to 2$ (weight $4 + 3 = 7$) or $1 \to 4 \to 3 \to 2$ (not possible since $3 \to 2$ is directed). Wait, $1 \to 4 \to 2$ is weight $7$. Wait! Is there another path? Let's check: $1 \to 4 \to 3 \to 2$? No, the edges are $4 \to 3$ (weight 6) and $3 \to 2$ (weight -1). Let's see: $1 \to 4 \to 3$ is weight $4 + 6 = 10$, then $3 \to 2$ is weight $-1$. So path $1 \to 4 \to 3 \to 2$ has weight $4 + 6 + (-1) = 9$. Thus, the longest distance to $2$ is $9$.
- Path to $3$: $1 \to 4 \to 3$ (weight $4 + 6 = 10$).

---

## 📐 Constraints

- $1 \le V \le 10^3$
- $1 \le \text{edges.size()} \le \frac{V \times (V - 1)}{2}$
- $0 \le \text{edges}[i][0], \text{edges}[i][1] < V$
- $-100 \le \text{edges}[i][2] \le 100$

---

## ⏱️ Expected Complexities

| Time Complexity | Auxiliary Space |
| :-------------: | :-------------: |
| $O(V + E)$      | $O(V)$          |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../197_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../199_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
