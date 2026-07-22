# [3501. Maximize Active Section with Trade II](https://leetcode.com/problems/maximize-active-section-with-trade-ii/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 42.9%](https://img.shields.io/badge/Acceptance-42.9%25-blue?style=for-the-badge)
![Topics: Array](https://img.shields.io/badge/Array-orange?style=for-the-badge)
![Topics: String](https://img.shields.io/badge/String-orange?style=for-the-badge)
![Topics: Binary Search](https://img.shields.io/badge/Binary%20Search-orange?style=for-the-badge)
![Topics: Segment Tree](https://img.shields.io/badge/Segment%20Tree-orange?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given a binary string `s` of length `n`, where:
- `'1'` represents an active section.
- `'0'` represents an inactive section.

You can perform **at most one trade** to maximize the number of active sections in `s`. In a trade, you:
1. Convert a contiguous block of `'1'`s that is surrounded by `'0'`s to all `'0'`s.
2. Afterward, convert a contiguous block of `'0'`s that is surrounded by `'1'`s to all `'1'`s.

Additionally, you are given a 2D array `queries`, where `queries[i] = [li, ri]` represents a substring `s[li...ri]`.

For each query, determine the maximum possible number of active sections in `s` after making the optimal trade on the substring `s[li...ri]`.

Return an array `answer`, where `answer[i]` is the result for `queries[i]`.

> **Note:**
> - For each query, treat `s[li...ri]` as if it is augmented with a `'1'` at both ends, forming `t = '1' + s[li...ri] + '1'`. The augmented `'1'`s do not contribute to the final count.
> - The queries are independent of each other.

---

## 📌 Examples

### Example 1
**Input:** 
```text
s = "01", queries = [[0,1]]
```
**Output:** 
```text
[1]
```
**Explanation:** 
Because there is no block of `'1'`s surrounded by `'0'`s, no valid trade is possible. The maximum number of active sections is 1.

### Example 2
**Input:** 
```text
s = "0100", queries = [[0,3],[0,2],[1,3],[2,3]]
```
**Output:** 
```text
[4,3,1,1]
```
**Explanation:** 
- **Query `[0, 3]`** $\rightarrow$ Substring `"0100"` $\rightarrow$ Augmented to `"101001"`. Choose `"0100"`, convert `"0100"` $\rightarrow$ `"0000"` $\rightarrow$ `"1111"`. The final string without augmentation is `"1111"`. The maximum number of active sections is 4.
- **Query `[0, 2]`** $\rightarrow$ Substring `"010"` $\rightarrow$ Augmented to `"10101"`. Choose `"010"`, convert `"010"` $\rightarrow$ `"000"` $\rightarrow$ `"111"`. The final string without augmentation is `"1110"`. The maximum number of active sections is 3.
- **Query `[1, 3]`** $\rightarrow$ Substring `"100"` $\rightarrow$ Augmented to `"11001"`. Because there is no block of `'1'`s surrounded by `'0'`s, no valid trade is possible. The maximum number of active sections is 1.
- **Query `[2, 3]`** $\rightarrow$ Substring `"00"` $\rightarrow$ Augmented to `"1001"`. Because there is no block of `'1'`s surrounded by `'0'`s, no valid trade is possible. The maximum number of active sections is 1.

### Example 3
**Input:** 
```text
s = "1000100", queries = [[1,5],[0,6],[0,4]]
```
**Output:** 
```text
[6,7,2]
```
**Explanation:** 
- **Query `[1, 5]`** $\rightarrow$ Substring `"00010"` $\rightarrow$ Augmented to `"1000101"`. Choose `"00010"`, convert `"00010"` $\rightarrow$ `"00000"` $\rightarrow$ `"11111"`. The final string without augmentation is `"1111110"`. The maximum number of active sections is 6.
- **Query `[0, 6]`** $\rightarrow$ Substring `"1000100"` $\rightarrow$ Augmented to `"110001001"`. Choose `"000100"`, convert `"000100"` $\rightarrow$ `"000000"` $\rightarrow$ `"111111"`. The final string without augmentation is `"1111111"`. The maximum number of active sections is 7.
- **Query `[0, 4]`** $\rightarrow$ Substring `"10001"` $\rightarrow$ Augmented to `"1100011"`. Because there is no block of `'1'`s surrounded by `'0'`s, no valid trade is possible. The maximum number of active sections is 2.

### Example 4
**Input:** 
```text
s = "01010", queries = [[0,3],[1,4],[1,3]]
```
**Output:** 
```text
[4,4,2]
```

---

## 📐 Constraints

- $1 \le n = s.\text{length} \le 10^5$
- $1 \le \text{queries.length} \le 10^5$
- `s[i]` is either `'0'` or `'1'`.
- $\text{queries}[i] = [l_i, r_i]$
- $0 \le l_i \le r_i < n$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $O((n + q) \log n)$ |
| 💾 Auxiliary Space | $O(n \log n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../175_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../177_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
