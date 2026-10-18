# 264. [Shortest Path From 1 To n](https://www.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 37.62%](https://img.shields.io/badge/Accuracy-37.62%25-orange?style=for-the-badge)
![Submissions: 94K+](https://img.shields.io/badge/Submissions-94K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topic: Mathematics](https://img.shields.io/badge/Mathematics-blue?style=for-the-badge)
![Topic: Graph](https://img.shields.io/badge/Graph-blue?style=for-the-badge)
![Topic: Shortest Path](https://img.shields.io/badge/Shortest%20Path-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)

---

## 🏢 Company Tags

![Morgan Stanley](https://img.shields.io/badge/Morgan%20Stanley-002D62?style=for-the-badge&logo=morgan-stanley&logoColor=white)
![Samsung](https://img.shields.io/badge/Samsung-1428A0?style=for-the-badge&logo=samsung&logoColor=white)
![Cisco](https://img.shields.io/badge/Cisco-1BA0D7?style=for-the-badge&logo=cisco&logoColor=white)
![Accolite](https://img.shields.io/badge/Accolite-F34F1D?style=for-the-badge)
![Synopsys](https://img.shields.io/badge/Synopsys-6A2569?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Reverse Greedy Transformation ($n \to 1$):**
> 1. **Inverting the State Space**:
>    Searching forward from $1 \to n$ involves exponential branching (every node $u$ branches into $u + 1$ and $3u$). Inverting the problem to search backward from $n \to 1$ transforms the branching into deterministic, greedy decisions: either divide by $3$ (if divisible) or decrement by $1$.
> 2. **Strict Dominance of Division**:
>    Suppose $n$ is divisible by $3$, say $n = 3k$. Dividing by $3$ takes $1$ step to reach $k$. If we instead choose decrement, reaching $k$ requires $3k \to 3k - 1 \to 3k - 2 \to 3(k - 1) \to k - 1$ ($4$ steps). Since $k < 3k - 1$ for all $k \ge 1$, dividing by $3$ whenever possible is strictly optimal.
> 3. **Logarithmic Convergence**:
>    Because $n$ is reduced by a factor of $3$ at least once every three steps, the total number of operations is bounded by $3 \log_3(n) = \mathcal{O}(\log n)$, executing in fewer than $55$ iterations even for $n = 10^8$.

---

## 🧩 Problem Description

Consider a directed graph whose vertices are numbered from $1$ to $n$. There is an edge from a vertex $i$ to a vertex $j$ if and only if either:
- $j = i + 1$
- $j = 3 \times i$

The task is to find the **minimum number of edges** in a path from vertex $1$ to vertex $n$.

---

## 📌 Examples

**Example 1:**

```text
Input: n = 4
Output: 2
Explanation:
Possible paths from 1 to 4 are:
1 -> 2 -> 3 -> 4 (length 3)
1 -> 3 -> 4 (length 2)
The second path of length 2 is the shortest.
```

**Example 2:**

```text
Input: n = 9
Output: 2
Explanation:
Many paths are possible from 1 to 9.
The shortest one possible is:
1 -> 3 -> 9 (length 2).
```

**Example 3:**

```text
Input: n = 15
Output: 4
Explanation:
The shortest path from 1 to 15 is:
1 -> 3 -> 4 -> 5 -> 15 (length 4).
```

---

## 📐 Constraints

- $1 \le n \le 10^8$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(\log n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

*Traversing in reverse from $n$ to $1$ divides $n$ by $3$ in $\mathcal{O}(\log_3 n)$ steps with at most two decrements between successive divisions. No additional memory is allocated.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../263_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../265_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
