# 265. [Count Indices That Escape Array](https://www.geeksforgeeks.org/problems/good-stones--170647/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 53.74%](https://img.shields.io/badge/Accuracy-53.74%25-orange?style=for-the-badge)
![Submissions: 26K+](https://img.shields.io/badge/Submissions-26K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Graph](https://img.shields.io/badge/Graph-blue?style=for-the-badge)
![Topic: DFS](https://img.shields.io/badge/DFS-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Functional Graph Traversal & 3-State Cycle Memoization:**
> 1. **Functional Graph Properties**:
>    Each index $i$ in the array has exactly one deterministic outgoing jump directed toward vertex $j = i + arr[i]$. Thus, the system forms a directed **functional graph** (out-degree $\le 1$ per vertex).
> 2. **Bipartition of Outcomes**:
>    Every connected component in a functional graph consists of directed trees rooted either in a **directed cycle** (infinite trap) or pointing toward a boundary transition outside $[0, n - 1]$ (**escape**).
> 3. **Tri-State DFS Memoization**:
>    By maintaining three explicit states: `0 = Unvisited`, `1 = Visiting (active in current DFS stack)`, and `2 = Good / 3 = Bad`, we can detect cycles in $\mathcal{O}(1)$ upon encountering an active `Visiting` node, memoize terminal states, and classify every index in strictly linear time $\mathcal{O}(n)$.

---

## 🧩 Problem Description

Given an array `arr[]`, where `arr[i]` represents the exact number of steps to move from index $i$.

An index is considered **good** if repeatedly following the jumps eventually takes you outside the array (i.e., $< 0$ or $\ge n$). Otherwise, if the jumps result in an infinite loop, the index is considered **bad**.

- A **positive** value indicates a move to the right ($i + arr[i]$).
- A **negative** value indicates a move to the left ($i + arr[i]$).
- A **$0$ value** means no move and is considered **bad** (self-loop).

Return the **total number of good indices**.

---

## 📌 Examples

**Example 1:**

```text
Input: arr = [2, 3, -1, 2, -2, 4, 1]
Output: 3
Explanation:
- Index 3: 3 -> 5 -> 9 (outside bounds). Escapes! (Good)
- Index 5: 5 -> 9 (outside bounds). Escapes! (Good)
- Index 6: 6 -> 7 (outside bounds). Escapes! (Good)
- Indices 1, 2, and 4 form a cycle: 1 -> 4 -> 2 -> 1 ...
- Index 0 jumps to 2 (0 -> 2) and enters this cycle.
Hence, the total number of good indices is 3.
```

**Example 2:**

```text
Input: arr = [1, 0, -3, 0, -5, 0]
Output: 2
Explanation:
- Index 2: 2 + (-3) = -1 (outside bounds). Escapes! (Good)
- Index 4: 4 + (-5) = -1 (outside bounds). Escapes! (Good)
- Indices 1, 3, and 5 have value 0 (dead-end traps).
- Index 0 jumps to 1, which has value 0.
Hence, the total number of good indices is 2.
```

---

## 📐 Constraints

- $1 \le arr.size() \le 10^5$
- $-10^5 \le arr[i] \le 10^5$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

*Each index is visited and evaluated at most a constant number of times during the DFS traversal. The auxiliary space accounts for the state memoization table and recursion call stack.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../264_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../266_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
