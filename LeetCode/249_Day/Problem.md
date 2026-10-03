# [32. Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 39.9%](https://img.shields.io/badge/Acceptance-39.9%25-orange?style=for-the-badge)
![Submissions: 3M+](https://img.shields.io/badge/Submissions-3M%2B-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/Topic-String-blue?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Stack](https://img.shields.io/badge/Stack-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Two-Pass Counter Invariant & Stack Boundary Tracking:**
> 1. **Two-Pass Counter ($\mathcal{O}(1)$ Space)**:
>    - In a left-to-right scan, maintain counts `left` of `'('` and `right` of `')'`.
>    - When `left == right`, we have discovered a balanced valid prefix of length $2 \times \text{right}$.
>    - When `right > left`, validity is permanently broken for the current segment; reset both counters to $0$.
>    - To catch cases where open brackets exceed closed brackets (e.g., `"(()"`), execute a symmetric right-to-left scan resetting when `left > right`.
> 2. **Stack-Based Boundary Tracking ($\mathcal{O}(n)$ Space)**:
>    - Maintain a stack of indices initialized with `-1` representing the baseline before any valid substring began.
>    - Push indices of `'('`.
>    - On encountering `')'`, pop the top index. If the stack is non-empty, the valid substring extends from the current index $i$ back to the new top of the stack, yielding length $i - \text{st.top()}$. If empty, push $i$ as the new base boundary.

---

## 🧩 Problem Description

Given a string `s` containing just the characters `'('` and `')'`, return the length of the longest valid (well-formed) parentheses substring.

---

## 📌 Examples

**Example 1:**

```text
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
```

**Example 2:**

```text
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
```

**Example 3:**

```text
Input: s = ""
Output: 0
Explanation: An empty string contains no valid parentheses substrings.
```

---

## 📐 Constraints

- $0 \le s\text{.length} \le 3 \times 10^4$
- `s[i]` is `'('` or `')'`.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ (Two-Pass) / $\mathcal{O}(n)$ (Stack / DP) |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../248_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../250_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
