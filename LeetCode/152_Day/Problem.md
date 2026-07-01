# [1846. Maximum Element After Decreasing and Rearranging](https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 62.3%](https://img.shields.io/badge/Acceptance-62.3%25-blue?style=for-the-badge)
![Submissions: 142.1K](https://img.shields.io/badge/Submissions-142.1K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given an array of positive integers `arr`. Perform some operations (possibly none) on `arr` so that it satisfies these conditions:

1. The value of the first element in `arr` must be `1`.
2. The absolute difference between any two adjacent elements must be less than or equal to `1` (i.e., `abs(arr[i] - arr[i - 1]) <= 1` for each $$1 \le i < arr.length$$).

You can perform two types of operations:

- **Decrease** the value of any element of `arr` to a smaller positive integer.
- **Rearrange** the elements of `arr` to be in any order.

Return *the **maximum** possible value of an element in `arr` after satisfying the conditions*.

---

## 📌 Examples

### Example 1

**Input:** `arr = [2,2,1,2,1]`  
**Output:** `2`  
**Explanation:**   
We can rearrange and decrease `arr` to `[1, 2, 2, 2, 1]` which satisfies all conditions.
- The first element is 1.
- Adjacent differences are at most 1: `abs(2 - 1) = 1`, `abs(2 - 2) = 0`, `abs(2 - 2) = 0`, `abs(1 - 2) = 1`.
- The maximum element is 2.

### Example 2

**Input:** `arr = [100,1,1000]`  
**Output:** `3`  
**Explanation:**   
One optimal way to satisfy the conditions is:
1. Rearrange `arr` to `[1, 100, 1000]`.
2. Decrease the second element to 2.
3. Decrease the third element to 3.
The resulting array is `[1, 2, 3]`, which satisfies all conditions.
- The maximum element is 3.

### Example 3

**Input:** `arr = [1,2,3,4,5]`  
**Output:** `5`  
**Explanation:** The array already satisfies the conditions, and the maximum element is 5.

---

## 📐 Constraints

- $$1 \le arr.length \le 10^5$$
- $$1 \le arr[i] \le 10^9$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :--- |
| 🕐 Time | $$O(n \log n)$$ where $$n$$ is the size of `arr`. |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-0A9EDC?style=for-the-badge)
![Greedy](https://img.shields.io/badge/Greedy-0A9EDC?style=for-the-badge)
![Sorting](https://img.shields.io/badge/Sorting-0A9EDC?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../151_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../153_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
