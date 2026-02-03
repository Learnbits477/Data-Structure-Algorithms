# Walkthrough - Stock Buy and Sell (GeeksForGeeks Day 07)

I have implemented the solution for the "Stock Buy and Sell – Max one Transaction Allowed" problem.

## Changes

### 1. [Problem.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/07_Day/Problem.md)
   - Added the problem description, examples, and constraints.

### 2. [Approach.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/07_Day/Approach.md)
   - Documented the O(N) single-pass approach.
   - We track the minimum price encountered so far and calculate the maximum profit if we sell at the current price.

### 3. [Solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/07_Day/Solution.cpp)
   - Implemented the [maxProfit](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/07_Day/Solution.cpp#9-22) function class.
   - **Time Complexity:** O(N)
   - **Space Complexity:** O(1)

### 4. [TestSolution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/07_Day/TestSolution.cpp)
   - Created a test runner to verify the solution with provided examples and edge cases.

## Verification Results

### Automated Tests
Ran the [TestSolution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/07_Day/TestSolution.cpp) with the following results:
```
Prices: {7, 10, 1, 3, 6, 9, 2} -> Expected: 8, Got: 8
Prices: {7, 6, 4, 3, 1} -> Expected: 0, Got: 0
Prices: {1, 3, 6, 9, 11} -> Expected: 10, Got: 10
Prices: {2, 4, 1} -> Expected: 2, Got: 2
Prices: {3, 2, 6, 5, 0, 3} -> Expected: 4, Got: 4
All tests passed!
```
The solution correctly handles all cases, including unsorted prices and decreasing prices.
