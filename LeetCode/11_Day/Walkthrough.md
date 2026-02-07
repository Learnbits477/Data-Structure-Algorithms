# Walkthrough - LeetCode 1653 Solution

## Changes

I have added the following files to `LeetCode/11_Day`:

### [Problem.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/11_Day/Problem.md)

Contains the problem description for "Minimum Deletions to Make String Balanced".

### [Approach.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/11_Day/Approach.md)

Explains the greedy/dynamic programming approach used to solve the problem with O(N) time complexity and O(1) space complexity.

### [Solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/11_Day/Solution.cpp)

Contains the C++ implementation of the solution and a `main` function to run test cases.

## Verification Results

### Automated Tests

I compiled and ran `Solution.cpp` using `g++`.

**Command:**

```powershell
g++ Solution.cpp -o Solution; .\Solution
```

**Output:**

```
Test Case 1: Input: aababbab
Expected Output: 2
Actual Output: 2
-----------------
Test Case 2: Input: bbaaaaabb
Expected Output: 2
Actual Output: 2
-----------------
```

The solution correctly computes the minimum deletions for the provided examples.
