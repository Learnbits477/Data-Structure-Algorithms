# [3300. Minimum Element After Replacement With Digit Sum](https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/description/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 88.9%](https://img.shields.io/badge/Acceptance-88.9%25-blue?style=for-the-badge)
![Submissions: 170K+](https://img.shields.io/badge/Submissions-170K%2B-blueviolet?style=for-the-badge)
![Topics: Array, Math](https://img.shields.io/badge/Topics-Array%20%7C%20Math-orange?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given an integer array `nums`.

You **replace** each element in `nums` with the **sum of its digits**.

Return the **minimum element** in `nums` after all replacements.

---

## 📌 Examples

### Example 1

**Input:**
```
nums = [10, 12, 13, 14]
```

**Output:**
```
1
```

**Explanation:**
`nums` becomes `[1, 3, 4, 5]` after all replacements, with minimum element **1**.

---

### Example 2

**Input:**
```
nums = [1, 2, 3, 4]
```

**Output:**
```
1
```

**Explanation:**
`nums` becomes `[1, 2, 3, 4]` after all replacements (single-digit numbers stay the same), with minimum element **1**.

---

### Example 3

**Input:**
```
nums = [999, 19, 199]
```

**Output:**
```
10
```

**Explanation:**
`nums` becomes `[27, 10, 19]` after all replacements, with minimum element **10**.

---

## 📐 Constraints

$$1 \leq \text{nums.length} \leq 100$$

$$1 \leq \text{nums}[i] \leq 10^4$$

---

## ⏱️ Expected Complexities

| Complexity | Value |
|:----------:|:-----:|
| 🕒 Time    | $O(n \cdot d)$ where $d$ = number of digits |
| 🗃️ Space   | $O(1)$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-0078D7?style=for-the-badge)
![Math](https://img.shields.io/badge/Math-FF6B35?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../121_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../123_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
