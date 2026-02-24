# Approach — Longest Span in two Binary Arrays

## Key Insight

We want the longest subarray `[i..j]` where the sum of `a1` equals the sum of `a2`.

This is equivalent to finding the longest subarray where:

```
sum(a1[i..j]) - sum(a2[i..j]) = 0
```

Define a **difference array**:

```
diff[k] = a1[k] - a2[k]   for each index k
```

Now the problem reduces to: **Find the longest subarray in `diff[]` with sum = 0**.

---

## Algorithm: Prefix Sum + Hash Map

### Steps

1. Maintain a running `prefixDiff` as we iterate.
2. Maintain a hash map `mp` storing the **first occurrence** of each prefix sum value.
3. At each index `i`:
   - Add `a1[i] - a2[i]` to `prefixDiff`.
   - If `prefixDiff == 0`, span `[0..i]` is valid → update `maxLen = i + 1`.
   - If `prefixDiff` was seen before at index `j`, subarray `[j+1..i]` has zero diff → update `maxLen = max(maxLen, i - j)`.
   - If `prefixDiff` is first seen, store it: `mp[prefixDiff] = i`.
4. Return `maxLen`.

### Complexity

| Aspect | Complexity |
| ------ | ---------- |
| Time   | O(n)       |
| Space  | O(n)       |

---

## Dry Run — Example 1

```
a1   = [0, 1, 0, 0, 0, 0]
a2   = [1, 0, 1, 0, 0, 1]
diff = [-1, 1, -1, 0, 0, -1]

i=0: prefixDiff = -1  → store mp[-1] = 0
i=1: prefixDiff =  0  → span = i+1 = 2,  ans = 2
i=2: prefixDiff = -1  → seen at j=0: span = 2-0 = 2, ans = 2
i=3: prefixDiff = -1  → seen at j=0: span = 3-0 = 3, ans = 3
i=4: prefixDiff = -1  → seen at j=0: span = 4-0 = 4, ans = 4
i=5: prefixDiff = -2  → store mp[-2] = 5

Final answer = 4 ✓
```

---

## Edge Cases

- **Identical arrays** → whole array is the answer (`n`).
- **No matching sums** → return `0`.
- **All 1s vs all 0s** → prefix never returns to 0 → return `0`.

---

## Why Not Brute Force?

A naive O(n²) approach iterates all pairs `(i, j)` and computes sums — too slow for `n = 10^6`. The prefix sum + hash map approach solves it in **O(n)** time.
