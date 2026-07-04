# [2492. Minimum Score of a Path Between Two Cities](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 63.6%](https://img.shields.io/badge/Acceptance-63.6%25-blue?style=for-the-badge)
![Submissions: 259.4K](https://img.shields.io/badge/Submissions-259.4K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given a positive integer `n` representing `n` cities numbered from `1` to `n`. You are also given a 2D array `roads` where `roads[i] = [ai, bi, distancei]` indicates that there is a bidirectional road between cities `ai` and `bi` with a distance equal to `distancei`. The cities graph is not necessarily connected.

The **score** of a path between two cities is defined as the **minimum** distance of a road in this path.

Return the ***minimum*** possible score of a path between cities `1` and `n`.

> [!NOTE]
> - A path is a sequence of roads between two cities.
> - It is allowed for a path to contain the same road multiple times, and you can visit cities `1` and `n` multiple times along the path.
> - The test cases are generated such that there is at least one path between `1` and `n`.

---

## 📌 Examples

### Example 1
Input:
![image](https://assets.leetcode.com/uploads/2022/10/12/grid11.png) (Representation only)
**Input:**
```text
n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
```
**Output:**
```text
5
```
**Explanation:**
The path from city 1 to 4 with the minimum score is: `1 -> 2 -> 4`. The score of this path is `min(9,5) = 5`.
It can be shown that no other path has less score.

### Example 2
Input:
![image2](https://assets.leetcode.com/uploads/2022/10/12/drawio.png) (Representation only)
**Input:**
```text
n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
```
**Output:**
```text
2
```
**Explanation:**
The path from city 1 to 4 with the minimum score is: `1 -> 2 -> 1 -> 3 -> 4`. The score of this path is `min(2,2,4,7) = 2`.

---

## 📐 Constraints

- $$2 \le n \le 10^5$$
- $$1 \le \text{roads.length} \le 10^5$$
- `roads[i].length == 3`
- $$1 \le ai, bi \le n$$
- $$ai \ne bi$$
- $$1 \le \text{distancei} \le 10^4$$
- There are no repeated edges.
- There is at least one path between `1` and `n`.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(V + E)$$ |
| 💾 Auxiliary Space | $$O(V + E)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Depth-First Search](https://img.shields.io/badge/Depth--First%20Search-8E44AD?style=for-the-badge)
![Breadth-First Search](https://img.shields.io/badge/Breadth--First%20Search-2ECC71?style=for-the-badge)
![Union-Find](https://img.shields.io/badge/Union--Find-3498DB?style=for-the-badge)
![Graph Theory](https://img.shields.io/badge/Graph%20Theory-E74C3C?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../157_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../159_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
