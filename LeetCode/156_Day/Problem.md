# [3286. Find a Safe Walk Through a Grid](https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 37.1%](https://img.shields.io/badge/Acceptance-37.1%25-blue?style=for-the-badge)
![Submissions: 123K](https://img.shields.io/badge/Submissions-123K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given an $$m \times n$$ binary matrix `grid` and an integer `health`.

You start on the upper-left corner $$(0, 0)$$ and would like to get to the lower-right corner $$(m - 1, n - 1)$$.

You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.

Cells $$(i, j)$$ with `grid[i][j] = 1` are considered unsafe and reduce your health by $$1$$.

Return `true` if you can reach the final cell with a health value of $$1$$ or more, and `false` otherwise.

---

## 📌 Examples

### Example 1
**Input:**
```text
grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1
```
**Output:**
```text
true
```
**Explanation:**
The final cell can be reached safely by walking along the path:
$$(0, 0) \to (1, 0) \to (2, 0) \to (2, 1) \to (2, 2) \to (1, 2) \to (0, 2) \to (0, 3) \to (0, 4) \to (1, 4) \to (2, 4) \to (2, 3) \to (2, 4)$$
Wait, a simpler path is:
$$(0,0) \to (1,0) \to (2,0) \to (2,1) \to (2,2) \to (1,2) \to (0,2) \to (0,3) \to (0,4) \to (1,4) \to (2,4)$$
No cells in this path contain a `1`. The total health reduction is $$0$$, leaving a remaining health of $$1$$.

### Example 2
**Input:**
```text
grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3
```
**Output:**
```text
false
```
**Explanation:**
A minimum of $$4$$ health points is needed to reach the final cell safely.

### Example 3
**Input:**
```text
grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5
```
**Output:**
```text
true
```
**Explanation:**
The final cell can be reached safely by walking along:
$$(0,0) \to (1,0) \to (1,1) \to (1,2) \to (2,2)$$
The path contains cells $$(0,0)$$, $$(1,0)$$, $$(1,2)$$, and $$(2,2)$$ which are all unsafe, reducing your health by $$4$$. The remaining health is $$5 - 4 = 1$$.

---

## 📐 Constraints

- $$m == \text{grid.length}$$
- $$n == \text{grid}[i]\text{.length}$$
- $$1 \le m, n \le 50$$
- $$2 \le m \times n$$
- $$1 \le \text{health} \le m + n$$
- `grid[i][j]` is either `0` or `1`.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(m \cdot n \log(m \cdot n))$$ |
| 💾 Auxiliary Space | $$O(m \cdot n)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-3498DB?style=for-the-badge)
![Breadth-First Search](https://img.shields.io/badge/Breadth--First%20Search-9B59B6?style=for-the-badge)
![Graph Theory](https://img.shields.io/badge/Graph%20Theory-E74C3C?style=for-the-badge)
![Heap (Priority Queue)](https://img.shields.io/badge/Heap%20(Priority%20Queue)-2ECC71?style=for-the-badge)
![Matrix](https://img.shields.io/badge/Matrix-34495E?style=for-the-badge)
![Shortest Path](https://img.shields.io/badge/Shortest%20Path-F1C40F?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../155_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../157_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
