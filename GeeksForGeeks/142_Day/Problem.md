# [142. Coverage of all Zeros in a Binary Matrix](https://www.geeksforgeeks.org/problems/coverage-of-all-zeros-in-a-binary-matrix4024/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 55.68%](https://img.shields.io/badge/Accuracy-55.68%25-green?style=for-the-badge)
![Submissions: 29K+](https://img.shields.io/badge/Submissions-29K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a binary matrix `mat[][]` containing only `0`s and `1`s, find the total coverage of all `0`'s. The coverage of a particular `0` cell is defined by checking `1`'s in its four directions (left, right, up, and down). For each direction, if there is at least one `1` anywhere between the `0` and the boundary of the matrix, the coverage increases by one.

Return the sum of the coverage values for all `0` cells in the matrix.

---

## 📌 Examples

### Example 1
```text
Input: mat = [[1, 1, 1, 0],
              [1, 0, 0, 1]]
Output: 8
Explanation: 
- Coverage of first zero at (0, 3) is 2 (Left, Down).
- Coverage of second zero at (1, 1) is 3 (Left, Right, Up).
- Coverage of third zero at (1, 2) is 3 (Left, Right, Up).
Total coverage = 2 + 3 + 3 = 8.
```

---

### Example 2
```text
Input: mat = [[0, 1, 0],
              [0, 1, 1],
              [0, 0, 0]]
Output: 6
Explanation: 
- Coverage of (0, 0) is 1.
- Coverage of (0, 2) is 2.
- Coverage of (1, 0) is 1.
- Coverage of (2, 0) is 0.
- Coverage of (2, 1) is 1.
- Coverage of (2, 2) is 1.
Total coverage = 1 + 2 + 1 + 0 + 1 + 1 = 6.
```

---

### Example 3
```text
Input: mat = [[0, 1]]
Output: 1
Explanation: 
- Coverage of (0, 0) is 1 (Right).
Total coverage = 1.
*(Note: GFG description text mentions output 5 as a typo, but the correct coverage output is 1)*.
```

---

## 📐 Constraints

- $$1 \le \text{matrix.size}, \text{matrix}[0].size \le 100$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n \times m)$$ |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Matrix](https://img.shields.io/badge/Matrix-0A9EDC?style=for-the-badge)
![Data Structures](https://img.shields.io/badge/Data%20Structures-2C3E50?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-E74C3C?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../141_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../143_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
