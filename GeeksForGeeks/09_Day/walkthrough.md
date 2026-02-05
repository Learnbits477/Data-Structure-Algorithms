# Walkthrough - Transformed Array & Maximize Number of 1's

## Part 1: Transformed Array (LeetCode)

Solves [LeetCode Problem 3379: Transformed Array](https://leetcode.com/problems/transformed-array/).

### Changes

#### LeetCode/09_Day

- **[NEW] [Problem.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/09_Day/Problem.md)**: Problem description.
- **[NEW] [Approach.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/09_Day/Approach.md)**: Circular array logic using modular arithmetic.
- **[NEW] [Solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/09_Day/Solution.cpp)**: C++ implementation.

### Verification (LeetCode)

- **Test Case 1**: Input `[3, -2, 1, 1]` -> Output `[1, 1, 1, 3]`.
- **Test Case 2**: Input `[-1, 4, -1]` -> Output `[-1, -1, 4]`.

---

## Part 2: Maximize Number of 1's (GeeksForGeeks)

Solves [GeeksForGeeks Problem: Maximize Number of 1's](https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1).

### Changes

#### GeeksForGeeks/09_Day

- **[NEW] [Problem.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/09_Day/Problem.md)**: Problem description.
- **[NEW] [Approach.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/09_Day/Approach.md)**: Sliding Window technique O(n).
- **[NEW] [Solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/09_Day/Solution.cpp)**: C++ implementation with [kZero](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/09_Day/Solution.cpp#9-35) function.

### Verification (GeeksForGeeks)

Ran [Solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/09_Day/Solution.cpp) with example cases:

**Test Case 1:**

- Input: `arr[] = [1, 0, 1], k = 1`
- Expected Output: `3`
- Actual Output: `3`

**Test Case 2:**

- Input: `arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2`
- Expected Output: `5`
- Actual Output: `5`

**Test Case 3:**

- Input: `arr[] = [1, 1], k = 2`
- Expected Output: `2`
- Actual Output: `2`

**Test Case 4 (Extra):**

- Input: `arr[] = [0, 0, 0], k = 1`
- Expected: `1`
- Actual: `1`

The solution correctly calculates the maximum consecutive 1s by flipping at most `k` zeros using a sliding window.
