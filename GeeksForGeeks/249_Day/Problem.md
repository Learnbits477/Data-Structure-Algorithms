# 249. [Coils in a Matrix](https://www.geeksforgeeks.org/problems/form-coils-in-a-matrix4726/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 75.17%](https://img.shields.io/badge/Accuracy-75.17%25-orange?style=for-the-badge)
![Submissions: 5K+](https://img.shields.io/badge/Submissions-5K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Company: Yahoo](https://img.shields.io/badge/Company-Yahoo-red?style=for-the-badge)
![Topic: Matrix](https://img.shields.io/badge/Topic-Matrix-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Inward Spiral Decomposition & Central Point Symmetry:**
> 1. **Coil Segment Pattern**:
>    In a $4n \times 4n$ matrix, Coil 1 starts at $(0, 0)$ and spirals inward. Its trajectory consists of segments whose cell counts follow a strict geometric sequence:
>    - First segment: Down of length $4n$.
>    - Subsequent segments: Pairs of equal lengths decreasing by $2$:
>      - $(4n - 2)$ Right, $(4n - 2)$ Up
>      - $(4n - 4)$ Left, $(4n - 4)$ Down
>      - $\dots$
>      - $2$ Right, $2$ Up.
>    - Total cells traversed = $4n + 2 \sum_{k=1}^{2n-1} 2k = 4n + 4 \cdot \frac{(2n-1)(2n)}{2} = 8n^2$.
> 2. **Central $180^\circ$ Point Symmetry**:
>    Because the matrix is numbered sequentially from $1$ to $16n^2$ in row-major order:
>    $$\text{val}(r, c) = r \cdot 4n + c + 1$$
>    The point-symmetric cell to $(r, c)$ is $(4n - 1 - r, 4n - 1 - c)$, which satisfies:
>    $$\text{val}(4n - 1 - r, 4n - 1 - c) = (16n^2 + 1) - \text{val}(r, c)$$
>    Consequently, Coil 2 is the exact symmetric complement of Coil 1 at every step:
>    $$\text{coil2}[i] = (16n^2 + 1) - \text{coil1}[i]$$

---

## 🧩 Problem Description

Given a positive integer $n$, consider a $4n \times 4n$ matrix filled with integers from $1$ to $(4n) \times (4n)$ in row-major order (left to right, top to bottom).

Form two coils from the matrix:
- The **first coil** starts from the top-left cell $(0, 0)$ and spirals inward.
- The **second coil** starts from the bottom-right cell $(4n - 1, 4n - 1)$ and spirals inward in the opposite direction.

Return these two coils in the same order as a 2D array/vector of size $2 \times (8n^2)$.

---

## 📌 Examples

**Example 1:**

```text
Input: n = 1
Output: [[1, 5, 9, 13, 14, 15, 11, 7], [16, 12, 8, 4, 3, 2, 6, 10]]

Explanation:
The 4 x 4 matrix is:
 1   2   3   4
 5   6   7   8
 9  10  11  12
13  14  15  16

Coil 1 path (starts at cell (0, 0) and spirals inward):
1 -> 5 -> 9 -> 13 -> 14 -> 15 -> 11 -> 7

Coil 2 path (starts at cell (3, 3) and spirals inward):
16 -> 12 -> 8 -> 4 -> 3 -> 2 -> 6 -> 10
```

**Example 2:**

```text
Input: n = 2
Output: 
[[1, 9, 17, 25, 33, 41, 49, 57, 58, 59, 60, 61, 62, 63, 55, 47, 39, 31, 23, 15, 14, 13, 12, 11, 19, 27, 35, 43, 44, 45, 37, 29], 
 [64, 56, 48, 40, 32, 24, 16, 8, 7, 6, 5, 4, 3, 2, 10, 18, 26, 34, 42, 50, 51, 52, 53, 54, 46, 38, 30, 22, 21, 20, 28, 36]]

Explanation:
The 8 x 8 matrix is filled from 1 to 64.
Both coils contain 8 * (2^2) = 32 elements.
```

---

## 📐 Constraints

- $1 \le n \le 20$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n^2)$ |
| **Auxiliary Space** | $\mathcal{O}(n^2)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../248_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../250_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
