# Approach – Find H-Index

## Intuition

We need the largest value **H** such that at least **H** papers have **≥ H** citations.

A naive approach sorts the array and scans from the end, but we can do better with a **counting / bucket sort** technique in **O(n)** time.

---

## Algorithm: Bucket / Count Array (O(n) time, O(n) space)

### Key Observation

- H-index can never exceed `n` (total number of papers).
- So we only care about citation counts in the range `[0, n]`. Any citation count > n is effectively treated as n (a paper with 100 citations still only contributes 1 to "papers with ≥ H citations" when H ≤ n).

### Steps

1. Let `n = citations.size()`.
2. Create a **count array** `cnt` of size `n + 1` (indices 0 to n).
3. For each citation `c`:
   - If `c >= n`, increment `cnt[n]`.
   - Else increment `cnt[c]`.
4. Traverse from `h = n` down to `0`, maintaining a running sum `papers` of papers seen so far.
   - At each step: `papers += cnt[h]`.
   - If `papers >= h`, return `h` — this is the H-index.
5. If no H found, return `0`.

### Dry Run on Example 1

```
citations = [3, 0, 5, 3, 0],  n = 5
cnt = [2, 0, 0, 2, 0, 1]   (indices 0..5; 5 maps to cnt[5] since 5>=n... wait n=5, so clip)
     idx:  0  1  2  3  4  5

h=5: papers = 1, 1 < 5 → skip
h=4: papers = 1, 1 < 4 → skip
h=3: papers = 1+2 = 3, 3 >= 3 → return 3 ✓
```

### Dry Run on Example 2

```
citations = [5, 1, 2, 4, 1],  n = 5
cnt = [0, 2, 1, 0, 1, 1]

h=5: papers=1, 1<5
h=4: papers=2, 2<4
h=3: papers=3, 3<3 (not >=3)  wait 3>=3 is true... but answer is 2?
```

Wait — let's recheck: papers at h=3: cnt[5]+cnt[4]+cnt[3] = 1+1+0 = 2, 2 < 3 → skip  
h=2: papers = 2+1 = 3, 3 >= 2 → return **2** ✓

---

## Complexity

| Metric | Value |
| ------ | ----- |
| Time   | O(n)  |
| Space  | O(n)  |

---

## Alternative: Sorting-Based (O(n log n))

1. Sort `citations` in **descending** order.
2. Iterate with index `i` (0-based). If `citations[i] >= i + 1`, H-index is at least `i + 1`.
3. The last valid index gives the answer.

This is simpler to implement but slightly slower.
