# [1331. Rank Transform of an Array](https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2026-07-12)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 71.8%](https://img.shields.io/badge/Acceptance-71.8%25-blue?style=for-the-badge)
![Submissions: 495.3K](https://img.shields.io/badge/Submissions-495.3K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an array of integers `arr`, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:
1. Rank is an integer starting from $1$.
2. The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
3. Rank should be as small as possible.

---

## 📌 Examples

### Example 1
**Input:**
```text
arr = [40, 10, 20, 30]
```
**Output:**
```text
[4, 1, 2, 3]
```
**Explanation:**
- `10` is the smallest element (Rank 1).
- `20` is the second smallest (Rank 2).
- `30` is the third smallest (Rank 3).
- `40` is the largest element (Rank 4).

### Example 2
**Input:**
```text
arr = [100, 100, 100]
```
**Output:**
```text
[1, 1, 1]
```
**Explanation:**
Same elements share the same rank.

### Example 3
**Input:**
```text
arr = [37, 12, 28, 9, 100, 56, 80, 5, 12]
```
**Output:**
```text
[5, 3, 4, 2, 8, 6, 7, 1, 3]
```

---

## 📐 Constraints

- $$0 \le arr.length \le 10^5$$
- $$-10^9 \le arr[i] \le 10^9$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(N \log N)$$ |
| 💾 Auxiliary Space | $$O(N)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-1ABC9C?style=for-the-badge)
![Hash Table](https://img.shields.io/badge/Hash%20Table-2ECC71?style=for-the-badge)
![Sorting](https://img.shields.io/badge/Sorting-3498DB?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../165_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../167_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
