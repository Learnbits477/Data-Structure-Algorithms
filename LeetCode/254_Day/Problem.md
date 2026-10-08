# [1021. Remove Outermost Parentheses](https://leetcode.com/problems/remove-outermost-parentheses/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 87.6%](https://img.shields.io/badge/Acceptance-87.6%25-orange?style=for-the-badge)
![Submissions: 884K+](https://img.shields.io/badge/Submissions-884K%2B-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/Topic-String-blue?style=for-the-badge)
![Topic: Stack](https://img.shields.io/badge/Stack-blue?style=for-the-badge)
![Topic: Bracket Sequences](https://img.shields.io/badge/Bracket%20Sequences-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Depth-Tracking & Primitive Boundary Detection:**
> 1. **Primitive Valid Parentheses Strings**:
>    A valid string is primitive if it cannot be split into two non-empty valid strings. Every primitive block has the form `"(" + A + ")"`, where $A$ is a (possibly empty) valid parentheses string.
> 2. **Nesting Depth Invariant**:
>    As we traverse the string while tracking the count of currently unclosed opening parentheses `opened`:
>    - The first `'('` of any primitive block occurs when `opened == 0`. It is the outermost opening bracket, so we **skip** it and increment `opened`.
>    - Any subsequent `'('` occurs when `opened > 0`. It is inside the primitive block, so we **include** it in the result and increment `opened`.
>    - When encountering a `')'`, we first decrement `opened`. If the resulting `opened > 0`, it is inside the primitive block and we **include** it; if `opened == 0`, it is the outermost closing bracket of the primitive block, so we **skip** it.
> 3. **Single Pass Efficiency**:
>    By observing nesting depth on the fly, we filter outermost parentheses in a single linear pass with $\mathcal{O}(1)$ auxiliary space.

---

## 🧩 Problem Description

A valid parentheses string is either empty `""`, `"(" + A + ")"`, or `A + B`, where `A` and `B` are valid parentheses strings, and `+` represents string concatenation.

For example, `""`, `"()"`, `"(())()"`, and `"(()(()))"` are all valid parentheses strings.

A valid parentheses string `s` is **primitive** if it is nonempty, and there does not exist a way to split it into `s = A + B`, with `A` and `B` nonempty valid parentheses strings.

Given a valid parentheses string `s`, consider its primitive decomposition: `s = P1 + P2 + ... + Pk`, where `Pi` are primitive valid parentheses strings.

Return `s` after removing the outermost parentheses of every primitive string in the primitive decomposition of `s`.

---

## 📌 Examples

**Example 1:**

```text
Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
```

**Example 2:**

```text
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
```

**Example 3:**

```text
Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
```

---

## 📐 Constraints

- $1 \le s.\text{length} \le 10^5$
- `s[i]` is either `'('` or `')'`.
- `s` is a valid parentheses string.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

*Where $n$ is the length of string $s$. The result string requires $\mathcal{O}(n)$ storage, but auxiliary operational space is $\mathcal{O}(1)$.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../253_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../255_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
