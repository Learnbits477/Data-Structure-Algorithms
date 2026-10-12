# 💡 Approach — Minimum Squares with Full Cuts

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
> 1. **Full-Cut Geometry**:
>    Because each cut must run completely from one boundary of the paper to the opposite boundary, we can only cut parallel to one of the rectangle's sides across its entire breadth or length.
> 2. **Maximal Square Carving**:
>    Given dimensions $n$ and $m$ (assume $n \ge m$), cutting off a square of size $s \times s$ with a full cut requires $s = m$. Any cut leaving a square of side $s < m$ would leave a non-square strip that cannot be resolved without making further cuts that violate the full-cut rule or yield strictly more pieces.
> 3. **Continued Fraction Equivalence**:
>    Removing as many $m \times m$ squares as possible yields $\lfloor n / m \rfloor$ squares. The remaining rectangle is $m \times (n \pmod m)$. This process mirrors the Euclidean GCD algorithm (or continuous fraction decomposition of $n / m$).

---

## 🔩 Step-by-Step Breakdown

### Method 1: Iterative Euclidean Algorithm ($\mathcal{O}(\log(\min(n, m)))$ Time, $\mathcal{O}(1)$ Space) — Primary

1. **Orientation Normalization**:
   - At each step, if $n < m$, swap $n$ and $m$ so $n$ is always the larger side.
2. **Division & Accumulation**:
   - While $m > 0$:
     - Add $\lfloor n / m \rfloor$ to the running count of squares.
     - Update $n = n \pmod m$.
     - Swap $n$ and $m$ so the non-zero dimension becomes the new divisor.
3. **Termination**:
   - When the remainder $m$ reaches $0$, all portions of the paper have been converted into squares.
   - Return the total accumulated count.

---

### Method 2: Recursive Euclidean Algorithm ($\mathcal{O}(\log(\min(n, m)))$ Time, $\mathcal{O}(\log(\min(n, m)))$ Stack Space) — Alternative

1. **Base Case**:
   - If either dimension is $0$ ($m == 0$), return $0$.
   - If $n < m$, swap arguments: `return minSquaresRecursive(m, n)`.
2. **Recursive Transition**:
   - Add $\lfloor n / m \rfloor$ squares and recurse on the remainder:
     $$\text{ans} = \lfloor n / m \rfloor + \text{minSquaresRecursive}(m, n \pmod m)$$
3. **Return Accumulation**:
   - Unwind recursion and return total squares formed.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start["Start: minSquares(n, m)"] --> Init["Initialize count = 0"]
    Init --> CheckCond{"m > 0 ?"}

    CheckCond -- "Yes" --> CheckSwap{"n < m ?"}
    CheckSwap -- "Yes" --> DoSwap["swap(n, m)"]
    CheckSwap -- "No" --> CalcQuotient["count += n / m"]
    DoSwap --> CalcQuotient

    CalcQuotient --> UpdateRem["n = n % m<br/>swap(n, m)"]
    UpdateRem --> CheckCond

    CheckCond -- "No" --> Return["Return count 🏁"]
```

---

## 🏃‍♂️ Dry Run

### Detailed Walkthrough: Example 1 ($n = 4, m = 5$)

- **Initial State**: $n = 4, m = 5$, `count = 0`.
- **Iteration 1**:
  - Since $n < m$, swap $\implies n = 5, m = 4$.
  - Squares added: $\lfloor 5 / 4 \rfloor = 1$. `count = 1`.
  - Remainder: $5 \pmod 4 = 1$.
  - Update: $n = 4, m = 1$.
- **Iteration 2**:
  - Squares added: $\lfloor 4 / 1 \rfloor = 4$. `count = 1 + 4 = 5`.
  - Remainder: $4 \pmod 1 = 0$.
  - Update: $n = 1, m = 0$.
- **Termination**: $m = 0 \implies$ return $5$.

---

### Detailed Walkthrough: Example 3 ($n = 11, m = 13$)

| Step | Larger ($n$) | Smaller ($m$) | Quotient $\lfloor n / m \rfloor$ | Remainder $n \pmod m$ | Squares Added | Running Total |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 1 | 13 | 11 | 1 | 2 | 1 square ($11 \times 11$) | 1 |
| 2 | 11 | 2 | 5 | 1 | 5 squares ($2 \times 2$) | 6 |
| 3 | 2 | 1 | 2 | 0 | 2 squares ($1 \times 1$) | 8 |

- **Final Square Count**: $1 + 5 + 2 = 8$.

---

## 📊 Complexity Analysis

| Complexity Metric | Estimation | Rationale |
| :--- | :---: | :--- |
| **Time Complexity (Method 1)** | $\mathcal{O}(\log(\min(n, m)))$ | In each Euclidean step, the product of dimensions decreases by at least half every two steps. The worst-case runtime occurs with consecutive Fibonacci numbers, requiring at most $\approx 4.785 \log_{10}(\min(n, m))$ iterations. |
| **Time Complexity (Method 2)** | $\mathcal{O}(\log(\min(n, m)))$ | The recursion depth is identical to the Euclidean step count. |
| **Auxiliary Space (Method 1)** | $\mathcal{O}(1)$ | Constant variables (`count`, `rem`, `n`, `m`) allocated in registers. |
| **Auxiliary Space (Method 2)** | $\mathcal{O}(\log(\min(n, m)))$ | Call stack depth bounded by the logarithmic number of recursive frames. |

---

> *"When a cut must stretch uninterrupted from end to end, nature mimics the harmony of continuous fractions — yielding the golden steps of Euclidean reduction."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../257_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../259_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
