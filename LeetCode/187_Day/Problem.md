# [877. Stone Game](https://leetcode.com/problems/stone-game/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 74.0%](https://img.shields.io/badge/Acceptance-74.0%25-blue?style=for-the-badge)
![Submissions: 497K+](https://img.shields.io/badge/Submissions-497K+-purple?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topics:-Array-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Math-cyan?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic_Programming-brightgreen?style=for-the-badge)
![Topic: Game Theory](https://img.shields.io/badge/Game_Theory-orange?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones `piles[i]`.

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return `true` if Alice wins the game, or `false` if Bob wins.

---

## 📌 Examples

**Example 1:**
- **Input:** `piles = [5,3,4,5]`
- **Output:** `true`
- **Explanation:** 
  Alice starts first, and can only take the first 5 or the last 5.
  Say she takes the first 5, so that the row becomes `[3, 4, 5]`.
  If Bob takes 3, then the board is `[4, 5]`, and Alice takes 5 to win with 10 points.
  If Bob takes the last 5, then the board is `[3, 4]`, and Alice takes 4 to win with 9 points.
  This demonstrated that taking the first 5 was a winning move for Alice, so we return `true`.

**Example 2:**
- **Input:** `piles = [3,7,2,3]`
- **Output:** `true`

---

## 📐 Constraints

- $2 \le piles.length \le 500$
- `piles.length` is even.
- $1 \le piles[i] \le 500$
- `sum(piles[i])` is odd.

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n^2)$ (dynamic programming) or $O(1)$ (mathematical insight) |
| **Auxiliary Space** | $O(n)$ or $O(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../186_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../188_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
