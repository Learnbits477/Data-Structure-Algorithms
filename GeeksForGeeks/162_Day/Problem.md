# [162. Geeks Island](https://www.geeksforgeeks.org/problems/geeks-island--170646/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 60.27%](https://img.shields.io/badge/Accuracy-60.27%25-green?style=for-the-badge)
![Submissions: 18K+](https://img.shields.io/badge/Submissions-18K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a matrix `mat[][]` of size $n \times m$, where `mat[i][j]` represents the signal strength of a communication tower. Two control stations monitor the network:

- **Station P** covers the top and left boundaries of the grid.
- **Station Q** covers the bottom and right boundaries of the grid.

A signal can propagate from a tower to one of its neighbouring towers in the four directions (North, South, East, and West) only if the neighbouring tower has a signal strength less than or equal to that of the current tower.

Determine the number of towers `(x, y)` from which a signal can eventually reach both Station P and Station Q. Any tower located on a boundary covered by a station can transmit directly to that station.

---

## 📌 Examples

### Example 1
**Input:**
```text
mat[][] = [
  [1, 2, 2, 3, 5],
  [3, 2, 3, 4, 4],
  [2, 4, 5, 3, 1],
  [6, 7, 1, 4, 5],
  [5, 1, 1, 2, 4]
]
```
**Output:**
```text
7
```
**Explanation:**
- `(0, 4)` and `(4, 0)` are part of both P and Q.
- `(1, 3)` reaches P using `(1,3) -> (0,3)` and Q using `(1,3) -> (1,4)`.
- `(1, 4)` reaches P using `(1,4) -> (1,3) -> (1,2) -> (0,2)` and it is on Q.
- `(2, 2)` reaches P using `(2,2) -> (2,1) -> (2,0)` and Q using `(2,2) -> (2,3) -> (2,4)`.
- `(3, 0)` is on P and reaches Q using `(3,0) -> (4,0)`.
- `(3, 1)` reaches P using `(3,1) -> (3,0)` and Q using `(3,1) -> (4,1)`.

### Example 2
**Input:**
```text
mat[][] = [
  [2, 2],
  [2, 2]
]
```
**Output:**
```text
4
```
**Explanation:**
All cells allow signals to propagate to both stations.

---

## 📐 Constraints

- $$1 \le n, m \le 10^3$$
- $$1 \le mat[i][j] \le 10^3$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n \times m)$$ |
| 💾 Auxiliary Space | $$O(n \times m)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![DFS](https://img.shields.io/badge/DFS-3498DB?style=for-the-badge)
![Matrix](https://img.shields.io/badge/Matrix-F39C12?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../161_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../163_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
