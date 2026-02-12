# Walkthrough: Max min Height

## Problem Understanding

We want to maximize the minimum height of flowers after `k` days of watering. Each day we can increase a window of size `w` by 1 unit height.
This is an optimization problem that can be solved by checking if a target minimum height is feasible.

## Approach

- **Binary Search**: Search range `[min(arr), max(arr) + k]`.
- **Feasibility Check**: Greedy approach. Iterate from left to right. If a flower is below target `H`, apply just enough watering operations starting at this flower to reach `H`. This extends the benefit to the right as much as possible (greedy).
- **Difference Array**: Use a difference array logic to track the cumulative effect of watering operations in $O(1)$.

## Code Structure

- **Solution.cpp**: Contains the `maximizeMinHeight` function and `isPossible` helper.
- **Problem.md**: Problem description.
- **Approach.md**: Detailed explanation of the algorithm.

## Verification

The `main` function runs the provided test cases.

- Case 1: `[2, 3, 4, 5, 1]`, k=2, w=2 -> Expected: 2.
- Case 2: `[5, 8]`, k=5, w=1 -> Expected: 9.

## Execution Results

```
Test 1: 2 Expected: 2
Test 2: 9 Expected: 9
```

The solution handles the examples correctly. The function name `maximizeMinHeight` was corrected to `maxMinHeight` to match the driver code.
