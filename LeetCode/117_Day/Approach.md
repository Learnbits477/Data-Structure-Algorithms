# 💡 Approach — Jump Game V

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 72.4%](https://img.shields.io/badge/Acceptance-72.4%25-blue?style=for-the-badge)
![Submissions: 106.3K](https://img.shields.io/badge/Submissions-106.3K-purple?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-blue?style=for-the-badge)

---

> [!TIP]
> **Core Insight:**  
> Since we can only jump from a higher element to a strictly lower element ($\text{arr}[i] > \text{arr}[j]$), the jump transitions form a **Directed Acyclic Graph (DAG)**. There can be no cycles because each step strictly decreases the height value.
> 
> Therefore, we can find the longest path in this DAG starting from any node using **Depth First Search (DFS) with Memoization (Dynamic Programming)**:
> 1. Let `dp[i]` store the maximum indices we can visit starting from index `i`.
> 2. For each index `i`, we can try jumping to index `j` within a range $d$ to the left and to the right.
> 3. The jump is valid if and only if $\text{arr}[i] > \text{arr}[j]$ and all elements between $i$ and $j$ are strictly smaller than $\text{arr}[i]$ (which means we cannot "jump over" any element that is $\ge \text{arr}[i]$). As soon as we see an element $\ge \text{arr}[i]$, we must stop scanning in that direction.
> 4. The transition is `dp[i] = 1 + max(dp[j])` for all valid destinations `j`.

---

## 🔩 Step-by-Step Breakdown

### Step 1: Initialize DP Cache
- Initialize a `dp` table of size $n$ filled with `-1` to represent unvisited/uncomputed states.

### Step 2: DFS with Memoization (`dfs(i)`)
- If `dp[i]` is already computed (i.e. `dp[i] != -1`), return `dp[i]`.
- Set the default path length starting from `i` as `ans = 1` (just visiting index `i` itself).
- **Scan Right:** Loop `x` from $1$ to $d$:
  - Let target index `j = i + x`.
  - If `j >= n` or `arr[j] >= arr[i]`, break the loop immediately (we cannot jump over or onto this element).
  - Otherwise, update `ans = max(ans, 1 + dfs(j))`.
- **Scan Left:** Loop `x` from $1$ to $d$:
  - Let target index `j = i - x`.
  - If `j < 0` or `arr[j] >= arr[i]`, break the loop immediately.
  - Otherwise, update `ans = max(ans, 1 + dfs(j))`.
- Cache the result: `dp[i] = ans` and return it.

### Step 3: Find Global Maximum
- Iterate through all possible starting indices $i$ from $0$ to $n-1$.
- Find the overall maximum indices visited: $\max_{0 \le i < n} (\text{dfs}(i))$.

---

## 🕸️ Jump Transition DAG (Example 1 Subset)

This directed graph shows a subset of valid transitions for the array `arr = [6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12]` with $d = 2$. Notice how starting at **Index 10 (value 12)** allows the longest chain of jumps: `10 --> 8 --> 6 --> 7`.

```mermaid
graph TD
    classDef startVal fill:#f9f,stroke:#333,stroke-width:2px;
    classDef pathVal fill:#bbf,stroke:#333,stroke-width:2px;
    
    idx10["Index 10 (val: 12)"]:::startVal -->|jump| idx8["Index 8 (val: 10)"]:::pathVal
    idx10 -->|jump| idx9["Index 9 (val: 6)"]
    
    idx8 -->|jump| idx6["Index 6 (val: 9)"]:::pathVal
    idx8 -->|jump| idx7["Index 7 (val: 7)"]
    idx8 -->|jump| idx9["Index 9 (val: 6)"]
    
    idx6 -->|jump| idx7["Index 7 (val: 7)"]:::pathVal
    
    idx7 --> idx_none["No outgoing jumps (Leaf)"]
    idx9 --> idx_none2["No outgoing jumps (Leaf)"]
```

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A([Start: maxJumps]) --> B["Initialize dp array with -1"]
    B --> C["Loop i from 0 to n - 1"]
    C --> D["Call dfs(i)"]
    D --> E["Update global max: ans = max(ans, dfs(i))"]
    E --> F{i == n - 1?}
    F -- No --> C
    F -- Yes --> G([Return ans])
    
    subgraph DFS [DFS i Function]
        D1{dp_i != -1?} -- Yes --> D2[Return dp_i]
        D1 -- No --> D3["Set ans = 1"]
        D3 --> D4["Loop x from 1 to d (Right Jump)"]
        D4 --> D5{"j = i + x < n and arr[i] > arr[j]?"}
        D5 -- Yes --> D6["ans = max(ans, 1 + DFS(j))"]
        D5 -- No/Blocked --> D7["Break Right Loop"]
        D6 --> D4
        D7 --> D8["Loop x from 1 to d (Left Jump)"]
        D8 --> D9{"j = i - x >= 0 and arr[i] > arr[j]?"}
        D9 -- Yes --> D10["ans = max(ans, 1 + DFS(j))"]
        D9 -- No/Blocked --> D11["Break Left Loop"]
        D10 --> D8
        D11 --> D12["dp_i = ans"]
        D12 --> D13[Return ans]
    end
```

---

## 📊 Complexity Analysis

| Type | Complexity | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $O(n \cdot d)$ | There are $n$ states in total. For each state `i`, we scan up to $d$ elements to the right and $d$ elements to the left, doing $O(1)$ work for each step. Since each state is computed exactly once, the total time complexity is bounded by $O(n \cdot d)$. |
| **Auxiliary Space** | $O(n)$ | The space is used for the memoization table `dp` of size $n$, plus the recursive system call stack which can go up to depth $n$ in the worst-case. |

---

> *"Sometimes, the longest path is found by taking one careful step at a time."* — Unknown

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../116_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../118_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
