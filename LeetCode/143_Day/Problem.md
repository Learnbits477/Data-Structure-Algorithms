# [1732. Find the Highest Altitude](https://leetcode.com/problems/find-the-highest-altitude/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 84.2%](https://img.shields.io/badge/Acceptance-84.2%25-blue?style=for-the-badge)
![Submissions: 927.5K](https://img.shields.io/badge/Submissions-927.5K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

There is a biker going on a road trip. The road trip consists of $$n + 1$$ points at different altitudes. The biker starts his trip on point `0` with altitude equal `0`.

You are given an integer array `gain` of length $$n$$ where `gain[i]` is the net gain in altitude between points $$i$$ and $$i + 1$$ for all ($$0 \le i < n$$). Return *the highest altitude of a point*.

---

## 📌 Examples

### Example 1

**Input:** `gain = [-5, 1, 5, 0, -7]`  
**Output:** `1`  
**Explanation:** The altitudes are `[0, -5, -4, 1, 1, -6]`. The highest is `1`.

### Example 2

**Input:** `gain = [-4, -3, -2, -1, 4, 3, 2]`  
**Output:** `0`  
**Explanation:** The altitudes are `[0, -4, -7, -9, -10, -6, -3, -1]`. The highest is `0`.

---

## 📐 Constraints

- $$n == \text{gain.length}$$
- $$1 \le n \le 100$$
- $$-100 \le \text{gain}[i] \le 100$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :--- |
| 🕐 Time | $$O(n)$$ |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-0A9EDC?style=for-the-badge)
![Prefix Sum](https://img.shields.io/badge/Prefix%20Sum-0A9EDC?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../142_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../144_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
