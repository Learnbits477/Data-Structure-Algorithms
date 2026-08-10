# 195. [Stone Game IV](https://leetcode.com/problems/stone-game-iv/description/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 60.2%](https://img.shields.io/badge/Acceptance-60.2%25-blue?style=for-the-badge)
![Submissions: 154K](https://img.shields.io/badge/Submissions-154K-purple?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are `n` stones in a pile. On each player's turn, that player makes a move consisting of removing **any non-zero square number** of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Assuming both players play optimally, return `true` if Alice wins the game and `false` if she loses.

---

## 📌 Examples

**Example 1:**
- **Input:** `n = 1`
- **Output:** `true`
- **Explanation:** Alice can remove 1 stone winning the game because Bob gets a state with 0 stones and cannot make a move.

**Example 2:**
- **Input:** `n = 2`
- **Output:** `false`
- **Explanation:** Alice can only remove 1 stone. Then Bob gets a state with 1 stone and removes 1 stone, winning the game.

**Example 3:**
- **Input:** `n = 4`
- **Output:** `true`
- **Explanation:** Alice can remove 4 stones winning the game because Bob gets a state with 0 stones.

---

## 📐 Constraints

- $1 \le n \le 10^5$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n\sqrt{n})$ |
| **Auxiliary Space** | $O(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../194_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../196_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
