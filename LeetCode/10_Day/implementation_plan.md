# Implementation Plan - LeetCode 3634

## Goal Description

Solve "Minimum Removals to Balance Array" by implementing a C++ solution that calculates the minimum number of removals required to satisfy the condition `max <= k * min`.

## User Review Required
>
> [!IMPORTANT]
>
> - Ensure `long long` is used for the comparison `nums[j] <= 1LL * nums[i] * k` to avoid overflow.

## Proposed Changes

### LeetCode/10_Day

#### [NEW] [Problem.md](file:///c:/Users/Pankaj Kumar/Desktop/DSA/LeetCode/10_Day/Problem.md)

- Contains the problem description, examples, and constraints.

#### [NEW] [Approach.md](file:///c:/Users/Pankaj Kumar/Desktop/DSA/LeetCode/10_Day/Approach.md)

- Explains the sorting + sliding window strategy.
- Time Complexity: $O(N \log N)$ due to sorting.
- Space Complexity: $O(1)$ ignoring sort space.

#### [NEW] [Solution.cpp](file:///c:/Users/Pankaj Kumar/Desktop/DSA/LeetCode/10_Day/Solution.cpp)

- Implementation of the solution class using [minRemoval](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/10_Day/Solution.cpp#9-24).

#### [NEW] [Solution2.cpp](file:///c:/Users/Pankaj Kumar/Desktop/DSA/LeetCode/10_Day/Solution2.cpp)

- Alternative implementation provided by the user.
- Uses sorting and a `left` pointer iteration with `right` pointer logic.

#### [NEW] [Walkthrough.md](file:///c:/Users/Pankaj Kumar/Desktop/DSA/LeetCode/10_Day/Walkthrough.md)

- Documentation of test cases and verification.

## Verification Plan

### Automated Tests

- We will construct a simple main function in [Solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/10_Day/Solution.cpp) or a separate `TestSolution.cpp` (if requested, but user asked for [Solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/10_Day/Solution.cpp)) to run the examples.
- For this task, we will include a [main](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/10_Day/Solution.cpp#26-49) function in [Solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/10_Day/Solution.cpp) and `Solution2.cpp` that runs the provided examples and asserts the output.

### Manual Verification

- Compile and run [Solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/10_Day/Solution.cpp).
- Verify output matches examples:
  - Example 1: `[2,1,5], k=2` -> Output: 1
  - Example 2: `[1,6,2,9], k=3` -> Output: 2
  - Example 3: `[4,6], k=2` -> Output: 0
