# [3534. Path Existence Queries in a Graph II](https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/description/?envType=daily-question&envId=2026-07-10)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 47.9%](https://img.shields.io/badge/Acceptance-47.9%25-blue?style=for-the-badge)
![Submissions: 32.5K](https://img.shields.io/badge/Submissions-32.5K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given an integer $n$ representing the number of nodes in a graph, labeled from $0$ to $n - 1$.

You are also given an integer array `nums` of length $n$ and an integer `maxDiff`.

An undirected edge exists between nodes $i$ and $j$ if the absolute difference between `nums[i]` and `nums[j]` is at most `maxDiff` (i.e., $|nums[i] - nums[j]| \le maxDiff$).

You are also given a 2D integer array `queries`. For each `queries[i] = [ui, vi]`, find the **minimum distance** (shortest path length) between nodes `ui` and `vi`. If no path exists between the two nodes, return `-1` for that query.

Return an array `answer`, where `answer[i]` is the result of the $i^{\text{th}}$ query.

*Note: The edges between the nodes are unweighted.*

---

## 📌 Examples

### Example 1
**Input:**
```text
n = 5, nums = [1,8,3,4,2], maxDiff = 3, queries = [[0,3],[2,4]]
```
**Output:**
```text
[1,1]
```
**Explanation:**
- Query `[0, 3]`: $|nums[0] - nums[3]| = |1 - 4| = 3 \le 3$, so $0 \to 3$ takes $1$ step.
- Query `[2, 4]`: $|nums[2] - nums[4]| = |3 - 2| = 1 \le 3$, so $2 \to 4$ takes $1$ step.

### Example 2
**Input:**
```text
n = 5, nums = [5,3,1,9,10], maxDiff = 2, queries = [[0,1],[0,2],[2,3],[4,3]]
```
**Output:**
```text
[1,2,-1,1]
```
**Explanation:**
- Query `[0, 1]`: $0 \to 1$ takes $1$ step ($|5 - 3| = 2 \le 2$).
- Query `[0, 2]`: $0 \to 1 \to 2$ takes $2$ steps ($|5 - 3| = 2 \le 2$ and $|3 - 1| = 2 \le 2$).
- Query `[2, 3]`: No path exists between Node 2 and Node 3 (they are in different components).
- Query `[4, 3]`: $3 \to 4$ takes $1$ step ($|10 - 9| = 1 \le 2$).

### Example 3
**Input:**
```text
n = 3, nums = [3,6,1], maxDiff = 1, queries = [[0,0],[0,1],[1,2]]
```
**Output:**
```text
[0,-1,-1]
```
**Explanation:**
There are no edges between any two nodes. Thus, the only reachable node from any node is itself.

---

## 📐 Constraints

- $$1 \le n == nums.length \le 10^5$$
- $$0 \le nums[i] \le 10^5$$
- $$0 \le maxDiff \le 10^5$$
- $$1 \le queries.length \le 10^5$$
- `queries[i] == [ui, vi]`
- $$0 \le ui, vi < n$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O((n + q) \log n)$$ |
| 💾 Auxiliary Space | $$O(n \log n)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-3498DB?style=for-the-badge)
![Two Pointers](https://img.shields.io/badge/Two%20Pointers-F39C12?style=for-the-badge)
![Binary Search](https://img.shields.io/badge/Binary%20Search-2ECC71?style=for-the-badge)
![Graph Theory](https://img.shields.io/badge/Graph%20Theory-9B59B6?style=for-the-badge)
![Sorting](https://img.shields.io/badge/Sorting-34495E?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../163_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../165_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
