# Walkthrough - Minimum Removals to Balance Array

## Problem Overview

We need to find the minimum removals such that `max <= min * k`. This involves finding the longest subsequence (which becomes a subarray after sorting) that satisfies the condition.

## Verification Steps

We will use the provided `main` function in `Solution.cpp` to verify the examples.

### Compile and Run

```bash
g++ Solution.cpp -o Solution
./Solution
```

### Test Case 1

- **Input**: `nums = [2,1,5], k = 2`
- **Sorted**: `[1, 2, 5]`
- **Logic**:
  - `i=0 (1), j=0 (1)`: `1 <= 1*2` (OK) -> len=1
  - `i=0 (1), j=1 (2)`: `2 <= 1*2` (OK) -> len=2
  - `i=0 (1), j=2 (5)`: `5 > 1*2` (Fail) -> inc `i`
  - `i=1 (2), j=2 (5)`: `5 > 2*2` (Fail) -> inc `i`
  - `i=2 (5), j=2 (5)`: `5 <= 5*2` (OK) -> len=1
  - Max Kept: 2. Removals: `3 - 2 = 1`.
- **Expected Output**: 1

### Test Case 2

- **Input**: `nums = [1,6,2,9], k = 3`
- **Sorted**: `[1, 2, 6, 9]`
- **Logic**:
  - `i=0 (1), j=0`: OK
  - `i=0 (1), j=1 (2)`: OK
  - `i=0 (1), j=2 (6)`: `6 > 1*3` -> inc `i` -> `i=1 (2)`
  - `i=1 (2), j=2 (6)`: `6 <= 2*3` (OK) -> len=2
  - `i=1 (2), j=3 (9)`: `9 > 2*3` -> inc `i` -> `i=2 (6)`
  - `i=2 (6), j=3 (9)`: `9 <= 6*3` (OK) -> len=2
  - Max Kept: 2. Removals: `4 - 2 = 2`.
- **Expected Output**: 2

### Test Case 3

- **Input**: `nums = [4,6], k = 2`
- **Logic**: Sorted `[4, 6]`. `6 <= 4*2` is True. Keep all 2. Removals: 0.
- **Expected Output**: 0

## Conclusion

The sliding window approach correctly identifies the maximum size subset to keep.
