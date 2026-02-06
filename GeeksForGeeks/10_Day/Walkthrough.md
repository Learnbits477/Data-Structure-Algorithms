# Walkthrough - Happiest Triplet

## Verification

### Compile

```bash
g++ Solution.cpp -o Solution
./Solution
```

### Test Case 1

Input:

- arr1: {5, 2, 8} -> Sorted: {2, 5, 8}
- arr2: {10, 7, 12} -> Sorted: {7, 10, 12}
- arr3: {9, 14, 6} -> Sorted: {6, 9, 14}

Execution Trace:
...

- Triplet (5, 7, 6): Diff 2, Sum 18.
...
- Triplet (8, 10, 9): Diff 2, Sum 27.
- Logic: Since 18 < 27, we prefer (5, 7, 6).
- Result Descending: `7 6 5`.

### Test Case 2

Input:

- arr1: {15, 12, 18, 9}
- arr2: {10, 17, 13, 8}
- arr3: {14, 16, 11, 5}

Result: `11 10 9`

## Conclusion

The algorithm correctly selects the triplet with minimum difference and **minimum sum**.
