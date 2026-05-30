# [3161. Block Placement Queries](https://leetcode.com/problems/block-placement-queries/description/)

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

![Topic: Array](https://img.shields.io/badge/Topic-Array-blueviolet?style=for-the-badge)
![Topic: Binary Search](https://img.shields.io/badge/Topic-Binary%20Search-orange?style=for-the-badge)
![Topic: BIT](https://img.shields.io/badge/Topic-Binary%20Indexed%20Tree-teal?style=for-the-badge)
![Topic: Segment Tree](https://img.shields.io/badge/Topic-Segment%20Tree-darkblue?style=for-the-badge)

</div>

---

## 🧩 Problem Description

There exists an **infinite number line**, with its origin at `0` and extending towards the positive x-axis.

You are given a 2D array `queries`, which contains two types of queries:

- **Type 1** — `queries[i] = [1, x]`: Build an obstacle at distance `x` from the origin. It is guaranteed that there is no obstacle at distance `x` when the query is asked.
- **Type 2** — `queries[i] = [2, x, sz]`: Check if it is possible to place a block of size `sz` **anywhere** in the range `[0, x]` on the line, such that the block **entirely lies** in the range `[0, x]`. A block **cannot** be placed if it intersects with any obstacle, but it **may touch** it. Note that you do not actually place the block — queries are independent.

Return a boolean array `results`, where `results[i]` is `true` if you can place the block specified in the `i`-th query of type 2, and `false` otherwise.

---

## 📌 Examples

### Example 1

**Input:**
```
queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]
```

**Output:**
```
[false, true, true]
```

**Explanation:**

| Query | Action | Effect |
|:-----:|:------:|:------:|
| `[1,2]` | Place obstacle at `x=2` | Obstacles: `{2}` |
| `[2,3,3]` | Can we fit size `3` in `[0,3]`? | Max gap = 2 → ❌ **false** |
| `[2,3,1]` | Can we fit size `1` in `[0,3]`? | Max gap = 2 ≥ 1 → ✅ **true** |
| `[2,2,2]` | Can we fit size `2` in `[0,2]`? | Gap `[0,2]` = 2 ≥ 2 → ✅ **true** |

---

### Example 2

**Input:**
```
queries = [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]
```

**Output:**
```
[true, true, false]
```

**Explanation:**

| Query | Action | Max Gap in Range | Result |
|:-----:|:------:|:----------------:|:------:|
| `[1,7]` | Obstacle at `x=7` | — | — |
| `[2,7,6]` | Fit size `6` in `[0,7]`? | `7` (gap `[0,7]`) | ✅ **true** |
| `[1,2]` | Obstacle at `x=2` | — | — |
| `[2,7,5]` | Fit size `5` in `[0,7]`? | `5` (gap `[2,7]`) | ✅ **true** |
| `[2,7,6]` | Fit size `6` in `[0,7]`? | `5` (gap `[2,7]`) | ❌ **false** |

---

## 📐 Constraints

$$1 \leq \text{queries.length} \leq 1.5 \times 10^4$$

$$2 \leq \text{queries}[i].\text{length} \leq 3$$

$$1 \leq \text{queries}[i][0] \leq 2$$

$$1 \leq x,\ sz \leq \min(5 \times 10^4,\ 3 \times \text{queries.length})$$

- The input guarantees that for Type 1 queries, no obstacle exists at distance `x` when the query is asked.
- There is at least one query of Type 2.

---

## ⏱️ Expected Complexities

| Complexity       | Bound                    |
|:----------------:|:------------------------:|
| **Time**         | `O(Q log M)`             |
| **Auxiliary Space** | `O(Q + M)`            |

> `Q` = number of queries, `M` = maximum coordinate value ≤ 5 × 10⁴

---

## 🏷️ Topic Tags

`Array` · `Binary Search` · `Binary Indexed Tree` · `Segment Tree`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../122_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../124_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
