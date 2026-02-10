# Approach: Longest Balanced Subarray I

## Problem Analysis
We need to find the length of the longest subarray where the count of distinct even numbers equals the count of distinct odd numbers.

## Constraints
- `N` (length of array) <= 1500.
- Values in `nums` <= 10^5.

## Algorithm: Brute Force with Optimization
Since `N` is small (up to 1500), an `O(N^2)` solution is feasible. We can iterate over all possible subarrays and check the condition.

To check the condition efficiently:
1. Iterate through all possible starting positions `i` from `0` to `n-1`.
2. For each `i`, iterate through all ending positions `j` from `i` to `n-1`.
3. Maintain the count of distinct even and odd numbers found so far in the current subarray `nums[i...j]`.
4. To track "distinctness" efficiently without clearing a large data structure every time:
   - Use a `visited` array of size 100005 (max value constraint).
   - `visited[val] = k` means the value `val` was last seen in the subarray starting at index `k`.
   - When considering subarrays starting at `i`, if `visited[nums[j]] != i`, it means `nums[j]` is a new distinct element for this specific starting position `i`. We increment the respective counter and update `visited[nums[j]] = i`.

## Steps
1. Initialize `max_len = 0`.
2. Initialize `visited` array with -1.
3. Loop `i` from 0 to `n-1`:
    - `odd_count = 0`, `even_count = 0`
    - Loop `j` from `i` to `n-1`:
        - `val = nums[j]`
        - If `visited[val] != i`:
            - If `val` is odd: `odd_count++`
            - Else: `even_count++`
            - `visited[val] = i`
        - If `odd_count == even_count`:
            - `max_len = max(max_len, j - i + 1)`
4. Return `max_len`.

## Complexity
- **Time Complexity:** `O(N^2)` - We visit each pair `(i, j)` once. Inside the loop, operations are `O(1)`.
- **Space Complexity:** `O(K)` where `K` is the maximum value in `nums` (100,000), for the `visited` array. This is constant space relative to N.
