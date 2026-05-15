# 💡 Approach — Special Keyboard

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 28.66%](https://img.shields.io/badge/Accuracy-28.66%25-blue?style=for-the-badge)
![Submissions: 53K+](https://img.shields.io/badge/Submissions-53K+-brightgreen?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Company Tags](https://img.shields.io/badge/Company%20Tags-Paytm%20|%20Flipkart%20|%20Amazon%20|%20Microsoft%20|%20Google-black?style=for-the-badge)

> [!TIP]
> **Core Insight:**
> For $n \le 6$, the maximum number of 'A's is simply $n$ (pressing Key 1 repeatedly). For $n > 6$, the optimal sequence will always end with a series of pastes (Key 4) preceded by a "Select All" (Key 2) and "Copy" (Key 3). Thus, if we perform the Ctrl+A and Ctrl+C operations at step $j$, the multiplier for the copied length will be $(i - j - 1)$ for the remaining steps up to $i$. We can dynamically calculate the max 'A's by finding the best break point $j$.

---
## 🔩 Step-by-Step Breakdown

1.  **Handle Base Cases:** If $n \le 6$, the optimal strategy is to just press Key 1 $n$ times. Thus, we can directly return $n$.
2.  **Initialize DP Array:** Create an array `dp` of size `n + 1` to store the maximum characters achievable for each key press count. For indices $1$ to $6$, set `dp[i] = i`.
3.  **Iterate for Larger $n$:** Start computing values from $i = 7$ up to $n$.
4.  **Find Optimal Break Point:** For each $i$, determine the optimal step $j$ (where $1 \le j \le i-3$) to perform the Select and Copy operations. The number of characters becomes `dp[j] * (i - j - 1)`. Update `dp[i]` with the maximum value found.
5.  **Return Result:** After filling the `dp` array, the answer for $n$ key presses is stored in `dp[n]`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A[Start: Input n] --> B{"Is n <= 6?"}
    B -- Yes --> C[Return n]
    B -- No --> D["Init DP Array of size n+1"]
    D --> E["Set DP[1..6] = 1..6"]
    E --> F["Iterate i from 7 to n"]
    F --> G["Iterate j from 1 to i-3"]
    G --> H["Calculate dp[j] * (i - j - 1)"]
    H --> I["Update DP[i] = max"]
    I --> J{"More j?"}
    J -- Yes --> G
    J -- No --> K{"More i?"}
    K -- Yes --> F
    K -- No --> L["Return DP[n]"]
    L --> M[End]
```

---
## 📊 Complexity Analysis

| Parameter | Complexity | Description |
|-----------|------------|-------------|
| **Time Complexity** | $\mathcal{O}(N^2)$ | We use two nested loops. The outer loop runs $N$ times and the inner loop runs up to $N-3$ times. Given the constraint ($N \le 70$), this is equivalent to $\mathcal{O}(N)$ in practical execution time and easily passes. |
| **Space Complexity** | $\mathcal{O}(N)$ | The algorithm requires an array of size $N+1$ to store the dynamic programming states. |

---

> *"First, solve the problem. Then, write the code."* — John Johnson

---

<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../107_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../109_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
