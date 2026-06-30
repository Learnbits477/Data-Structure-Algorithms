# [151. Ways to Tile the Floor](https://www.geeksforgeeks.org/problems/count-the-number-of-ways-to-tile-the-floor-of-size-n-x-m-using-1-x-m-size-tiles0509/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 39.12%](https://img.shields.io/badge/Accuracy-39.12%25-green?style=for-the-badge)
![Submissions: 24K+](https://img.shields.io/badge/Submissions-24K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a floor of dimensions $n \times m$ and an unlimited supply of tiles of size $1 \times m$, find the total number of ways to completely tile the floor.

Each tile can be placed in one of the following ways:
1. **Horizontally**, covering $1$ row and $m$ columns.
2. **Vertically**, covering $m$ rows and $1$ column.

Count all possible ways to cover the entire floor such that there are no overlaps and no uncovered cells.

Since the number of possible tilings can be very large, return the answer modulo $10^9+7$.

> [!NOTE]
> $n$ and $m$ are positive integers, and $m \ge 2$.

---

## 📌 Examples

### Example 1
**Input:**
```text
n = 4, m = 4
```
**Output:**
```text
2
```
**Explanation:**
There are exactly two valid ways to tile the floor of size $4 \times 4$ using $1 \times 4$ tiles:
1. Place all $4$ tiles horizontally.
2. Place all $4$ tiles vertically.

### Example 2
**Input:**
```text
n = 2, m = 3
```
**Output:**
```text
1
```
**Explanation:**
Placing a tile vertically would require a height of $3$, which exceeds the floor's height of $2$. The only way to cover the entire floor is by placing $2$ tiles horizontally, one in each row, resulting in exactly one valid tiling.

---

## 📐 Constraints

- $$1 \le n \le 10^5$$
- $$2 \le m \le 10^5$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n)$$ |
| 💾 Auxiliary Space | $$O(n)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-8E44AD?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../150_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../152_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
