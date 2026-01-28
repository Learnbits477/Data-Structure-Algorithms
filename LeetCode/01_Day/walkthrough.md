# Walkthrough - Minimum Cost Path with Teleportations

## Changes
### [solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/01_Day/solution.cpp)
- Implemented [minCost](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/01_Day/solution.cpp#11-122) using **Dijkstra's Algorithm** with **Virtual Nodes**.
- **Virtual Nodes optimization**: 
  - Instead of iterating all cells for teleportation (O(MN)), we use virtual nodes that group teleports by value.
  - Reduced teleport edge complexity from O(T * MN) to O(MN) where T is total cells.
- **Compatibility**: Fixed code to support C++11/14 (removed structured bindings and initializer lists for tuples).
- **Verification**: Added [main](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/01_Day/solution.cpp#133-144) function with test cases.

## Verification Results
### Automated Tests
Ran the following command:
`g++ solution.cpp -o solution.exe && .\solution.exe`

**Output**:
```
Test Case: k=2 Result: 7 Expected: 7 [PASSED]
Test Case: k=1 Result: 9 Expected: 9 [PASSED]
```

Both example cases passed.
