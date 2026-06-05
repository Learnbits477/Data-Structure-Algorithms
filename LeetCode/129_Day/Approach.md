# 💡 Approach — Total Waviness of Numbers in Range II

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Topic-Math-brightgreen?style=for-the-badge)

> [!TIP]
> **Core Insight:**  
> This problem can be elegantly solved using **Digit DP**. Instead of evaluating each number individually (which is too slow for $10^{15}$), we can dynamically count the waviness by building the number digit by digit. For a given state, we track the current digit and its two previous predecessors to determine if a "peak" or "valley" condition has been satisfied.

## 🔩 Step-by-Step Breakdown

1.  **Digit DP Framework**:
    - We use the function `solve(num)` to compute the total waviness for all numbers in the range `[1, num]`.
    - Our answer will then be `solve(num2) - solve(num1 - 1)`.
2.  **State Definition**:
    - `idx`: The current index in the string representation of our upper bound limit.
    - `tight`: A boolean indicating if we are bounded by the digits of the upper limit string.
    - `leading_zero`: A boolean flag checking if we're still padding zeros at the start of our constructed number.
    - `prev`: The digit chosen immediately prior.
    - `prev_prev`: The digit chosen two steps prior.
3.  **Recursive Subproblem (Waviness Calculation)**:
    - At each step, iterate through all valid digits `d` (from `0` to `limit`).
    - Using `prev` and `prev_prev`, determine if the newly formed triplet constitutes a peak or a valley.
    - A **peak** occurs if `prev_prev < prev > d` and a **valley** occurs if `prev_prev > prev < d`.
    - Crucially, we ignore `leading_zero`s since they do not contribute to peaks or valleys.
4.  **Combinatorial Accumulation**:
    - Instead of just returning waviness, the recursive function returns a `pair`: the total count of valid numbers formed down that recursive path, and their aggregated waviness sum.
    - `Total Waviness = child_waviness + (added_waviness * child_count)`.
5.  **Memoization Check**:
    - Since many states overlap, we store the computed `pair` results in a 5D array cache initialized for each call of `solve()` to trim our complexity heavily.

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A["Start dfs(idx, tight, lz, prev, pp)"] --> B{"Is idx == length?"}
    B -- "Yes" --> C["Return {1, 0}"]
    B -- "No" --> D{"Is memoized?"}
    D -- "Yes" --> E["Return memo[state]"]
    D -- "No" --> F["Determine limit"]
    F --> G["Loop digit d from 0 to limit"]
    G --> H{"Valid triplet?"}
    H -- "Yes" --> I{"Is Peak or Valley?"}
    I -- "Yes" --> J["added = 1"]
    I -- "No" --> K["added = 0"]
    H -- "No" --> K
    J --> L["res = dfs(idx+1, new_state)"]
    K --> L
    L --> M["accumulate counts and waviness"]
    M --> N{"More digits to try?"}
    N -- "Yes" --> G
    N -- "No" --> O["Save memo and return"]
```

## 📊 Complexity Analysis

| Measure | Complexity | Explanation |
|:---:|:---:|:---|
| **Time Complexity** | $$O(\log_{10}(\text{num2}))$$ | There are $\approx 16 \times 2 \times 2 \times 11 \times 11$ possible states. Evaluating each state takes $O(10)$ time, leading to near instant execution. |
| **Space Complexity** | $$O(\log_{10}(\text{num2}))$$ | The depth of the recursive call stack is capped at $16$, and the DP table memory usage is $O(1)$ relatively (constant dimensions). |

> *"First, solve the problem. Then, write the code."* — John Johnson

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../128_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../130_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
