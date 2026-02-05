# Implementation Plan - Maximize Number of 1's

Solving GeeksForGeeks problem "Maximize Number of 1's".

## Problem Description

Given a binary array `arr[]` and an integer `k`, find the maximum number of consecutive 1s possible by flipping at most `k` 0s.

## Proposed Changes

### GeeksForGeeks/09_Day

#### [NEW] [Problem.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/09_Day/Problem.md)

- Contains problem statement, examples, and constraints.

#### [NEW] [Approach.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/09_Day/Approach.md)

- **Algorithm**: Sliding Window technique.
  - Maintain a window `[left, right]`.
  - Count zeros in the current window.
  - If zeros > `k`, increment `left` to shrink window until zeros <= `k`.
  - Maximize `right - left + 1`.
- **Complexity**: O(n) time, O(1) space.

#### [NEW] [Solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/09_Day/Solution.cpp)

- Implementation of the sliding window algorithm.
- [main()](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/08_Day/Solution.cpp#60-75) function with test cases.

## Verification Plan

### Automated Tests

- Compile with `g++`.
- Run with provided examples:
  1. `arr = [1, 0, 1], k = 1` -> Output: 3
  2. `arr = [1, 0, 0, 1, 0, 1, 0, 1], k = 2` -> Output: 5
  3. `arr = [1, 1], k = 2` -> Output: 2
