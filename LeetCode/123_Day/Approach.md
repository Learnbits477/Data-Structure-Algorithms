# 💡 Approach — Block Placement Queries

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 22.1%](https://img.shields.io/badge/Acceptance-22.1%25-red?style=for-the-badge)
![Submissions: 16K+](https://img.shields.io/badge/Submissions-16K%2B-blue?style=for-the-badge)

</div>

---

## 🧠 Core Insight

> [!TIP]
> **The key observation:** A block of size `sz` fits in `[0, x]` if and only if the **maximum gap** between any two consecutive obstacles within `[0, x]` (including the origin `0` as a virtual obstacle, and capping the rightmost gap at `x`) is ≥ `sz`.
>
> **The clever trick:** Process queries **offline in reverse**. When reversed, type-1 queries become **obstacle removals** — meaning gaps can only **grow**. A BIT (Fenwick Tree) for **prefix maximum** only supports monotone increases, so this reversal makes it perfectly applicable.
>
> Store each gap at its **right endpoint**. To answer a type-2 query at `x`, take `max(x − prevObs, BIT.prefixMax(prevObs))` where `prevObs` is the last obstacle ≤ `x`.

---

## 🔩 Step-by-Step Breakdown

**Step 1 — Scan for maximum coordinate.**
Iterate over all queries to find `maxX` — the largest coordinate. This sizes the BIT and sentinel.

**Step 2 — Collect all type-1 positions.**
Pre-insert `0` (origin) and `maxX + 1` (right sentinel) alongside all type-1 obstacle positions into a sorted `set<int>`. This gives the initial obstacle configuration (all obstacles pre-placed since we process in reverse).

**Step 3 — Initialise BIT with all initial gaps.**
Walk consecutive pairs in the set; for each pair `(left, right)`, call `BIT.update(right, right − left)`. The BIT stores the gap with its **right endpoint** as the key.

**Step 4 — Process queries in reverse.**
- **Type 2 `[2, x, sz]`:** Find `prevObs` = last obstacle ≤ `x` via `upper_bound`. Compute `maxGap = max(x − prevObs, BIT.query(prevObs))`. Push `maxGap ≥ sz` to results.
- **Type 1 `[1, x]`** (treated as removal): Locate `x` in the set; find its `prev` and `next` neighbours. Call `BIT.update(next, next − prev)` — this widens the merged gap and always **increases** the BIT value (safe). Erase `x` from the set.

**Step 5 — Reverse results and return.**
Since queries were processed right-to-left, reverse the collected boolean answers.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A([🚀 Start]) --> B["Step 1: Scan queries → find maxX\nAdd sentinel maxX+1"]
    B --> C["Step 2: Insert 0 + all type-1 positions\n+ sentinel into sorted set"]
    C --> D["Step 3: Walk consecutive pairs\nBIT.update(right, right−left)"]
    D --> E["Step 4: i = Q−1 → 0  (reverse)"]
    E --> F{Query type?}

    F -- "Type 2\n[2, x, sz]" --> G["Find prevObs = last obstacle ≤ x\nvia upper_bound"]
    G --> H["maxGap = max(x − prevObs,\n BIT.query(prevObs))"]
    H --> I["Push maxGap ≥ sz\nto results"]
    I --> J["i--"]

    F -- "Type 1\n[1, x]  →  removal" --> K["Find prev, next in set\nBIT.update(next, next−prev)"]
    K --> L["Erase x from set"]
    L --> J

    J --> M{i < 0 ?}
    M -- No --> F
    M -- Yes --> N["Step 5: reverse(results)"]
    N --> O([✅ Return results])
```

---

## 🔍 Dry Run — Example 2

`queries = [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]`  
Initial set: `{0, 2, 7, 8}` · BIT: `update(2,2), update(7,5), update(8,1)`

| i | Query | Action | prevObs | maxGap | Result |
|:-:|:-----:|:------:|:-------:|:------:|:------:|
| 4 | `[2,7,6]` | query x=7,sz=6 | 7 | max(0, BIT(7)=5)=5 | 5≥6? ❌ false |
| 3 | `[2,7,5]` | query x=7,sz=5 | 7 | max(0, 5)=5 | 5≥5? ✅ true |
| 2 | `[1,2]`   | remove 2; update(7, 7−0=7) | — | — | — |
| 1 | `[2,7,6]` | query x=7,sz=6 | 7 | max(0, BIT(7)=7)=7 | 7≥6? ✅ true |
| 0 | `[1,7]`   | remove 7; update(8, 8−0=8) | — | — | — |

Results collected (reverse): `[false, true, true]` → reversed → **`[true, true, false]`** ✅

---

## 💡 Why Stale BIT Values Are Safe

When obstacle `x` (between `prev` and `next`) is removed:
- BIT at `x` retains the old (stale) value `x − prev`.
- BIT at `next` is updated to the new (larger) value `next − prev`.
- Any future query on `BIT.query(pos)` where `pos ≥ next` sees both values; since `x − prev < next − prev`, **the stale value is always dominated**. ✅

---

## 📊 Complexity Analysis

| Complexity Type  | Value           | Reasoning |
|:----------------:|:---------------:|:---------:|
| **Time**         | `O(Q log M)`    | Each query does one `set` operation (O(log Q)) and one BIT operation (O(log M)) |
| **Auxiliary Space** | `O(Q + M)`   | Sorted set holds ≤ Q+2 elements; BIT of size M |

> `Q` = number of queries ≤ 1.5×10⁴, `M` = max coordinate ≤ 5×10⁴

---

> *"Simplicity is prerequisite for reliability."*
> — **Edsger W. Dijkstra**

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../122_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../124_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
