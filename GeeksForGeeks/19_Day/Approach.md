# Approach

## Intuition

We want to minimize the difference between the packet with the most chocolates and the packet with the fewest chocolates among the `m` packets we select.
If we sort the array of packets, the packets with close values will be adjacent. To pick `m` packets with the minimum range (difference roughly equal to length of the segment on a number line), we should pick a contiguous subarray of size `m` from the sorted array.

## Algorithm

1. **Sort** the array `arr` in ascending order.
2. Initialize `min_diff` to infinity.
3. Iterate through the sorted array using a sliding window of size `m`.
    - The window starts at index `i` and ends at index `i + m - 1`.
    - The current difference for this window is `arr[i + m - 1] - arr[i]`.
    - Update `min_diff` if the current difference is smaller than `min_diff`.
4. Continue this until the end of the window reaches the end of the array.
5. Return `min_diff`.

## Complexity

- **Time Complexity:** O(N log N) due to sorting.
- **Space Complexity:** O(1) if we ignore space for sorting, or O(log N) depending on sorting logic.
