# Approach: Greedy Selection

## Intuition

The problem asks us to divide the array `nums` into 3 contiguous subarrays. The cost of a subarray is defined as its first element.
We want to minimize the sum of the costs of these 3 subarrays.

Let the three subarrays be $S_1, S_2, S_3$.
Since the subarrays must cover the entire original array and be contiguous:

1. $S_1$ must start at index `0`. Thus, the cost of $S_1$ is always `nums[0]`.
2. $S_2$ must start at some index `i` (where $i > 0$).
3. $S_3$ must start at some index `j` (where $j > i$).

The total cost is `nums[0] + nums[i] + nums[j]`.
To minimize this sum, since `nums[0]` is fixed, we simply need to find the two smallest elements in the remaining part of the array `nums[1...n-1]`.

## Algorithm

1. Initialize `cost` with `nums[0]`.
2. Consider the subarray `nums[1...n-1]`.
3. Find the two smallest elements in this subarray.
   - We can do this by sorting `nums[1...n-1]` and taking the first two elements.
   - Or, we can iterate through `nums[1...n-1]` maintaining the two minimums seen so far.
4. Add these two smallest values to `cost`.
5. Return the total `cost`.

## Complexity Analysis

- **Time Complexity:** $O(N \log N)$ if we sort, or $O(N)$ if we scan linearly. Given $N \le 50$, both are extremely fast. We will implement the sorting approach for simplicity and readability, or the linear scan for efficiency. Let's use sorting as $N$ is very small.
- **Space Complexity:** $O(1)$ (ignoring space for sorting copy) or $O(N)$ if we create a copy.

## Example Walkthrough

**Input:** `nums = [1, 2, 3, 12]`

1. Fixed cost: `nums[0] = 1`.
2. Remaining elements: `[2, 3, 12]`.
3. Two smallest in remaining: `2` and `3`.
4. Total cost: `1 + 2 + 3 = 6`.
