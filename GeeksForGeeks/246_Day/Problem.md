# 246. [Ways to Reach Origin](https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 53.93%](https://img.shields.io/badge/Accuracy-53.93%25-orange?style=for-the-badge)
![Submissions: 57K+](https://img.shields.io/badge/Submissions-57K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Matrix](https://img.shields.io/badge/Matrix-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Grid Path Combinatorics & Dynamic Programming:**
> 1. **Directional Constraints**:
>    From $(x, y)$, any valid move reduces either the $x$-coordinate by $1$ (move left) or the $y$-coordinate by $1$ (move down). No upward or rightward moves are permitted.
> 2. **Invariant Move Count**:
>    To reach the origin $(0, 0)$ from $(x, y)$, Geek must make exactly $x$ leftward moves and $y$ downward moves. Thus, every path consists of exactly $x + y$ steps.
> 3. **Combinatorial Equivalence**:
>    The number of unique paths is equivalent to choosing $x$ positions for the leftward moves out of $x + y$ total steps:
>    $$\text{Ways} = \binom{x + y}{x} = \binom{x + y}{y} = \frac{(x + y)!}{x! \, y!}$$
> 4. **Dynamic Programming Recurrence**:
>    Defining $dp[i][j]$ as the number of paths from $(i, j)$ to $(0, 0)$:
>    - Base cases: $dp[0][j] = 1$ and $dp[i][0] = 1$ for all $i, j \ge 0$.
>    - Recurrence: $dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) \pmod{10^9 + 7}$.

---

## 🧩 Problem Description

Geek is standing at a point $(x, y)$ on a 2D grid and wants to reach the origin $(0, 0)$.

From any point, Geek can move in only two directions:
1. **Left:** from $(x, y)$ to $(x - 1, y)$
2. **Down:** from $(x, y)$ to $(x, y - 1)$

Find the total number of distinct paths for Geek to reach $(0, 0)$ from $(x, y)$. Since the answer can be very large, return it modulo $10^9 + 7$.

---

## 📌 Examples

**Example 1:**

```text
Input: x = 3, y = 0
Output: 1
Explanation:
The only possible path is (3, 0) -> (2, 0) -> (1, 0) -> (0, 0).
Since y = 0, there is no option to move down at any step.
```

**Example 2:**

```text
Input: x = 3, y = 6
Output: 84
Explanation:
There are a total of 84 distinct paths from (3, 6) to (0, 0) using only left and down moves.
```

---

## 📐 Constraints

- $0 \le x, y \le 500$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(x \cdot y)$ |
| **Auxiliary Space** | $\mathcal{O}(x \cdot y)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../245_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../247_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
