# Approach: Binary Search on Answer + Difference Array

## Intuition

The problem asks us to **maximize the minimum height**. This is a classic indicator for **Binary Search on Answer**. If we can achieve a minimum height of `X`, we can definitely achieve any minimum height less than `X`. This monotonicity allows us to binary search for the maximum possible minimum height.

## Algorithm

1. **Binary Search Range**:
    * Low (`l`) = Minimum element in `arr` (simplest valid answer).
    * High (`r`) = Maximum element in `arr` + `k` (theoretical max if we dump all `k` on the max element, though usually just `max(arr) + k` is safe).

2. **Check Function (`check(val, k, w, arr)`)**:
    * Checks if it is possible to make all flowers have at least height `val` using at most `k` days.
    * Iterate through the array. For each flower `i`, calculate its current height including past watering effects.
    * We use a **Difference Array** (or a running sum variable `water_supply` plus a queue/array for decrements) to manage range updates efficiently in $O(1)$.
    * Current height = `arr[i] + water_supply`.
    * If `current_height < val`:
        * We need `needed = val - current_height` more units.
        * If `needed > k` (remaining days), return `false`.
        * We add `needed` to our watering effect. This effect lasts from `i` to `i + w - 1`.
        * Decrement `k` by `needed`.
        * Update `water_supply += needed`.
        * Record that at index `i + w`, we must subtract `needed` from `water_supply`. A simple array `diff` or a queue can store these future subtractions.
    * At each step, update `water_supply` by applying expiring effects.

3. **Optimization**:
    * Using a difference array (or separate `effect` array) allows the check function to run in $O(N)$.
    * Total Time Complexity: $O(N \log(\text{Range}))$.

## Complexity

* **Time Complexity:** $O(N \log(10^9 + 10^5))$, effectively $O(N \log (\text{max\_height}))$.
* **Space Complexity:** $O(N)$ for the difference/effect array used in the check function.
