# Approach: Painting the Fence

## Problem Analysis

The task is to find the number of ways to paint a fence with `n` posts and `k` colors such that no more than two consecutive posts have the same color.

## Dynamic Programming State

Let `total[i]` be the number of ways to paint `i` posts.
At each post `i`, we have two possibilities:
1.  **Same color as post `i-1`**: This is only allowed if post `i-1` had a different color than post `i-2`.
2.  **Different color from post `i-1`**: We can choose any of the `k-1` remaining colors.

## State Transitions

We can derive the recurrence relation as follows:
- **`same[i]`**: Number of ways where post `i` and post `i-1` have the same color.
  - This is equal to the number of ways post `i-1` was different from post `i-2`.
  - `same[i] = diff[i-1]`
- **`diff[i]`**: Number of ways where post `i` and post `i-1` have different colors.
  - We can append a different color to any valid painting of `i-1` posts.
  - `diff[i] = (same[i-1] + diff[i-1]) * (k-1) = total[i-1] * (k-1)`

Total ways `total[i] = same[i] + diff[i]`
`total[i] = diff[i-1] + total[i-1] * (k-1)`
Since `diff[i-1] = total[i-2] * (k-1)`, we have:
`total[i] = total[i-2] * (k-1) + total[i-1] * (k-1)`
`total[i] = (total[i-1] + total[i-2]) * (k-1)`

## Initial Values

- `n = 1`: `k` ways.
- `n = 2`: `k * k` ways (can be same or different).
  - Same: `k` ways.
  - Different: `k * (k-1)` ways.
  - Total: `k + k^2 - k = k^2`.

## Space Optimization

The recurrence only depends on the previous two states (`total[i-1]` and `total[i-2]`), so we can optimize the space complexity from `O(n)` to `O(1)` by using only two variables.

## Complexity Analysis

- **Time Complexity**: **O(n)** - We iterate from 3 to `n` once.
- **Space Complexity**: **O(1)** - We only use a few variables for DP.

---

### Code Illustration

```cpp
long long total_i_minus_2 = k;
long long total_i_minus_1 = k * k;

for (int i = 3; i <= n; i++) {
    long long current = (total_i_minus_1 + total_i_minus_2) * (k - 1);
    total_i_minus_2 = total_i_minus_1;
    total_i_minus_1 = current;
}
return total_i_minus_1;
```

---

[Problem Link](https://www.geeksforgeeks.org/problems/painting-the-fence3727/1)
