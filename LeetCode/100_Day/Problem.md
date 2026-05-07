# [3660. Jump Game IX](https://leetcode.com/problems/jump-game-ix/description/)
---
<div align="center">

| [📝 Problem](Problem.md) | [💡 Approach](Approach.md) | [💻 Solution](Solution.cpp) | [🚀 Main](Main.cpp) |
| :---: | :---: | :---: | :---: |

</div>

---

## Metadata
- **Difficulty:** Medium | **Accuracy:** 31.1% | **Accepted:** 27,070/87K | **Original Env:** Daily Question (2026-05-03)

---

## Problem Description

You are given an integer array `nums`.

From any index `i`, you can jump to another index `j` under the following rules:

1.  **Jump Forward:** Jump to index `j` where `j > i` is allowed only if `nums[j] < nums[i]`.
2.  **Jump Backward:** Jump to index `j` where `j < i` is allowed only if `nums[j] > nums[i]`.

For each index `i`, find the **maximum value** in `nums` that can be reached by following any sequence of valid jumps starting at `i`.

Return an array `ans` where `ans[i]` is the maximum value reachable starting from index `i`.

---

## Examples

### Example 1:
**Input:** `nums = [2, 1, 3]`  
**Output:** `[2, 2, 3]`  
**Explanation:** 
- For `i = 0`: No jump increases the value.
- For `i = 1`: Jump to `j = 0` as `nums[j] = 2` is greater than `nums[i]`.
- For `i = 2`: Since `nums[2] = 3` is the maximum value in `nums`, no jump increases the value.
Thus, `ans = [2, 2, 3]`.

### Example 2:
**Input:** `nums = [2, 3, 1]`  
**Output:** `[3, 3, 3]`  
**Explanation:** 
- For `i = 0`: Jump forward to `j = 2` as `nums[j] = 1 < nums[i] = 2`, then from `i = 2` jump backward to `j = 1` as `nums[j] = 3 > nums[2] = 1`.
- For `i = 1`: Max value is 3.
- For `i = 2`: Jump to `j = 1` as `nums[j] = 3 > nums[2] = 1`.
Thus, `ans = [3, 3, 3]`.

---

## Constraints
- $1 \le nums.length \le 10^5$
- $1 \le nums[i] \le 10^9$

---

<p align="center">
  <b>Happy Coding! 🚀</b>
</p>
