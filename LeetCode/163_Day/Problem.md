# [3532. Path Existence Queries in a Graph I](https://leetcode.com/problems/path-existence-queries-in-a-graph-i/description/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 63.6%](https://img.shields.io/badge/Acceptance-63.6%25-blue?style=for-the-badge)
![Submissions: 69.3K](https://img.shields.io/badge/Submissions-69.3K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given an integer `n` representing the number of nodes in a graph, labeled from `0` to `n - 1`.

You are also given an integer array `nums` of length `n` sorted in non-decreasing order, and an integer `maxDiff`.

An undirected edge exists between nodes `i` and `j` if the absolute difference between `nums[i]` and `nums[j]` is at most `maxDiff` (i.e., $|nums[i] - nums[j]| \le maxDiff$).

You are also given a 2D integer array `queries`. For each `queries[i] = [ui, vi]`, determine whether there exists a path between nodes `ui` and `vi`.

Return a boolean array `answer`, where `answer[i]` is `true` if there exists a path between `ui` and `vi` in the $i^{\text{th}}$ query and `false` otherwise.

---

## 📌 Examples

### Example 1
**Input:**
```text
n = 2, nums = [1, 3], maxDiff = 1, queries = [[0, 0], [0, 1]]
```
**Output:**
```text
[true, false]
```
**Explanation:**
- Query `[0, 0]`: Node 0 has a trivial path to itself.
- Query `[0, 1]`: There is no edge between Node 0 and Node 1 because $|nums[0] - nums[1]| = |1 - 3| = 2$, which is greater than `maxDiff`.
Thus, the final answer after processing all the queries is `[true, false]`.

### Example 2
**Input:**
```text
n = 4, nums = [2, 5, 6, 8], maxDiff = 2, queries = [[0, 1], [0, 2], [1, 3], [2, 3]]
```
**Output:**
```text
[false, false, true, true]
```
**Explanation:**
- Query `[0, 1]`: There is no edge between Node 0 and Node 1 because $|nums[0] - nums[1]| = |2 - 5| = 3$, which is greater than `maxDiff`.
- Query `[0, 2]`: There is no edge between Node 0 and Node 2 because $|nums[0] - nums[2]| = |2 - 6| = 4$, which is greater than `maxDiff`.
- Query `[1, 3]`: There is a path between Node 1 and Node 3 through Node 2 since $|nums[1] - nums[2]| = |5 - 6| = 1$ and $|nums[2] - nums[3]| = |6 - 8| = 2$, both of which are within `maxDiff`.
- Query `[2, 3]`: There is an edge between Node 2 and Node 3 because $|nums[2] - nums[3]| = |6 - 8| = 2$, which is equal to `maxDiff`.
Thus, the final answer after processing all the queries is `[false, false, true, true]`.

---

## 📐 Constraints

- $$1 \le n == nums.length \le 10^5$$
- $$0 \le nums[i] \le 10^5$$
- `nums` is sorted in non-decreasing order.
- $$0 \le maxDiff \le 10^5$$
- $$1 \le queries.length \le 10^5$$
- `queries[i] == [ui, vi]`
- $$0 \le ui, vi < n$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n + q)$$ |
| 💾 Auxiliary Space | $$O(n)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-3498DB?style=for-the-badge)
![Hash Table](https://img.shields.io/badge/Hash%20Table-F39C12?style=for-the-badge)
![Binary Search](https://img.shields.io/badge/Binary%20Search-2ECC71?style=for-the-badge)
![Union-Find](https://img.shields.io/badge/Union--Find-9B59B6?style=for-the-badge)
![Graph Theory](https://img.shields.io/badge/Graph%20Theory-34495E?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../162_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../164_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
