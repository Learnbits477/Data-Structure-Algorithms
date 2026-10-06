# [921. Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 74.3%](https://img.shields.io/badge/Acceptance-74.3%25-orange?style=for-the-badge)
![Submissions: 1M+](https://img.shields.io/badge/Submissions-1M%2B-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/Topic-String-blue?style=for-the-badge)
![Topic: Stack](https://img.shields.io/badge/Topic-Stack-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)
![Topic: Bracket Sequences](https://img.shields.io/badge/Bracket%20Sequences-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Greedy Balance Tracking & Deficit Counting:**
> 1. **Balance Invariant**:
>    A parentheses string is valid if and only if at every prefix, the number of opening brackets is at least the number of closing brackets, and at the end of the string, the total counts are equal.
> 2. **Unmatched Left vs Unmatched Right**:
>    - An unmatched closing bracket `')'` cannot be resolved by any future characters; an opening bracket `'('` must be added before it immediately. We greedily increment `closeMoves++` whenever a `')'` is encountered and our pool of unmatched `'('` is empty.
>    - An unmatched opening bracket `'('` increments `openCount++`. Any subsequent `')'` consumes one unmatched `'('`.
> 3. **Final Deficit Aggregation**:
>    After scanning the entire string, each leftover unmatched `'('` in `openCount` will need a corresponding `')'` inserted at the end. Thus, the minimum moves required is simply:
>    $$\text{Moves} = \text{closeMoves} + \text{openCount}$$
>    This enables an optimal single-pass $\mathcal{O}(n)$ time and $\mathcal{O}(1)$ auxiliary space solution.

---

## 🧩 Problem Description

A parentheses string is valid if and only if:
1. It is the empty string,
2. It can be written as $AB$ ($A$ concatenated with $B$), where $A$ and $B$ are valid strings, or
3. It can be written as $(A)$, where $A$ is a valid string.

You are given a parentheses string `s`. In one move, you can insert a parenthesis at any position of the string.

- For example, if `s = "()))"`, you can insert an opening parenthesis to be `"(()))"` or a closing parenthesis to be `"())))"`.

Return the minimum number of moves required to make `s` valid.

---

## 📌 Examples

**Example 1:**

```text
Input: s = "())"
Output: 1
Explanation: Inserting an opening parenthesis at the beginning yields "()())" (or inserted in the middle yields "(())"), which is valid.
```

**Example 2:**

```text
Input: s = "((("
Output: 3
Explanation: Inserting three closing parentheses at the end yields "((()))", requiring 3 moves.
```

**Example 3:**

```text
Input: s = "()"
Output: 0
Explanation: The string is already valid, requiring 0 moves.
```

**Example 4:**

```text
Input: s = "()))(("
Output: 4
Explanation:
- Two unmatched ')' require 2 '(' inserted before them.
- Two unmatched '(' require 2 ')' inserted after them.
Total moves = 2 + 2 = 4.
```

---

## 📐 Constraints

- $1 \le s.\text{length} \le 1000$
- `s[i]` is either `'('` or `')'`.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ (Greedy Counter) / $\mathcal{O}(n)$ (Stack-based) |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../251_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../253_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
