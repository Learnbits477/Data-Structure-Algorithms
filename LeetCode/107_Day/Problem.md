# [2784. Check if Array is Good](https://leetcode.com/problems/check-if-array-is-good/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 51.0%](https://img.shields.io/badge/Acceptance-51.0%25-orange?style=for-the-badge)
![Submissions: 154.3K+](https://img.shields.io/badge/Submissions-154.3K%2B-lightgrey?style=for-the-badge)
![Avg Time: 15m](https://img.shields.io/badge/Avg%20Time-15m-informational?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Topic-Hash%20Table-blueviolet?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Topic-Sorting-yellow?style=for-the-badge)

---

## 🧩 Problem Description

You are given an integer array `nums`. We consider an array **good** if it is a permutation of an array `base[n]`.

`base[n] = [1, 2, ..., n - 1, n, n]` (in other words, it is an array of length `n + 1` which contains `1` to `n - 1` exactly once, plus two occurrences of `n`). For example, `base[1] = [1, 1]` and `base[3] = [1, 2, 3, 3]`.

Return `true` if the given array is good, otherwise return `false`.

> **Note:** A permutation of integers represents an arrangement of these numbers.

---

## 📌 Examples

### Example 1

```text
Input: nums = [2, 1, 3]
Output: false
Explanation: 
  Since the maximum element of the array is 3, the only candidate n for which this array could be a permutation of base[n], is n = 3. 
  However, base[3] has four elements but array nums has three. 
  Therefore, it can not be a permutation of base[3] = [1, 2, 3, 3]. So the answer is false.
```

### Example 2

```text
Input: nums = [1, 3, 3, 2]
Output: true
Explanation: 
  Since the maximum element of the array is 3, the only candidate n for which this array could be a permutation of base[n], is n = 3. 
  It can be seen that nums is a permutation of base[3] = [1, 2, 3, 3] (by swapping the second and fourth elements in nums, we reach base[3]). 
  Therefore, the answer is true.
```

### Example 3

```text
Input: nums = [1, 1]
Output: true
Explanation: 
  Since the maximum element of the array is 1, the only candidate n for which this array could be a permutation of base[n], is n = 1. 
  It can be seen that nums is a permutation of base[1] = [1, 1]. Therefore, the answer is true.
```

### Example 4

```text
Input: nums = [3, 4, 4, 1, 2, 1]
Output: false
Explanation: 
  Since the maximum element of the array is 4, the only candidate n for which this array could be a permutation of base[n], is n = 4. 
  However, base[4] has five elements but array nums has six. 
  Therefore, it can not be a permutation of base[4] = [1, 2, 3, 4, 4]. So the answer is false.
```

---

## 📐 Constraints

$$1 \leq \text{nums.length} \leq 100$$

$$1 \leq \text{nums}[i] \leq 200$$

---

## ⏱️ Expected Complexities

| Metric          | Complexity   |
|-----------------|--------------|
| Time Complexity | $O(N)$       |
| Auxiliary Space | $O(N)$       |

---

## 🏷️ Topic Tags

`Array` &nbsp; `Hash Table` &nbsp; `Sorting`

---
<div align="center">
Happy Coding! 🚀 <br>
<a href="../106_Day/Problem.md">
  <img src="https://img.shields.io/badge/Previous%20Day%20Problem-000000?style=for-the-badge&logo=leetcode&logoColor=yellow" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Twitter%20%2F%20X-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../108_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day%20Problem-000000?style=for-the-badge&logo=leetcode&logoColor=yellow" alt="Next">
</a>
</div>
