# 💡 Approach — Minimum Moves to Make Array Complementary

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 48.6%](https://img.shields.io/badge/Acceptance-48.6%25-red?style=for-the-badge)
![Submissions: 35.8K](https://img.shields.io/badge/Submissions-35.8K-lightgrey?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Topic-Hash%20Table-blue?style=for-the-badge)
![Topic: Prefix Sum](https://img.shields.io/badge/Topic-Prefix%20Sum-blueviolet?style=for-the-badge)

---

> [!TIP]
> **Core Insight:** For each mirrored pair `(a, b)`, the cost to achieve a target sum `T`
> is a **step function** with at most 4 breakpoints. Instead of evaluating every `T` per pair
> (O(n·limit)), we accumulate those breakpoints into a **difference array** and recover the
> minimum with a single prefix-sum sweep — yielding **O(n + limit)** overall.

---

## 🎯 Why Not Brute Force?

| Approach | Time | Notes |
|---|---|---|
| Try every T for every pair | $O(n \cdot \text{limit})$ | TLE for $n, \text{limit} = 10^5$ |
| Sorting + greedy | Does not apply cleanly | Pairs are interdependent |
| **Difference Array + Prefix Sum** ✅ | $O(n + \text{limit})$ | Optimal; 4 breakpoints per pair |

---

## 🔩 Step-by-Step Breakdown

### Step 1 — Understand a Single Pair

For each symmetric pair `(nums[i], nums[n-1-i])`:

```
lo = min(a, b),   hi = max(a, b)

Cost to achieve target sum T:
  ┌─────────────────────────────────────────────────────┐
  │  T in [2, lo]              →  2 moves (change both)     │
  │  T in [lo+1, lo+hi-1]     →  1 move  (change lo)        │
  │  T = lo+hi                 →  0 moves (already done).   │
  │  T in [lo+hi+1, limit+hi] →  1 move  (change hi)        │
  │  T in [limit+hi+1,2*limit]→  2 moves (change both)      │
  └─────────────────────────────────────────────────────┘
```

This cost function has exactly **4 breakpoints**: `lo+1`, `lo+hi`, `lo+hi+1`, `limit+hi+1`.

### Step 2 — Build the Difference Array

Start with total cost `= n` (n/2 pairs × 2 base moves each).  
For each pair `(lo, hi)`, apply delta changes at breakpoints:

```
delta[lo + 1]        -= 1    // cost 2 → 1 starts here
delta[lo + hi]       -= 1    // cost 1 → 0  (perfect sum)
delta[lo + hi + 1]   += 1    // cost 0 → 1  (past perfect)
delta[limit + hi + 1]+= 1    // cost 1 → 2  (out of range)
```

### Step 3 — Prefix Sum Sweep

Scan `T` from `2` to `2·limit`. At each `T`:

```cpp
total += delta[T];
ans    = min(ans, total);
```

The running `total` always equals the exact number of moves for target `T`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A([Start]) --> B["Initialize delta array of size 2·limit+2 with zeros"]
    B --> C["Set total = n  base cost for all pairs"]
    C --> D{For each pair i = 0 to n/2-1}
    D --> E["lo = min, hi = max of the mirrored pair"]
    E --> F["delta[lo+1] -= 1"]
    F --> G["delta[lo+hi] -= 1"]
    G --> H["delta[lo+hi+1] += 1"]
    H --> I["delta[limit+hi+1] += 1"]
    I --> D
    D -- All pairs processed --> J{Prefix sum sweep T = 2 to 2·limit}
    J --> K["total += delta[T]"]
    K --> L["ans = min(ans, total)"]
    L --> J
    J -- Done --> M([Return ans])
```

---

## 🖼️ Premium Visualization

```mermaid
flowchart TD
    %% Base Array
    N["nums = [1, 2, 4, 3] | limit = 4"] --> P1["Pair A: (1, 3)<br>lo=1, hi=3"]
    N --> P2["Pair B: (2, 4)<br>lo=2, hi=4"]

    %% Pair A deltas
    subgraph Breakpoints Pair A
        P1 -->|cost 2 → 1<br>lo+1| A1["delta[2] -= 1"]
        P1 -->|cost 1 → 0<br>lo+hi| A2["delta[4] -= 1"]
        P1 -->|cost 0 → 1<br>lo+hi+1| A3["delta[5] += 1"]
        P1 -->|cost 1 → 2<br>limit+hi+1| A4["delta[5] += 1"]
    end

    %% Pair B deltas
    subgraph Breakpoints Pair B
        P2 -->|cost 2 → 1<br>lo+1| B1["delta[3] -= 1"]
        P2 -->|cost 1 → 0<br>lo+hi| B2["delta[6] -= 1"]
        P2 -->|cost 0 → 1<br>lo+hi+1| B3["delta[7] += 1"]
        P2 -->|cost 1 → 2<br>limit+hi+1| B4["delta[7] += 1"]
    end

    %% Aggregation
    A1 & A2 & A3 & A4 & B1 & B2 & B3 & B4 --> agg(("Combined Delta<br>Array"))

    agg --> D2["T=2: delta=-1"]
    agg --> D3["T=3: delta=-1"]
    agg --> D4["T=4: delta=-1"]
    agg --> D5["T=5: delta=+2"]
    agg --> D6["T=6: delta=-1"]
    agg --> D7["T=7: delta=+2"]

    %% Sweep
    S0["Base total = 4"] -->|add delta| S2["T=2: ans=3"]
    D2 -.-> S2
    S2 -->|add delta| S3["T=3: ans=2"]
    D3 -.-> S3
    S3 -->|add delta| S4["T=4: ans=1 🏆 Minimum"]
    D4 -.-> S4
    S4 -->|add delta| S5["T=5: ans=3"]
    D5 -.-> S5
    S5 -->|add delta| S6["T=6: ans=2"]
    D6 -.-> S6
    S6 -->|add delta| S7["T=7: ans=4"]
    D7 -.-> S7

    style S4 fill:#2e8b57,stroke:#fff,stroke-width:2px,color:#fff
```

---

## 📊 Complexity Analysis

| Phase | Time | Space |
|---|---|---|
| Build delta (n/2 pairs) | $O(n)$ | $O(\text{limit})$ |
| Prefix sum sweep | $O(\text{limit})$ | $O(1)$ |
| **Overall** | $O(n + \text{limit})$ | $O(\text{limit})$ |

---

## ⚙️ Key Implementation Notes

1. **Delta array size** — `2 * limit + 2` to safely accommodate index `limit+hi+1` (max = `2·limit+1`).
2. **Base cost = n** — `n/2` pairs, each costing 2 moves initially; using `n` simplifies the accumulation.
3. **Breakpoint at `lo+hi`** — the `-1` at `lo+hi` (not `lo+hi-1`) ensures `T = lo+hi` itself costs 0 (the transition point is inclusive on the left).
4. **No floating-point** — pure integer arithmetic throughout; no risk of precision issues.
5. **Valid T range** — only sweep `T` from `2` (minimum possible sum: `1+1`) to `2·limit` (maximum: `limit+limit`).

---

> *"The ability to simplify means to eliminate the unnecessary so that the necessary may speak."*  
> — **Hans Hofmann**, Artist & Educator

---
<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../105_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../107_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
