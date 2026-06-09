# [3689. Maximum Total Subarray Value I](https://leetcode.com/problems/maximum-total-subarray-value-i/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 66.2%](https://img.shields.io/badge/Acceptance-66.2%25-green?style=for-the-badge)
![Submissions: 95.2K](https://img.shields.io/badge/Submissions-95.2K-blue?style=for-the-badge)
![Topics: Array | Greedy](https://img.shields.io/badge/Topics-Array%20%7C%20Greedy-lightgrey?style=for-the-badge)

## 🧩 Problem Description
You are given an integer array `nums` of length `n` and an integer `k`.

You need to choose exactly `k` non-empty subarrays `nums[l..r]` of `nums`. Subarrays may overlap, and the exact same subarray (same `l` and `r`) can be chosen more than once.

The value of a subarray `nums[l..r]` is defined as: $\max(nums[l..r]) - \min(nums[l..r])$.

The total value is the sum of the values of all chosen subarrays.

Return the maximum possible total value you can achieve.

## 📌 Examples

**Example 1:**
```text
Input: nums = [1,3,2], k = 2
Output: 4
Explanation:
One optimal approach is:
- Choose nums[0..1] = [1, 3]. The maximum is 3 and the minimum is 1, giving a value of 3 - 1 = 2.
- Choose nums[0..2] = [1, 3, 2]. The maximum is still 3 and the minimum is still 1, so the value is also 3 - 1 = 2.
Adding these gives 2 + 2 = 4.
```

**Example 2:**
```text
Input: nums = [4,2,5,1], k = 3
Output: 12
Explanation:
One optimal approach is:
- Choose nums[0..3] = [4, 2, 5, 1]. The maximum is 5 and the minimum is 1, giving a value of 5 - 1 = 4.
- Choose nums[0..3] = [4, 2, 5, 1]. The maximum is 5 and the minimum is 1, so the value is also 4.
- Choose nums[2..3] = [5, 1]. The maximum is 5 and the minimum is 1, so the value is again 4.
Adding these gives 4 + 4 + 4 = 12.
```

## 📐 Constraints
- $$1 \le n == \text{nums.length} \le 5 \times 10^4$$
- $$0 \le \text{nums}[i] \le 10^9$$
- $$1 \le k \le 10^5$$

## ⏱️ Expected Complexities
| Parameter | Complexity |
|:---:|:---:|
| **Time Complexity** | $$O(n)$$ |
| **Auxiliary Space** | $$O(1)$$ |

## 🏷️ Topic Tags
`Array`, `Greedy`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../132_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../134_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
