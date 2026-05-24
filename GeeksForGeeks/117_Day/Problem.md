# [117. Last Coin in a Game of Alternates](https://www.geeksforgeeks.org/problems/last-coin-in-a-game-of-alternates/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata

![Difficulty: Basic](https://img.shields.io/badge/Difficulty-Basic-green?style=for-the-badge)
![Accuracy: 68.75%](https://img.shields.io/badge/Accuracy-68.75%25-blue?style=for-the-badge)
![Submissions: 78K+](https://img.shields.io/badge/Submissions-78K%2B-purple?style=for-the-badge)

---

## 🧩 Problem Description

Given an array integer `arr[]` representing the values of coins arranged in a row.

Two players play a game by picking coins alternately. At each turn, a player can pick a coin from either the beginning or the end of the array. Both players follow a greedy strategy, i.e., they always pick the coin with the maximum value among the two available ends. 

The game continues until only one coin remains. Find the value of the last remaining coin.

---

## 📌 Examples

### Example 1

**Input:** `arr[] = [5, 3, 1, 6, 9]`  
**Output:** `1`  
**Explanation:**  
- Players always pick the larger coin from the two ends.
- First pick: `9` from the right, remaining array: `[5, 3, 1, 6]`
- Second pick: `6` from the right, remaining array: `[5, 3, 1]`
- Third pick: `5` from the left, remaining array: `[3, 1]`
- Fourth pick: `3` from the left, remaining array: `[1]`
- Final remaining coin value: `1`

### Example 2

**Input:** `arr[] = [5, 9, 2, 5]`  
**Output:** `2`  
**Explanation:**  
- First pick: `5` (left coin chosen when ends are equal), remaining array: `[9, 2, 5]`
- Second pick: `9` from the left, remaining array: `[2, 5]`
- Third pick: `5` from the right, remaining array: `[2]`
- Final remaining coin value: `2`

### Example 3

**Input:** `arr[] = [11]`  
**Output:** `11`  
**Explanation:**  
- Only one coin is present in the array, so no moves are made.
- Final remaining coin value: `11`

---

## 📐 Constraints

- $1 \le \text{arr.size()} \le 10^5$
- $1 \le \text{arr}[i] \le 10^6$

---

## ⏱️ Expected Complexities

| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(1)$ |

---

## 🏷️ Topic Tags

- `two-pointer-algorithm`
- `Arrays`
- `Greedy`
- `Data Structures`
- `Algorithms`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../116_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../118_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
