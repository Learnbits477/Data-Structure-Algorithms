# [3702. Longest Subsequence With Non-Zero Bitwise XOR](https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 40.6%](https://img.shields.io/badge/Acceptance-40.6%25-blue?style=for-the-badge)
![Submissions: 40.1K/98.9K](https://img.shields.io/badge/Submissions-40.1K-blue?style=for-the-badge)

![Topic: Array](https://img.shields.io/badge/Topics:-Array-blue?style=for-the-badge)
![Topic: Bit Manipulation](https://img.shields.io/badge/Bit_Manipulation-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given an integer array `nums`.

Return the length of the longest subsequence in `nums` whose bitwise XOR is **non-zero**. If no such subsequence exists, return `0`.

---

## 📌 Examples

### Example 1

**Input:**
```text
nums = [1, 2, 3]
```

**Output:**
```text
2
```

**Explanation:**
One longest subsequence is `[2, 3]`. The bitwise XOR is computed as $2 \oplus 3 = 1$, which is non-zero.

---

### Example 2

**Input:**
```text
nums = [2, 3, 4]
```

**Output:**
```text
3
```

**Explanation:**
The longest subsequence is `[2, 3, 4]`. The bitwise XOR is computed as $2 \oplus 3 \oplus 4 = 5$, which is non-zero.

---

## 📐 Constraints

- $1 \le \text{nums.length} \le 10^5$
- $0 \le \text{nums}[i] \le 10^9$

---

## ⏱️ Expected Complexities

| Operation | Time Complexity | Space Complexity |
| :--- | :---: | :---: |
| Single Pass | $O(N)$ | $O(1)$ |

---

## 🏷️ Topic Tags

- `Array`
- `Bit Manipulation`

<br/>

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../199_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../201_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
