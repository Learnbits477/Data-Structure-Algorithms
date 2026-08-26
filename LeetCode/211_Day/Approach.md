# 💡 Approach — Shortest and Lexicographically Smallest Beautiful String

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 52.1%](https://img.shields.io/badge/Acceptance-52.1%25-green?style=for-the-badge)
![Submissions: 142K](https://img.shields.io/badge/Submissions-142K-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-String-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Sliding%20Window-blue?style=for-the-badge)

---

> [!TIP]
> **Core Algorithmic Insight — Index Tracking of Minimal Substrings:**
> - Any **shortest** beautiful substring containing exactly $k$ ones must **start with `'1'`** and **end with `'1'`**.
> - If a substring starts or ends with `'0'`, trimming that `'0'` produces a strictly shorter substring with the exact same number of `1`'s.
> - Therefore, if we record all indices where $s[i] == '1'$ into a list `ones`:
>   - Every candidate minimal beautiful substring corresponds directly to a window of length $k$ in `ones`:
>     $$\text{left} = \text{ones}[i], \quad \text{right} = \text{ones}[i + k - 1]$$
>   - The candidate substring is $s[\text{left} \dots \text{right}]$, having length $\text{len} = \text{right} - \text{left} + 1$.
> - We simply iterate through all valid windows of size $k$ and maintain the shortest (and lexicographically smallest) substring.

---

## 🧭 Intuition & Mathematical Formulation

1. **Boundary Property:**
   - Let a candidate substring have indices $[L, R]$.
   - If $s[L] == '0'$, the substring $[L+1, R]$ has fewer characters and still has $k$ ones.
   - If $s[R] == '0'$, the substring $[L, R-1]$ has fewer characters and still has $k$ ones.
   - Hence, an optimal shortest substring must satisfy $s[L] = '1'$ and $s[R] = '1'$.

2. **Index Collection:**
   - Let $\text{ones} = [p_0, p_1, \dots, p_{m-1}]$ be the 0-indexed positions where $s[p_j] == '1'$.
   - If $m < k$, it is impossible to have $k$ ones $\implies$ return `""`.

3. **Window Traversal:**
   - For every $i \in [0, m - k]$:
     - Form $\text{sub} = s[p_i \dots p_{i+k-1}]$.
     - Length is $p_{i+k-1} - p_i + 1$.
     - Compare with current best `result`:
       - If `sub.length() < result.length()`, update `result = sub`.
       - If `sub.length() == result.length()` and `sub < result`, update `result = sub`.

---

## 🔩 Step-by-Step Breakdown

1. **Step 1: Collect all indices where $s[i] == '1'$**:
   - Iterate over string $s$ and store every index $i$ where $s[i] == '1'$ in `ones`.

2. **Step 2: If total 1's is less than $k$, return empty string**:
   - If `ones.size() < k`, return `""`.

3. **Step 3: Find the shortest and lexicographically smallest beautiful substring**:
   - Initialize `result = ""`.
   - For each window $i$ from $0$ to $\text{ones.size()} - k$:
     - Let $\text{left} = \text{ones}[i]$ and $\text{right} = \text{ones}[i + k - 1]$.
     - Extract $\text{sub} = s.\text{substr}(\text{left}, \text{right} - \text{left} + 1)$.
     - If `result` is empty, or $\text{sub}$ is shorter, or $\text{sub}$ has same length and is lexicographically smaller:
       - Update `result = sub`.

4. **Step 4: Return optimal beautiful substring**:
   - Return `result`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A["Start: shortestBeautifulSubstring(s, k)"] --> B["Collect indices of '1' into vector ones"]
    B --> C{"ones.size() < k?"}
    C -- Yes --> D["Return empty string ''"]
    C -- No --> E["Initialize result = ''<br/>Loop i from 0 to ones.size() - k"]
    E --> F["left = ones[i]<br/>right = ones[i + k - 1]<br/>sub = s.substr(left, right - left + 1)"]
    F --> G{"result.empty() OR<br/>sub.length() < result.length() OR<br/>(sub.length() == result.length() AND sub < result)?"}
    G -- Yes --> H["result = sub"]
    G -- No --> I{"More windows?"}
    H --> I
    I -- Yes --> E
    I -- No --> J["Return result"]
```

---

## 🏃‍♂️ Dry Run

Let's trace **Example 1:** `s = "100011001"`, `k = 3`:

- Indices of `'1'`: `ones = [0, 4, 5, 8]`
- Total 1's $m = 4 \ge 3$.

| Window $i$ | `left` ($\text{ones}[i]$) | `right` ($\text{ones}[i+2]$) | Candidate `sub` | Length | Comparison with `result` | New `result` |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **0** | $0$ | $5$ | `"100011"` | $6$ | `result` was empty | `"100011"` |
| **1** | $4$ | $8$ | `"11001"` | $5$ | $\text{len } 5 < 6$ (shorter!) | `"11001"` |

- **Final Answer:** `"11001"`

---

## 📊 Complexity Analysis

| Complexity Metric | Estimation | Rationale |
| :--- | :---: | :--- |
| **Time Complexity** | $\mathcal{O}(n^2)$ | Collecting 1s takes $\mathcal{O}(n)$. There are at most $n$ windows of size $k$, and extracting/comparing substrings of length up to $n$ takes $\mathcal{O}(n)$. With $n \le 100$, this executes in $< 1\text{ ms}$. |
| **Auxiliary Space** | $\mathcal{O}(n)$ | Vector `ones` stores at most $n$ indices, and `result` stores a substring of length at most $n$. |

---

> *"Find the true anchors, and the noise between them easily resolves."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../210_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../212_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
