# [3739. Count Subarrays with Majority Element II](https://leetcode.com/problems/count-subarrays-with-majority-element-ii/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 30.0%](https://img.shields.io/badge/Acceptance-30.0%25-blue?style=for-the-badge)
![Submissions: 3.5K](https://img.shields.io/badge/Submissions-3.5K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given an integer array `nums` and an integer `target`. Your task is to return the number of subarrays of `nums` in which `target` is the **majority element**.

A **majority element** in a subarray is defined as an element that appears **strictly more than half** of the times in that subarray.

---

## 📌 Examples

### Example 1

**Input:** `nums = [1,2,2,3]`, `target = 2`  
**Output:** `5`  
**Explanation:** The valid subarrays are:
- `[2]` (index 1..1)
- `[2]` (index 2..2)
- `[2, 2]` (index 1..2)
- `[1, 2, 2]` (index 0..2)
- `[2, 2, 3]` (index 1..3)

### Example 2

**Input:** `nums = [1,1,1,1]`, `target = 1`  
**Output:** `10`  
**Explanation:** Every possible subarray has `1` as its majority element.

### Example 3

**Input:** `nums = [1,2,3]`, `target = 4`  
**Output:** `0`  
**Explanation:** `4` does not exist in the array, so it cannot be a majority element in any subarray.

---

## 📐 Constraints

- $$1 \le nums.length \le 10^5$$
- $$1 \le nums[i] \le 10^9$$
- $$1 \le target \le 10^9$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :--- |
| 🕐 Time | $$O(n \log n)$$ where $$n$$ is the size of `nums`. |
| 💾 Auxiliary Space | $$O(n)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-0A9EDC?style=for-the-badge)
![Binary Indexed Tree](https://img.shields.io/badge/Binary%20Indexed%20Tree-0A9EDC?style=for-the-badge)
![Segment Tree](https://img.shields.io/badge/Segment%20Tree-0A9EDC?style=for-the-badge)
![Prefix Sum](https://img.shields.io/badge/Prefix%20Sum-0A9EDC?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../149_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../151_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
