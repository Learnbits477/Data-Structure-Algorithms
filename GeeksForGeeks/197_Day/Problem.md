# 197. [Adventure in a Maze](https://www.geeksforgeeks.org/problems/adventure-in-a-maze2051/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 39.96%](https://img.shields.io/badge/Acceptance-39.96%25-blue?style=for-the-badge)
![Submissions: 13K+](https://img.shields.io/badge/Submissions-13K+-orange?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topics-Dynamic_Programming-blue?style=for-the-badge)
![Topic: Matrix](https://img.shields.io/badge/Matrix-blue?style=for-the-badge)

---

## 🧩 Problem Description
Given a maze represented as an $n \times n$ grid, `grid[][]`, using 0-based indexing. Each cell contains one of the values 1, 2, or 3, which determines the direction(s) you are allowed to move from that cell:
- **1** - you may move Right only.
- **2** - you may move Down only.
- **3** - you may move Right or Down (both directions are available).

You start at the top-left cell `(0, 0)` (the Entry) and must reach the bottom-right cell `(n-1, n-1)` (the Exit), following the movement rule of each cell you pass through. You are never allowed to move outside the boundaries of the grid.

The **Adventure** of a path is the sum of the values of all cells visited along that path (including both the entry and exit cells).

Find the total number of distinct valid paths from Entry to Exit, and among all such paths, the maximum possible Adventure. Return the answer as `[totalPaths, maxAdventure]`.

> [!NOTE]
> Return `totalPaths` modulo $10^9 + 7$. `maxAdventure` needs no modulo, as it stays small regardless of grid size.

---

## 📌 Examples

### Example 1
**Input**:
```text
grid[][] = [[3, 2],
            [1, 3]]
```
**Output**:
```text
[2, 8]
```
**Explanation**:
There are 2 valid paths from `[0, 0]` to `[1, 1]`:
- **Path 1**: `[0, 0] -> [0, 1] -> [1, 1]`, values $3 + 2 + 3 = 8$
- **Path 2**: `[0, 0] -> [1, 0] -> [1, 1]`, values $3 + 1 + 3 = 7$

The maximum Adventure among these is 8, so the output is `[2, 8]`.

### Example 2
**Input**:
```text
grid[][] = [[1, 1, 3, 2, 1],
            [3, 2, 2, 1, 2],
            [1, 3, 3, 1, 3],
            [1, 2, 3, 1, 2],
            [1, 1, 1, 3, 1]]
```
**Output**:
```text
[4, 18]
```
**Explanation**:
There are 4 valid paths from Entry to Exit, with total Adventures 18, 17, 17, and 16 respectively. The maximum among these is 18, so the output is `[4, 18]`.

---

## 📐 Constraints
- $$1 \le n \le 100$$
- $$grid[i][j] \in \{1, 2, 3\}$$

---

## ⏱️ Expected Complexities
| Time Complexity | Auxiliary Space |
| :--- | :--- |
| $\mathcal{O}(n^2)$ | $\mathcal{O}(n^2)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../196_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../198_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
