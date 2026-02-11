# Approach: Sliding Window with Segment Tree

## Intuition

We want to find the longest subarray `nums[L...R]` such that `CountDistinctEven(L, R) == CountDistinctOdd(L, R)`.
Let `Diff(L, R) = CountDistinctEven(L, R) - CountDistinctOdd(L, R)`. We want to find `L, R` to maximize `R - L` subject to `Diff(L, R) == 0`.

## Algorithm

1. **Prefix Calculation**:
    - Compute a `prefix_sum` array where `prefix_sum[k]` represents `Diff(0, k)`.
    - This is done by iterating through the array and adding `1` for even and `-1` for odd numbers, but *only for the first occurrence* of each number.

2. **Segment Tree**:
    - Build a Segment Tree on the `prefix_sum` array.
    - The Segment Tree supports **Range Add** and **Find Last Zero**.
    - At any step `i` (left bound of subarray), the Segment Tree nodes `k` will store `Diff(i, k)`.

3. **Sliding Window**:
    - Iterate `i` from `0` to `N-1`.
    - Query the Segment Tree to find the largest index `k >= i + current_max_len` such that the value is `0` (i.e., `Diff(i, k) == 0`).
    - Update `max_len`.
    - **Transition**: When moving from `i` to `i+1`, we remove `nums[i]` from the window.
    - Removing `nums[i]` affects `Diff(i+1, k)` for all `k` where `nums[i]` was the *first* occurrence in `nums[i...k]`.
    - This range is `[i+1, next_occurrence_index(nums[i]) - 1]`.
    - Update the Segment Tree by adding `-sgn(nums[i])` to this range.

## Complexity

- **Time**: $O(N \log N)$ due to Segment Tree operations.
- **Space**: $O(N)$ for Segment Tree and map.
