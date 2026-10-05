# [856. Score of Parentheses](https://leetcode.com/problems/score-of-parentheses/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 63.6%](https://img.shields.io/badge/Acceptance-63.6%25-orange?style=for-the-badge)
![Submissions: 236.9K+](https://img.shields.io/badge/Submissions-236.9K%2B-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/Topic-String-blue?style=for-the-badge)
![Topic: Stack](https://img.shields.io/badge/Stack-blue?style=for-the-badge)
![Topic: Bracket Sequences](https://img.shields.io/badge/Bracket%20Sequences-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Nesting Depth Counting & Bit-Shift Contribution:**
> 1. **Polynomial / Power of Two Decomposition**:
>    Every balanced parentheses string can be expanded algebraically using the distributive law $2 \times (A + B) = 2A + 2B$. Each primitive core `"()"` is a leaf node that is multiplied by $2$ for every enclosing parenthesis pair.
> 2. **Contribution by Depth**:
>    A core `"()"` nested within $d$ outer pairs contributes exactly $1 \times 2^d = (1 \ll d)$ to the total score.
> 3. **Leaf Detection**:
>    We only add points when an immediate adjacent pair `s[i] == ')'` and `s[i - 1] == '('` is found. Outer closing brackets simply adjust the active nesting depth without generating independent leaf score, allowing an optimal $\mathcal{O}(1)$ space solution.

---

## 🧩 Problem Description

Given a balanced parentheses string `s`, return the score of the string.

The score of a balanced parentheses string is based on the following rules:
- `"()"` has score $1$.
- `AB` has score $A + B$, where $A$ and $B$ are balanced parentheses strings.
- `(A)` has score $2 \times A$, where $A$ is a balanced parentheses string.

---

## 📌 Examples

**Example 1:**

```text
Input: s = "()"
Output: 1
Explanation: A single pair of balanced parentheses has a score of 1.
```

**Example 2:**

```text
Input: s = "(())"
Output: 2
Explanation: The outer parentheses wrap a valid string "()" with score 1, giving 2 * 1 = 2.
```

**Example 3:**

```text
Input: s = "()()"
Output: 2
Explanation: Two concatenated substrings "()" and "()", each with score 1, giving 1 + 1 = 2.
```

**Example 4:**

```text
Input: s = "(()(()))"
Output: 6
Explanation:
Inner parts:
- First "()" has depth 1 -> 2^1 = 2
- Second inner "(())" has score 2 * 1 = 2, so "() + (())" = 1 + 2 = 3
Outer layer doubles it: 2 * 3 = 6.
Equivalently: 2^1 + 2^2 = 2 + 4 = 6.
```

---

## 📐 Constraints

- $2 \le s.\text{length} \le 50$
- `s` consists of only `'('` and `')'`.
- `s` is a balanced parentheses string.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ (Optimal Depth Counting) / $\mathcal{O}(n)$ (Stack) |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../250_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../252_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
