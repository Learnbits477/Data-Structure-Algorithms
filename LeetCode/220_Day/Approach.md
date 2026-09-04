# 💡 Approach — Smallest Stable Index I

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-green?style=for-the-badge)
![Acceptance: 71.4%](https://img.shields.io/badge/Acceptance-71.4%25-green?style=for-the-badge)
![Submissions: 86.2K+](https://img.shields.io/badge/Submissions-86.2K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Array%20%7C%20Prefix%20Sum-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Prefix Maximum & Suffix Minimum Decomposition:**
> - For any index $i \in [0, n - 1]$:
>   - $\text{max\_prefix}(i) = \max(\text{nums}[0 \dots i])$ is monotonically non-decreasing as $i$ increases.
>   - $\text{min\_suffix}(i) = \min(\text{nums}[i \dots n - 1])$ is the minimum element in the suffix from $i$ to $n-1$.
> - The instability score at index $i$ is defined as:
>   $$\text{score}(i) = \text{max\_prefix}(i) - \text{min\_suffix}(i)$$
> - By precomputing the suffix minimums in $\mathcal{O}(n)$ time and maintaining a running prefix maximum during a single forward pass, we can compute the instability score for every index $i$ in $\mathcal{O}(1)$ time.
> - The first (smallest) index $i$ where $\text{score}(i) \le k$ is our answer. If no such index satisfies the condition, return $-1$.

---

## 🔩 Step-by-Step Breakdown

1. **Precompute Suffix Minimums**:
   - Create an array `suffix_min` of size $n$.
   - Set $\text{suffix\_min}[n - 1] = \text{nums}[n - 1]$.
   - Iterate backwards from $i = n - 2$ down to $0$:
     $$\text{suffix\_min}[i] = \min(\text{nums}[i], \text{suffix\_min}[i + 1])$$

2. **Evaluate Instability Scores with Running Prefix Maximum**:
   - Initialize `prefix_max = nums[0]`.
   - Iterate forward from $i = 0$ to $n - 1$:
     - Update $\text{prefix\_max} = \max(\text{prefix\_max}, \text{nums}[i])$.
     - Calculate $\text{instability\_score} = \text{prefix\_max} - \text{suffix\_min}[i]$.
     - If $\text{instability\_score} \le k$, immediately return index $i$ as it is the smallest stable index.

3. **Fallback**:
   - If the loop completes without finding any stable index, return $-1$.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A["Start: firstStableIndex(nums, k)"] --> B["Compute suffix_min array<br/>from right to left (n-1 down to 0)"]
    B --> C["Initialize prefix_max = 0<br/>Loop i from 0 to n - 1"]
    C --> D["prefix_max = max(prefix_max, nums[i])"]
    D --> E{"prefix_max - suffix_min[i] <= k?"}
    E -- "Yes" --> F["Return i (Smallest Stable Index) ✅"]
    E -- "No" --> G{"i < n - 1?"}
    G -- "Yes" --> H["i = i + 1"]
    H --> D
    G -- "No" --> I["Return -1 (No Stable Index) ❌"]
```

---

## 🏃‍♂️ Dry Run

### Example 1: $\text{nums} = [5, 0, 1, 4]$, $k = 3$ ($n = 4$)

1. **Precomputing Suffix Minimums:**
   - $\text{suffix\_min}[3] = 4$
   - $\text{suffix\_min}[2] = \min(1, 4) = 1$
   - $\text{suffix\_min}[1] = \min(0, 1) = 0$
   - $\text{suffix\_min}[0] = \min(5, 0) = 0$
   - Array: $\text{suffix\_min} = [0, 0, 1, 4]$

2. **Forward Scan:**

| Index $i$ | $\text{nums}[i]$ | `prefix_max` | `suffix_min[i]` | Instability Score | $\le k=3$? | Action |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **0** | $5$ | $5$ | $0$ | $5 - 0 = 5$ | ❌ No | Continue |
| **1** | $0$ | $5$ | $0$ | $5 - 0 = 5$ | ❌ No | Continue |
| **2** | $1$ | $5$ | $1$ | $5 - 1 = 4$ | ❌ No | Continue |
| **3** | $4$ | $5$ | $4$ | $5 - 4 = 1$ | ✅ Yes | **Return 3** |

**Final Answer:** $\mathbf{3}$ ✅

---

## 📊 Complexity Analysis

| Complexity Metric | Estimation | Rationale |
| :--- | :---: | :--- |
| **Time Complexity** | $\mathcal{O}(n)$ | Backward pass to compute suffix minimums takes $\mathcal{O}(n)$. Forward pass takes at most $\mathcal{O}(n)$. Overall time is strictly linear. |
| **Auxiliary Space** | $\mathcal{O}(n)$ | Storing the `suffix_min` array requires $\mathcal{O}(n)$ extra space. |

---

> *"Prefix and suffix decompositions turn global window queries into instant local lookups."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../219_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../221_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
