# Approach for The Painter's Partition Problem-II

## Problem Understanding

We need to assign contiguous boards to `k` painters such that the maximum time taken by any painter is minimized. This is a classic "Minimize the Maximum" problem, which can be solved using Binary Search on the Answer.

## Binary Search on Answer

The answer (minimum time) must lie within a specific range:

- **Lower Bound (`low`):** The maximum length of a single board. Even if we have infinite painters, the board with the largest length must be painted by a single painter.
- **Upper Bound (`high`):** The sum of all board lengths. This corresponds to the case where we have only 1 painter.

## Algorithm

1. Initialize `low = max(arr)` and `high = sum(arr)`.
2. While `low <= high`:
   - Calculate `mid = low + (high - low) / 2`.
   - Check if it is possible to paint all boards within `mid` time using at most `k` painters.
   - If **possible**:
     - `mid` is a potential answer.
     - Try to find a smaller time: `ans = mid`, `high = mid - 1`.
   - If **not possible**:
     - We need more time: `low = mid + 1`.

## Feasibility Check (`isPossible`)

To check if a time `limit` is feasible:

1. Initialize `painters = 1` and `currentsum = 0`.
2. Iterate through the boards:
   - If `currentsum + board_length <= limit`, add board to current painter.
   - Else, assign board to a new painter (`painters++`) and reset `currentsum = board_length`.
   - If `painters > k`, return `false`.
3. Return `true`.

## Complexity

- **Time Complexity:** `O(N * log(sum(arr) - max(arr)))`.
  - The binary search runs for `log(sum - max)` iterations.
  - The feasibility check takes `O(N)` time.
  - Given constraints `N <= 10^5`, `sum` approx `10^9`, `log` is small (~30). Steps ~ 3 \* 10^6.
- **Space Complexity:** `O(1)`.
