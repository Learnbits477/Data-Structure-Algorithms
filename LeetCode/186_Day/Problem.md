# [486. Predict the Winner](https://leetcode.com/problems/predict-the-winner/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 57.2%](https://img.shields.io/badge/Acceptance-57.2%25-blue?style=for-the-badge)
![Submissions: 565K](https://img.shields.io/badge/Submissions-565K-purple?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topics:-Array-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Math-cyan?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic_Programming-brightgreen?style=for-the-badge)
![Topic: Game Theory](https://img.shields.io/badge/Game_Theory-orange?style=for-the-badge)
![Company: Amazon](https://img.shields.io/badge/Companies:-Amazon-orange?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given an integer array `nums`. Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., `nums[0]` or `nums[nums.length - 1]`) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

Return `true` if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return `true`. You may assume that both players are playing optimally.

---

## 📌 Examples

**Example 1:**
- **Input:** `nums = [1,5,2]`
- **Output:** `false`
- **Explanation:** 
  Initially, player 1 can choose between `1` and `2`. 
  If he chooses `2` (or `1`), then player 2 can choose from `1` (or `2`) and `5`. If player 2 chooses `5`, then player 1 will be left with `1` (or `2`). 
  So, final score of player 1 is $1 + 2 = 3$, and player 2 is $5$. 
  Hence, player 1 will never be the winner and you need to return `false`.

**Example 2:**
- **Input:** `nums = [1,5,233,7]`
- **Output:** `true`
- **Explanation:** 
  Player 1 first chooses `1`. Then player 2 has to choose between `5` and `7`. No matter which number player 2 chooses, player 1 can choose `233`.
  Finally, player 1 has more score ($234$) than player 2 ($12$), so you need to return `true` representing player 1 can win.

---

## 📐 Constraints

- $1 \le nums.length \le 20$
- $0 \le nums[i] \le 10^7$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n^2)$ |
| **Auxiliary Space** | $O(n^2)$ or $O(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../185_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../187_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
