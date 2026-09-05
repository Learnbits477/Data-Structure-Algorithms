# 💡 Approach — Smallest Stable Index II

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 74.8%](https://img.shields.io/badge/Acceptance-74.8%25-green?style=for-the-badge)
![Submissions: 74.4K+](https://img.shields.io/badge/Submissions-74.4K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Array%20%7C%20Prefix%20Sum-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Linear Prefix Max & Suffix Min Decomposition:**
> - For every index $i \in [0, n - 1]$:
>   - $\text{max\_prefix}(i) = \max(\text{nums}[0 \dots i])$ represents the running maximum from index $0$ to $i$.
>   - $\text{min\_suffix}(i) = \min(\text{nums}[i \dots n - 1])$ represents the suffix minimum from index $i$ to $n - 1$.
> - The instability score at index $i$ is:
>   $$\text{score}(i) = \text{max\_prefix}(i) - \text{min\_suffix}(i)$$
> - Because $n \le 10^5$, an $\mathcal{O}(n^2)$ brute-force check would result in Time Limit Exceeded (TLE).
> - By precomputing all suffix minimums from right to left in $\mathcal{O}(n)$ time and performing a single forward scan while maintaining `prefix_max`, each index's score is computed in $\mathcal{O}(1)$ time.
> - The first index $i$ satisfying $\text{score}(i) \le k$ is returned immediately. If no index satisfies this, return $-1$.

---

## 🔩 Step-by-Step Breakdown

1. **Precompute Suffix Minimums**:
   - Allocate `suffix_min` vector of size $n$.
   - Initialize $\text{suffix\_min}[n - 1] = \text{nums}[n - 1]$.
   - Iterate backwards from $i = n - 2$ down to $0$:
     $$\text{suffix\_min}[i] = \min(\text{nums}[i], \text{suffix\_min}[i + 1])$$

2. **Evaluate Instability Scores**:
   - Initialize `prefix_max = nums[0]`.
   - Iterate forward from $i = 0$ to $n - 1$:
     - Update $\text{prefix\_max} = \max(\text{prefix\_max}, \text{nums}[i])$.
     - Compute $\text{score} = (\text{long long})\text{prefix\_max} - \text{suffix\_min}[i]$.
     - If $\text{score} \le k$, return $i$ immediately (smallest index).

3. **Fallback**:
   - If no valid index is found across the entire array, return $-1$.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A["Start: smallestStableIndex(nums, k)"] --> B["Compute suffix_min array<br/>from right to left (n-1 down to 0)"]
    B --> C["Initialize prefix_max = nums[0]<br/>Loop i from 0 to n - 1"]
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

1. **Suffix Minimums Array:**
   - $\text{suffix\_min}[3] = 4$
   - $\text{suffix\_min}[2] = \min(1, 4) = 1$
   - $\text{suffix\_min}[1] = \min(0, 1) = 0$
   - $\text{suffix\_min}[0] = \min(5, 0) = 0$
   - $\text{suffix\_min} = [0, 0, 1, 4]$

2. **Forward Scan:**

| Index $i$ | $\text{nums}[i]$ | `prefix_max` | `suffix_min[i]` | Score (`prefix_max - suffix_min[i]`) | $\le k=3$? | Result |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **0** | $5$ | $5$ | $0$ | $5 - 0 = 5$ | ❌ No | Next |
| **1** | $0$ | $5$ | $0$ | $5 - 0 = 5$ | ❌ No | Next |
| **2** | $1$ | $5$ | $1$ | $5 - 1 = 4$ | ❌ No | Next |
| **3** | $4$ | $5$ | $4$ | $5 - 4 = 1$ | ✅ Yes | **Return 3** |

**Final Output:** $\mathbf{3}$ ✅

---

## 📊 Complexity Analysis

| Complexity Metric | Estimation | Rationale |
| :--- | :---: | :--- |
| **Time Complexity** | $\mathcal{O}(n)$ | Backward traversal takes $\mathcal{O}(n)$ and forward traversal takes at most $\mathcal{O}(n)$. Overall linear time. |
| **Auxiliary Space** | $\mathcal{O}(n)$ | Storing the `suffix_min` array takes $\mathcal{O}(n)$ extra space (approx. 400 KB for $n = 10^5$). |

---

> *"Precomputation of suffix extrema allows constant-time boundary queries during linear scans."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../220_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../222_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
