# [2685. Count the Number of Complete Components](https://leetcode.com/problems/count-the-number-of-complete-components/description/?envType=daily-question&envId=2026-07-11)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 79.0%](https://img.shields.io/badge/Acceptance-79.0%25-blue?style=for-the-badge)
![Submissions: 243.3K](https://img.shields.io/badge/Submissions-243.3K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given an integer $n$. There is an undirected graph with $n$ vertices, numbered from $0$ to $n - 1$. You are given a 2D integer array `edges` where `edges[i] = [ai, bi]` denotes that there exists an undirected edge connecting vertices `ai` and `bi`.

Return the number of **complete connected components** of the graph.

A **connected component** is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be **complete** if there exists an edge between every pair of its vertices.

---

## 📌 Examples

### Example 1
**Input:**
```text
n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
```
**Output:**
```text
3
```
**Explanation:**
All three components of this graph are complete:
- Node 0, 1, and 2 form a complete component of size 3 (all pairs connected).
- Node 3 and 4 form a complete component of size 2 (connected).
- Node 5 is an isolated component of size 1 (complete by definition).

### Example 2
**Input:**
```text
n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
```
**Output:**
```text
1
```
**Explanation:**
- The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices.
- The component containing vertices 3, 4, and 5 is **not** complete since there is no edge between vertices 4 and 5.
- Therefore, the number of complete components is 1.

---

## 📐 Constraints

- $$1 \le n \le 50$$
- $$0 \le edges.length \le \frac{n \times (n - 1)}{2}$$
- $$edges[i].length == 2$$
- $$0 \le ai, bi \le n - 1$$
- $$ai \ne bi$$
- There are no repeated edges.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(V + E)$$ |
| 💾 Auxiliary Space | $$O(V + E)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Depth-First Search](https://img.shields.io/badge/Depth--First%20Search-9B59B6?style=for-the-badge)
![Breadth-First Search](https://img.shields.io/badge/Breadth--First%20Search-3498DB?style=for-the-badge)
![Union-Find](https://img.shields.io/badge/Union--Find-E74C3C?style=for-the-badge)
![Graph Theory](https://img.shields.io/badge/Graph%20Theory-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../164_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../166_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
