# 💡 Approach — Equal Point in Brackets

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 40.8%](https://img.shields.io/badge/Accuracy-40.8%25-green?style=for-the-badge)
![Submissions: 34K+](https://img.shields.io/badge/Submissions-34K+-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topics: Strings](https://img.shields.io/badge/Topics-Strings-lightgrey?style=for-the-badge)

> [!TIP]
> **Core Insight:**
> For any split point $k$ (where $0 \le k \le n$):
> - The left part of the string has length $k$.
> - The number of characters in the left part is the sum of opening brackets and closing brackets in it: $\text{open\_count\_left} + \text{close\_count\_left} = k$.
> - The right part has closing brackets equal to: $\text{close\_count\_right} = \text{total\_closing} - \text{close\_count\_left}$.
> - We want $\text{open\_count\_left} = \text{close\_count\_right}$, which is:
>   $$\text{open\_count\_left} = \text{total\_closing} - \text{close\_count\_left}$$
>   $$\implies \text{open\_count\_left} + \text{close\_count\_left} = \text{total\_closing}$$
>   $$\implies k = \text{total\_closing}$$
> 
> Thus, the equal point $k$ is always mathematically equal to the total count of closing brackets `)` in the entire string!
> Although returning this count directly is $O(n)$ time and $O(1)$ space, we can also simulate the step-by-step verification to find the exact point explicitly, maintaining a clear algorithmic flow.

## 🔩 Step-by-Step Breakdown

1. **Step 1: Count total closing brackets**
   - Traverse the string once to count the total number of closing brackets `)` in the string. Let this count be `total_closing`.

2. **Step 2: Iterate to find the equal point**
   - Traverse the string from $k = 0$ to $n$ while tracking the number of opening brackets `open_count` and closing brackets `close_count` encountered so far.
   - At each step $k$, check if the opening brackets on the left (`open_count`) equals the closing brackets remaining on the right (`total_closing - close_count`).
   - If equal, return $k$. Otherwise, update the counters based on the character at index $k$ and continue.

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A[Start: findIndex] --> B[Initialize total_closing = 0]
    B --> C[Loop char c in str]
    C --> D{"c == ')'?"}
    D -- Yes --> E[Increment total_closing]
    D -- No --> F[Continue]
    E --> G[Next character]
    F --> G
    G --> H{End of string?}
    H -- No --> C
    H -- Yes --> I[Initialize open_count = 0, close_count = 0]
    I --> J[Loop k from 0 to n]
    J --> K{"open_count == total_closing - close_count?"}
    K -- Yes --> L[Return k]
    K -- No --> M{"k < n?"}
    M -- Yes --> N{"str[k] == '('?"}
    N -- Yes --> O[Increment open_count]
    N -- No --> P[Increment close_count]
    O --> Q[Increment k]
    P --> Q
    Q --> J
    M -- No --> R[Return -1]
```

## 📊 Complexity Analysis

| Complexity | Analysis |
|:---:|:---|
| **Time Complexity** | $$O(n)$$ — We traverse the string twice (once to count closing brackets, and once to find the index). |
| **Auxiliary Space** | $$O(1)$$ — We use a constant amount of extra memory for counters. |

> *"Elegant code is not code that does the job; it is code that does it with such simplicity that the solution seems obvious in hindsight."* — Unknown

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../134_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../136_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
