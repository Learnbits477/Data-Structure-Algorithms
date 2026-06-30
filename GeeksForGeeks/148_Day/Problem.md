# [148. Rat Maze with Multiple Jumps](https://www.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps3852/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 38.46%](https://img.shields.io/badge/Accuracy-38.46%25-green?style=for-the-badge)
![Submissions: 41K+](https://img.shields.io/badge/Submissions-41K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

A Rat is in a maze at $(0, 0)$ and has to reach $(n - 1, n - 1)$. The transition from cell $(i, j)$ to other cells is governed by the value of $\text{mat}[i][j]$, which represents the **maximum number of steps** the rat can jump either forward (right) or downward from that cell.

Your task is to find a path for the rat to reach the destination $(n - 1, n - 1)$. 

### Rules:
1. **Movement:** The rat can move only **Right** or **Down**.
2. **Jumping:** From a cell $(i, j)$ with value $k$, the rat can jump any number of steps $s$ such that $1 \le s \le k$, provided the destination remains within the matrix boundaries.
3. **Blocked Cells:** A cell containing $0$ is a wall (blocked) and cannot be used in the path (the rat cannot land on or jump from it), except for the destination cell itself.
4. **Goal:** Reach $(n - 1, n - 1)$.
5. **Priority:** If multiple valid paths exist, choose the path with the **shortest jumps first**. If there are multiple paths with the same jump length, choose the path that moves **Right** first, and then **Down**.

The path should be represented by a binary matrix $\text{ans}[][]$ of the same size, where $\text{ans}[i][j] = 1$ if cell $(i, j)$ is part of the path, else $0$. If no path exists, return a 2D vector containing `{{-1}}`.

---

## 📌 Examples

### Example 1
**Input:**
```text
mat[][] = [[2, 1, 0, 0],
           [3, 0, 0, 1],
           [0, 1, 0, 1],
           [0, 0, 0, 1]]
```
**Output:**
```text
[[1, 0, 0, 0],
 [1, 0, 0, 1],
 [0, 0, 0, 1],
 [0, 0, 0, 1]]
```
**Explanation:**
- Start at $(0, 0)$. Jump capacity is $2$.
- Attempt jump of size $1$ to the right to $(0, 1)$. But from $(0, 1)$ (capacity 1) we can only jump right to $(0, 2)$ (blocked) or down to $(1, 1)$ (blocked). So this path fails.
- Backtrack and try jump of size $1$ down to $(1, 0)$. From $(1, 0)$ (capacity 3):
  - Try jump of size $1$ to the right to $(1, 1)$ (blocked).
  - Try jump of size $1$ down to $(2, 0)$ (blocked).
  - Try jump of size $2$ to the right to $(1, 2)$ (blocked).
  - Try jump of size $2$ down to $(3, 0)$ (blocked).
  - Try jump of size $3$ to the right to $(1, 3)$ (capacity 1). From $(1, 3)$ jump $1$ down to $(2, 3)$ (capacity 1). From $(2, 3)$ jump $1$ down to $(3, 3)$ (destination).
- This yields the successful path: $(0, 0) \to (1, 0) \to (1, 3) \to (2, 3) \to (3, 3)$.
- The output matrix marks these cells with $1$.

---

### Example 2
**Input:**
```text
mat[][] = [[2, 1, 0, 0],
           [2, 0, 0, 1],
           [0, 1, 0, 1],
           [0, 0, 0, 1]]
```
**Output:**
```text
[[-1]]
```
**Explanation:**
- No path exists from $(0, 0)$ to $(3, 3)$.

---

## 📐 Constraints

- $$1 \le n \le 50$$
- $$0 \le mat[i][j] \le 20$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n^2 \times \max(mat[i][j]))$$ |
| 💾 Auxiliary Space | $$O(n^2)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Backtracking](https://img.shields.io/badge/Backtracking-007ACC?style=for-the-badge)
![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-8E44AD?style=for-the-badge)
![Matrix](https://img.shields.io/badge/Matrix-FF5722?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../147_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../149_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
