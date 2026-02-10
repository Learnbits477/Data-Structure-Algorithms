# Approach: Koko Eating Bananas

## Problem Analysis

We need to find the minimum eating speed `s` such that Koko can eat all bananas within `k` hours.
The time taken to eat a pile of size `p` with speed `s` is `ceil(p / s)`, which can be calculated as `(p + s - 1) / s`.

## Algorithm: Binary Search on Answer

The possible values for `s` range from 1 to the maximum pile size (eating more than the largest pile per hour doesn't reduce time further per pile, as it still takes 1 hour).
The function `hours_needed(s)` is monotonically decreasing with `s`.
Thus, we can use binary search to find the minimum `s` that satisfies the condition.

## Steps

1. **Initialize Search Range:**
   - `low = 1`
   - `high = max(arr)` (or 10^9 to be safe, but max element is sufficient)
   - `ans = high`

2. **Binary Search:**
   - While `low <= high`:
     - `mid = low + (high - low) / 2`
     - Calculate `hours = 0`
     - For each pile `p` in `arr`:
       - `hours += (p + mid - 1) / mid`
     - If `hours <= k`:
       - `ans = mid`
       - `high = mid - 1` (Try smaller speed)
     - Else:
       - `low = mid + 1` (Need faster speed)

3. **Return `ans`**.

## Complexity

- **Time Complexity:** `O(N * log(max(arr)))`, where `N` is the number of piles.
- **Space Complexity:** `O(1)`.
