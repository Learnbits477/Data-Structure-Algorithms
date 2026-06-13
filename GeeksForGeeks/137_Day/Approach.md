# 💡 Approach — Binary Strings with Equal Sum of Two Halves

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 41.34%](https://img.shields.io/badge/Accuracy-41.34%25-green?style=for-the-badge)
![Submissions: 25K+](https://img.shields.io/badge/Submissions-25K+-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topics: Algorithms & Combinatorics](https://img.shields.io/badge/Topics-Algorithms%20%26%20Combinatorics-lightgrey?style=for-the-badge)

> [!TIP]
> **Core Insight:**
> For a binary string of length $$2n$$ to have an equal sum of bits in the first and second halves:
> 1. Let the sum of the first half (number of 1s) be $$k$$, where $$0 \le k \le n$$.
> 2. The second half must also contain exactly $$k$$ 1s.
> 3. The number of ways to choose $$k$$ positions for 1s in the first half is $$\binom{n}{k}$$.
> 4. The number of ways to choose $$k$$ positions for 1s in the second half is also $$\binom{n}{k}$$.
> 5. Since choices for both halves are independent, the total number of valid strings for a fixed $$k$$ is:
>    $$\binom{n}{k} \times \binom{n}{k} = \binom{n}{k}^2$$
> 6. Summing over all possible values of $$k$$ from $$0$$ to $$n$$, we get:
>    $$\text{Total Sequences} = \sum_{k=0}^{n} \binom{n}{k}^2 = \binom{2n}{n}$$
>    *(This equivalence is given by Vandermonde's Identity, representing the number of ways to choose $$n$$ objects out of a total of $$2n$$ objects).*
>
> Thus, the entire problem simplifies to computing $$\binom{2n}{n} \pmod{10^9+7}$$.

## 🔩 Step-by-Step Breakdown

1. **Step 1: Factorial Precomputation**
   - We need to compute $$\binom{2n}{n} = \frac{(2n)!}{n! \cdot n!} \pmod{10^9+7}$$.
   - Iterate from $$1$$ to $$2n$$ to compute $$(2n)! \pmod{10^9+7}$$.
   - On the way, when the loop index reaches $$n$$, store the value as $$n! \pmod{10^9+7}$$.

2. **Step 2: Modular Exponentiation**
   - Calculate the denominator product: $$\text{denom} = (n! \cdot n!) \pmod{10^9+7}$$.
   - Find the modular multiplicative inverse of $$\text{denom}$$ using Fermat's Little Theorem:
     $$\text{denom}^{-1} \equiv \text{denom}^{MOD - 2} \pmod{MOD}$$
   - We implement this using a binary exponentiation helper function taking $$O(\log MOD)$$ time.

3. **Step 3: Calculate the Result**
   - Compute the final result:
     $$\text{ans} = ((2n)! \cdot \text{denom}^{-1}) \pmod{10^9+7}$$

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A[Start: computeValue] --> B["Set MOD = 10^9 + 7"]
    B --> C["Loop i from 1 to 2n"]
    C --> D["fact_2n = (fact_2n * i) % MOD"]
    D --> E{"i == n?"}
    E -- Yes --> F["fact_n = fact_2n"]
    E -- No --> G{"i == 2n?"}
    F --> H["Continue Loop"]
    G -- No --> C
    G -- Yes --> I["denom = (fact_n * fact_n) % MOD"]
    I --> J["denom_inv = modInverse(denom) via power(denom, MOD-2)"]
    J --> K["ans = (fact_2n * denom_inv) % MOD"]
    K --> L[Return ans]
```

## 📊 Complexity Analysis

| Complexity | Analysis |
|:---:|:---|
| **Time Complexity** | $$O(n)$$ — A single loop runs up to $$2n$$ to calculate factorials. Modular inverse takes $$O(\log MOD)$$ using binary exponentiation, which is negligible compared to $$n$$. Thus, the overall time complexity is $$O(n)$$. |
| **Auxiliary Space** | $$O(1)$$ — We only store a few variables (`fact_2n`, `fact_n`, `denom`, `denom_inv`) to compute the answer. No extra memory is allocated, resulting in constant space. |

> *"Mathematics is the language in which God has written the universe."* — Galileo Galilei

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../136_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../138_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
