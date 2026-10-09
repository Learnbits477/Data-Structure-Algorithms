# 255. [Minimum Operations to Reach n](https://www.geeksforgeeks.org/problems/find-optimum-operation4504/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 60.02%](https://img.shields.io/badge/Accuracy-60.02%25-orange?style=for-the-badge)
![Submissions: 109K+](https://img.shields.io/badge/Submissions-109K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)
![Topic: Bit Manipulation](https://img.shields.io/badge/Bit%20Manipulation-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Reverse Engineering & Greedy Halving:**
> 1. **Work Backwards from $n$ to $0$**:
>    Moving forward from $0$ to $n$, at any value we could either double or add $1$, creating a branching search tree. Working backwards from $n$ to $0$, the optimal decision at each step is completely deterministic!
> 2. **Optimal Local Choice**:
>    - If $n$ is **even**, dividing by $2$ ($n \to n / 2$) halves the magnitude in a single move. This drastically shrinks the distance to $0$ compared to subtracting $1$.
>    - If $n$ is **odd**, $n$ could not have resulted from doubling, so the only valid preceding operation was adding $1$. Thus, we must subtract $1$ ($n \to n - 1$).
> 3. **Logarithmic Bound**:
>    Because every odd step is immediately followed by an even step (which halves $n$), $n$ is halved at least every 2 operations, guaranteeing termination in $\mathcal{O}(\log n)$ steps.

---

## 🧩 Problem Description

Given a number `n`. Find the minimum number of operations required to reach `n` starting from `0`.

You have two operations available:
1. **Double the number** (`x = 2 * x`)
2. **Add one to the number** (`x = x + 1`)

---

## 📌 Examples

**Example 1:**

```text
Input: n = 8
Output: 4
Explanation:
0 + 1 = 1 --> 1 + 1 = 2 --> 2 * 2 = 4 --> 4 * 2 = 8.
Total operations: 4.
```

**Example 2:**

```text
Input: n = 7
Output: 5
Explanation:
0 + 1 = 1 --> 1 + 1 = 2 --> 1 + 2 = 3 --> 3 * 2 = 6 --> 6 + 1 = 7.
Total operations: 5.
```

**Example 3:**

```text
Input: n = 1
Output: 1
Explanation:
0 + 1 = 1.
Total operations: 1.
```

---

## 📐 Constraints

- $1 \le n \le 10^6$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(\log n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

*Where $n$ represents the target number. Since $n$ is halved on every even number, the total loop iterations are bounded by $2 \times \lfloor\log_2 n\rfloor + 1$.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../254_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../256_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
