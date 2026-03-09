# DP Approach for Find All Possible Stable Binary Arrays I

## Intuition

The problem asks us to find the number of "stable" binary arrays with exactly `zero` 0s and `one` 1s, such that no continuous block of 0s or 1s has a length strictly greater than `limit`. Because the constraints are small (`zero, one, limit <= 200`), a 3D Dynamic Programming approach is appropriate.

## State Definition

Let `dp[i][j][k]` be the number of stable valid arrays composed of `i` zeros and `j` ones, ending with the digit `k` (where `k \in \{0, 1\}`).

## Transitions

To form an array of `i` zeros and `j` ones ending in `0`, we can append a `0` to any valid array of length `i + j - 1`. The previous element can either be `0` or `1`.

- `dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1]`

However, this overcounts arrays that end with `limit + 1` zeros. The number of such invalid arrays is precisely the number of valid arrays ending in `1` that have `i - 1 - limit` zeros and `j` ones, because we can just append `limit + 1` zeros to them.
Thus, we must subtract `dp[i - 1 - limit][j][1]`.

Similarly:

- `dp[i][j][1] = dp[i][j-1][0] + dp[i][j-1][1] - dp[i][j - 1 - limit][0]`
  (adding modulo arithmetic to handle negative numbers).

## Constraints and Base Cases

- For `i == 0`, if `j <= limit`, `dp[0][j][1] = 1`, otherwise `0`.
- For `j == 0`, if `i <= limit`, `dp[i][0][0] = 1`, otherwise `0`.

## Complexity

- **Time Complexity:** $O(\text{zero} \times \text{one})$ since loop operations are $O(1)$ by using the optimized recurrence relation.
- **Space Complexity:** $O(\text{zero} \times \text{one})$ matrix to store results.
