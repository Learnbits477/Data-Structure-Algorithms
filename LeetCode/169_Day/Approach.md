# 💡 Approach — GCD of Odd and Even Sums

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 85.7%](https://img.shields.io/badge/Acceptance-85.7%25-blue?style=for-the-badge)
![Submissions: 126.8K](https://img.shields.io/badge/Submissions-126.8K-brightgreen?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Topic-Math-orange?style=for-the-badge)
![Topic: Number Theory](https://img.shields.io/badge/Topic-Number%20Theory-purple?style=for-the-badge)

</div>

---

## 🎯 Core Insight

> [!TIP]
> **Mathematical Reduction via Coprimality**
>
> 1. **Formula for Odd Sum:**
>    - The sum of the first $n$ odd positive integers is:
>      $$\text{sumOdd} = 1 + 3 + 5 + \dots + (2n-1) = n^2$$
>
> 2. **Formula for Even Sum:**
>    - The sum of the first $n$ even positive integers is:
>      $$\text{sumEven} = 2 + 4 + 6 + \dots + 2n = n(n+1)$$
>
> 3. **Algebraic Simplification:**
>    - We are asked to compute:
>      $$\text{GCD}(\text{sumOdd}, \text{sumEven}) = \text{GCD}(n^2, n(n+1))$$
>    - Using the GCD distributive property:
>      $$\text{GCD}(n^2, n(n+1)) = n \cdot \text{GCD}(n, n+1)$$
>    - Because $n$ and $n+1$ are consecutive positive integers, they are **coprime** ($\text{GCD}(n, n+1) = 1$).
>    - Therefore, the expression simplifies directly to:
>      $$\text{GCD}(n^2, n(n+1)) = n \cdot 1 = n$$
>    - Hence, the greatest common divisor is always $n$.

---

## 🔩 Step-by-Step Breakdown

**Step 1: Simplify Mathematically**

- Establish that $\text{sumOdd} = n^2$ and $\text{sumEven} = n(n+1)$.

**Step 2: Apply Coprimality**

- Recognize that consecutive numbers $n$ and $n+1$ always have a greatest common divisor of $1$.

**Step 3: Return Result**

- Return $n$ directly, bypassing any sequential addition or division cycles.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start(["Start: gcdOfOddEvenSums(n)"]) --> MathInsight["Mathematical Reduction:
    sumOdd = n²
    sumEven = n(n + 1)
    GCD(n², n(n + 1)) = n * GCD(n, n + 1)"]
    MathInsight --> Coprimality["Consecutive Integers Coprimality:
    GCD(n, n + 1) = 1"]
    Coprimality --> DirectReturn["Return n"]
    DirectReturn --> End(["End"])
```

---

## 📊 Complexity Analysis

| Metric | Complexity | Reasoning |
| :---: | :---: | :--- |
| 🕐 Time | $$O(1)$$ | The result is obtained directly in constant time by returning $n$. |
| 💾 Space | $$O(1)$$ | No auxiliary memory is allocated. |

---

> *"Mathematics is the language in which God has written the universe. By simplifying the equations of nature, the most daunting tasks yield to the simplest truths."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../168_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../170_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
