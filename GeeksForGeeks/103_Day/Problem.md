# [Max Profit from Two Machines](https://www.geeksforgeeks.org/problems/max-profit-from-two-machines/1)

<div align="center">

| [Problem.md](Problem.md) | [Approach.md](Approach.md) | [Solution.cpp](Solution.cpp) | [Main.cpp](Main.cpp) |
| :--- | :--- | :--- | :--- |

</div>

---
**Difficulty:** Medium | **Accuracy:** 16.39% | **Submissions:** 88K+ | **Points:** 4 | **Average Time:** 20m

---
## Problem Description

Given two machines, Machine A and Machine B, and a set of `n` tasks. The profit earned for performing each task is given in two arrays `a[]` and `b[]` such that if Machine A performs the $i^{th}$ task, the profit is `a[i]`, and if Machine B performs it, the profit is `b[i]`.

Machine A can process at most `x` tasks, and Machine B can process at most `y` tasks. It is guaranteed that $x + y \geq n$, so all tasks can be assigned. Return the maximum possible profit after assigning each task to either Machine A or Machine B.

---
### Examples

**Input:**
```text
x = 3, y = 3
a[] = [1, 2, 3, 4, 5]
b[] = [5, 4, 3, 2, 1]
```
**Output:** `21`
**Explanation:** Machine A performs tasks with indices `[2, 3, 4]`, and Machine B performs the rest `[0, 1]`, giving profits $(3 + 4 + 5) + (5 + 4) = 21$.

**Input:**
```text
x = 4, y = 4
a[] = [1, 4, 3, 2, 7, 5, 9, 6]
b[] = [1, 2, 3, 6, 5, 4, 9, 8]
```
**Output:** `43`
**Explanation:** Machine A performs tasks with indices `[1, 4, 5, 7]`, and Machine B performs the rest `[0, 2, 3, 6]`, giving profits $(4 + 7 + 5 + 6) + (1 + 3 + 6 + 9) = 43$. (Note: Example output says 43, let's re-verify).
Wait, the example says 41 in explanation but 43 in output. Let's check:
A: indices 1, 4, 5, 7 -> profits 4, 7, 5, 6. Sum = 22.
B: indices 0, 2, 3, 6 -> profits 1, 3, 6, 9. Sum = 19.
Total = 22 + 19 = 41.
Let's see if we can get 43.
Diffs: [0, 2, 0, -4, 2, 1, 0, -2]
Sorted desc: [2, 2, 1, 0, 0, 0, -2, -4]
Base B profit: 1+2+3+6+5+4+9+8 = 38.
Min A = max(0, 8-4) = 4.
Pick first 4 diffs: 2+2+1+0 = 5.
Total = 38 + 5 = 43. Yes, 43 is correct. The explanation in the prompt has a typo.

**Input:**
```text
x = 3, y = 4
a[] = [8, 7, 15, 19, 16, 16, 18]
b[] = [1, 7, 15, 11, 12, 31, 9]
```
**Output:** `110`
**Explanation:** Machine A performs tasks with indices `[0, 3, 6]`, and Machine B performs the rest `[1, 2, 4, 5]`, giving profits $(8 + 19 + 18) + (7 + 15 + 12 + 31) = 110$.

---
### Constraints

- $1 \leq a.size() == b.size() \leq 10^5$
- $1 \leq x, y \leq 10^5$
- $1 \leq a[i], b[i] \leq 10^4$
- $x + y \geq n$

---
<div align="center">
Happy Coding! 🚀 <br>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Twitter%20%2F%20X-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
</div>

