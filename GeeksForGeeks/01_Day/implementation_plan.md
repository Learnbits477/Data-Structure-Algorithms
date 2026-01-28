# Count Subset With Target Sum II Solution Plan

## Goal Description
Solve the "Count Subset With Target Sum II" problem where we need to find the number of subsets in an array `arr` (size up to 40) that sum to `k`. Elements can be negative.

## Proposed Changes
We will use the **Meet-in-the-middle** algorithm because `N=40` is too large for recursive brute force ($2^{40}$) but small enough for $2^{20}$ split.

### Algorithm
1. Split `arr` into two halves: `left` (size `n/2`) and `right` (size `n - n/2`).
2. Generate all possible subset sums for `left` and store them in a vector `leftSums`.
3. Generate all possible subset sums for `right` and store them in a vector `rightSums`.
4. Sort `rightSums` to allow for binary search / range counting.
5. For each sum `s` in `leftSums`:
   - Calculate needed complement `target = k - s`.
   - Find count of `target` in `rightSums` using `std::equal_range` or `std::lower_bound`/`std::upper_bound`.
6. Sum up the counts to get the total answer.

### Files
#### [NEW] [CountSubsetWithTargetSumII.cpp](file:///c:/Users/Pankaj Kumar/Desktop/DSA/CountSubsetWithTargetSumII.cpp)
- Implementation of `class Solution` with `countSubset` method.
- Main function for testing with provided examples.

## Verification Plan
### Automated Tests
- Compile the C++ file.
- Run the executable.
- The `main` function will contain assertions or print statements for the example cases:
    1. `arr = [1, 3, 2], k = 3` -> Output: 2
    2. `arr = [4, 2, 3, 1, 2], k = 4` -> Output: 3
    3. `arr = [10, 20, 30], k = 25` -> Output: 0
