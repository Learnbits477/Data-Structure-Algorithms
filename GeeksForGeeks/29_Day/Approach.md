# Approach: Longest Subarray with Majority Greater than K

## Key Insight

We need a subarray where **count(elements > k) > count(elements ≤ k)**.

**Transform the array:** Replace each element with:

- `+1` if `arr[i] > k`
- `-1` if `arr[i] ≤ k`

Now the problem reduces to: **Find the longest subarray with sum > 0** (i.e., sum ≥ 1).

---

## Algorithm: Prefix Sum + Hash Map

1. Maintain a running `prefixSum` starting at `0`.
2. For each index `i`, compute `prefixSum` after including `arr[i]`.
3. We want the longest subarray `[j+1, i]` such that `prefixSum[i] - prefixSum[j] >= 1`, i.e., `prefixSum[j] <= prefixSum[i] - 1`.
4. Use a hash map to store the **first occurrence** of each prefix sum value.
5. For current prefix sum `s`, look up `s - 1` in the map → the subarray from that index+1 to current index has sum ≥ 1.

---

## Step-by-Step on Example

```text
arr = [1, 2, 3, 4, 1], k = 2
Transformed: [-1, -1, +1, +1, -1]

Index:  -1   0   1   2   3   4
PSum:    0  -1  -2  -1   0  -1

firstOccurrence map built left to right:
  0 → -1 (before array)
 -1 →  0
 -2 →  1

At index 2: psum = -1, look for psum-1 = -2 → first seen at index 1 → length = 2-1 = 1
At index 3: psum =  0, look for psum-1 = -1 → first seen at index 0 → length = 3-0 = 3
At index 4: psum = -1, look for psum-1 = -2 → first seen at index 1 → length = 4-1 = 3

Answer: 3 ✓
```

---

## Complexity

| Complexity | Value |
| ---------- | ----- |
| Time       | O(n)  |
| Space      | O(n)  |

---

## Why This Works

- Storing **first occurrence** of prefix sums ensures the longest possible subarray.
- We look for `prefixSum - 1` (not `prefixSum`) because we need sum ≥ 1 (strictly positive).
- The initial entry `map[0] = -1` handles subarrays starting from index 0.
