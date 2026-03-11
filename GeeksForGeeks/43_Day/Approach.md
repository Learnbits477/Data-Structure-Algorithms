# Approach for Sum of Subarray Minimums

## Intuition

A naive solution would generate all subarrays, find the minimum in each, and sum them up. This takes $O(N^2)$ time, which is too slow (Constraints: $N \le 3 \cdot 10^4$).

Instead of finding the minimum for each subarray, we can reverse the perspective: for each element `arr[i]`, in how many subarrays is `arr[i]` the minimum element?
If we know that `arr[i]` is the minimum element in `K` subarrays, it contributes `arr[i] \times K` to the total sum.

## Monotonic Stack

To find the number of subarrays where `arr[i]` is the minimum, we determine its validating boundaries:

1. **Left Boundary**: The nearest element to the left that is strictly smaller than `arr[i]`. Let's say its index is `L`. Then there are `i - L` choices for the start of the subarray. (If no such element exists, consider `L = -1`).
2. **Right Boundary**: The nearest element to the right that is smaller than or equal to `arr[i]`. Let's say its index is `R`. Then there are `R - i` choices for the end of the subarray. (If no such element exists, consider `R = N`).

_Note:_ To avoid double counting valid subarrays when duplicating elements exist, we look for a strictly smaller element on one side, and a smaller _or equal_ element on the other side.

The number of subarrays where `arr[i]` acts as the minimum is exactly `(i - L) * (R - i)`.
Thus, the total sum is given by $\sum (arr[i] \times (i - L) \times (R - i))$.
We can compute the left and right boundaries for all elements in linear time $O(N)$ using a Monotonic Stack.

## Complexity

- **Time Complexity:** $O(N)$, where $N$ is the number of elements in the array. Every element is pushed and popped from the stack at most once.
- **Space Complexity:** $O(N)$, for storing the `left`/`right` boundary arrays and the stack data structures.
