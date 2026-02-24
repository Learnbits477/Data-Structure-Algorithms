# Approach: Largest Number Formed from an Array

## Strategy: Custom Comparator Sort

### Key Insight

To decide which of two numbers `a` and `b` should come first, compare the two concatenations:

- `ab` (a placed before b) vs `ba` (b placed before a)

If `ab > ba`, then `a` should come before `b`. This comparison naturally handles all edge cases (e.g., `3` vs `30`: `330 > 303`, so `3` comes first).

### Algorithm

1. **Convert to Strings**: Convert all integers in `arr[]` to strings.
2. **Custom Sort**: Sort the string array using the comparator: `a + b > b + a`.
3. **Handle All-Zeros**: If the largest element (after sorting) is `"0"`, return `"0"` to avoid leading zeros like `"000"`.
4. **Concatenate & Return**: Join all sorted strings to form the final result.

### Complexity Analysis

| Metric           | Value            |
| ---------------- | ---------------- |
| Time Complexity  | O(N · K · log N) |
| Space Complexity | O(N · K)         |

- **N** = number of elements
- **K** = average number of digits per element (at most 6 for `arr[i] ≤ 10^5`)
- Sorting with string comparison of length K strings: O(K · log N) per comparison

### Walkthrough – Example 1

```
arr = [3, 30, 34, 5, 9]
Strings = ["3", "30", "34", "5", "9"]

Comparisons (pick a before b if a+b > b+a):
  "9" vs "5"  → "95" > "59" → 9 first
  "5" vs "34" → "534" > "345" → 5 first
  "34" vs "3" → "343" > "334" → 34 first
  "3" vs "30" → "330" > "303" → 3 first

Sorted = ["9", "5", "34", "3", "30"]
Result = "9534330" ✓
```

### Walkthrough – Example 2

```
arr = [54, 546, 548, 60]
Strings = ["54", "546", "548", "60"]

Sorted = ["60", "548", "546", "54"]
Result = "6054854654" ✓
```

### Edge Case – All Zeros

```
arr = [0, 0, 0]
After sort: ["0", "0", "0"]
result[0] == "0" → return "0"  (not "000")
```
