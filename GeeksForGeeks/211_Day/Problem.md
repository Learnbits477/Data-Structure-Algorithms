# 211. [Negative Weight Cycle](https://www.geeksforgeeks.org/problems/negative-weight-cycle3504/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 41.9%](https://img.shields.io/badge/Acceptance-41.9%25-green?style=for-the-badge)
![Submissions: 82K+](https://img.shields.io/badge/Submissions-82K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Graph-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Shortest%20Path-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Bellman--Ford-blue?style=for-the-badge)
![Company](https://img.shields.io/badge/Company-Cisco-lightgrey?style=for-the-badge)

---

## 🧩 Problem Description

Given a weighted directed graph containing $V$ vertices numbered from $0$ to $V - 1$ and a list of $E$ directed edges `edges[][]`, determine whether the graph contains a **negative weight cycle** or not.

Each edge is represented as: `[u, v, w]`, where there is a directed edge from vertex $u$ to vertex $v$ having the weight $w$.

> **Note:** A negative-weight cycle is a cycle in a graph whose edge weights sum to a negative value.

---

## 📌 Examples

**Example 1:**
```text
Input: V = 4, E = 4, edges[][] = [[0, 3, 6], [1, 0, 4], [1, 2, 6], [3, 1, 2]]
Output: 0
Explanation: Cycle 1 -> 0 -> 3 -> 1 has total weight 6 + 4 + 2 = 12, which is positive, so no negative weight cycle exists.
```

**Example 2:**
```text
Input: V = 4, E = 4, edges[][] = [[1, 0, 4], [3, 1, -2], [1, 2, -6], [2, 3, 5]]
Output: 1
Explanation: There is a cycle 1 -> 2 -> 3 -> 1 with total weight -6 + 5 + (-2) = -3, which is negative, so a negative weight cycle exists.
```

---

## 📐 Constraints
- $1 \le V \le 10^3$
- $0 \le E \le 10^5$
- $0 \le u, v < V$
- $-10^6 \le w \le 10^6$

---

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(V \times E)$ |
| **Auxiliary Space** | $\mathcal{O}(V)$ |



---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../210_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../212_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
