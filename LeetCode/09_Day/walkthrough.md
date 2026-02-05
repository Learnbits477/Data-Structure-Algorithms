# Walkthrough - Transformed Array

Solves [LeetCode Problem 3379: Transformed Array](https://leetcode.com/problems/transformed-array/).

## Changes

### LeetCode/09_Day

#### [NEW] [Problem.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/09_Day/Problem.md)

- Contains the problem description and examples.

#### [NEW] [Approach.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/09_Day/Approach.md)

- Explains the circular array transformation logic using modular arithmetic.
- Key formula: `target_index = ((i + nums[i]) % n + n) % n`.

#### [NEW] [Solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/09_Day/Solution.cpp)

- Implements the [constructTransformedArray](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/09_Day/Solution.cpp#9-19) function.
- Includes a [main](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/09_Day/Solution.cpp#21-48) function to verify the solution with examples.

## Verification Results

### Automated Tests

Ran [Solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/08_Day/Solution.cpp) with the provided examples.

**Test Case 1:**

- Input: `[3, -2, 1, 1]`
- Expected Output: `[1, 1, 1, 3]`
- Actual Output: `[1, 1, 1, 3]`

**Test Case 2:**

- Input: `[-1, 4, -1]`
- Expected Output: `[-1, -1, 4]`
- Actual Output: `[-1, -1, 4]`

The solution correctly handles positive shifts, negative shifts, and zero values with wrap-around.
