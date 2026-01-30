# Implementation Plan - LeetCode 2977

## Goal
Implement a solution for "Minimum Cost to Convert String II" in C++. The solution will calculate the minimum cost to transform `source` to `target` using provided transformation rules.

## Proposed Changes

### Documentation
#### [NEW] [Approach.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/03_Day/Approach.md)
- detailed explanation of the algorithm:
    - **Graph Construction**: Group transformation rules by string length. For each length, build a graph where nodes are unique strings and edges are transformation costs.
    - **Shortest Path**: Use Floyd-Warshall algorithm to compute all-pairs shortest paths for each length group.
    - **Dynamic Programming**: Let `dp[i]` be the min cost to convert prefix `source[0...i-1]`. Transition `dp[i] -> dp[j]` by checking all possible substrings `source[i...j-1]` and `target[i...j-1]`.

### Code
#### [NEW] [Solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/03_Day/Solution.cpp)
- Implementation of the `Solution` class with the `minimumCost` method.
- Helper structures for the Trie/Map to manage string IDs.
- DP logic execution.

## Verification Plan

### Automated Tests
- Create a local test runner `TestRunner.cpp` that helps compile and run the solution against the 3 provided examples in the problem description.
- Command: `g++ TestRunner.cpp -o TestRunner && ./TestRunner` (or `.\TestRunner.exe` on Windows).
- Verify that outputs match 28, 9, and -1 respectively.

### Manual Verification
- None needed if automated tests pass.
