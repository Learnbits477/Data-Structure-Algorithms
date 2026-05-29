# [122. Count Sorted Digit Groupings](https://www.geeksforgeeks.org/problems/count-digit-groupings-of-a-number1520/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 59.38%](https://img.shields.io/badge/Accuracy-59.38%25-yellow?style=for-the-badge)
![Submissions: 39K+](https://img.shields.io/badge/Submissions-39K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-purple?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a string `s` consisting of digits, you can split it into contiguous substrings (**sub-groups**). For example, the string `"112"` can be split as:

- `["1","1","2"]`
- `["11","2"]`
- `["1","12"]`
- `["112"]`

A grouping is considered **valid** if the sums of digits of the sub-groups form a **non-decreasing** sequence from left to right.

Determine the **total number** of such valid groupings for the given string.

---

## 📌 Examples

### Example 1

**Input:**
```
s = "1119"
```

**Output:**
```
7
```

**Explanation:**
One valid grouping is `["1", "11", "9"]`.
- Sum of `"1"` → **1**
- Sum of `"11"` → **2**
- Sum of `"9"` → **9**

Since **1 ≤ 2 ≤ 9**, this is valid.

All 7 valid groupings:
| # | Grouping | Sums |
|---|----------|------|
| 1 | `["1", "11", "9"]` | 1, 2, 9 |
| 2 | `["1", "119"]` | 1, 11 |
| 3 | `["1", "1", "19"]` | 1, 1, 10 |
| 4 | `["1", "1", "1", "9"]` | 1, 1, 1, 9 |
| 5 | `["11", "19"]` | 2, 10 |
| 6 | `["111", "9"]` | 3, 9 |
| 7 | `["1119"]` | 12 |

---

### Example 2

**Input:**
```
s = "12"
```

**Output:**
```
2
```

**Explanation:**
`["1","2"]` and `["12"]` are two valid groupings.

---

## 📐 Constraints

$$1 \leq \text{s.size()} \leq 100$$

$$s[i] \in \{0, 1, 2, 3, 4, 5, 6, 7, 8, 9\}$$

---

## ⏱️ Expected Complexities

| Complexity | Value |
|:----------:|:-----:|
| 🕒 Time    | $O(n^3)$ |
| 🗃️ Space   | $O(n^2)$ |

---

## 🏷️ Topic Tags

<div align="center">

![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-0078D7?style=for-the-badge)
![Memoization](https://img.shields.io/badge/Memoization-6A0DAD?style=for-the-badge)
![Strings](https://img.shields.io/badge/Strings-FF6B35?style=for-the-badge)
![Recursion](https://img.shields.io/badge/Recursion-2ECC71?style=for-the-badge)

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
