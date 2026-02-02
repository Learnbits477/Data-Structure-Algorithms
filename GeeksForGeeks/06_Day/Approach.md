# approach for Max Circular Subarray Sum

## Intuition
The problem asks for the maximum subarray sum in a circular array. A circular subarray can be:
1.  **Non-wrapping**: A standard contiguous subarray (e.g., `[1, 2, 3]` in `[1, 2, 3, -1]`).
2.  **Wrapping**: A subarray that wraps around the end to the beginning (e.g., `[3, -1, 1]` but omitting the middle part).

## Algorithm

We can use **Kadane's Algorithm**, which finds the maximum sum of a contiguous subarray in $O(n)$ time.

1.  **Case 1: Max sum is non-circular**
    - Simply run Kadane's algorithm to find the maximum subarray sum (`max_normal`).

2.  **Case 2: Max sum is circular**
    - A circular subarray essentially excludes a contiguous subarray from the middle of the original array.
    - To maximize the circular sum, we want to minimize the sum of the non-circular part we exclude.
    - `Max Circular Sum` = `Total Array Sum` - `Min Subarray Sum`.
    - We can find `Min Subarray Sum` by running Kadane's algorithm on the inverted array (multiplying all elements by -1) or by modifying the logic to find minimums.
    - Alternatively, standard Minimum Subarray Sum logic: `current_min = min(num, current_min + num)`, `total_min = min(total_min, current_min)`.

3.  **Handling Corner Case**
    - If all numbers are negative, `max_normal` will be the maximum single element (e.g., -1).
    - In this case, `Total Sum` will be equal to `Min Subarray Sum` (sum of all elements). Thus, `Total Sum - Min Subarray Sum` would be 0, which implies an empty subarray is excluded, but we need a non-empty subarray.
    - So, if `max_normal < 0`, the answer is just `max_normal`.

4.  **Final Result**
    - `max(max_normal, total_sum - min_subarray_sum)` (if `max_normal >= 0`).

## Steps
1.  Calculate `total_sum`.
2.  Calculate `max_so_far` using Kadane's (to get `max_normal`).
3.  Calculate `min_so_far` using modified Kadane's (to get `min_subarray_sum`).
4.  If `max_so_far < 0`, return `max_so_far`.
5.  Otherwise, return `max(max_so_far, total_sum - min_so_far)`.

## Complexity
-   **Time Complexity**: $O(n)$, single pass.
-   **Space Complexity**: $O(1)$.
