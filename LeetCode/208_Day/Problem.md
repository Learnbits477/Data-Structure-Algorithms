# 1927. [Sum Game](https://leetcode.com/problems/sum-game/description/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 47.8%](https://img.shields.io/badge/Acceptance-47.8%25-green?style=for-the-badge)
![Submissions: 30K+](https://img.shields.io/badge/Submissions-30K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Math-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Game%20Theory-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Greedy-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-String-blue?style=for-the-badge)

---

## 🧩 Problem Description

Alice and Bob take turns playing a game, with **Alice going first**.

You are given a string `num` of **even length** consisting of digits and the character `'?'`.

On each turn, a player must choose a `'?'` and replace it with a digit between `'0'` and `'9'`.

The game ends when there are no more `'?'` characters in `num`.

- **Bob wins** if the sum of the digits in the first half of `num` is **equal** to the sum of the digits in the second half of `num`.
- **Alice wins** if the two sums are **not equal**.

Assuming both Alice and Bob play **optimally**, return `true` *if Alice wins*, or `false` *if Bob wins*.

---

## 📌 Examples

### Example 1:
```text
Input: num = "5023"
Output: false
Explanation: 
There are no '?' characters in num.
- Sum of first half = 5 + 0 = 5
- Sum of second half = 2 + 3 = 5
Since 5 == 5, Bob wins.
```

### Example 2:
```text
Input: num = "25??"
Output: true
Explanation: 
Alice can replace one '?' with '9' on her first turn.
Regardless of Bob's replacement for the second '?', the sum of the second half cannot equal 2 + 5 = 7.
Therefore, Alice wins.
```

### Example 3:
```text
Input: num = "?3295???"
Output: false
Explanation: 
- First half: "?329" -> Sum = 14, 1 '?'
- Second half: "5???" -> Sum = 5, 3 '?'
Bob can always mirror Alice's strategy by adding complementary digits (summing to 9 per pair of '?') to ensure both halves sum to 23 at the end.
Therefore, Bob wins.
```

---

## 📐 Constraints
- $2 \le \text{num.length} \le 10^5$
- $\text{num.length}$ is **even**.
- `num` consists of only digits (`'0'` - `'9'`) and `'?'`.

---

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time** | $\mathcal{O}(n)$ |
| **Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../207_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../209_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
