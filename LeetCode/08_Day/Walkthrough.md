# Walkthrough: Trionic Array II

## Example 1 Trace

Input: `nums = [0, -2, -1, -3, 0, 2, -1]`

Initialization:
`dp0 = 0`, `dp1 = -inf`, `dp2 = -inf`, `dp3 = -inf`
`max_sum = -inf`

**Iteration i=1** (`curr = -2`, `prev = 0`): `curr < prev` (Decreasing)

- `dp0 = -2` (Start fresh inc)
- `dp1 = -inf`
- `dp2 = max(-inf, -inf) + -2 = -inf` (Valid only if we came from dp1 or dp2, but both were -inf)
- `dp3 = -inf`

**Iteration i=2** (`curr = -1`, `prev = -2`): `curr > prev` (Increasing)

- `dp0 = -2 + -1 = -3`
- `dp1 = max(-inf, dp0_prev=-2) + -1 = -3` (Valid phase 1 end)
- `dp2 = -inf`
- `dp3 = max(-inf, -inf) + -1 = -inf`

**Iteration i=3** (`curr = -3`, `prev = -1`): `curr < prev` (Decreasing)

- `dp0 = -3`
- `dp1 = -inf`
- `dp2 = max(-inf, dp1_prev=-3) + -3 = -6` (Transition from dp1. Phase 1 ended at -1, now decreasing)
  - Sequence so far: `-2, -1, -3`. Phase 1: `[-2, -1]`. Phase 2 start: `[-1, -3]`?
  - Actually DP state `dp1` ending at `i-1` meant `[-2, -1]` (sum -3).
  - Now `dp2` adds `-3`. Sum `-6`. Corresponds to `[-2, -1, -3]`.
- `dp3 = -inf`

**Iteration i=4** (`curr = 0`, `prev = -3`): `curr > prev` (Increasing)

- `dp0 = -3 + 0 = -3`
- `dp1 = max(-inf, dp0_prev=-3) + 0 = -3`
- `dp2 = -inf`
- `dp3 = max(-inf, dp2_prev=-6) + 0 = -6` (Transition from dp2. Phase 2 ended at -3, now increasing)
  - Sequence: `[-2, -1, -3, 0]`.
  - Phase 1: `[-2, -1]`. Phase 2: `[-1, -3]`. Phase 3 start: `[-3, 0]`.
  - Sum: `-2 + -1 + -3 + 0 = -6`.

**Iteration i=5** (`curr = 2`, `prev = 0`): `curr > prev` (Increasing)

- `dp0 = -3 + 2 = -1`
- `dp1 = max(-3, -3) + 2 = -1`
- `dp2 = -inf`
- `dp3 = max(-6, -6) + 2 = -4` (Extend phase 3)
  - Sequence: `[-2, -1, -3, 0, 2]`.
  - Sum: `-4`.
  - Max sum updated to `-4`.

**Iteration i=6** (`curr = -1`, `prev = 2`): `curr < prev` (Decreasing)
... transitions ...

Final Answer: `-4`.

## Explanation of Logic

The DP state effectively "carries" the maximum sum of a prefix that satisfies the partial structural constraints.

- `dp1` captures the "Inc" part.
- `dp2` captures "Inc -> Dec".
- `dp3` captures "Inc -> Dec -> Inc".

By maximizing at each step, we ensure we find the optimal subarray.
Because we restart `dp0` whenever we can't extend strictly increasing, and `dp1`/`dp2`/`dp3` depend on valid predecessors, we implicitly handle all start positions.

## Verification Results (User's Iterative Solution)

Ran the solution against the example cases:

1. Input: `[0,-2,-1,-3,0,2,-1]` -> Output: `-4` (Matches Example 1)
2. Input: `[1,4,2,7]` -> Output: `14` (Matches Example 2)

Solution verified successfully.
