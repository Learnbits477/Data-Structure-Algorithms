# [Approach - Partitions with Given Difference](https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1)

## Mathematical Reduction

We need to partition the array `arr` into two subsets $S_1$ and $S_2$ such that:

1. $S_1 - S_2 = \text{diff}$
2. $S_1 + S_2 = \text{totalSum}$

Adding the two equations:
$2S_1 = \text{totalSum} + \text{diff}$
$S_1 = \frac{\text{totalSum} + \text{diff}}{2}$

The problem reduces to: **Count the number of subsets with sum equal to $S_1$**.

### Constraints & Edge Cases

- If $(\text{totalSum} + \text{diff})$ is odd, no integer solution for $S_1$ exists. Return `0`.
- If $\text{totalSum} < \text{diff}$, it's impossible. Return `0`.
- The array can contain zeros ($0 \le \text{arr[i]} \le 6$). This is crucial for DP because adding a zero to a subset doesn't change its sum but creates a new distinct subset.

## Dynamic Programming Strategy

### 1. State Definition

Let `dp[i][j]` be the number of ways to form a sum `j` using the first `i` elements of the array.

### 2. Transition

- If we don't include the current element `arr[i-1]`: `dp[i][j] = dp[i-1][j]`
- If we include the current element `arr[i-1]` (if `arr[i-1] <= j`): `dp[i][j] += dp[i-1][j - arr[i-1]]`

### 3. Space Optimization

Since `dp[i]` only depends on `dp[i-1]`, we can use a 1D array `dp[j]`. To avoid using the same element twice in the same sum, we iterate backwards from `target` down to `arr[i]`.

### 4. Handling Zeros

By initializing `dp[0] = 1` and iterating through all elements (including zeros), the DP naturally handles zeros. A zero will update `dp[j]` as `dp[j] = dp[j] + dp[j-0]`, effectively doubling the count for all achievable sums.

## Complexity

- **Time Complexity:** $O(N \times \text{target})$, where $N$ is the size of the array and $\text{target} = \frac{\text{totalSum} + \text{diff}}{2}$.
- **Space Complexity:** $O(\text{target})$ using a 1D DP array.
