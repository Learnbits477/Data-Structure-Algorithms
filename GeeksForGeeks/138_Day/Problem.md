# [138. Exit Point in a Matrix](https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 50.0%](https://img.shields.io/badge/Accuracy-50.0%25-green?style=for-the-badge)
![Submissions: 62K+](https://img.shields.io/badge/Submissions-62K+-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Companies: Samsung](https://img.shields.io/badge/Companies-Samsung-orange?style=for-the-badge)
![Topics: Matrix & Data Structures](https://img.shields.io/badge/Topics-Matrix%20%26%20Data%20Structures-lightgrey?style=for-the-badge)

## 🧩 Problem Description
Given a matrix `mat[][]` of size $$n \times m$$ consisting of 0s and 1s. You start at the top-left cell $$(0, 0)$$ and initially move in the left-to-right direction (i.e., towards the right).

While traversing the matrix, follow these rules:
- If the current cell contains 0, continue moving in the same direction.
- If the current cell contains 1, change your direction to the right (clockwise turn), and update the cell value to 0.

You continue this process until you move outside the boundaries of the matrix. Your task is to determine the coordinates (row and column index) of the cell from which you exit the matrix.

## 📌 Examples

**Example 1:**
```text
Input: mat[][] = [[0, 1, 0],
               [0, 1, 1], 
               [0, 0, 0]]
Output: [1, 0]
Explanation: 
We enter the matrix at (0, 0)
-> then move towards (0, 1) -> 1 is encountered
-> turn right towards (1, 1) -> again 1 is encountered
-> turn right again towards (1, 0)
-> now, the boundary of matrix will be crossed. Hence, exit point reached at [1, 0].
```

**Example 2:**
```text
Input: mat[][] = [[0, 0]]
Output: [0, 1]
Explanation: 
Enter the matrix at cell (0, 0).
Since the cell contains 0, we continue moving in the same direction.
We reach cell (0, 1), which also contains a 0. So, we continue moving in the same direction, we exit the matrix from cell [0, 1].
```

## 📐 Constraints
- $$1 \le n, m \le 100$$
- `mat[i][j]` is either 0 or 1.

## ⏱️ Expected Complexities
| Parameter | Complexity |
|:---:|:---:|
| **Time Complexity** | $$O(n \times m)$$ |
| **Auxiliary Space** | $$O(1)$$ |

## 🏷️ Topic Tags
`Matrix` `Data Structures`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../137_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../139_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
