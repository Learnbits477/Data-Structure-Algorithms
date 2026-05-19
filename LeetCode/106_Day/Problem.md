# [1674. Minimum Moves to Make Array Complementary](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/description/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 48.6%](https://img.shields.io/badge/Acceptance-48.6%25-red?style=for-the-badge)
![Submissions: 35.8K](https://img.shields.io/badge/Submissions-35.8K-lightgrey?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Topic-Hash%20Table-blue?style=for-the-badge)
![Topic: Prefix Sum](https://img.shields.io/badge/Topic-Prefix%20Sum-blueviolet?style=for-the-badge)

---

## 🧩 Problem Description

You are given an integer array `nums` of **even length** `n` and an integer `limit`.  
In one move, you can replace any integer from `nums` with another integer between `1` and `limit`, inclusive.

The array `nums` is **complementary** if for all indices `i` (0-indexed),  
`nums[i] + nums[n - 1 - i]` equals the **same number**.

> For example, the array `[1, 2, 3, 4]` is complementary because for all indices `i`,  
> `nums[i] + nums[n - 1 - i] = 5`.

Return the **minimum number of moves** required to make `nums` complementary.

---

## 📌 Examples

### Example 1

```
Input:  nums = [1, 2, 4, 3], limit = 4
Output: 1

Explanation:
  In 1 move, change nums to [1, 2, 2, 3].
  nums[0] + nums[3] = 1 + 3 = 4
  nums[1] + nums[2] = 2 + 2 = 4
  nums[2] + nums[1] = 2 + 2 = 4
  nums[3] + nums[0] = 3 + 1 = 4
  All pairs sum to 4 → complementary. ✅
```

### Example 2

```
Input:  nums = [1, 2, 2, 1], limit = 2
Output: 2

Explanation:
  In 2 moves, change nums to [2, 2, 2, 2].
  (Cannot change any number to 3 since 3 > limit.)
```

### Example 3

```
Input:  nums = [1, 2, 1, 2], limit = 2
Output: 0

Explanation:
  nums is already complementary.
  nums[0] + nums[3] = 1 + 2 = 3
  nums[1] + nums[2] = 2 + 1 = 3
```

---

## 📐 Constraints

$$n = \texttt{nums.length}$$

$$2 \leq n \leq 10^5$$

$$1 \leq \texttt{nums}[i] \leq \texttt{limit} \leq 10^5$$

$$n \text{ is even}$$

---

## ⏱️ Expected Complexities

| Metric          | Complexity          |
|-----------------|---------------------|
| Time Complexity | $O(n + \text{limit})$ |
| Auxiliary Space | $O(\text{limit})$   |

---

## 🏷️ Topic Tags

`Array` &nbsp; `Hash Table` &nbsp; `Prefix Sum`

---
<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../105_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../107_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
