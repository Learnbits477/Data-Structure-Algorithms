# [3310. Remove Methods From Project](https://leetcode.com/problems/remove-methods-from-project/description/?envType=daily-question&envId=2026-08-05)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 59.8%](https://img.shields.io/badge/Acceptance-59.8%25-blue?style=for-the-badge)
![Topic: Depth-First Search](https://img.shields.io/badge/Topics:-Depth--First%20Search-blue?style=for-the-badge)
![Topic: Breadth-First Search](https://img.shields.io/badge/Breadth--First%20Search-blue?style=for-the-badge)
![Topic: Graph Theory](https://img.shields.io/badge/Graph%20Theory-blue?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are maintaining a project that has `n` methods numbered from `0` to `n - 1`.

You are given two integers `n` and `k`, and a 2D integer array `invocations`, where `invocations[i] = [ai, bi]` indicates that method `ai` invokes method `bi`.

There is a known bug in method `k`. Method `k`, along with any method invoked by it, either directly or indirectly, are considered suspicious and we aim to remove them.

A group of methods can only be removed if no method outside the group invokes any methods within it.

Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the suspicious methods, none should be removed.

---

## 📌 Examples

**Example 1:**
- **Input:** `n = 4`, `k = 1`, `invocations = [[1,2],[0,1],[3,2]]`
- **Output:** `[0,1,2,3]`
- **Explanation:** Methods 2 and 1 are suspicious, but they are directly invoked by methods 3 and 0, which are not suspicious. Therefore, we return all elements without removing anything.

**Example 2:**
- **Input:** `n = 5`, `k = 0`, `invocations = [[1,2],[0,2],[0,1],[3,4]]`
- **Output:** `[3,4]`
- **Explanation:** Methods 0, 1, and 2 are suspicious and they are not directly invoked by any other method. We can remove them.

**Example 3:**
- **Input:** `n = 3`, `k = 2`, `invocations = [[1,2],[0,1],[2,0]]`
- **Output:** `[]`
- **Explanation:** All methods are suspicious. We can remove them all.

---

## 📐 Constraints

- $1 \le n \le 10^5$
- $0 \le k \le n - 1$
- $0 \le invocations.length \le 2 \cdot 10^5$
- $invocations[i] == [ai, bi]$
- $0 \le ai, bi \le n - 1$
- $ai \neq bi$
- All elements in `invocations` are unique.

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n + \text{invocations.length})$ |
| **Auxiliary Space** | $O(n + \text{invocations.length})$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../189_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../191_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
