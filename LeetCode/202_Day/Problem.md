# [1563. Stone Game V](https://leetcode.com/problems/stone-game-v/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 40.8%](https://img.shields.io/badge/Acceptance-40.8%25-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topics:-Array-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Topics:-Math-blue?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topics:-Dynamic--Programming-blue?style=for-the-badge)
![Topic: Game Theory](https://img.shields.io/badge/Topics:-Game--Theory-blue?style=for-the-badge)
![Company Tags](https://img.shields.io/badge/Company%20Tags-Google%20%7C%20Amazon%20%7C%20Microsoft-black?style=for-the-badge)

---

<div align="center">
  <img src="./stone_game_v.jpg" alt="Stone Game V Visual Illustration" width="600"/>
</div>

---

## 🧩 Problem Description

There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array `stoneValue`.

Alice and Bob play a game based on the following rules:
- There are $N$ stones in a row.
- On each turn, Alice divides the remaining row of stones into two non-empty rows (left row and right row).
- Bob compares the sum of values of stones in the left row ($sum_L$) and right row ($sum_R$):
  - If $sum_L < sum_R$, Bob throws away the right row, and Alice gets $sum_L$ points. The game continues with the left row.
  - If $sum_R < sum_L$, Bob throws away the left row, and Alice gets $sum_R$ points. The game continues with the right row.
  - If $sum_L == sum_R$, Alice gets to choose which row Bob throws away (and gets that sum of points). The game continues with the chosen remaining row.
- The game ends when there is only 1 stone left.

Assuming Alice plays to **maximize** her total score, return the maximum score Alice can obtain.

---

## 📌 Examples

### Example 1
**Input:**
```text
stoneValue = [6, 2, 3, 4, 5, 5]
```
**Output:**
```text
18
```
**Explanation:**
- Round 1: Alice divides `[6, 2, 3, 4, 5, 5]` into `[6, 2, 3]` (sum 11) and `[4, 5, 5]` (sum 14). Bob throws away the right row. Score = 11. Remaining row: `[6, 2, 3]`.
- Round 2: Alice divides `[6, 2, 3]` into `[6]` (sum 6) and `[2, 3]` (sum 5). Bob throws away the left row. Score = 11 + 5 = 16. Remaining row: `[2, 3]`.
- Round 3: Alice divides `[2, 3]` into `[2]` (sum 2) and `[3]` (sum 3). Bob throws away the right row. Score = 16 + 2 = 18. Remaining row: `[2]`.
- Game ends. Maximum score is 18.

### Example 2
**Input:**
```text
stoneValue = [7, 7, 7, 7, 7, 7, 7]
```
**Output:**
```text
28
```

### Example 3
**Input:**
```text
stoneValue = [4]
```
**Output:**
```text
0
```

---

## 📐 Constraints

- $1 \le \text{stoneValue.length} \le 500$
- $1 \le \text{stoneValue}[i] \le 10^6$

---

## ⏱️ Expected Complexities

| Time Complexity | Auxiliary Space |
| :-------------: | :-------------: |
| $O(N^3)$        | $O(N^2)$        |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../201_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../203_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
