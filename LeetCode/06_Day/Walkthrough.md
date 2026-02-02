# Walkthrough - LeetCode 3013: Divide an Array Into Subarrays With Minimum Cost II

This document outlines the solution approach and verification for the "Divide an Array Into Subarrays With Minimum Cost II" problem.

## Problem Analysis

The core of the problem is finding `k-1` elements in a sliding window of size `dist + 1` (starting from index 1) that have the minimum sum. The first element `nums[0]` is always included in the cost.

## Solution Strategy

We used a **Sliding Window** combined with two **Multisets**:

- `lowers`: Maintains the smallest `k-1` elements in the current window.
- `uppers`: Maintains the remaining elements.

As we slide the window:

1. **Insert** the new element `nums[i]`. If it's smaller than the largest in `lowers`, it replaces it.
2. **Remove** the old element `nums[i - dist - 1]`. If it was in `lowers`, we replace it with the smallest element from `uppers`.
3. **Track Sum**: We maintain `current_sum` of elements in `lowers` for O(1) access to the cost.

## Verification

### Example 1

**Input**: `nums = [1,3,2,6,4,2]`, `k = 3`, `dist = 3`

- `target_k = 2`.
- Window slides.
- Optimal window found includes elements `{2, 2}` from indices 2 and 5 (or similar).
- `sum_lowers = 4`.
- Total = `nums[0] + 4 = 1 + 4 = 5`.
- Matches Output: `5`.

### Example 2

**Input**: `nums = [10,1,2,2,2,1]`, `k = 4`, `dist = 3`

- `target_k = 3`.
- Optimal window includes `1, 2, 2`.
- Sum = 5.
- Total = `10 + 5 = 15`.
- Matches Output: `15`.

### Example 3

**Input**: `nums = [10,8,18,9]`, `k = 3`, `dist = 1`

- `target_k = 2`.
- `dist = 1` means indices must be adjacent.
- Valid pairs: `(8, 18)`, `(18, 9)`.
- `8+18 = 26`.
- `18+9 = 27`.
- Min is 26.
- Total = `10 + 26 = 36`.
- Matches Output: `36`.

## Complexity Analysis

- **Time**: O(N log K) due to multiset operations.
- **Space**: O(N) to store elements in the sets.
