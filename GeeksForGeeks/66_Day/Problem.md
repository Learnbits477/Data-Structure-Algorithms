# [Print Diagonally](https://www.geeksforgeeks.org/problems/print-diagonally4331/1)

## Description

Given a `n * n` square matrix, return all the elements of its anti-diagonals from top to bottom.

### Examples:

**Example 1:**
```text
Input: n = 2
mat[][] = [[1, 2],
           [3, 4]]
Output: [1, 2, 3, 4]
Explanation: 
The anti-diagonals are:
1
2 3
4
```

**Example 2:**
```text
Input: n = 3
mat[][] = [[1, 2, 3],
           [4, 5, 6],
           [7, 8, 9]]
Output: [1, 2, 4, 3, 5, 7, 6, 8, 9]
Explanation:
The anti-diagonals are:
1
2 4
3 5 7
6 8
9
```

### Constraints:
- `1 ≤ n ≤ 10^3`
- `0 ≤ mat[i][j] ≤ 10^6`
