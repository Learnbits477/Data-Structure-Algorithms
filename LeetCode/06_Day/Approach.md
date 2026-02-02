# Approach: Sliding Window with Two Sets

## Intuition

The problem asks for the minimum cost to divide the array into `k` subarrays.
The cost is the sum of the first elements of these subarrays.
Let the starting indices of the subarrays be $i_0, i_1, \dots, i_{k-1}$.
By definition, $i_0 = 0$ always (the first subarray starts at index 0).
So the total cost is $nums[i_0] + nums[i_1] + \dots + nums[i_{k-1}]$.
We know $nums[i_0] = nums[0]$ is fixed.
We need to select $k-1$ indices $i_1, i_2, \dots, i_{k-1}$ from the range $[1, n-1]$ such that the constraint $i_{k-1} - i_1 \le dist$ is satisfied.

This means all the chosen indices $i_1, \dots, i_{k-1}$ must fit within a window of size at most `dist + 1`. Specifically, if we pick the smallest chosen index $i_1$ and the largest chosen index $i_{k-1}$, their difference must be at most `dist`.
Actually, the indices $i_1, \dots, i_{k-1}$ are just $k-1$ distinct indices chosen from some range $[L, R]$ where $R - L \le dist$.
More precisely, since $i_1$ is the first chosen index and $i_{k-1}$ is the last, all $k-1$ indices must lie in the range $[i_1, i_{k-1}]$ which has length $i_{k-1} - i_1 + 1 \le dist + 1$.

So the problem reduces to:
Finding a subarray (window) of valid indices in `nums` (starting from index 1) with length at most `dist + 1`, such that the sum of the `k-1` smallest elements in that window is minimized.
Then add `nums[0]` to this minimum sum.

## Algorithm

1. **Fixed Cost**: The first element `nums[0]` is always part of the cost.
2. **Sliding Window**: We iterate through the array `nums` starting from index 1. We maintain a window representing a potential range of indices for our `k-1` subarrays.
    The window will effectively be of size `dist + 1`. Let's say the window is `[i - dist, i]`.
    However, strictly speaking, we just need to find `k-1` elements within a range of size `dist + 1`.
    We can iterate `i` from `1` to `n - 1`. `i` represents the current rightmost candidate for our set of indices.
    We maintain a collection of elements in the range `[max(1, i - dist), i]`.
3. **Data Structures**:
    We need to efficiently:
    - Add an element to our window.
    - Remove an element from our window.
    - Calculate the sum of the `k-1` smallest elements in the current window.

    We can use two `multiset`s (or `priority_queue`s with lazy deletion, but sets are easier to manage for deletions):
    - `lowers`: Contains the `k-1` smallest elements in the current window.
    - `uppers`: Contains the remaining elements in the current window.
    - `sum_lowers`: Tracks the sum of elements in `lowers`.

4. **Window Management**:
    - **Add `nums[i]`**:
      - If `lowers` is not full (size < `k-1`), add to `lowers`, update `sum_lowers`.
      - Else if `nums[i]` is smaller than the largest in `lowers`:
        - Move largest of `lowers` to `uppers`.
        - Add `nums[i]` to `lowers`.
        - Update `sum_lowers`.
      - Else:
        - Add `nums[i]` to `uppers`.
    - **Remove `nums[i - dist - 1]`** (when `i > dist + 1`):
      - The element to remove is `out_val = nums[i - dist - 1]`.
      - If `out_val` is in `uppers`, just remove it.
      - If `out_val` is in `lowers`:
        - Remove from `lowers`, update `sum_lowers`.
        - If `uppers` is not empty, move the smallest from `uppers` to `lowers` to refill it.

5. **Result Update**:
    - Whenever the window size is sufficiently large (i.e., we have processed at least `k-1` elements), update the global minimum cost: `ans = min(ans, nums[0] + sum_lowers)`.
    - Note that the problem asks for `k` subarrays, so we need `k-1` split points (indices). The window size constraint applies to the range of these split points. The indices are valid if they are within `dist` of each other.
      Specifically, we simply slide a window of length `dist + 1` starting from index 1.
      For each right endpoint `i` from `1` to `n-1`:
    - Add `nums[i]`.
    - If window length exceeds `dist + 1` (i.e., size > `dist + 1`), remove `nums[i - (dist + 1)]`.
    - If current elements count >= `k-1`, update answer.

## Complexity

- **Time Complexity**: $O(n \log k)$. Each insertion and deletion in the multisets takes logarithmic time. Since we do this for each element, the total time is linear-logarithmic.
- **Space Complexity**: $O(n)$. We store elements in the sets. In the worst case (large `dist`), we store $O(n)$ elements.

## Corner Cases

- `k` and `dist` values relative to `n`.
- Array elements can be large (use `long long` for sum).
