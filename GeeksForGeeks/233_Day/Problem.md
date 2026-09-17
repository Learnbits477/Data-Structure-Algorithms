# 233. [Min Edge Reversals for Path](https://www.geeksforgeeks.org/problems/minimum-edges/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 46.93%](https://img.shields.io/badge/Accuracy-46.93%25-orange?style=for-the-badge)
![Submissions: 7K+](https://img.shields.io/badge/Submissions-7K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: Graph](https://img.shields.io/badge/Topic-Graph-blue?style=for-the-badge)
![Topic: Deque](https://img.shields.io/badge/Deque-blue?style=for-the-badge)
![Topic: Shortest Path](https://img.shields.io/badge/Shortest%20Path-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given a directed graph with $n$ vertices numbered from $1$ to $n$. The graph is represented using a 2D array `edges[][]` of size $m$, where each entry $\text{edges}[i] = [u, v]$ denotes a directed edge from vertex $u$ to vertex $v$. You are also given a source vertex `src` and a destination vertex `dst`.

Find the minimum number of edges that need to be reversed so that there exists at least one directed path from `src` to `dst`.

If it is not possible to create a path from `src` to `dst` even after reversing edges, return $-1$.

---

## 📌 Examples

**Example 1:**

```text
Input: n = 3, edges[][] = [[1, 2], [3, 2]], src = 1, dst = 3
Output: 1
Explanation:
Reverse the edge 3 -> 2 so that it becomes 2 -> 3.
Now, a path exists from 1 to 3: 1 -> 2 -> 3.
The minimum number of edge reversals required is 1.
```

**Example 2:**

```text
Input: n = 4, edges[][] = [[1, 2], [2, 3], [3, 4]], src = 1, dst = 4
Output: 0
Explanation:
A direct path already exists from 1 to 4: 1 -> 2 -> 3 -> 4.
No edge reversals are needed.
```

---

## 📐 Constraints

- $1 \le n, m \le 10^5$
- $1 \le \text{edges}[i][0], \text{edges}[i][1] \le n$
- $1 \le \text{src}, \text{dst} \le n$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n + m)$ |
| **Auxiliary Space** | $\mathcal{O}(n + m)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../232_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../234_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
