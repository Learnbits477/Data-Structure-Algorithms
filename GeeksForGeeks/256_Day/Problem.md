# 256. [Balancing with Distinct Powers](https://www.geeksforgeeks.org/problems/balancing-pan5038/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 59.79%](https://img.shields.io/badge/Accuracy-59.79%25-orange?style=for-the-badge)
![Submissions: 3K+](https://img.shields.io/badge/Submissions-3K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topic: Mathematics](https://img.shields.io/badge/Topic-Mathematics-blue?style=for-the-badge)
![Topic: Number Theory](https://img.shields.io/badge/Number%20Theory-blue?style=for-the-badge)
![Topic: Balanced Base](https://img.shields.io/badge/Balanced%20Base-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Balanced Base-$a$ Representation:**
> 1. **Pan Equation as Balanced Base System**:
>    The weighing equation $b + \sum_{i \in S_1} a^i = \sum_{j \in S_2} a^j$ with disjoint subsets $S_1 \cap S_2 = \emptyset$ is equivalent to expressing $b$ in a balanced base-$a$ number system:
>    $$b = \sum_{k=0}^{M} c_k a^k \quad \text{where } c_k \in \{-1, 0, 1\}$$
> 2. **Modular Invariant at Each Power**:
>    At each power step $k$, taking modulo $a$ isolates coefficient $c_k$:
>    - If $b \pmod a == 0 \implies c_k = 0$: no weight of power $a^k$ is placed on either pan. We advance $b \leftarrow b / a$.
>    - If $b \pmod a == 1 \implies c_k = 1$: weight $a^k$ is placed on the opposite pan. We advance $b \leftarrow (b - 1) / a$.
>    - If $b \pmod a == a - 1 \implies c_k = -1$: weight $a^k$ is placed on $b$'s pan ($a - 1 \equiv -1 \pmod a$). We advance $b \leftarrow (b + 1) / a$.
>    - If $b \pmod a$ is any other remainder: it is mathematically impossible to balance using a single weight of power $a^k$, so we return `false`.
> 3. **Binary Base Invariant**:
>    For $a = 2$, any positive integer has a unique representation in standard binary using digits $0$ and $1$ (no weights needed on $b$'s pan), guaranteeing that $a = 2$ is always balanceable (`true`).

---

## 🧩 Problem Description

Given a simple weighing scale with two pans, a target weight $b$, and a set of weights where each weight is a distinct power of $a$, find if the scale can be balanced such that:

$$b + (\text{some powers of } a) = (\text{some other powers of } a)$$

> **Note**: Exactly one weight is available for each power of $a$ (i.e., $a^0, a^1, a^2, \dots$), so each power can be used at most once.

---

## 📌 Examples

**Example 1:**

```text
Input: a = 4, b = 11
Output: true
Explanation:
11 + 4 + 1 = 16.
Here, weights 4^1 (4) and 4^0 (1) are placed on the pan with target 11, balancing against 4^2 (16) on the opposite pan.
So, target = 11 can be balanced using powers of 4.
```

**Example 2:**

```text
Input: a = 3, b = 5
Output: true
Explanation:
5 + 3 + 1 = 9.
Weights 3^1 (3) and 3^0 (1) are placed with 5, balancing against 3^2 (9).
So, target = 5 can be balanced using powers of 3.
```

---

## 📐 Constraints

- $2 \le a \le 10^9$
- $1 \le b \le 10^9$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(\log_a b)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

*Where $b$ is the target weight and $a$ is the power base. At each iteration, $b$ is divided by $a$, shrinking exponentially to $0$.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../255_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../257_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
