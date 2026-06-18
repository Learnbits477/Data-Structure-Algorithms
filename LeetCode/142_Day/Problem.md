# [1344. Angle Between Hands of a Clock](https://leetcode.com/problems/angle-between-hands-of-a-clock/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 64.8%](https://img.shields.io/badge/Acceptance-64.8%25-blue?style=for-the-badge)
![Submissions: 230.1K](https://img.shields.io/badge/Submissions-230.1K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given two numbers, `hour` and `minutes`, return the smaller angle (in degrees) formed between the hour and the minute hand.

Answers within $10^{-5}$ of the actual value will be accepted as correct.

---

## 📌 Examples

### Example 1

<div align="center">
  <img src="./sample_1.png" alt="Example 1" width="300px">
</div>

**Input:** `hour = 12`, `minutes = 30`  
**Output:** `165`  
**Explanation:** The minute hand points to 6, and the hour hand points exactly halfway between 12 and 1. The smaller angle is 165 degrees.

---

### Example 2

<div align="center">
  <img src="./sample_2.png" alt="Example 2" width="300px">
</div>

**Input:** `hour = 3`, `minutes = 30`  
**Output:** `75`  
**Explanation:** The minute hand points to 6, and the hour hand points halfway between 3 and 4. The smaller angle is 75 degrees.

---

### Example 3

<div align="center">
  <img src="./sample_3.png" alt="Example 3" width="300px">
</div>

**Input:** `hour = 3`, `minutes = 15`  
**Output:** `7.5`  
**Explanation:** The minute hand points to 3, and the hour hand points one quarter of the way between 3 and 4. The smaller angle is 7.5 degrees.

---

## 📐 Constraints

- $$1 \le \text{hour} \le 12$$
- $$0 \le \text{minutes} \le 59$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :--- |
| 🕐 Time | $$O(1)$$ |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Math](https://img.shields.io/badge/Math-0A9EDC?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../141_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../143_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
