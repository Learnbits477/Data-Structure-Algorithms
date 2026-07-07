# [161. Largest Unblocked Submatrix](https://www.geeksforgeeks.org/problems/largest-unblocked-submatrix/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 52.99%](https://img.shields.io/badge/Accuracy-52.99%25-green?style=for-the-badge)
![Submissions: 17K+](https://img.shields.io/badge/Submissions-17K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given integers $n$ and $m$, and an array `arr[][]` of size $k$, where `arr[i] = [r, c]` represents a blocked cell in an $n \times m$ grid.

Each blocked cell blocks its entire row and column. Find the largest continuous unblocked area (submatrix) in the grid.

> [!NOTE]
> No two blocked cells are in the same row or the same column.

---

## 📌 Examples

### Example 1
**Input:**
```text
n = 5, m = 5, k = 2, arr[][] = [[2, 3], [5, 1]]
```
**Output:**
```text
4
```
**Explanation:**
Blocked cells are at $(2, 3)$ and $(5, 1)$.
- Rows 2 and 5 are blocked. Between rows 2 and 5, rows 3 and 4 remain unblocked, giving a maximum row segment of length 2.
- Columns 1 and 3 are blocked. Between column 3 and the right boundary (column 5), columns 4 and 5 remain unblocked, giving a maximum column segment of length 2.
- Hence, the largest continuous unblocked rectangle has area $2 \times 2 = 4$.

### Example 2
**Input:**
```text
n = 2, m = 2, k = 1, arr[][] = [[2, 2]]
```
**Output:**
```text
1
```
**Explanation:**
Since only the $(1, 1)$ cell is free from any blocked row or column, the answer is 1.

---

## 📐 Constraints

- $$1 \le n, m \le 10^4$$
- $$0 \le k \le \min(n, m)$$
- $$1 \le r \le n$$
- $$1 \le c \le m$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(k \log k)$$ |
| 💾 Auxiliary Space | $$O(k)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Greedy](https://img.shields.io/badge/Greedy-3498DB?style=for-the-badge)
![Sorting](https://img.shields.io/badge/Sorting-F39C12?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../160_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../162_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
