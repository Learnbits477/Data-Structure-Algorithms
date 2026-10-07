# [301. Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 50.4%](https://img.shields.io/badge/Acceptance-50.4%25-orange?style=for-the-badge)
![Submissions: 523K+](https://img.shields.io/badge/Submissions-523K%2B-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/Topic-String-blue?style=for-the-badge)
![Topic: Backtracking](https://img.shields.io/badge/Backtracking-blue?style=for-the-badge)
![Topic: Breadth-First Search](https://img.shields.io/badge/Breadth--First%20Search-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Misplaced Deficit Counting & Pruned Backtracking / Level-Order BFS:**
> 1. **Determining Minimum Removals Upfront**:
>    In a valid parentheses string, the running prefix balance of `'('` minus `')'` must never drop below zero, and the overall balance at the end must be zero. By performing a greedy single pass, we can count exactly:
>    - `remL`: Total misplaced `'('` that remain unclosed.
>    - `remR`: Total misplaced `')'` that occurred when no open bracket was available.
>    Any valid string with the **minimum number of removals** must delete exactly `remL` opening parentheses and `remR` closing parentheses.
> 2. **Targeted Backtracking (DFS)**:
>    Equipped with exact deletion budgets (`remL` and `remR`), the backtracking search space is dramatically reduced. At each character, we either keep it (updating the current open balance) or remove it (decrementing `remL` or `remR`). Consecutive duplicate removals can be skipped to prevent redundant exploration branches.
> 3. **Breadth-First Search (BFS) Alternative**:
>    Because we seek the minimum deletions, BFS naturally explores states level-by-level (0 deletions, 1 deletion, 2 deletions, etc.). The very first level where valid strings are discovered guarantees the minimum removal criteria.

---

## 🧩 Problem Description

Given a string `s` that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return *a list of unique strings that are valid with the minimum number of removals*. You may return the answer in **any order**.

---

## 📌 Examples

**Example 1:**

```text
Input: s = "()())()"
Output: ["(())()","()()()"]
Explanation:
Removing the second ')' yields "(())()".
Removing the third ')' yields "()()()".
Both strings are valid and require the minimum removal of 1 parenthesis.
```

**Example 2:**

```text
Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
Explanation:
Letters remain preserved in their original sequence.
Removing either the third or fourth ')' yields valid outputs with 1 removal.
```

**Example 3:**

```text
Input: s = ")("
Output: [""]
Explanation:
Both ')' and '(' are invalid in their positions.
Removing both yields the empty string "", which is valid and requires 2 removals.
```

---

## 📐 Constraints

- $1 \le s.\text{length} \le 25$
- `s` consists of lowercase English letters and parentheses `'('` and `')'`.
- There will be at most $20$ parentheses in `s`.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(2^n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

*Where $n$ is the length of string $s$. With $n \le 25$ and at most 20 parentheses, pruned backtracking explores only the feasible subsets of deletions.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../252_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../254_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
