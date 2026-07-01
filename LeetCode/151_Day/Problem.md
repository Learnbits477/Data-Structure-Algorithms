# [3020. Find the Maximum Number of Elements in Subset](https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 35.6%](https://img.shields.io/badge/Acceptance-35.6%25-blue?style=for-the-badge)
![Submissions: 62.4K](https://img.shields.io/badge/Submissions-62.4K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given an array of positive integers `nums`.

You need to select a subset of `nums` such that its elements can be arranged in a sequence:

$$[x, x^2, x^4, \dots, x^{k/2}, x^k, x^{k/2}, \dots, x^4, x^2, x]$$

where $k$ must be a non-negative power of 2.

Return *the **maximum** number of elements in a subset that satisfies these conditions*.

---

## 📌 Examples

### Example 1

**Input:** `nums = [5,4,1,2,2]`  
**Output:** `3`  
**Explanation:** We can select the subset `{4, 2, 2}`, which can be arranged as `[2, 4, 2]`.
- $$2^2 = 4$$. This follows the required pattern of $$[x, x^2, x]$$.
- The length is 3, which is the maximum possible.

### Example 2

**Input:** `nums = [1,3,2,4]`  
**Output:** `1`  
**Explanation:** Valid subsets are `{1}`, `{2}`, `{3}`, or `{4}`, all of which satisfy the condition with $$k = 0$$ (having size 1).
- The maximum length is 1.

---

## 📐 Constraints

- $$2 \le nums.length \le 10^5$$
- $$1 \le nums[i] \le 10^9$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :--- |
| 🕐 Time | $$O(n)$$ where $$n$$ is the size of `nums`. |
| 💾 Auxiliary Space | $$O(n)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-0A9EDC?style=for-the-badge)
![Hash Table](https://img.shields.io/badge/Hash%20Table-0A9EDC?style=for-the-badge)
![Math](https://img.shields.io/badge/Math-0A9EDC?style=for-the-badge)
![Simulation](https://img.shields.io/badge/Simulation-0A9EDC?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../150_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../152_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
