# 194. [Stone Game II](https://leetcode.com/problems/stone-game-ii/description/?envType=daily-question&envId=2026-08-07)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 73.0%](https://img.shields.io/badge/Acceptance-73.0%25-blue?style=for-the-badge)
![Submissions: 286.8K](https://img.shields.io/badge/Submissions-286.8K-purple?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones `piles[i]`. The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.

On each player's turn, that player can take all the stones in the first $X$ remaining piles, where $1 \le X \le 2M$. Then, we set $M = \max(M, X)$. Initially, $M = 1$.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

---

## 📌 Examples

**Example 1:**
- **Input:** `piles = [2, 7, 9, 4, 4]`
- **Output:** `10`
- **Explanation:** 
  - If Alice takes one pile at the beginning ($X=1$), $M$ remains $1$. Remaining piles are `[7, 9, 4, 4]`.
  - Bob can take up to $2M = 2$ piles. Bob takes two piles ($X=2$), setting $M = 2$. Remaining piles are `[4, 4]`.
  - Alice can take up to $2M = 4$ piles. Alice takes the remaining two piles ($X=2$).
  - Alice gets $2 + 4 + 4 = 10$ stones in total.
  - If Alice takes two piles at the beginning, Bob can take all three remaining piles. Alice would get $2 + 7 = 9$ stones.
  - Since $10 > 9$, we return $10$.

**Example 2:**
- **Input:** `piles = [1, 2, 3, 4, 5, 100]`
- **Output:** `104`
- **Explanation:** Alice takes $2$ piles at the beginning ($X=2$, $M=2$), Bob takes $1$ pile ($X=1$, $M=2$), then Alice takes the remaining $3$ piles ($X=3$, $M=3$). Alice gets $1 + 2 + 5 + 100 = 104$.

---

## 📐 Constraints

- $1 \le \text{piles.length} \le 100$
- $1 \le \text{piles}[i] \le 10^4$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n^3)$ |
| **Auxiliary Space** | $O(n^2)$ |

---


<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../193_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../195_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
