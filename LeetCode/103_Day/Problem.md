# [Maximum Number of Jumps to Reach the Last Index](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/)

<div align="center">

| [Problem.md](Problem.md) | [Approach.md](Approach.md) | [Solution.cpp](Solution.cpp) | [Main.cpp](Main.cpp) |
| :--- | :--- | :--- | :--- |

</div>

---
**Difficulty:** Medium | **Accuracy:** 37.2% | **Accepted:** 45.2K | **Submissions:** 121.6K
---

## Problem Description

You are given a **0-indexed** array `nums` of `n` integers and an integer `target`.

You are initially positioned at index `0`. In one step, you can jump from index `i` to any index `j` such that:

- $0 \leq i < j < n$
- $-target \leq nums[j] - nums[i] \leq target$

Return the **maximum number of jumps** you can make to reach index `n - 1`.

If there is no way to reach index `n - 1`, return `-1`.

---

### Examples

**Input:** `nums = [1,3,6,4,1,2], target = 2`  
**Output:** `3`  
**Explanation:** To reach index `n - 1` with maximum jumps:
1. Jump from index `0` to `1` ($|3 - 1| = 2 \leq 2$)
2. Jump from index `1` to `3` ($|4 - 3| = 1 \leq 2$)
3. Jump from index `3` to `5` ($|2 - 4| = 2 \leq 2$)
Total jumps: 3.

**Input:** `nums = [1,3,6,4,1,2], target = 3`  
**Output:** `5`  
**Explanation:** Jumping sequence: $0 \rightarrow 1 \rightarrow 2 \rightarrow 3 \rightarrow 4 \rightarrow 5$. Total jumps: 5.

**Input:** `nums = [1,3,6,4,1,2], target = 0`  
**Output:** `-1`  
**Explanation:** No way to reach the last index.

---

### Constraints

- $2 \leq nums.length == n \leq 1000$
- $-10^9 \leq nums[i] \leq 10^9$
- $0 \leq target \leq 2 \times 10^9$

---

<div align="center">
Happy Coding! 🚀
</div>
