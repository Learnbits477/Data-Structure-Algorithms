# Walkthrough: Divide an Array Into Subarrays With Minimum Cost I

This document details the solution for LeetCode 3010.

## Problem Analysis

We need to split the array into 3 contiguous subarrays. `nums[0]` is always the head of the first subarray. We just need to pick the heads of the 2nd and 3rd subarrays from the remaining elements such that their values are minimized.

Constraint Checklist & Confidence Score:

1. $3 \le n \le 50$: Yes, solution is $O(N)$, very efficient.
2. $1 \le nums[i] \le 50$: Yes, `int` is sufficient.

Confidence Score: 5/5

## Implementation Details

We implemented an $O(N)$ linear scan to find the two smallest values in `nums[1...n-1]`.

- **First Minimum (`min1`)**: Smallest value.
- **Second Minimum (`min2`)**: Second smallest value.

Total Cost = `nums[0] + min1 + min2`.

## Test Case Trace

**Input:** `nums = [1, 2, 3, 12]`

1. `cost` initialized to `nums[0] = 1`.
2. Scan from index `1` to `3`:
   - `i=1`, `val=2`: `min1` becomes `2`.
   - `i=2`, `val=3`: `3 >= min1` (2), but `3 < min2` (inf). `min2` becomes `3`.
   - `i=3`, `val=12`: `12` is larger than `min1` and `min2`.
3. Result: `1 + 2 + 3 = 6`.

**Input:** `nums = [10, 3, 1, 1]`

1. `cost` initialized to `nums[0] = 10`.
2. Scan from index `1` to `3`:
   - `i=1`, `val=3`: `min1` becomes `3`.
   - `i=2`, `val=1`: `1 < min1`. `min2` becomes `3`, `min1` becomes `1`.
   - `i=3`, `val=1`: `1` is not `< min1` (1), but `1 < min2` (3). `min2` becomes `1`.
3. Result: `10 + 1 + 1 = 12`.

## Conclusion

The greedy strategy works because picking the smallest start indices for the 2nd and 3rd subarrays minimizes the cost function directly.
