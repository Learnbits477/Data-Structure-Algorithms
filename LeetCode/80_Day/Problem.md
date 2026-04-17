# [3761. Minimum Absolute Distance Between Mirror Pairs](https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/)

---

## 🏷️ Problem Info

| Field         | Details                                                                                              |
| :------------ | :--------------------------------------------------------------------------------------------------- |
| 🌐 Platform   | ![LeetCode](https://img.shields.io/badge/LeetCode-FFA116?style=flat&logo=leetcode&logoColor=white)    |
| 📌 Difficulty | ![Medium](https://img.shields.io/badge/Medium-FFB800?style=flat)                                     |
| 📂 Topic      | Hash Table / Math / String                                                                             |
| 🔗 Link       | [Minimum Absolute Distance Between Mirror Pairs](https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/) |

---

## 📖 Problem Statement

You are given an integer array `nums`.

A **mirror pair** is a pair of indices `(i, j)` such that:
- `0 <= i < j < nums.length`, and
- `reverse(nums[i]) == nums[j]`, where `reverse(x)` denotes the integer formed by reversing the digits of `x`. Leading zeros are omitted after reversing (e.g., `reverse(120) = 21`).

Return the **minimum absolute distance** between the indices of any mirror pair. The absolute distance between indices `i` and `j` is `abs(i - j)`.

If no mirror pair exists, return **-1**.

---

## 🧩 Examples

### Example 1
**Input:** `nums = [12, 21, 45, 33, 54]`  
**Output:** `1`  
**Explanation:**  
- Mirror pair `(0, 1)`: `reverse(12) = 21 = nums[1]`, distance `abs(0-1) = 1`.
- Mirror pair `(2, 4)`: `reverse(45) = 54 = nums[4]`, distance `abs(2-4) = 2`.
The minimum distance is `1`.

### Example 2
**Input:** `nums = [120, 21]`  
**Output:** `1`  
**Explanation:**  
- Mirror pair `(0, 1)`: `reverse(120) = 21 = nums[1]`, distance `1`.

### Example 3
**Input:** `nums = [21, 120]`  
**Output:** `-1`  
**Explanation:**  
- No pair `(i, j)` satisfies the condition `reverse(nums[i]) == nums[j]` for `i < j`.

---

## 📐 Constraints

| Constraint         | Value                          |
| :----------------- | :----------------------------- |
| `nums.length`      | `1 ≤ nums.length ≤ 10⁵`       |
| `nums[i]`          | `1 ≤ nums[i] ≤ 10⁹`           |
