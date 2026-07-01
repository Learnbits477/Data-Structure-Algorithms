# [1833. Maximum Ice Cream Bars](https://leetcode.com/problems/maximum-ice-cream-bars/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 74.2%](https://img.shields.io/badge/Acceptance-74.2%25-blue?style=for-the-badge)
![Submissions: 250.3K](https://img.shields.io/badge/Submissions-250.3K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

It is a sweltering summer day, and a boy wants to buy some ice cream bars.

You are given an array `costs` of length $$n$$, where `costs[i]` is the price of the $$i$$-th ice cream bar in coins. The boy initially has `coins` coins to spend, and he wants to buy as many ice cream bars as possible. 

**Note:** The boy can buy the ice cream bars in any order.

Return *the **maximum** number of ice cream bars the boy can buy with `coins` coins*.

---

## 📌 Examples

### Example 1

**Input:** `costs = [1,3,2,4,1]`, `coins = 7`  
**Output:** `4`  
**Explanation:** The boy can buy ice cream bars at indices `0, 1, 2, 4` for a total cost of $$1 + 3 + 2 + 1 = 7$$.

### Example 2

**Input:** `costs = [10,6,8,7,7,8]`, `coins = 5`  
**Output:** `0`  
**Explanation:** The boy cannot afford any of the ice cream bars.

### Example 3

**Input:** `costs = [1,6,3,1,2,5]`, `coins = 20`  
**Output:** `6`  
**Explanation:** The boy can buy all the ice cream bars for a total cost of $$1 + 6 + 3 + 1 + 2 + 5 = 18$$.

---

## 📐 Constraints

- $$costs.length == n$$
- $$1 \le n \le 10^5$$
- $$1 \le costs[i] \le 10^5$$
- $$1 \le coins \le 10^8$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :--- |
| 🕐 Time | $$O(n \log n)$$ |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-0A9EDC?style=for-the-badge)
![Greedy](https://img.shields.io/badge/Greedy-0A9EDC?style=for-the-badge)
![Sorting](https://img.shields.io/badge/Sorting-0A9EDC?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../144_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../146_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
