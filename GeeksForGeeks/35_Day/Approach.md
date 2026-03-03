# Approach: Sliding Window

To find the length of the longest subarray with at most two distinct integers, we can use the **Sliding Window** (Two Pointers) technique.

### Intuition:

We need a contiguous subarray (window) and we need to keep track of the frequency of elements within this window.
As we iterate through the array, we expand our window to the right by including `arr[right]`.
If the number of distinct elements in our window exceeds 2, it is no longer valid. Thus, we need to shrink the window from the left by moving the `left` pointer and decreasing the frequency of `arr[left]` until the number of distinct elements becomes at most 2 again.

### Algorithm:

1. Initialize two pointers, `left` and `right`, both at `0`.
2. Initialize `max_len` to keep track of the maximum length found so far.
3. Use a frequency array (or an unordered_map) to keep track of the count of elements in the current window. We can use a frequency vector of size `100005` since the problem constraints guarantee that `arr[i] <= 10^5`.
4. Keep a `distinct_count` variable to track how many unique elements are currently in the window.
5. Iterate `right` from `0` to `n-1`:
   - Increase the frequency of `arr[right]`. If its frequency becomes `1`, it means we saw a new distinct element, so increment `distinct_count`.
   - While `distinct_count > 2`:
     - Decrease the frequency of `arr[left]`.
     - If its frequency becomes `0`, decrement `distinct_count`.
     - Increment `left` to shrink the window.
   - Now the window `[left, right]` is valid. Update `max_len = max(max_len, right - left + 1)`.
6. Return `max_len`.

### Complexity Analysis:

- **Time Complexity:** `O(N)`, where `N` is the number of elements in the array. Both `left` and `right` pointers traverse the array at most once.
- **Space Complexity:** `O(K)` where `K` is the maximum value in `arr` (up to `10^5`), to store the frequency array. This can also be done using an `unordered_map` taking `O(1)` space because the map will securely store at most 3 distinct elements at any point. Using a static array or vector is slightly faster due to lower overhead.
