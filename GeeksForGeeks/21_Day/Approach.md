# Approach

The problem asks for the maximum number of intervals overlapping at any point in time. This is a classic problem that can be solved using the "Sweep Line" algorithm or by sorting start and end times.

## Sorting Approach

1.  **Separate and Sort:** Extract all start times into one array and all end times into another array. Sort both arrays in ascending order.
2.  **Traverse:** Use two pointers, `i` for the start times array and `j` for the end times array. Initialize `count = 0` (current overlapping intervals) and `max_overlap = 0`.
3.  **Logic:**
    - If `start[i] <= end[j]`, it means a new interval has started before the earliest ending interval has finished. This increases the overlap count. Increment `count` and `i`. Update `max_overlap`.
    - If `start[i] > end[j]`, it means an interval has finished. This decreases the overlap count. Decrement `count` and increment `j`.
4.  **Repeat** this until we process all start times.

## Complexity

- **Time Complexity:** O(N log N) because we sort the start and end time arrays. The traversal takes O(N).
- **Space Complexity:** O(N) to store the start and end times.
