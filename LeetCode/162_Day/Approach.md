# 💡 Approach — Concatenate Non-Zero Digits and Multiply by Sum II

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 32.5%](https://img.shields.io/badge/Acceptance-32.5%25-blue?style=for-the-badge)
![Submissions: 68.2K](https://img.shields.io/badge/Submissions-68.2K-brightgreen?style=for-the-badge)

</div>

---

## 🎯 Core Insight

> [!TIP]
> **Prefix Hash & Prefix Sum (O(1) Range Queries)**
>
> 1. **Isolate Non-Zero Digits:**
>    - Let $D$ be the array of only the non-zero digits in $s$.
>    - For any query range `[l, r]`, the non-zero digits falling inside this range form a contiguous subarray $D[p..q]$.
> 
> 2. **Efficient Range Localization:**
>    - Precompute `first_non_zero_idx[i]`: the index in $D$ of the first non-zero digit at or after $i$.
>    - Precompute `last_non_zero_idx[i]`: the index in $D$ of the last non-zero digit at or before $i$.
>    - For a query `[l, r]`, $p = \text{first\_non\_zero\_idx}[l]$ and $q = \text{last\_non\_zero\_idx}[r]$. If $p > q$, the substring has no non-zero digits (result is 0).
> 
> 3. **Rolling Hash / Concatenation Formula:**
>    - Compute the concatenated number $x$ of $D[p..q]$ using a prefix rolling hash array $H$:
>      $$x = (H[q+1] - H[p] \cdot 10^{q - p + 1}) \pmod{10^9+7}$$
>    - Compute the digit sum using standard prefix sums $P$:
>      $$\text{sum} = P[q+1] - P[p]$$
>    - The answer is $(x \cdot \text{sum}) \pmod{10^9+7}$.

---

## 🔩 Step-by-Step Breakdown

**Step 1 — Non-Zero Digits and Indices Filtering**
- Iterate through the string `s`.
- Save all digits other than `'0'` in a vector `D`.
- Save their original indices in `pos` to assist boundary mappings.

**Step 2 — Prefix Sum and Hash Precomputation**
- Construct the prefix sum array `P` and prefix rolling hash array `H` of `D`:
  - $P[i+1] = P[i] + D[i]$
  - $H[i+1] = (H[i] \cdot 10 + D[i]) \pmod{10^9+7}$
- Precompute the powers of 10 modulo $10^9+7$ to perform range shifts in $O(1)$ time.

**Step 3 — Query Range Mapping**
- Build mapping arrays `first_non_zero_idx` and `last_non_zero_idx` of size $m$:
  - `first_non_zero_idx[i]` tells us the index in `D` of the first non-zero character on or to the right of `i`.
  - `last_non_zero_idx[i]` tells us the index in `D` of the last non-zero character on or to the left of `i`.

**Step 4 — Constant-Time Query Evaluation**
- For each query `[l, r]`, obtain the indices $p$ and $q$ in $D$.
- If $p > q$, no non-zero digits are in the range, return `0`.
- Else, calculate $x = (H[q+1] - H[p] \cdot 10^{q - p + 1}) \pmod{10^9+7}$ (making sure to handle negative modulo subtraction in C++ by adding MOD).
- Calculate the digit sum $sum = P[q+1] - P[p]$.
- Store $(x \cdot sum) \pmod{10^9+7}$ as the answer for this query.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start(["Start: sumAndMultiply(s, queries)"]) --> Filter["Filter non-zero digits into D<br>Store original indices in pos"]
    Filter --> Maps["Precompute range maps:<br>first_non_zero_idx & last_non_zero_idx"]
    Maps --> Pref["Precompute prefix sum P, prefix hash H,<br>and powers of 10"]
    Pref --> Loop["For each query [l, r]:"]
    Loop --> MapQuery["p = first_non_zero_idx[l]<br>q = last_non_zero_idx[r]"]
    MapQuery --> Check{"p <= q?"}
    Check -- No --> ZeroAns["Result = 0"]
    Check -- Yes --> Calc["x = (H[q+1] - H[p] * 10^(q-p+1)) % MOD<br>sum = P[q+1] - P[p]<br>Result = (x * sum) % MOD"]
    ZeroAns --> Collect["Push Result to answers"]
    Calc --> Collect
    Collect --> EndLoop{"More queries?"}
    EndLoop -- Yes --> Loop
    EndLoop -- No --> Return["Return answers"]
    Return --> End(["End"])
```

---

## 📊 Complexity Analysis

| Metric | Complexity | Reasoning |
| :---: | :---: | :--- |
| 🕐 Time | $$O(m + q)$$ | $O(m)$ preprocessing for prefix arrays and index mappings, followed by $O(1)$ range evaluations per query. |
| 💾 Space | $$O(m)$$ | Space used to store prefix arrays, powers of 10, and range mapping arrays. |

---

> *"By mapping the complex to the structured, we transform exponential queries into constant time steps."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../161_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../163_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
