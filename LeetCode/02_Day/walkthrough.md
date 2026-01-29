# Walkthrough - LeetCode 2976 Solution

I have implemented the solution for "Minimum Cost to Convert String I".

## Changes

### [solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/02_Day/solution.cpp)
Implemented the [minimumCost](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/02_Day/solution.cpp#10-52) method using the **Floyd-Warshall Algorithm**.
1.  **Graph Construction**: Created a 26x26 adjacency matrix representing costs between lowercase English letters.
2.  **Shortest Path**: Used Floyd-Warshall to computer all-pairs shortest paths for character transformations.
    -   Complexity: O(A^3) where A=26 (alphabet size), which is effectively O(1).
3.  **Cost Calculation**: Iterated through the `source` string, accumulating the cost to transform each character to the corresponding character in `target`.
    -   If a transformation is impossible (cost is infinite), returned -1.

## Verification Results

### Automated Tests
Ran a custom test runner [runner.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/02_Day/runner.cpp) with the provided examples.

**Command:**
```powershell
./runner
```

**Output:**
```
Running tests...
Test Case 1 Passed!
Test Case 2 Passed!
Test Case 3 Passed!
```

- **Test Case 1**: Source "abcd" -> Target "acbe". Cost 28. Passed.
- **Test Case 2**: Source "aaaa" -> Target "bbbb". Cost 12. Passed.
- **Test Case 3**: Source "abcd" -> Target "abce". Impossible. Passed.
