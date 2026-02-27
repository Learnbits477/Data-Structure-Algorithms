# Number of Submatrix Have Sum X

**Platform:** GeeksforGeeks  
**Link:** [Number of Submatrix Have Sum X](https://www.geeksforgeeks.org/problems/number-of-submatrix-have-sum-k/1)  
**Difficulty:** Hard  
**Accuracy:** 80.35%  
**Submissions:** 2K+  
**Points:** 8

---

## Problem Statement

Given a matrix `mat[][]` of size `n × m` and an integer `x`, find the **number of square submatrices** whose sum of elements is equal to `x`.

---

## Examples

### Example 1

```text
Input:
mat[][] = [[2, 4, 7, 8, 10],
           [3, 1, 1, 1, 1],
           [9, 11, 1, 2, 1],
           [12, -17, 1, 1, 1]]
x = 10

Output: 3

Explanation: There are 3 square submatrices whose elements sum to 10.
```

### Example 2

```text
Input:
mat[][] = [[3, 3, 5, 3],
           [2, 2, 2, 6],
           [11, 2, 2, 4]]
x = 1

Output: 0

Explanation: There is no square submatrix whose elements sum to 1.
```

---

## Constraints

- `1 ≤ n, m ≤ 100`
- `-10³ ≤ mat[i][j] ≤ 10³`
- `-10⁹ ≤ x ≤ 10⁹`
