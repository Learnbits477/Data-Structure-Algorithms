# Approach: Ternary Search

## Intuition

The problem asks to find a target height `H` such that $\sum \text{cost}[i] \times |H - \text{heights}[i]|$ is minimized.
This function $f(H)$ is a **convex function**.

- It is a sum of absolute value functions, which are convex.
- The cost coefficients are positive.

Since the function is convex, we can use **Ternary Search** to find the minimum value.

## Algorithm

1. Initialize `low = min(heights)` and `high = max(heights)`.
2. While `high - low > 2`:
    - `m1 = low + (high - low) / 3`
    - `m2 = high - (high - low) / 3`
    - Calculate `cost1 = calculateCost(m1)` and `cost2 = calculateCost(m2)`.
    - If `cost1 < cost2`, `high = m2`.
    - Else, `low = m1`.
3. The minimum cost will be `min(calculateCost(low), calculateCost(low+1), ..., calculateCost(high))`.
    - Usually just need to check a small range around `low` after loop terminates.

## Complexity

- **Time**: $O(N \log (\max(H) - \min(H)))$. Since max height is $10^4$, this is very efficient.
- **Space**: $O(1)$.
