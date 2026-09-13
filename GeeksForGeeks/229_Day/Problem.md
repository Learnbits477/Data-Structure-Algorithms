# 229. [Party in Town](https://www.geeksforgeeks.org/problems/party-in-town3951/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 60.32%](https://img.shields.io/badge/Accuracy-60.32%25-orange?style=for-the-badge)
![Submissions: 8K+](https://img.shields.io/badge/Submissions-8K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: DFS](https://img.shields.io/badge/Topic-DFS-blue?style=for-the-badge)
![Topic: Tree](https://img.shields.io/badge/Tree-blue?style=for-the-badge)

---

## 🧩 Problem Description

Geek Town has $n$ houses numbered from $1$ to $n$. Choose a house to host a party such that its distance from its farthest house is as small as possible. Return this **minimum possible distance**.

The houses are connected by $n - 1$ bidirectional roads, forming a **tree**.
The connections are given as an adjacency list `adj`, where `adj[i]` contains all houses directly connected to house $i + 1$.

---

## 📌 Examples

**Example 1:**

```text
Input: adj[][] = [[2], [1, 4, 3], [2], [2]]
Output: 1
Explanation: Party should take place at house number 2. Maximum distance from house number 2 to any house is 1 (to houses 1, 3, and 4).
```

**Example 2:**

```text
Input: adj[][] = [[2], [1, 3], [4, 2], [3]]
Output: 2
Explanation: Party should take place at house number 2 or 3. The minimum maximum distance is 2.
```

---

## 📐 Constraints

- $1 \le n \le 10^5$
- $1 \le \text{adj}[i][j] \le n$
- $\text{adj.size()} = n$
- The graph is a connected, undirected tree with $n - 1$ edges.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---



<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../228_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../230_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
