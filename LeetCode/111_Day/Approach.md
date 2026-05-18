# 💡 Approach — Maximum Sum Problem

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 57.09%](https://img.shields.io/badge/Accuracy-57.09%25-blue?style=for-the-badge)
![Submissions: 66K+](https://img.shields.io/badge/Submissions-66K+-purple?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-blue?style=for-the-badge)

---
> [!TIP]
> **Core Insight:** The problem requires us to find the maximum sum of $n$ after recursively splitting it into $\lfloor n/2 \rfloor$, $\lfloor n/3 \rfloor$, and $\lfloor n/4 \rfloor$. At each step, we can either keep $n$ as it is or split it. This exhibits **Optimal Substructure** and **Overlapping Subproblems**, defined by the recurrence relation:
> $$f(n) = \max(n, f(\lfloor n/2 \rfloor) + f(\lfloor n/3 \rfloor) + f(\lfloor n/4 \rfloor))$$
> Since $n \le 10^6$, we can compute these values bottom-up using a Dynamic Programming table (array) in linear time $O(n)$ without any recursion stack overhead!

---

## 🔩 Step-by-Step Breakdown
1. **Handle Base Cases:** If $n = 0$, the maximum sum is simply $0$.
2. **Initialize DP Table:** Create a vector `dp` of size $n + 1$ initialized with $0$ to store the maximum sum for each value from $0$ to $n$.
3. **Bottom-Up DP Computation:** Loop through all integers $i$ from $1$ to $n$. For each $i$, compute `dp[i]` as the maximum of:
   - The number itself: $i$
   - The sum of its recursive splits: `dp[i / 2] + dp[i / 3] + dp[i / 4]`
4. **Return Results:** Return the precalculated result for $n$, which is `dp[n]`.

---

## 🔄 Mermaid Flowchart
```mermaid
flowchart TD
    A[Start] --> B{"Is n == 0?"}
    B -- Yes --> C[Return 0]
    B -- No --> D["Initialize dp array of size n + 1"]
    D --> E["Iterate i from 1 to n"]
    E --> F["dp[i] = max(i, dp[i/2] + dp[i/3] + dp[i/4])"]
    F --> G{"Is i == n?"}
    G -- No --> E
    G -- Yes --> H["Return dp[n]"]
    H --> I[End]
```

---

## 📊 Complexity Analysis
| Type | Complexity | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $$O(n)$$ | We compute the maximum sum for each integer from $1$ to $n$ exactly once. Each transition takes $$O(1)$$ time. |
| **Auxiliary Space** | $$O(n)$$ | We use a DP array of size $$n + 1$$ to store the computed results. For the maximum constraint $n = 10^6$, this is only ~4 MB. |

---

> *"Recursion is the root of computation, but memoization is the fruit of efficiency."*

---

<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../110_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../112_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
