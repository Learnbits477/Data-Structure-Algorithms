# 3876. [Construct Uniform Parity Array II](https://leetcode.com/problems/construct-uniform-parity-array-ii/description/?envType=daily-question&envId=2026-09-03)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 54.6%](https://img.shields.io/badge/Acceptance-54.6%25-green?style=for-the-badge)
![Submissions: 91.7K+](https://img.shields.io/badge/Submissions-91.7K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Array%20%7C%20Math-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given an array `nums1` of $n$ **distinct** integers.

You want to construct another array `nums2` of length $n$ such that the elements in `nums2` are either **all odd** or **all even** (i.e., have uniform parity).

For each index $i$, you must choose exactly one of the following (in any order):
1. $\text{nums2}[i] = \text{nums1}[i]$
2. $\text{nums2}[i] = \text{nums1}[i] - \text{nums1}[j]$, for an index $j \neq i$, such that $\text{nums1}[i] - \text{nums1}[j] \ge 1$

Return `true` if it is possible to construct such an array, otherwise return `false`.

---

## 📌 Examples

**Example 1:**
```text
Input: nums1 = [1, 4, 7]
Output: true
Explanation:
- Set nums2[0] = nums1[0] = 1 (odd).
- Set nums2[1] = nums1[1] - nums1[0] = 4 - 1 = 3 (odd).
- Set nums2[2] = nums1[2] = 7 (odd).
nums2 = [1, 3, 7], and all elements are odd. Thus, the answer is true.
```

**Example 2:**
```text
Input: nums1 = [2, 3]
Output: false
Explanation:
It is not possible to construct nums2 such that all elements have the same parity. 
- 2 is the minimum element and cannot subtract any smaller element (2 - 3 < 0 is invalid).
- Keeping 2 leaves it even, while 3 cannot be transformed to even because no odd number smaller than 3 exists.
Thus, the answer is false.
```

**Example 3:**
```text
Input: nums1 = [4, 6]
Output: true
Explanation:
- Set nums2[0] = nums1[0] = 4 (even).
- Set nums2[1] = nums1[1] = 6 (even).
nums2 = [4, 6], and all elements are even. Thus, the answer is true.
```

---

## 📐 Constraints

- $1 \le n == \text{nums1.length} \le 10^5$
- $1 \le \text{nums1}[i] \le 10^9$
- `nums1` consists of **distinct** integers.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../218_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../220_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
