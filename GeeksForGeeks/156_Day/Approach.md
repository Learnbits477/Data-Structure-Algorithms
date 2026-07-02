# 💡 Approach — Subset with Sum Divisible by m

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 22.41%](https://img.shields.io/badge/Accuracy-22.41%25-green?style=for-the-badge)
![Submissions: 21K+](https://img.shields.io/badge/Submissions-21K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🎯 Core Insight

> [!TIP]
> **Pigeonhole Principle Optimization & Modulo DP**
>
> 1. **Pigeonhole Principle (PHP):**
>    - Let $n$ be the number of elements. If $n \ge k$, the number of prefix sums $S_0, S_1, \dots, S_n$ is $n + 1 \ge k + 1$.
>    - By the Pigeonhole Principle, at least two prefix sums must have the same remainder modulo $k$.
>    - The difference between these two prefix sums represents a contiguous subarray (which is a subset) whose sum is divisible by $k$.
>    - Hence, if $n \ge k$, we can return `true` immediately in $O(1)$ time.
>
> 2. **Modulo DP:**
>    - For cases where $n < k$, we maintain a boolean state array `dp` of size $k$ to track achievable subset sums modulo $k$.
>    - If remainder $j$ was possible using previous elements, then after incorporating element $x$ with $rem = x \pmod k$, the remainder $(j + rem) \pmod k$ also becomes possible.
>    - We also mark the current element's remainder $rem$ as achievable (a single-element subset).
>    - If at any point the remainder $0$ becomes achievable, we exit early and return `true`.

---

## 🔩 Step-by-Step Breakdown

**Step 1 — Apply Pigeonhole Principle Check**
- If the array size $n \ge k$, return `true` immediately.
- This is because among $n$ prefix sums, at least two will share the same remainder modulo $k$, and their difference yields a non-empty subarray sum that is divisible by $k$.

**Step 2 — Initialize DP Table**
- Create a boolean array `dp` of size $k$ initialized to `false`.
- This array tracks achievable subset sums modulo $k$. We do not pre-initialize `dp[0] = true` to avoid counting an empty subset.

**Step 3 — Iterate and Transition States**
- For each element $x$ in the array:
  - Compute `rem = x % k`.
  - Create a copy of the current DP state `next_dp = dp`.
  - For each remainder `j` from $0$ to $k-1$:
    - If `dp[j]` is `true`, set `next_dp[(j + rem) % k] = true`.
  - Mark `next_dp[rem] = true` (representing the single element subset `{x}`).
  - Update `dp = next_dp`.
  - **Early Exit:** If `dp[0]` is `true`, return `true` immediately as we found a non-empty subset whose sum is divisible by $k$.

**Step 4 — Return Failure**
- If we finish iterating through all elements and `dp[0]` is still `false`, return `false`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start(["Start: divisibleByK(arr, k)"]) --> CheckPHP{"n >= k?"}
    CheckPHP -- Yes --> ReturnTruePHP["Return true (Pigeonhole Principle)"]
    CheckPHP -- No --> InitDP["Initialize dp[k] = {false}"]
    InitDP --> Loop["For each x in arr"]
    Loop --> ComputeRem["rem = x % k"]
    ComputeRem --> CopyDP["next_dp = dp"]
    CopyDP --> InnerLoop["For j = 0 to k-1"]
    InnerLoop --> Transition{"dp[j] is true?"}
    Transition -- Yes --> SetState["next_dp[(j + rem) % k] = true"]
    Transition -- No --> NextJ["Next j"]
    SetState --> NextJ
    NextJ --> EndInner{"All j processed?"}
    EndInner -- No --> InnerLoop
    EndInner -- Yes --> SetSelf["next_dp[rem] = true"]
    SetSelf --> UpdateDP["dp = next_dp"]
    UpdateDP --> CheckZero{"dp[0] == true?"}
    CheckZero -- Yes --> ReturnTrueDP["Return true"]
    CheckZero -- No --> CheckEnd{"All elements processed?"}
    CheckEnd -- No --> Loop
    CheckEnd -- Yes --> ReturnFalse["Return false"]
```

---

## 🧮 Dry Run — Example 1 ($arr = [3, 1, 7, 5], k = 6$)

- **Step 1: Initialization**
  - $n = 4$, $k = 6$. Since $n < k$, we bypass the Pigeonhole Principle check.
  - `dp` of size $6$ is initialized to all `false`.

- **Step 2: State Transitions**
  - **At element $3$ ($rem = 3$):**
    - `next_dp[3] = true`.
    - `dp = [F, F, F, T, F, F]`.
  - **At element $1$ ($rem = 1$):**
    - `dp[3]` is `true` $\implies$ `next_dp[(3+1)%6] = next_dp[4] = true`.
    - `next_dp[1] = true`.
    - `dp = [F, T, F, T, T, F]`.
  - **At element $7$ ($rem = 7 \pmod 6 = 1$):**
    - `dp[1]` is `true` $\implies$ `next_dp[(1+1)%6] = next_dp[2] = true`.
    - `dp[3]` is `true` $\implies$ `next_dp[(3+1)%6] = next_dp[4] = true`.
    - `dp[4]` is `true` $\implies$ `next_dp[(4+1)%6] = next_dp[5] = true`.
    - `next_dp[1] = true`.
    - `dp = [F, T, T, T, T, T]`.
  - **At element $5$ ($rem = 5$):**
    - `dp[1]` is `true` $\implies$ `next_dp[(1+5)%6] = next_dp[0] = true`.
    - Since `next_dp[0]` is `true`, we immediately return `true`.

---

## 📊 Complexity Analysis

| Metric | Complexity | Reasoning |
| :---: | :---: | :--- |
| 🕐 Time | $$O(n \cdot k)$$ | We do at most $k$ iterations of the DP update for each of the $n$ elements. Due to PHP optimization, $n < k$ holds when we run DP, so worst-case time is bounded by $O(k^2)$ which is $10^6$ operations. |
| 💾 Space | $$O(k)$$ | We maintain a few boolean DP arrays of size $k$ to store the state. |

---

> *"Dividing a problem down to its remainders is the first step toward conquering its complexity."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../155_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../157_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
