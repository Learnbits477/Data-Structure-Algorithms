# [1541. Minimum Insertions to Balance a Parentheses String](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 54.9%](https://img.shields.io/badge/Acceptance-54.9%25-orange?style=for-the-badge)
![Submissions: 172.9K+](https://img.shields.io/badge/Submissions-172.9K%2B-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/Topic-String-blue?style=for-the-badge)
![Topic: Stack](https://img.shields.io/badge/Stack-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)
![Topic: Bracket Sequences](https://img.shields.io/badge/Bracket%20Sequences-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — 1-to-2 Parenthesis Pairing & Consecutive Right Matching:**
> 1. **Asymmetric Rule**:
>    Unlike standard balanced parentheses where each `'('` requires a single `')'`, here every left parenthesis `'('` requires **two consecutive** right parentheses `'))'`.
> 2. **Greedy State Machine**:
>    - When scanning, whenever we see `')'`, we check if it is followed by another `')'`. If so, we consume both as a unit `'))'`. If not, we must insert one `')'` to complete the pair (cost $+1$).
>    - Now that we have a complete `'))'` block:
>      - If we currently have an unmatched `'('` available (`openCount > 0`), it absorbs this `'))'` (`openCount--`).
>      - Otherwise, we must insert a `'('` before it (cost $+1$).
> 3. **Unmatched Openings at the End**:
>    Any remaining open `'('` after scanning the entire string will each require two `')'`, adding $2 \times \text{openCount}$ to the answer.

---

## 🧩 Problem Description

Given a parentheses string `s` containing only the characters `'('` and `')'`. A parentheses string is balanced if:
1. Any left parenthesis `'('` must have a corresponding two consecutive right parenthesis `'))'`.
2. Left parenthesis `'('` must go before the corresponding two consecutive right parenthesis `'))'`.

In other words, we treat `'('` as an opening parenthesis and `'))'` as a closing parenthesis.

- For example, `"())"`, `"())(())))"` and `"(())())))"` are balanced, while `")()"`, `"()))"` and `"(()))"` are not balanced.

You can insert the characters `'('` and `')'` at any position of the string to balance it if needed.

Return the minimum number of insertions needed to make `s` balanced.

---

## 📌 Examples

**Example 1:**

```text
Input: s = "(()))"
Output: 1
Explanation:
The second '(' has two matching '))', but the first '(' has only ')' matching.
We need to add one more ')' at the end of the string to be "(())))" which is balanced.
```

**Example 2:**

```text
Input: s = "())"
Output: 0
Explanation:
The string is already balanced.
```

**Example 3:**

```text
Input: s = "))())("
Output: 3
Explanation:
Add '(' to match the first '))', Add '))' to match the last '('.
Resulting string: "())())())".
Total insertions: 3.
```

---

## 📐 Constraints

- $1 \le s.\text{length} \le 10^5$
- `s` consists of `'('` and `')'` only.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

*Where $n$ is the length of string $s$. The string is scanned in a single pass with constant auxiliary variables.*

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
