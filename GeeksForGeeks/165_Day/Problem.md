# [165. Longest Possible Route in a Matrix with Hurdles](https://www.geeksforgeeks.org/problems/longest-possible-route-in-a-matrix-with-hurdles/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 50.0%](https://img.shields.io/badge/Accuracy-50.0%25-green?style=for-the-badge)
![Submissions: 20K+](https://img.shields.io/badge/Submissions-20K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a binary matrix `mat[][]` of size $n \times m$ containing values `0` and `1`, and four integers `xs`, `ys`, `xd`, and `yd` representing the source cell `(xs, ys)` and destination cell `(xd, yd)`, find the length of the longest possible path from the source cell to the destination cell. 

From any cell, you can move to its adjacent cells in the up, down, left, and right directions.

- `1` represents a traversable cell.
- `0` represents a blocked cell that cannot be visited.
- A cell can be visited at most once in a path.
- If the destination cannot be reached from the source, return `-1`.

---

## 📌 Examples

### Example 1
**Input:**
```text
mat[][] = [
  [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
  [1, 1, 0, 1, 1, 0, 1, 1, 0, 1],
  [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
]
xs = 0, ys = 0
xd = 1, yd = 7
```
**Output:**
```text
24
```
**Explanation:**
The longest valid path from `(0, 0)` to `(1, 7)` without revisiting any cell has length `24`.

### Example 2
**Input:**
```text
mat[][] = [
  [1, 0, 0, 1, 0],
  [0, 0, 0, 1, 0],
  [0, 1, 1, 0, 0]
]
xs = 0, ys = 3
xd = 2, yd = 2
```
**Output:**
```text
-1
```
**Explanation:**
The destination cell `(2, 2)` cannot be reached from the source cell `(0, 3)`, so the answer is `-1`.

---

## 📐 Constraints

- $$1 \le n, m \le 10$$
- $$mat[i][j] \in \{0, 1\}$$
- The source and destination cells are always inside the matrix.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(4^{n \times m})$$ |
| 💾 Auxiliary Space | $$O(n \times m)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Matrix](https://img.shields.io/badge/Matrix-1ABC9C?style=for-the-badge)
![Backtracking](https://img.shields.io/badge/Backtracking-2ECC71?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-3498DB?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../164_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../166_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
