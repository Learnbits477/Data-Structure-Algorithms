# [Remove Invalid Parentheses](https://www.geeksforgeeks.org/problems/remove-invalid-parentheses/1)

<div align="center">

| [Problem.md](Problem.md) | [Approach.md](Approach.md) | [Solution.cpp](Solution.cpp) | [Main.cpp](Main.cpp) |
| :---: | :---: | :---: | :---: |

</div>

**Difficulty:** `Hard` | **Accuracy:** `41.0%` | **Submissions:** `10K+` | **Points:** `8` | **Average Time:** `40m`

---

## Problem Description

Given a string `s` consisting of lowercase letters and parentheses '(' and ')'.

A string is considered valid if:
1. Every opening parenthesis '(' has a corresponding closing parenthesis ')'.
2. Parentheses are properly nested.

Remove the **minimum number** of invalid parentheses from `s` so that the resulting string becomes valid. Return all the possible **distinct** valid strings in **lexicographically sorted order**.

### Examples

**Input:** `s = "()())()"`
**Output:** `["(())()", "()()()"]`
**Explanation:** 
The string "()())()" has one extra ')', making it invalid. By removing one ')', we can make it valid in two ways:
- Remove the 3rd index ')' -> `"(())()"`
- Remove the 4th index ')' -> `"()()()"`
Both are valid and require the minimum removals.

**Input:** `s = "(a)())()"`
**Output:** `["(a())()", "(a)()()"]`
**Explanation:** 
We remove one ')' (minimum removals) to make it valid. Possible valid results:
- Remove a ')' -> `"(a())()"`
- Remove another ')' -> `"(a)()()"`

**Input:** `s = ")("`
**Output:** `[""]`
**Explanation:** 
The string ")(" is invalid. Removing both parentheses (minimum removals) gives an empty string "", which is valid.

### Constraints

- $1 \le |s| \le 20$
- `s` consists of lowercase English letters and parentheses '(' and ')'

---
<div align="center">
Happy Coding! 🚀 <br>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Twitter%20%2F%20X-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
</div>
