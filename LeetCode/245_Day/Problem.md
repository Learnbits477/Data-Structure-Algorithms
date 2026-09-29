# [2267. Check if There Is a Valid Parentheses String Path](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 43.7%](https://img.shields.io/badge/Acceptance-43.7%25-orange?style=for-the-badge)
![Submissions: 59.2K+](https://img.shields.io/badge/Submissions-59.2K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topics:-Array-blue?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Matrix](https://img.shields.io/badge/Matrix-blue?style=for-the-badge)
![Topic: Breadth-First Search](https://img.shields.io/badge/Breadth--First%20Search-blue?style=for-the-badge)

---

## 🧩 Problem Description

A parentheses string is a **non-empty** string consisting only of `'('` and `')'`. It is **valid** if any of the following conditions is true:
- It is `()`.
- It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid parentheses strings.
- It can be written as `(A)`, where `A` is a valid parentheses string.

You are given an $m \times n$ matrix of parentheses `grid`. A valid parentheses string path in the grid is a path satisfying all of the following conditions:
- The path starts from the upper-left cell $(0, 0)$.
- The path ends at the bottom-right cell $(m - 1, n - 1)$.
- The path only ever moves **down** or **right**.
- The resulting parentheses string formed by the path is **valid**.

Return `true` if there exists a valid parentheses string path in the grid. Otherwise, return `false`.

---

## 📌 Examples

**Example 1:**

```text
Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
Output: true
Explanation:
The grid has paths that form valid parentheses strings:
- Path 1: (0,0) -> (0,1) -> (1,1) -> (2,1) -> (3,1) -> (3,2) produces "()(())" which is valid.
- Path 2: (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) produces "((()))" which is valid.
```

**Example 2:**

```text
Input: grid = [[")",")"],["(","("]]
Output: false
Explanation:
The two possible paths form the strings "))(" and ")((".
Since neither of them are valid parentheses strings, return false.
```

---

## 📐 Constraints

- $m == \text{grid.length}$
- $n == \text{grid}[i]\text{.length}$
- $1 \le m, n \le 100$
- `grid[i][j]` is either `'('` or `')'`.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(m \cdot n \cdot \frac{m + n}{64}) \approx \mathcal{O}(m \cdot n)$ |
| **Auxiliary Space** | $\mathcal{O}(m \cdot n \cdot \frac{m + n}{64}) \approx \mathcal{O}(m \cdot n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../244_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../246_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
