# Approach: Missing Element in Range

## Strategy: Unordered Set Lookup

### Key Insight

Store all array elements in a hash set for O(1) lookups, then iterate through the range `[low, high]` and collect any number not found in the set.

### Algorithm

1. **Build a Set**: Insert all elements of `arr[]` into an `unordered_set`.
2. **Iterate the Range**: Loop from `low` to `high` (inclusive).
3. **Check Membership**: If the current number is **not** in the set, add it to the result.
4. **Return Result**: The result list is already in sorted order since we iterate low → high.

### Complexity Analysis

| Metric           | Value               |
| ---------------- | ------------------- |
| Time Complexity  | O(N + (high - low)) |
| Space Complexity | O(N)                |

- **N** = size of the array (for building the set)
- **(high - low)** = range size (for iterating and checking)

### Walkthrough – Example 1

```
arr = [10, 12, 11, 15], low = 10, high = 15

Set = {10, 11, 12, 15}

Check 10 → in set → skip
Check 11 → in set → skip
Check 12 → in set → skip
Check 13 → NOT in set → add
Check 14 → NOT in set → add
Check 15 → in set → skip

Result = [13, 14] ✓
```

### Walkthrough – Example 2

```
arr = [1, 4, 11, 51, 15], low = 50, high = 55

Set = {1, 4, 11, 15, 51}

Check 50 → NOT in set → add
Check 51 → in set → skip
Check 52 → NOT in set → add
Check 53 → NOT in set → add
Check 54 → NOT in set → add
Check 55 → NOT in set → add

Result = [50, 52, 53, 54, 55] ✓
```
