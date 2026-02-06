# Approach: Sorting and Sliding Window

## Intuition

The problem asks us to find the minimum number of removals to satisfy the condition `max <= k * min` for the remaining elements. Minimizing removals is equivalent to **maximizing the number of remaining elements**.

The condition involves the minimum and maximum values of the subset.
If we sort the original array `nums`, any contiguous subarray `nums[i...j]` represents a subset where:

- `min_val = nums[i]`
- `max_val = nums[j]`

The condition becomes: `nums[j] <= nums[i] * k`.

## Algorithm

1. **Sort** the array `nums` in non-decreasing order.
2. Use a **Sliding Window** (or Two Pointers) approach to find the maximum width window `[i, j]` that satisfies `nums[j] <= nums[i] * k`.
    - Initialize `max_kept = 0`.
    - Iterate with a right pointer `j` from `0` to `n-1`.
    - While the condition `nums[j] > nums[i] * k` holds (where `i` is the left pointer), increment `i` to shrink the window from the left until the condition is met.
    - At each step, update `max_kept = max(max_kept, j - i + 1)`.
3. The answer is `n - max_kept`.

## Complexity Analysis

- **Time Complexity**: $O(N \log N)$
  - Sorting takes $O(N \log N)$.
  - The sliding window iterates through the array once, which is $O(N)$.
  - Overall: $O(N \log N)$.
- **Space Complexity**: $O(1)$ (or $O(\log N)$ depending on the sorting implementation's stack usage). We sort in-place.

## Corner Cases

- `k = 0`: Condition becomes `nums[j] <= 0`. Since `nums[i] >= 1`, this is only possible if `nums[i] = 0`, but constraints say `nums[i] >= 1`. However, `max <= 0` implies elements must be 0? Wait, constraints say `nums[i] >= 1`. So `k` will likely be $\ge 1$ based on logic, but strict constraints say `k >= 1`.
- Single element array: Always balanced.
- Large numbers: `nums[i] * k` can exceed $2^{31}-1$. Use `long long` for the comparison.
