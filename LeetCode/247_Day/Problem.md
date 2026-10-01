# [20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-green?style=for-the-badge)
![Acceptance: 45.0%](https://img.shields.io/badge/Acceptance-45.0%25-orange?style=for-the-badge)
![Submissions: 18.3M+](https://img.shields.io/badge/Submissions-18.3M%2B-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/Topic-String-blue?style=for-the-badge)
![Topic: Stack](https://img.shields.io/badge/Topic-Stack-blue?style=for-the-badge)
![Topic: Bracket Sequences](https://img.shields.io/badge/Bracket%20Sequences-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Last-In, First-Out (LIFO) Stack Principle:**
> 1. **Symmetric Nesting**:
>    Parentheses must close in reverse chronological order of their opening. The most recently opened bracket must be the first one closed.
> 2. **Immediate Parity Check**:
>    Any valid bracket string must have an even length. An odd length string can never be valid ($s.\text{length}() \pmod 2 \ne 0 \implies \text{false}$).
> 3. **Expected Closer Invariant**:
>    When an opening bracket is encountered (`(`, `{`, `[`), we can push its corresponding closing counterpart (`)`, `}`, `]`) onto the stack.
> 4. **Constant-Time Verification**:
>    When encountering a closing bracket, it must match the top element of the stack. If the stack is empty (unmatched closer) or the top element does not match (wrong closer type), the string is immediately invalid.
> 5. **Empty Stack Completion**:
>    After examining every character, the string is valid if and only if the stack is completely empty (no leftover unclosed openers).

---

## 🧩 Problem Description

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

---

## 📌 Examples

**Example 1:**

```text
Input: s = "()"
Output: true
Explanation: The opening '(' is correctly closed by ')'.
```

**Example 2:**

```text
Input: s = "()[]{}"
Output: true
Explanation: All three bracket pairs open and close in their appropriate respective orders.
```

**Example 3:**

```text
Input: s = "(]"
Output: false
Explanation: The open bracket '(' is closed by a mismatched bracket type ']'.
```

**Example 4:**

```text
Input: s = "([])"
Output: true
Explanation: The inner square brackets are closed first, followed by the outer round brackets.
```

**Example 5:**

```text
Input: s = "([)]"
Output: false
Explanation: The brackets are interleaved improperly; the inner '(' must be closed before ']' can close '['.
```

---

## 📐 Constraints

- $1 \le s\text{.length} \le 10^4$
- `s` consists of parentheses only: `'()[]{}'`.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../246_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../248_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
