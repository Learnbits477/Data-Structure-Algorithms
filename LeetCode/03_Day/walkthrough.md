# Walkthrough - LeetCode 2977 Solution

## Changes
I have created the following files to solve "Minimum Cost to Convert String II":

- **[Problem.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/03_Day/Problem.md)**: Contains the full problem description.
- **[Approach.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/03_Day/Approach.md)**: Explains the Floyd-Warshall + Dynamic Programming approach.
- **[Solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/03_Day/Solution.cpp)**: The C++ source code implementing the [Solution](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/03_Day/Solution.cpp#10-121) class.

## Verification
I verified the solution using a local test runner [TestRunner.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/03_Day/TestRunner.cpp) which executed the 3 examples provided in the problem statement.

### Test Results
- **Example 1**: Input `source="abcd"`, `target="acbe"`, ... -> Output `28` (PASSED)
- **Example 2**: Input `source="abcdefgh"`, ... -> Output `9` (PASSED)
- **Example 3**: Input `source="abcdefgh"`, ... -> Output `-1` (PASSED)

The solution correctly handles disjoint and identical substring operations as well as impossible cases.
