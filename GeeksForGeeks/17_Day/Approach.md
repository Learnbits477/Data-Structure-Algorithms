# Approach: All numbers with specific difference

The function $f(k) = k - \text{sum\_digits}(k)$ is a non-decreasing function.
Proof idea: When $k$ increases by 1, $k$ increases by 1. The sum of digits might increase (e.g., 12 -> 13, sum 3 -> 4) or decrease (e.g., 19 -> 20, sum 10 -> 2).
However, for large ranges, the property holds generally that larger numbers have larger "number minus sum of digits" values.
Wait, let's strictly check if it's monotonic.

- 19: 19 - 10 = 9
- 20: 20 - 2 = 18
- 21: 21 - 3 = 18
- 29: 29 - 11 = 18
- 30: 30 - 3 = 27
  It IS non-decreasing.

Therefore, we can use **Binary Search** to find the smallest number `min_k` in range `[1, n]` such that `min_k - sum_digits(min_k) >= d`.

If such a `min_k` exists, then all numbers in `[min_k, n]` satisfy the condition.
Count = `n - min_k + 1`.

## Algorithm

1. Initialize `low = 1`, `high = n`, `ans = -1`.
2. While `low <= high`:
   - `mid = low + (high - low) / 2`
   - Calculate `diff = mid - sum_digits(mid)`
   - If `diff >= d`:
     - `ans = mid`
     - `high = mid - 1` (try smaller numbers)
   - Else:
     - `low = mid + 1`
3. If `ans != -1`, return `n - ans + 1`.
4. Else return `0`.

## Complexity

- **Time Complexity:** O(log N). Binary search takes O(log N) steps. Sum of digits takes O(log N). Total O((log N)^2).
- **Space Complexity:** O(1).
