# [3723. Maximize Sum of Squares of Digits](https://leetcode.com/problems/maximize-sum-of-squares-of-digits/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 64.0%](https://img.shields.io/badge/Acceptance-64.0%25-orange?style=for-the-badge)
![Submissions: 59.9K+](https://img.shields.io/badge/Submissions-59.9K%2B-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Convexity of Squares & Greedy Place-Value Assignment:**
> 1. **Convexity of Square Function ($f(x) = x^2$)**:
>    For any two positive quantities $a \le b$, transferring mass from the smaller to the larger strictly increases the sum of squares: $(a - 1)^2 + (b + 1)^2 = a^2 + b^2 + 2(b - a + 1) > a^2 + b^2$. To maximize $\sum d_i^2$ subject to a fixed digit sum, we must concentrate the sum into as many maximal digits ($9$'s) as possible.
> 2. **Lexicographical & Numerical Maximization**:
>    Among all permutations with identical multiset of digits, the integer is numerically maximized when larger digits appear in the most significant (leftmost) positions.
> 3. **Canonical Partition**:
>    The optimal digit sequence consists of $\lfloor sum / 9 \rfloor$ nines, followed by one remainder digit $sum \pmod 9$ (if non-zero), padded with trailing zeros to achieve length `num`.

---

## 🧩 Problem Description

You are given two positive integers `num` and `sum`.

A positive integer `n` is **good** if it satisfies both of the following:
- The number of digits in `n` is exactly `num`.
- The sum of digits in `n` is exactly `sum`.

The **score** of a good integer `n` is the sum of the squares of digits in `n`.

Return a string denoting the good integer `n` that achieves the **maximum score**. If there are multiple possible integers, return the **maximum** one. If no such integer exists, return an empty string `""`.

---

## 📌 Examples

**Example 1:**

```text
Input: num = 2, sum = 3
Output: "30"
Explanation:
There are 3 good integers: 12, 21, and 30.
The score of 12 is 1^2 + 2^2 = 5.
The score of 21 is 2^2 + 1^2 = 5.
The score of 30 is 3^2 + 0^2 = 9.
The maximum score is 9, which is achieved by the good integer 30. Therefore, the answer is "30".
```

**Example 2:**

```text
Input: num = 2, sum = 17
Output: "98"
Explanation:
There are 2 good integers: 89 and 98.
The score of 89 is 8^2 + 9^2 = 145.
The score of 98 is 9^2 + 8^2 = 145.
The maximum score is 145. The maximum good integer that achieves this score is 98. Therefore, the answer is "98".
```

**Example 3:**

```text
Input: num = 1, sum = 10
Output: ""
Explanation:
There are no integers that have exactly 1 digit and whose digits sum to 10. Therefore, the answer is "".
```

---

## 📐 Constraints

- $1 \le num \le 2 \times 10^5$
- $1 \le sum \le 2 \times 10^6$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(num)$ |
| **Auxiliary Space** | $\mathcal{O}(num)$ |

*Where $num$ is the required number of digits. Creating and returning the result string of length $num$ takes linear time and memory.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../259_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../261_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
