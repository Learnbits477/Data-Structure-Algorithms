# Solve LeetCode 3637: Trionic Array I

## Goal Description
The goal is to solve the LeetCode daily problem "3637. Trionic Array I".
The task involves checking if an array can be divided into three segments:
1. Strictly increasing.
2. Strictly decreasing.
3. Strictly increasing.

## Proposed Changes
I will create the following files in `c:\Users\Pankaj Kumar\Desktop\DSA\LeetCode\07_Day`:

### LeetCode/07_Day
#### [NEW] [Problem.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/07_Day/Problem.md)
Contains the problem description.

#### [NEW] [Approach.md](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/07_Day/Approach.md)
Explains the algorithm:
1. Iterate through all possible indices `p` and `q` such that `0 < p < q < n-1`.
2. Check strictly increasing condition for `0...p`.
3. Check strictly decreasing condition for `p...q`.
4. Check strictly increasing condition for `q...n-1`.
5. Since `n <= 100`, an $O(n^3)$ solution is acceptable. Optimization to $O(n^2)$ is possible by simple checks.

#### [NEW] [Solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/07_Day/Solution.cpp)
Implements the solution in C++.

## Verification Plan
### Automated Tests
- I will attempt to compile the code using `g++`.
- I will create a simple `main` function in a temporary file or within `Solution.cpp` (commented out or if user permits) to test with the provided examples.
    - Example 1: `nums = [1,3,5,4,2,6]` -> `true`
    - Example 2: `nums = [2,1,3]` -> `false`
