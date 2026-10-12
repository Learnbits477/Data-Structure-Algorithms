# 258. [Minimum Squares with Full Cuts](https://www.geeksforgeeks.org/problems/squares-in-reactangle3340/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 31.6%](https://img.shields.io/badge/Accuracy-31.6%25-orange?style=for-the-badge)
![Submissions: 3K+](https://img.shields.io/badge/Submissions-3K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: Mathematics](https://img.shields.io/badge/Topic-Mathematics-blue?style=for-the-badge)
![Company: Amazon](https://img.shields.io/badge/Company-Amazon-orange?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Euclidean Division & Full Cut Constraint:**
> 1. **Full-Cut Invariant**:
>    Because every cut must travel completely across the remaining paper (either horizontally or vertically), cutting off a square of side $s$ from an $n \times m$ rectangle (with $n \ge m$) requires that $s = m$. Any smaller square ($s < m$) would require partial cuts that terminate inside the paper, which is strictly disallowed.
> 2. **Euclidean Greedy Reduction**:
>    From an $n \times m$ sheet ($n \ge m$), we can greedily carve out $\lfloor n / m \rfloor$ squares of dimension $m \times m$. The remaining piece is a rectangle of dimensions $m \times (n \pmod m)$.
> 3. **Logarithmic Termination**:
>    This reduction is mathematically identical to the Euclidean Greatest Common Divisor (GCD) algorithm. It processes the rectangle until dimensions reach zero in $\mathcal{O}(\log(\min(n, m)))$ iterations and $\mathcal{O}(1)$ space.

---

## 🧩 Problem Description

Given a rectangular paper with dimensions $n \times m$, find the minimum number of squares that can be formed by cutting the paper. Each cut must be made completely across the remaining paper, either horizontally or vertically.

---

## 📌 Examples

**Example 1:**

```text
Input: n = 4, m = 5
Output: 5
Explanation:
One square of size 4 x 4 leaves a 4 x 1 rectangle.
Four squares of size 1 x 1 fill the remaining 4 x 1 strip.
Total squares: 1 + 4 = 5.
```

**Example 2:**

```text
Input: n = 2, m = 4
Output: 2
Explanation:
Two squares of size 2 x 2 are enough to fill the 2 x 4 rectangle completely.
Total squares: 2.
```

**Example 3:**

```text
Input: n = 11, m = 13
Output: 8
Explanation:
One square of size 11 x 11 leaves an 11 x 2 rectangle.
Five squares of size 2 x 2 leave a 2 x 1 rectangle.
Two squares of size 1 x 1 leave 0.
Total squares: 1 + 5 + 2 = 8.
(Please note that if partial cuts were permitted, a 6-square pinwheel dissection would be possible, which is the distinct Min Cut Square problem).
```

---

## 📐 Constraints

- $1 \le n, m \le 10^9$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(\log(\min(n, m)))$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

*Where $n$ and $m$ are the rectangle dimensions. The Euclidean division step halves the smaller dimension at least every two iterations, guaranteeing logarithmic time.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../257_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../259_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
