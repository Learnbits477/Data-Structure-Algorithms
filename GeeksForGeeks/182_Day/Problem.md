# [182. Shortest Path in 1-2 Graph](https://www.geeksforgeeks.org/problems/level-of-nodes1147/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 67.23%](https://img.shields.io/badge/Accuracy-67.23%25-blue?style=for-the-badge)
![Submissions: 6K+](https://img.shields.io/badge/Submissions-6K%2B-purple?style=for-the-badge)
![Topic: Graph](https://img.shields.io/badge/Graph-blue?style=for-the-badge)
![Topic: BFS](https://img.shields.io/badge/BFS-brightgreen?style=for-the-badge)

---

## 🧩 Problem Description

Given a weighted undirected graph with $V$ vertices numbered from $0$ to $V - 1$, represented by an array `edges`, where `edges[i] = [ui, vi, wi]` indicates that there is an edge between vertices $u_i$ and $v_i$ with a weight of $w_i$. (Note: $w_i$ can only be $1$ or $2$), and two vertices `src` and `dest`, find the shortest distance from `src` to `dest`.

The shortest distance is defined as the minimum total weight required to reach `dest` starting from `src`.

Return the shortest distance from `src` to `dest`. If `dest` is not reachable from `src`, return $-1$.

---

## 📌 Examples

**Example 1:**
- **Input:** $V = 4$, `edges[][]` = `[[0, 1, 1], [0, 2, 2], [2, 3, 1], [1, 2, 1], [1, 3, 2]]`, `src = 0`, `dest = 3`
- **Output:** `3`
- **Explanation:** 
  One of the shortest paths from vertex $0$ to vertex $3$ is $0 \rightarrow 1 \rightarrow 3$ with a total weight of $1 + 2 = 3$.
  Another shortest path is $0 \rightarrow 2 \rightarrow 3$ with a total weight of $2 + 1 = 3$.
  Hence, the shortest distance from $0$ to $3$ is $3$.

**Example 2:**
- **Input:** $V = 5$, `edges[][]` = `[[0, 1, 1], [0, 2, 2], [1, 2, 1], [3, 4, 2]]`, `src = 1`, `dest = 3`
- **Output:** `-1`
- **Explanation:** 
  There is no path from vertex $1$ to vertex $3$, so the answer is $-1$.

**Example 3:**
- **Input:** $V = 5$, `edges[][]` = `[[1, 0, 1], [0, 3, 2], [1, 3, 1], [1, 2, 2], [2, 3, 2], [3, 4, 1], [2, 4, 1]]`, `src = 1`, `dest = 4`
- **Output:** `2`
- **Explanation:** 
  The shortest path from vertex $1$ to vertex $4$ is $1 \rightarrow 3 \rightarrow 4$ with a total weight of $1 + 1 = 2$.
  Hence, the shortest distance from $1$ to $4$ is $2$.

---

## 📐 Constraints

- $2 \le V \le 10^5$
- $1 \le edges.size() \le \min(2 \cdot 10^5, \frac{V \cdot (V - 1)}{2})$
- $0 \le edges[i][0], edges[i][1] \le V - 1$
- $edges[i][0] \ne edges[i][1]$
- $1 \le edges[i][2] \le 2$ *(Note: The platform description contains a minor typo citing `edges[i][1] <= 2`)*

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(V + E)$ |
| **Auxiliary Space** | $O(V)$ |

---

## 🏷️ Topic Tags

- Graph
- BFS
- Shortest Path
- Dial's Algorithm

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../181_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../183_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
