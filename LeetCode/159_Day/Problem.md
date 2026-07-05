# [1301. Number of Paths with Max Score](https://leetcode.com/problems/number-of-paths-with-max-score/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 53.5%](https://img.shields.io/badge/Acceptance-53.5%25-blue?style=for-the-badge)
![Submissions: 68.6K](https://img.shields.io/badge/Submissions-68.6K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character `'S'`.

You need to reach the top left square marked with the character `'E'`. The rest of the squares are labeled either with a numeric character `1`, `2`, ..., `9` or with an obstacle `'X'`. In one move you can go **up**, **left**, or **up-left** (diagonally) only if there is no obstacle there.

Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo $$10^9 + 7$$.

In case there is no path, return `[0, 0]`.

---

## 📌 Examples

### Example 1
**Input:**
```text
board = ["E23","2X2","12S"]
```
**Output:**
```text
[7, 1]
```

### Example 2
**Input:**
```text
board = ["E12","1X1","21S"]
```
**Output:**
```text
[4, 2]
```

### Example 3
**Input:**
```text
board = ["E11","XXX","11S"]
```
**Output:**
```text
[0, 0]
```

---

## 📐 Constraints

- $$2 \le \text{board.length} = \text{board}[i].\text{length} \le 100$$
- `board[i][j]` is `'S'`, `'E'`, `'X'`, or a digit `'1'`-`'9'`.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(N^2)$$ |
| 💾 Auxiliary Space | $$O(N^2)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-3498DB?style=for-the-badge)
![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-8E44AD?style=for-the-badge)
![Matrix](https://img.shields.io/badge/Matrix-F39C12?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../158_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../160_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
