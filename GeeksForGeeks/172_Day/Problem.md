# [172. Cut Matrix](https://www.geeksforgeeks.org/problems/cut-matrix/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 36.37%](https://img.shields.io/badge/Accuracy-36.37%25-green?style=for-the-badge)
![Submissions: 4K+](https://img.shields.io/badge/Submissions-4K%2B-blue?style=for-the-badge)
![Points: 8](https://img.shields.io/badge/Points-8-yellow?style=for-the-badge)
![Company: Google](https://img.shields.io/badge/Company-Google-black?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a matrix of `0`s and `1`s and an integer `k`, divide the matrix into `k` pieces such that each piece has at least one `1` in it. A cut can be made in the following way:

1. Choose a direction: vertical or horizontal.
2. Choose an index to cut the matrix into two pieces.
3. If the cut is horizontal, only the bottom part can be cut further.
4. If the cut is vertical, only the right part can be cut further.

Return the number of different ways to divide the matrix modulo $$10^9 + 7$$.

---

## 📌 Examples

### Example 1
**Input:**
```text
matrix = [[1, 0, 0], [1, 1, 1], [0, 0, 0]], k = 3
```
**Output:**
```text
3
```
**Explanation:**
There are 3 valid ways to divide the matrix into 3 pieces each having at least one `1`:
- Horizontal cut after row 0 then vertical cut after col 0 on bottom part.
- Horizontal cut after row 0 then vertical cut after col 1 on bottom part.
- Vertical cut after col 0 then vertical cut after col 1 on the right part.

### Example 2
**Input:**
```text
matrix = [[0, 0], [1, 1]], k = 2
```
**Output:**
```text
1
```
**Explanation:**
Only way is to cut vertically in the middle (after col 0) since the top half has no `1`.

### Example 3
**Input:**
```text
matrix = [[1, 0], [0, 0]], k = 1
```
**Output:**
```text
1
```
**Explanation:**
No cut needed as $$k = 1$$, the whole matrix is one piece with at least one `1`.

---

## 📐 Constraints

- $$1 \le n, m, k \le 200$$
- `matrix[i][j]` is either `0` or `1`.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n \cdot m \cdot k \cdot \log(n + m))$$ |
| 💾 Auxiliary Space | $$O(n \cdot m \cdot k)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-2ECC71?style=for-the-badge)
![Matrix](https://img.shields.io/badge/Matrix-3498DB?style=for-the-badge)

</div>

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../171_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../173_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
