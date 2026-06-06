# [130. Non-Attacking Black and White Knights](https://www.geeksforgeeks.org/problems/black-and-white-1587115620/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 51.2%](https://img.shields.io/badge/Accuracy-51.2%25-green?style=for-the-badge)
![Submissions: 32K+](https://img.shields.io/badge/Submissions-32K+-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topics: Backtracking, Algorithms](https://img.shields.io/badge/Topics-Backtracking%20%7C%20Algorithms-lightgrey?style=for-the-badge)

## 🧩 Problem Description
Given two integers `n` and `m` representing the dimensions of a chessboard, find the number of ways to place one black knight and one white knight on the chessboard such that they cannot attack each other.

**Note:**
- The knights have to be placed on different squares.
- A knight can move two squares horizontally and one square vertically (L shaped), or two squares vertically and one square horizontally (L shaped).
- The knights attack each other if one can reach the other in one move.

## 📌 Examples

**Example 1:**
```text
Input: n = 2, m = 2
Output: 12 
Explanation: There are 12 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.
```

**Example 2:**
```text
Input: n = 2, m = 3
Output: 26
Explanation: There are 26 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.
```

## 📐 Constraints
- $$1 \le n \le 200$$
- $$1 \le m \le 225$$

## ⏱️ Expected Complexities
| Parameter | Complexity |
|:---:|:---:|
| **Time Complexity** | $$O(n \times m)$$ |
| **Auxiliary Space** | $$O(1)$$ |

## 🏷️ Topic Tags
`Backtracking`, `Algorithms`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../129_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../131_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
