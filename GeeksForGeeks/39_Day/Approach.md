# Approach: Dynamic Programming Space Optimized

This problem can be efficiently solved using Dynamic Programming.

## Intuition

The problem asks for the number of ways to achieve a sum `x` using `n` dice, where each die has `m` faces (numbered 1 to `m`).
For a single die, the possible outcomes are from 1 to `m`.
If we already know the number of ways to form any sum with `i-1` dice, we can compute the number of ways to form a sum with `i` dice by adding the ways to form `sum - k` with `i-1` dice, where `k` represents the outcome of the current `i`-th die (from 1 to `m`).

## DP State Definition

Let `dp[i][j]` be the number of ways to get a sum `j` using `i` dice.
Base Case: `dp[0][0] = 1`, because there is exactly 1 way to get a sum of 0 using 0 dice.

## Transition

For `i` from 1 to `n` (representing the current number of dice):
For `j` from 1 to `x` (representing the current target sum):
For `k` from 1 to `m` (representing the face value of the current die):
If `j - k >= 0`:
`dp[i][j] += dp[i-1][j - k]`

## Space Optimization

Notice that `dp[i][j]` only depends on the values of `dp[i-1][...]` from the previous row. Instead of maintaining a 2D array of size `(n + 1) x (x + 1)`, we can use two 1D arrays: `prev` and `curr`, each of size `x + 1`. `prev` will store the ways for `i-1` dice, and `curr` will compute the ways for `i` dice. After processing each die, `prev` is updated to `curr`.

## Complexity Insights

- **Time Complexity:** $O(n \times x \times m)$. There are three nested loops for $n$, $x$, and $m$. Given the constraints ($1 \le m, n, x \le 50$), this will take at most $50 \times 50 \times 50 = 125,000$ operations, which executes well within the time limit.
- **Space Complexity:** $O(x)$. We are only storing two 1D arrays of size `x + 1`. This is highly optimal.
