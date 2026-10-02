# [22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 79.3%](https://img.shields.io/badge/Acceptance-79.3%25-orange?style=for-the-badge)
![Submissions: 4M+](https://img.shields.io/badge/Submissions-4M%2B-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/Topic-String-blue?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Backtracking](https://img.shields.io/badge/Backtracking-blue?style=for-the-badge)
![Topic: Bracket Sequences](https://img.shields.io/badge/Bracket%20Sequences-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Constrained Backtracking & Catalan Numbers:**
> 1. **Validity Invariant**:
>    A sequence of parentheses is valid if and only if:
>    - At every prefix, the number of closing brackets `)` does not exceed the number of opening brackets `(`.
>    - The total number of `(` and `)` both equal $n$.
> 2. **Branching Decisions**:
>    At any step with `open` opening brackets and `close` closing brackets placed so far:
>    - If $\text{open} < n$, we can always append `'('` and branch.
>    - If $\text{close} < \text{open}$, we can append `')'` without ever violating prefix validity and branch.
> 3. **Pruning Without Post-Validation**:
>    Because branches that could ever become invalid are never taken, every single leaf reached in the recursion tree is guaranteed to be a valid, well-formed combination!
> 4. **Number of Combinations**:
>    The number of well-formed parentheses strings of length $2n$ is given by the $n$-th **Catalan Number**:
>    $$C_n = \frac{1}{n + 1}\binom{2n}{n} \approx \frac{4^n}{n\sqrt{\pi n}}$$
>    For $n \le 8$, $C_8 = 1430$, well within practical runtime limits.

---

## 🧩 Problem Description

Given `n` pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

---

## 📌 Examples

**Example 1:**

```text
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```

**Example 2:**

```text
Input: n = 1
Output: ["()"]
```

---

## 📐 Constraints

- $1 \le n \le 8$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}\left(\frac{4^n}{\sqrt{n}}\right)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../247_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../249_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
