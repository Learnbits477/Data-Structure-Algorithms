# [3499. Maximize Active Section with Trade I](https://leetcode.com/problems/maximize-active-section-with-trade-i/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 52.8%](https://img.shields.io/badge/Acceptance-52.8%25-blue?style=for-the-badge)
![Topics: String](https://img.shields.io/badge/Topics-String-orange?style=for-the-badge)
![Topics: Enumeration](https://img.shields.io/badge/Topics-Enumeration-orange?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given a binary string `s` of length `n`, where:
- `'1'` represents an active section.
- `'0'` represents an inactive section.

You can perform **at most one trade** to maximize the number of active sections in `s`. In a trade, you:
1. Convert a contiguous block of `'1'`s that is surrounded by `'0'`s to all `'0'`s.
2. Afterward, convert a contiguous block of `'0'`s that is surrounded by `'1'`s to all `'1'`s.

Return the maximum number of active sections in `s` after making the optimal trade.

> **Note:** Treat `s` as if it is augmented with a `'1'` at both ends, forming `t = '1' + s + '1'`. The augmented `'1'`s do not contribute to the final count.

---

## 📌 Examples

### Example 1
**Input:** 
```text
s = "01"
```
**Output:** 
```text
1
```
**Explanation:** 
Because there is no block of `'1'`s surrounded by `'0'`s, no valid trade is possible. The maximum number of active sections is 1.

### Example 2
**Input:** 
```text
s = "0100"
```
**Output:** 
```text
4
```
**Explanation:** 
- String `"0100"` $\rightarrow$ Augmented to `"101001"`.
- Choose `"0100"`, convert `"101001"` $\rightarrow$ `"100001"` $\rightarrow$ `"111111"`.
- The final string without augmentation is `"1111"`. The maximum number of active sections is 4.

### Example 3
**Input:** 
```text
s = "1000100"
```
**Output:** 
```text
7
```
**Explanation:** 
- String `"1000100"` $\rightarrow$ Augmented to `"110001001"`.
- Choose `"000100"`, convert `"110001001"` $\rightarrow$ `"110000001"` $\rightarrow$ `"111111111"`.
- The final string without augmentation is `"1111111"`. The maximum number of active sections is 7.

### Example 4
**Input:** 
```text
s = "01010"
```
**Output:** 
```text
4
```
**Explanation:** 
- String `"01010"` $\rightarrow$ Augmented to `"1010101"`.
- Choose `"010"`, convert `"1010101"` $\rightarrow$ `"1000101"` $\rightarrow$ `"1111101"`.
- The final string without augmentation is `"11110"`. The maximum number of active sections is 4.

---

## 📐 Constraints

- $1 \le n = s.\text{length} \le 10^5$
- `s[i]` is either `'0'` or `'1'`.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $O(n)$ |
| 💾 Auxiliary Space | $O(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../174_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../176_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
