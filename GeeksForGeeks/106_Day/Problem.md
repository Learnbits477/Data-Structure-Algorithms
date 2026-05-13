# [Mother Vertex](https://www.geeksforgeeks.org/problems/mother-vertex/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 47.64%](https://img.shields.io/badge/Accuracy-47.64%25-red?style=for-the-badge)
![Submissions: 88K+](https://img.shields.io/badge/Submissions-88K%2B-lightgrey?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)
![Avg Time: 15m](https://img.shields.io/badge/Avg%20Time-15m-informational?style=for-the-badge)
![Topic: Graph](https://img.shields.io/badge/Topic-Graph-blue?style=for-the-badge)
![Topic: Data Structures](https://img.shields.io/badge/Topic-Data%20Structures-blueviolet?style=for-the-badge)

---

## 🧩 Problem Description

Given a directed graph with **V** vertices labeled from `0` to `V-1` and a list of edges `edges[][]`,  
where each edge is represented as `[u, v]` indicating a directed edge from vertex `u` to vertex `v`,  
find a **Mother Vertex** of the graph.

A **Mother Vertex** is a vertex from which **all other vertices can be reached**.

- If **multiple** such vertices exist, return the one with the **smallest value**.
- If **no** such vertex exists, return `-1`.

---

## 📌 Examples

### Example 1

```
Input:
  V = 5
  edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]

Output: 0

Explanation:
  Vertices 0, 1, and 2 can each reach all other vertices in the graph.
  Among them, 0 is the smallest, so the output is 0.
```

### Example 2

```
Input:
  V = 3
  edges[][] = [[0, 1], [2, 1]]

Output: -1

Explanation:
  No vertex can reach all other vertices in the graph.
  Hence, there is no Mother Vertex, and the output is -1.
```

---

## 📐 Constraints

$$1 \leq V \leq 10^5$$

$$1 \leq \texttt{edges}[i][0],\ \texttt{edges}[i][1] \leq V - 1$$

---

## ⏱️ Expected Complexities

| Metric          | Complexity   |
|-----------------|--------------|
| Time Complexity | $O(V + E)$   |
| Auxiliary Space | $O(V)$       |

---

## 🏷️ Topic Tags

`Graph` &nbsp; `DFS` &nbsp; `Kosaraju's Algorithm` &nbsp; `Strongly Connected Components`

---
<div align="center">
Happy Coding! 🚀 <br>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Twitter%20%2F%20X-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
</div>
