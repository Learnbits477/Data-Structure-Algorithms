# [2657. Find the Prefix Common Array of Two Arrays](https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 88.3%](https://img.shields.io/badge/Acceptance-88.3%25-blue?style=for-the-badge)
![Submissions: 346.4K](https://img.shields.io/badge/Submissions-346.4K-purple?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given two $0$-indexed integer permutations `A` and `B` of length `n`.

A **prefix common array** of `A` and `B` is an array `C` such that `C[i]` is equal to the count of numbers that are present at or before the index `i` in both `A` and `B`.

Return the prefix common array of `A` and `B`.

A sequence of `n` integers is called a **permutation** if it contains all integers from `1` to `n` exactly once.

---

## 📌 Examples

### Example 1

**Input:**
```text
A = [1, 3, 2, 4]
B = [3, 1, 2, 4]
```
**Output:** `[0, 2, 3, 4]`  
**Explanation:**
- At $i = 0$: no number is common, so `C[0] = 0`.
- At $i = 1$: `1` and `3` are common in both prefixes of `A` and `B`, so `C[1] = 2`.
- At $i = 2$: `1`, `2`, and `3` are common in both prefixes of `A` and `B`, so `C[2] = 3`.
- At $i = 3$: `1`, `2`, `3`, and `4` are common in both prefixes of `A` and `B`, so `C[3] = 4`.

### Example 2

**Input:**
```text
A = [2, 3, 1]
B = [3, 1, 2]
```
**Output:** `[0, 1, 3]`  
**Explanation:**
- At $i = 0$: no number is common, so `C[0] = 0`.
- At $i = 1$: only `3` is common in both prefixes of `A` and `B`, so `C[1] = 1`.
- At $i = 2$: `1`, `2`, and `3` are common in both prefixes of `A` and `B`, so `C[2] = 3`.

---

## 📐 Constraints

- $1 \le \text{A.length} == \text{B.length} == n \le 50$
- $1 \le \text{A}[i], \text{B}[i] \le n$
- It is guaranteed that `A` and `B` are both a permutation of `n` integers.

---

## ⏱️ Expected Complexities

| Metric               | Complexity       |
| :------------------- | :--------------- |
| **Time Complexity**  | $\mathcal{O}(N)$ |
| **Space Complexity** | $\mathcal{O}(N)$ |

---

## 🏷️ Topic Tags

- `Array`
- `Hash Table`
- `Bit Manipulation`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../112_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../114_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
