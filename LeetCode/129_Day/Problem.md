# [3753. Total Waviness of Numbers in Range II](https://leetcode.com/problems/total-waviness-of-numbers-in-range-ii/description/?envType=daily-question&envId=2026-05-22)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance Rate: 41.0%](https://img.shields.io/badge/Acceptance%20Rate-41.0%25-orange?style=for-the-badge)
![Submissions: 30.5K](https://img.shields.io/badge/Submissions-30.5K-blue?style=for-the-badge)

## 🧩 Problem Description
You are given two integers `num1` and `num2` representing an inclusive range `[num1, num2]`.

The **waviness** of a number is defined as the total count of its peaks and valleys:
- A digit is a **peak** if it is strictly greater than both of its immediate neighbors.
- A digit is a **valley** if it is strictly less than both of its immediate neighbors.
- The first and last digits of a number cannot be peaks or valleys.
- Any number with fewer than `3` digits has a waviness of `0`.

Return the total sum of waviness for all numbers in the range `[num1, num2]`.

## 📌 Examples

**Example 1:**
> **Input:** num1 = 120, num2 = 130
> **Output:** 3
> **Explanation:**
> In the range `[120, 130]`:
> - 120: middle digit 2 is a peak, waviness = 1.
> - 121: middle digit 2 is a peak, waviness = 1.
> - 130: middle digit 3 is a peak, waviness = 1.
> All other numbers in the range have a waviness of 0.
> Thus, total waviness is 1 + 1 + 1 = 3.

**Example 2:**
> **Input:** num1 = 198, num2 = 202
> **Output:** 3
> **Explanation:**
> In the range `[198, 202]`:
> - 198: middle digit 9 is a peak, waviness = 1.
> - 201: middle digit 0 is a valley, waviness = 1.
> - 202: middle digit 0 is a valley, waviness = 1.
> All other numbers in the range have a waviness of 0.
> Thus, total waviness is 1 + 1 + 1 = 3.

**Example 3:**
> **Input:** num1 = 4848, num2 = 4848
> **Output:** 2
> **Explanation:**
> Number 4848: the second digit 8 is a peak, and the third digit 4 is a valley, giving a waviness of 2.

## 📐 Constraints
- $$1 \le \text{num1} \le \text{num2} \le 10^{15}$$

## ⏱️ Expected Complexities
| Parameter | Complexity |
|:---:|:---:|
| **Time Complexity** | $$O(\log_{10}(\text{num2}))$$ |
| **Auxiliary Space** | $$O(\log_{10}(\text{num2}))$$ |

## 🏷️ Topic Tags
`Math` `Dynamic Programming` `Digit DP`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../128_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../130_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
