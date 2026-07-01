# [3700. Number of Zigzag Arrays II](https://leetcode.com/problems/number-of-zigzag-arrays-ii/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 35.0%](https://img.shields.io/badge/Acceptance-35.0%25-blue?style=for-the-badge)
![Submissions: 2.1K](https://img.shields.io/badge/Submissions-2.1K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given three integers $$n$$, $$l$$, and $$r$$. A **ZigZag array** of length $$n$$ is defined by the following rules:

1. **Range:** Each element in the array must be in the range $$[l, r]$$.
2. **No Equal Adjacent Elements:** No two adjacent elements are equal ($$arr[i] \neq arr[i+1]$$).
3. **ZigZag Pattern:** No three consecutive elements form a strictly increasing or strictly decreasing sequence. In other words, the sequence must strictly alternate between "increasing" and "decreasing" transitions.

Return the total number of valid ZigZag arrays of length $$n$$. Since the result can be very large, return it **modulo $$10^9 + 7$$**.

---

## 📌 Examples

### Example 1

**Input:** `n = 3, l = 4, r = 5`  
**Output:** `2`  
**Explanation:** The valid arrays of length 3 using values in the range $$[4, 5]$$ are:
- `[4, 5, 4]`
- `[5, 4, 5]`

### Example 2

**Input:** `n = 3, l = 1, r = 3`  
**Output:** `10`  
**Explanation:** The 10 valid arrays of length 3 using values in the range $$[1, 3]$$ are:
- `[1, 2, 1]`, `[1, 3, 1]`, `[1, 3, 2]`
- `[2, 1, 2]`, `[2, 1, 3]`, `[2, 3, 1]`, `[2, 3, 2]`
- `[3, 1, 2]`, `[3, 1, 3]`, `[3, 2, 3]`

---

## 📐 Constraints

- $$3 \le n \le 10^9$$
- $$1 \le l < r \le 75$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :--- |
| 🕐 Time | $$O(m^3 \log n)$$ where $$m = r - l + 1$$. |
| 💾 Auxiliary Space | $$O(m^2)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-0A9EDC?style=for-the-badge)
![Math](https://img.shields.io/badge/Math-0A9EDC?style=for-the-badge)
![Matrix Exponentiation](https://img.shields.io/badge/Matrix%20Exponentiation-0A9EDC?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../147_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../149_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
