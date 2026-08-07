# [193. Connecting the Graph](https://www.geeksforgeeks.org/problems/connecting-the-graph/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 52.79%](https://img.shields.io/badge/Accuracy-52.79%25-blue?style=for-the-badge)
![Submissions: 26K+](https://img.shields.io/badge/Submissions-26K+-purple?style=for-the-badge)
![Topic: Graph Disjoint Set](https://img.shields.io/badge/Topic-Graph%20%26%20Disjoint%20Set-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a graph with $n$ vertices ($0$ to $n-1$) and $m$ edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation.

Find the minimum number of operations that will be required to connect the graph. If it is not possible to connect the graph, return `-1`.

---

## 📌 Examples

**Example 1:**
- **Input:** `n = 4`, `edges[][] = [[0, 1], [0, 2], [1, 2]]`
- **Output:** `1`
- **Explanation:** Remove the edge between vertices 1 and 2 and add it between vertices 1 and 3.

**Example 2:**
- **Input:** `n = 6`, `edges[][] = [[0, 1], [0, 2], [0, 3], [1, 2], [1, 3]]`
- **Output:** `2`
- **Explanation:** Remove edge between (1, 2) and (0, 3) and add edges between (1, 4) and (3, 5).

---

## 📐 Constraints

- $1 \le n \le 10^5$
- $1 \le m \le 10^5$
- $2 \le \text{edges}[i].\text{size}() \le 2$
- $\text{edges}[i][j] < n$
- There are no multi-edges in the graph.

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n + m)$ |
| **Auxiliary Space** | $O(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../192_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../194_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
