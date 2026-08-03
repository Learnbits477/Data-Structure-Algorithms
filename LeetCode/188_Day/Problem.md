# [1406. Stone Game III](https://leetcode.com/problems/stone-game-iii/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 64.1%](https://img.shields.io/badge/Acceptance-64.1%25-blue?style=for-the-badge)
![Submissions: 192.8K](https://img.shields.io/badge/Submissions-192.8K-purple?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topics:-Array-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Math-cyan?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic_Programming-brightgreen?style=for-the-badge)
![Topic: Game Theory](https://img.shields.io/badge/Game_Theory-orange?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array `stoneValue`.

Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

Assume Alice and Bob play optimally.

Return *"Alice"* if Alice will win, *"Bob"* if Bob will win, or *"Tie"* if they will end the game with the same score.

---

## 📌 Examples

**Example 1:**
- **Input:** `stoneValue = [1,2,3,7]`
- **Output:** `"Bob"`
- **Explanation:** Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.

**Example 2:**
- **Input:** `stoneValue = [1,2,3,-9]`
- **Output:** `"Alice"`
- **Explanation:** Alice must choose all the three piles at the first move to win and leave Bob with negative score.
  If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
  If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
  Remember that both play optimally so here Alice will choose the scenario that makes her win.

**Example 3:**
- **Input:** `stoneValue = [1,2,3,6]`
- **Output:** `"Tie"`
- **Explanation:** Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.

---

## 📐 Constraints

- $1 \le stoneValue.length \le 5 \times 10^4$
- $-1000 \le stoneValue[i] \le 1000$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../187_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../189_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
