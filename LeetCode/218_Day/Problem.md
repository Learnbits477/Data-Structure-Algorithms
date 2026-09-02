# 3875. [Construct Uniform Parity Array I](https://leetcode.com/problems/construct-uniform-parity-array-i/description/?envType=daily-question&envId=2026-09-02)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 74.2%](https://img.shields.io/badge/Acceptance-74.2%25-green?style=for-the-badge)
![Submissions: 15K+](https://img.shields.io/badge/Submissions-15K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Array%20%7C%20Math%20%7C%20Brainteaser-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given an array `nums1` of $n$ distinct integers.

You want to construct another array `nums2` of length $n$ such that all elements in `nums2` have the **same parity** (either all are even or all are odd).

For each index $i$ ($0 \le i < n$), you must choose exactly one of the following operations:
1. `nums2[i] = nums1[i]`
2. `nums2[i] = nums1[i] - nums1[j]` (for any index $j \neq i$)

Return `true` if it is possible to construct such an array, otherwise return `false`.

---

## 📌 Examples

**Example 1:**
```text
Input: nums1 = [2, 3]
Output: true
Explanation:
- For index 0: choose nums2[0] = nums1[0] - nums1[1] = 2 - 3 = -1 (odd).
- For index 1: choose nums2[1] = nums1[1] = 3 (odd).
The resulting array is nums2 = [-1, 3], where all elements are odd.
Thus, the condition is satisfied.
```

**Example 2:**
```text
Input: nums1 = [4, 6]
Output: true
Explanation:
- For index 0: choose nums2[0] = nums1[0] = 4 (even).
- For index 1: choose nums2[1] = nums1[1] = 6 (even).
The resulting array is nums2 = [4, 6], where all elements are even.
Thus, the condition is satisfied.
```

**Example 3:**
```text
Input: nums1 = [1, 5, 9]
Output: true
Explanation:
All elements are already odd, so we can directly pick nums2[i] = nums1[i] for all i.
```

---

## 📐 Constraints

- $1 \le n == \text{nums1.length} \le 100$
- $1 \le \text{nums1}[i] \le 100$
- `nums1` consists of **distinct** positive integers.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(1)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../217_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../219_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
