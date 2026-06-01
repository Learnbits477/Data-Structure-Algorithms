# [2144. Minimum Cost of Buying Candies With Discount](https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance Rate: 66.9%](https://img.shields.io/badge/Acceptance%20Rate-66.9%25-green?style=for-the-badge)
![Submissions: 174.1K](https://img.shields.io/badge/Submissions-174.1K-blue?style=for-the-badge)

## 🧩 Problem Description

A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.

The customer can choose any candy to take away for free as long as the cost of the chosen candy is **less than or equal to** the minimum cost of the two candies bought.

Given a **0-indexed** integer array `cost`, where `cost[i]` denotes the cost of the $i^{th}$ candy, return the **minimum cost** of buying all the candies.

## 📌 Examples

**Example 1:**
> **Input:** `cost = [1,2,3]`
> **Output:** `5`
> **Explanation:** We buy the candies with costs 2 and 3, and take the candy with cost 1 for free.
> The total cost of buying all candies is 2 + 3 = 5. This is the only way we can buy the candies.
> Note that we cannot buy candies with costs 1 and 3, and then take the candy with cost 2 for free.
> The cost of the free candy has to be less than or equal to the minimum cost of the purchased candies.

**Example 2:**
> **Input:** `cost = [6,5,7,9,2,2]`
> **Output:** `23`
> **Explanation:** The way in which we can get the minimum cost is described below:
> - Buy candies with costs 9 and 7
> - Take the candy with cost 6 for free
> - We buy candies with costs 5 and 2
> - Take the last remaining candy with cost 2 for free
> Hence, the minimum cost to buy all candies is 9 + 7 + 5 + 2 = 23.

**Example 3:**
> **Input:** `cost = [5,5]`
> **Output:** `10`
> **Explanation:** Since there are only 2 candies, we buy both of them. There is not a third candy we can take for free.
> Hence, the minimum cost to buy all candies is 5 + 5 = 10.

## 📐 Constraints

- $1 \le cost.length \le 100$
- $1 \le cost[i] \le 100$

## ⏱️ Expected Complexities

| Parameter | Complexity |
|:---:|:---:|
| **Time Complexity** | $O(n \log n)$ |
| **Auxiliary Space** | $O(1)$ |

## 🏷️ Topic Tags

`Array`, `Greedy`, `Sorting`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../124_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../126_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
