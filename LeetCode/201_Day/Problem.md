# [2029. Stone Game IX](https://leetcode.com/problems/stone-game-ix/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 37.4%](https://img.shields.io/badge/Acceptance-37.4%25-blue?style=for-the-badge)
![Submissions: 18.5K/49.6K](https://img.shields.io/badge/Submissions-18.5K-blue?style=for-the-badge)

![Topic: Array](https://img.shields.io/badge/Topics:-Array-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Math-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)
![Topic: Game Theory](https://img.shields.io/badge/Game_Theory-blue?style=for-the-badge)

---

## 🧩 Problem Description

Alice and Bob play a game with stones. There is a row of $n$ stones, where `stones[i]` is the value of the $i$-th stone.

Alice and Bob take turns, with Alice starting first. On each turn, the player may remove any stone from `stones`.
- The player who removes a stone **loses** if the sum of the values of all removed stones is divisible by $3$.
- Bob will win automatically if there are no remaining stones (even if it is Alice's turn) and no player has lost.

Assuming both players play optimally, return `true` if Alice wins and `false` if Bob wins.

---

## 📌 Examples

### Example 1

**Input:**
```text
stones = [2, 1]
```
**Output:**
```text
true
```
**Explanation:**
- Turn 1: Alice can remove either stone. Suppose she picks stone 1 (value 1). Sum = 1.
- Turn 2: Bob removes the remaining stone (value 2). Sum = 1 + 2 = 3 (divisible by 3).
- Therefore, Bob loses and Alice wins the game.

---

### Example 2

**Input:**
```text
stones = [2]
```
**Output:**
```text
false
```
**Explanation:**
- Alice removes the only stone (value 2). Sum = 2.
- Since all stones are removed and the sum is not divisible by 3, Bob wins the game.

---

### Example 3

**Input:**
```text
stones = [5, 1, 2, 4, 3]
```
**Output:**
```text
false
```
**Explanation:**
Bob will always win under optimal play.

---

## 📐 Constraints

- $1 \le \text{stones.length} \le 10^5$
- $1 \le \text{stones}[i] \le 10^4$

---

## ⏱️ Expected Complexities

| Operation | Time Complexity | Space Complexity |
| :--- | :---: | :---: |
| Remainder Counting | $O(N)$ | $O(1)$ |

---

<br/>

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../200_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../202_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
