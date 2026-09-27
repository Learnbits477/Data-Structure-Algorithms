# 243. [Longest Colored Path](https://www.geeksforgeeks.org/problems/longest-colored-path--151454/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 34.64%](https://img.shields.io/badge/Accuracy-34.64%25-orange?style=for-the-badge)
![Submissions: 2K+](https://img.shields.io/badge/Submissions-2K%2B-blue?style=for-the-badge)
![Points: 8](https://img.shields.io/badge/Points-8-orange?style=for-the-badge)
![Topic: Tree](https://img.shields.io/badge/Topic-Tree-blue?style=for-the-badge)
![Topic: Graph](https://img.shields.io/badge/Graph-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an undirected acyclic graph (tree) with $n$ nodes numbered from $1$ to $n$. Each node is colored either Red (`'R'`) or Blue (`'B'`).

The colors of the nodes are given by a string $s$ of length $n$, where:
- $s[i] = \text{'R'}$ means node $i + 1$ is Red.
- $s[i] = \text{'B'}$ means node $i + 1$ is Blue.

You are also given a list of $n - 1$ edges `edges[][]`, where each `edges[i] = [u, v]` represents an undirected edge between nodes $u$ and $v$.

You can start from any node and traverse along the edges to form a path.

A path is called **valid** if, once you visit a Blue node, you cannot visit any Red node after it on the same path.

In other words, a valid path must have one of the following forms:
1. Only Red nodes ($R^*$), or
2. Only Blue nodes ($B^*$), or
3. Some Red nodes followed by some Blue nodes ($R^+ B^+$).

A path containing a pattern like $\text{Blue} \to \text{Red}$ is invalid.

Find the maximum number of nodes in a valid path.

---

## 📌 Examples

**Example 1:**

```text
Input: s = "RBB", edges = [[1, 2], [1, 3]]
Output: 2
Explanation:
The longest valid path is either 1 -> 2 or 1 -> 3. In both cases, the length of the path is 2 nodes.
```

**Example 2:**

```text
Input: s = "BB", edges = [[1, 2]]
Output: 2
Explanation:
The longest valid path is 1 -> 2 consisting of 2 Blue nodes. The length of the path is 2 nodes.
```

---

## 📐 Constraints

- $1 \le s.\text{size}() \le 10^5$
- $1 \le \text{edges}[i][j] \le s.\text{size}()$
- $s$ consists only of the characters `'R'` and `'B'`
- $\text{edges}.\text{size}() = s.\text{size}() - 1$
- The given edges form an undirected acyclic tree.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../242_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../244_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
