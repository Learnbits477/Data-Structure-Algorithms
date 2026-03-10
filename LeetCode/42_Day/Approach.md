# Approach for Stable Binary Arrays II

## Intuition

The problem asks us to find the number of ways to arrange `zero` 0s and `one` 1s such that no continuous block of 0s or 1s exceeds the length `limit`. This sequence building process can be modeled naturally using Dynamic Programming (DP).

## Dynamic Programming State

Let `dp[i][j][0]` be the number of valid stable arrays with `i` zeros and `j` ones that end with `0`.
Let `dp[i][j][1]` be the number of valid stable arrays with `i` zeros and `j` ones that end with `1`.

## Transitions

To form an array ending in `0` with `i` zeros and `j` ones, we can normally append a `0` to any valid array of length `i+j-1` that had `i-1` zeros and `j` ones (which could have ended in `0` or `1`). Thus, the base transition is:
`dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1]`

However, this includes invalid arrays which now end with a continuous block of `limit + 1` zeros. We must subtract these invalid cases. A sequence ends with exactly `limit + 1` zeros if it previously ended with a `1` followed by exactly `limit` zeros. So the number of such invalid arrays is exactly the number of ways to build a valid array with `i - 1 - limit` zeros and `j` ones ending in `1`.
Correction transition:
`if (i > limit) dp[i][j][0] -= dp[i - 1 - limit][j][1]`

Similarly, for sequences ending in `1`:
`dp[i][j][1] = dp[i][j-1][0] + dp[i][j-1][1]`
`if (j > limit) dp[i][j][1] -= dp[i][j - 1 - limit][0]`

## Complexity

- **Time Complexity:** $\mathcal{O}(\text{zero} \times \text{one})$. We compute two basic states for each pair of `(i, j)`. To highly optimize this in practice, modulo `%` operations are replaced with fast manual additions and subtractions.
- **Space Complexity:** $\mathcal{O}(\text{zero} \times \text{one})$. We store two flat 2D arrays (`dp0` and `dp1`) of size `(zero + 1) x (one + 1)`. This avoids the massive memory overhead, pointer chasing, and cache misses of a 3D `vector<vector<vector<int>>>`.
