# Split an Array into Two Equal Sum Subarrays

*** [**Difficulty:** Easy  **Accuracy:** 54.45%  **Submissions:** 44K+  **Points:** 2]***
---
**Link:** [GeeksForGeeks Problem](https://www.geeksforgeeks.org/problems/split-an-array-into-two-equal-sum-subarrays/1)

## Problem Description

Given an array of integers `arr[]`, return `true` if it is possible to split it in two subarrays (without reordering the elements), such that the sum of the two subarrays are equal. If it is not possible then return `false`.

### Examples

**Example 1:**
- **Input:** `arr[] = [1, 2, 3, 4, 5, 5]`
- **Output:** `true`
- **Explanation:** We can divide the array into `[1, 2, 3, 4]` and `[5, 5]`. The sum of both the subarrays are 10.

**Example 2:**
- **Input:** `arr[] = [4, 3, 2, 1]`
- **Output:** `false`
- **Explanation:** We cannot divide the array into two subarrays with equal sum.

### Constraints
- $1 \le arr.size() \le 10^5$
- $1 \le arr[i] \le 10^6$

---
**Solution:** [Solution.cpp](Solution.cpp) | **Approach:** [Approach.md](Approach.md)
