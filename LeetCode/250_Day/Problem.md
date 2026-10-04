# [678. Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 41.6%](https://img.shields.io/badge/Acceptance-41.6%25-orange?style=for-the-badge)
![Submissions: 1.7M+](https://img.shields.io/badge/Submissions-1.7M%2B-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/Topics:-String-blue?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Stack](https://img.shields.io/badge/Stack-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)
![Topic: Bracket Sequences](https://img.shields.io/badge/Bracket%20Sequences-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Range of Possible Open Parentheses `[low, high]`:**
> 1. **Continuous Possible Range**:
>    Because each `'*'` can contribute $+1$ (as `'('`), $-1$ (as `')'`), or $0$ (as empty `""`), the number of currently unmatched open parentheses at any position forms a continuous interval of valid counts $[low, high]$.
> 2. **Invariants**:
>    - $high$ tracks the maximum possible open parentheses (treating every `'*'` as `'('`). If $high < 0$, there are strictly more closing brackets than any possible opening brackets can balance, making validity impossible.
>    - $low$ tracks the minimum required open parentheses (treating every `'*'` as `')'`). We clamp $low = \max(low, 0)$ because an open count cannot stay negative if we choose `'*'` as empty `""` or `'('`.
>    - At the end of the string, $s$ is valid if and only if $low == 0$.

---

## 🧩 Problem Description

Given a string `s` containing only three types of characters: `'('`, `')'` and `'*'`, return `true` if `s` is valid.

The following rules define a valid string:
1. Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.
2. Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.
3. Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.
4. `'*'` could be treated as a single right parenthesis `')'` or a single left parenthesis `'('` or an empty string `""`.

---

## 📌 Examples

**Example 1:**

```text
Input: s = "()"
Output: true
Explanation: The string is already a standard balanced parenthesis pair.
```

**Example 2:**

```text
Input: s = "(*)"
Output: true
Explanation: Treating '*' as an empty string "" yields "()", which is valid.
```

**Example 3:**

```text
Input: s = "(*))"
Output: true
Explanation: Treating '*' as '(' yields "(())", which is valid.
```

**Example 4:**

```text
Input: s = "("
Output: false
Explanation: The opening parenthesis has no corresponding closing parenthesis or wildcard to close it.
```

---

## 📐 Constraints

- $1 \le s\text{.length} \le 100$
- `s[i]` is `'('`, `')'`, or `'*'`.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ (Greedy Range) / $\mathcal{O}(n)$ (Two Stacks / DP) |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../249_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../251_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
