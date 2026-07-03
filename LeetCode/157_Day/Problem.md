# [3620. Network Recovery Pathways](https://leetcode.com/problems/network-recovery-pathways/description/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 41.0%](https://img.shields.io/badge/Acceptance-41.0%25-blue?style=for-the-badge)
![Submissions: 84.7K](https://img.shields.io/badge/Submissions-84.7K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given a directed acyclic graph (DAG) of `n` nodes numbered from `0` to `n - 1`. This is represented by a 2D array `edges` of length `m`, where `edges[i] = [ui, vi, costi]` indicates a one-way communication from node `ui` to node `vi` with a recovery cost of `costi`.

Some nodes may be offline. You are given a boolean array `online` where `online[i] = true` means node `i` is online. Nodes `0` and `n - 1` are always online.

A path from `0` to `n - 1` is valid if:
1. All intermediate nodes on the path are online.
2. The total recovery cost of all edges on the path does not exceed `k`.

For each valid path, define its score as the **minimum edge-cost** along that path.

Return the **maximum path score** (i.e., the largest minimum-edge cost) among all valid paths. If no valid path exists, return `-1`.

---

## 📌 Examples

### Example 1
**Input:**
```text
edges = [[0,1,5],[1,3,10],[0,2,3],[2,3,4]], online = [true,true,true,true], k = 10
```
**Output:**
```text
3
```
**Explanation:**
The graph has two possible routes from node `0` to node `3`:
1. **Path 0 → 1 → 3**
   - Total cost = $$5 + 10 = 15$$, which exceeds `k` ($$15 > 10$$), so this path is invalid.
2. **Path 0 → 2 → 3**
   - Total cost = $$3 + 4 = 7 \le k$$, so this path is valid.
   - The minimum edge-cost along this path is $$\min(3, 4) = 3$$.

There are no other valid paths. Hence, the maximum among all valid path-scores is `3`.

### Example 2
**Input:**
```text
edges = [[0,1,7],[1,4,5],[0,2,6],[2,3,6],[3,4,2],[2,4,6]], online = [true,true,true,false,true], k = 12
```
**Output:**
```text
6
```
**Explanation:**
Node `3` is offline, so any path passing through `3` is invalid.
Consider the remaining routes from `0` to `4`:
1. **Path 0 → 1 → 4**
   - Total cost = $$7 + 5 = 12 \le k$$, so this path is valid.
   - The minimum edge-cost along this path is $$\min(7, 5) = 5$$.
2. **Path 0 → 2 → 3 → 4**
   - Node `3` is offline, so this path is invalid regardless of cost.
3. **Path 0 → 2 → 4**
   - Total cost = $$6 + 6 = 12 \le k$$, so this path is valid.
   - The minimum edge-cost along this path is $$\min(6, 6) = 6$$.

Among the two valid paths, their scores are `5` and `6`. Therefore, the answer is `6`.

---

## 📐 Constraints

- $$n == \text{online.length}$$
- $$2 \le n \le 5 \cdot 10^4$$
- $$0 \le m == \text{edges.length} \le \min\left(10^5, \frac{n \cdot (n - 1)}{2}\right)$$
- `edges[i] = [ui, vi, costi]`
- $$0 \le ui, vi < n$$
- $$ui \ne vi$$
- $$0 \le \text{costi} \le 10^9$$
- $$0 \le k \le 5 \cdot 10^{13}$$
- `online[i]` is either `true` or `false`, and both `online[0]` and `online[n - 1]` are `true`.
- The given graph is a **directed acyclic graph**.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O((n + m) \log m)$$ |
| 💾 Auxiliary Space | $$O(n + m)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-3498DB?style=for-the-badge)
![Binary Search](https://img.shields.io/badge/Binary%20Search-2ECC71?style=for-the-badge)
![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-8E44AD?style=for-the-badge)
![Graph Theory](https://img.shields.io/badge/Graph%20Theory-E74C3C?style=for-the-badge)
![Topological Sort](https://img.shields.io/badge/Topological%20Sort-E67E22?style=for-the-badge)
![Shortest Path](https://img.shields.io/badge/Shortest%20Path-F1C40F?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../156_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../158_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
