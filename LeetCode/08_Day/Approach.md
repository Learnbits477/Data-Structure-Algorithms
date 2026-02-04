# Approach: Dynamic Programming

## Problem Analysis

The problem asks for the maximum sum of a "trionic" subarray, which consists of three phases:

1. Strictly Increasing (`l` to `p`)
2. Strictly Decreasing (`p` to `q`)
3. Strictly Increasing (`q` to `r`)

Constraints: `l < p < q < r`.
This means each phase must have at least one transition, or at least two elements involved in the transition boundaries.
Specifically:

- `nums[l...p]` has length at least 2.
- `nums[p...q]` has length at least 2.
- `nums[q...r]` has length at least 2.

## DP State Definitions

We can maintain 4 states for each index `i` representing the maximum sum of a subarray ending at `i` in a specific phase:

1. `dp0[i]`: Max sum ending at `i` in the **first increasing** phase (pure increasing sequence).
    - Condition: `nums[i] > nums[i-1]`.
    - Length >= 1.
2. `dp1[i]`: Max sum ending at `i` in the **first increasing** phase, but eligible to transition to decreasing (Length >= 2).
    - Condition: `nums[i] > nums[i-1]`.
    - Transition: From `dp0[i-1]` or `dp1[i-1]`.
3. `dp2[i]`: Max sum ending at `i` in the **decreasing** phase.
    - Condition: `nums[i] < nums[i-1]`.
    - Transition: From `dp1[i-1]` (start decreasing) or `dp2[i-1]` (continue decreasing).
4. `dp3[i]`: Max sum ending at `i` in the **second increasing** phase.
    - Condition: `nums[i] > nums[i-1]`.
    - Transition: From `dp2[i-1]` (start second increasing) or `dp3[i-1]` (continue second increasing).

## Transitions

Iterate `i` from 1 to `n-1`. Let `curr = nums[i]`, `prev = nums[i-1]`.

- **If `curr > prev`:**
  - `dp0[i] = dp0[i-1] + curr` (Extend increasing)
  - `dp1[i] = max(dp0[i-1], dp1[i-1]) + curr` (Extend valid increasing)
  - `dp2[i] = -INF` (Cannot end decreasing if current > prev)
  - `dp3[i] = max(dp2[i-1], dp3[i-1]) + curr` (Start or extend second increasing)

- **If `curr < prev`:**
  - `dp0[i] = curr` (Start new increasing sequence - strictly speaking, a single element can be start of increasing)
  - `dp1[i] = -INF` (Cannot be increasing if current < prev)
  - `dp2[i] = max(dp1[i-1], dp2[i-1]) + curr` (Start decreasing from peak or extend)
  - `dp3[i] = -INF` (Cannot be increasing if current < prev)

- **If `curr == prev`:**
  - STRICTLY increasing/decreasing means equal elements break the sequence.
  - Start fresh for `dp0`? No, `dp0` is start of *strictly* increasing. Single element is always strictly increasing (vacuously).
  - `dp0[i] = curr`.
  - All others `-INF`.

## Base Case

Initialize all with `-INF` (or a very small number).
`dp0[0] = nums[0]`.

## Final Answer

The answer is the maximum value found in `dp3` across all `i`.

## Complexity

- Time Complexity: O(N) - Single pass.
- Space Complexity: O(N) or O(1) - We only need previous states.
