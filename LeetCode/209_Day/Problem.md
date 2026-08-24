# 1872. [Stone Game VIII](https://leetcode.com/problems/stone-game-viii/description/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 72.4%](https://img.shields.io/badge/Acceptance-72.4%25-green?style=for-the-badge)
![Submissions: 78.5K+](https://img.shields.io/badge/Submissions-78.5K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Array-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Math-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Dynamic%20Programming-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Game%20Theory-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Prefix%20Sum-blue?style=for-the-badge)

---

## 🧩 Problem Description

Alice and Bob take turns playing a game, with **Alice starting first**.

There are `n` stones arranged in a row. On each player's turn, while the number of stones is **more than one**, they will do the following:
1. Choose an integer $x > 1$, and remove the leftmost `x` stones from the row.
2. Add the sum of the removed stones' values to the player's score.
3. Place a new stone, whose value is equal to that sum, on the left side of the row.

The game stops when **only one stone** is left in the row.

The score difference between Alice and Bob is `(Alice's score - Bob's score)`. Alice's goal is to **maximize** the score difference, and Bob's goal is to **minimize** the score difference.

Given an integer array `stones` of length `n` where `stones[i]` represents the value of the $i^{\text{th}}$ stone from the left, return the **score difference** between Alice and Bob if they both play **optimally**.

---

## 📌 Examples

### Example 1:
```text
Input: stones = [-1,2,-3,4,-5]
Output: 5
Explanation: 
- Alice removes the first 4 stones, adds (-1) + 2 + (-3) + 4 = 2 to her score, and places a stone of value 2 on the left. stones = [2,-5].
- Bob removes the first 2 stones, adds 2 + (-5) = -3 to his score, and places a stone of value -3 on the left. stones = [-3].
The difference between their scores is 2 - (-3) = 5.
```

### Example 2:
```text
Input: stones = [7,-6,5,10,5,-2,-6]
Output: 13
Explanation: 
- Alice removes all stones, adds 7 + (-6) + 5 + 10 + 5 + (-2) + (-6) = 13 to her score, and places a stone of value 13 on the left. stones = [13].
The difference between their scores is 13 - 0 = 13.
```

### Example 3:
```text
Input: stones = [-10,-12]
Output: -22
Explanation: 
- Alice can only make one move, which is to remove both stones. She adds (-10) + (-12) = -22 to her score and places a stone of value -22 on the left. stones = [-22].
The difference between their scores is (-22) - 0 = -22.
```

---

## 📐 Constraints

- $n == \text{stones.length}$
- $2 \le n \le 10^5$
- $-10^4 \le \text{stones}[i] \le 10^4$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ or $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../208_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../210_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
