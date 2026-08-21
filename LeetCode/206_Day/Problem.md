# 3116. [Kth Smallest Amount With Single Denomination Combination](https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 26.0%](https://img.shields.io/badge/Acceptance-26.0%25-green?style=for-the-badge)
![Submissions: 67.6K](https://img.shields.io/badge/Submissions-67.6K-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Array,_Math,_Binary_Search,_Bit_Manipulation,_Combinatorics,_Number_Theory-blue?style=for-the-badge)

## 🧩 Problem Description

You are given an integer array `coins` representing coins of different denominations and an integer `k`.

You have an infinite number of coins of each denomination. However, you are **not** allowed to combine coins of different denominations.

Return the $k^{\text{th}}$ smallest amount that can be made using these coins.

## 📌 Examples

### Example 1:
```text
Input: coins = [3,6,9], k = 3
Output: 9
Explanation: 
The given coins can make the following amounts:
- Coin 3 produces multiples of 3: 3, 6, 9, 12, 15, etc.
- Coin 6 produces multiples of 6: 6, 12, 18, 24, etc.
- Coin 9 produces multiples of 9: 9, 18, 27, 36, etc.
All of the coins combined produce: 3, 6, 9, 12, 15, etc.
The 3rd smallest amount is 9.
```

### Example 2:
```text
Input: coins = [5,2], k = 7
Output: 12
Explanation: 
The given coins can make the following amounts:
- Coin 5 produces multiples of 5: 5, 10, 15, 20, etc.
- Coin 2 produces multiples of 2: 2, 4, 6, 8, 10, 12, etc.
All of the coins combined produce: 2, 4, 5, 6, 8, 10, 12, 14, 15, etc.
The 7th smallest amount is 12.
```

## 📐 Constraints
- $1 \le \text{coins.length} \le 15$
- $1 \le \text{coins}[i] \le 25$
- $1 \le k \le 2 \cdot 10^9$
- `coins` contains pairwise distinct integers.

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time** | $\mathcal{O}(2^m \cdot \log(\min(\text{coins}) \cdot k))$ |
| **Space** | $\mathcal{O}(2^m)$ |
*(where $m \le \text{coins.length} \le 15$ is the number of non-redundant coin denominations)*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../205_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../207_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
