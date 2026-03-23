# [1594. Maximum Non Negative Product in a Matrix](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/?envType=daily-question&envId=2026-03-06)

## Problem Overview
The goal is to find a path from the top-left to the bottom-right corner of a matrix such that the product of the numbers on the path is maximized and non-negative. Because multiply by a negative number flips the sign, tracking just the maximum product is insufficient. A highly negative product can become powerfully positive if multiplied by another negative value. Thus, we must maintain both the **maximum** and **minimum** products at each cell.

## Code Explanation: Step-by-Step

### Step 1: Initialization
```cpp
int m = grid.size();
int n = grid[0].size();
int MOD = 1e9 + 7;

vector<vector<long long>> max_prod(m, vector<long long>(n));
vector<vector<long long>> min_prod(m, vector<long long>(n));
```
- We define our matrix bounds `m` and `n`.
- We use a 64-bit integer (`long long`) 2D array for `max_prod` and `min_prod`. We need `long long` because the product can be up to $4^{29}$, which fits inside a signed 64-bit int but overruns a 32-bit int. 
- We define `MOD` as `1e9 + 7` as required. 

### Step 2: Base Cases
```cpp
max_prod[0][0] = min_prod[0][0] = grid[0][0];

for (int i = 1; i < m; ++i) {
    max_prod[i][0] = min_prod[i][0] = max_prod[i-1][0] * grid[i][0];
}
for (int j = 1; j < n; ++j) {
    max_prod[0][j] = min_prod[0][j] = max_prod[0][j-1] * grid[0][j];
}
```
- **Starting point**: Initialize `max_prod[0][0]` and `min_prod[0][0]` to the value of the top-left cell.
- **First Column & First Row**: Since there's only one way to move along the first column (downwards) and the first row (rightwards), the product is straightforwardly built by multiplying the previous cell's product.

### Step 3: Dynamic Programming Transitions
```cpp
for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
        if (grid[i][j] >= 0) {
            max_prod[i][j] = max(max_prod[i-1][j], max_prod[i][j-1]) * grid[i][j];
            min_prod[i][j] = min(min_prod[i-1][j], min_prod[i][j-1]) * grid[i][j];
        } else {
            max_prod[i][j] = min(min_prod[i-1][j], min_prod[i][j-1]) * grid[i][j];
            min_prod[i][j] = max(max_prod[i-1][j], max_prod[i][j-1]) * grid[i][j];
        }
    }
}
```
For all other cells `(i, j)`, we inspect the top `(i-1, j)` and left `(i, j-1)` cell options:
- **When `grid[i][j]` is $\ge 0$**: The maximal possible value relies strictly on the maximal incoming values, and the minimal depends upon the minimal incoming values.
- **When `grid[i][j]` is $< 0$**: Multiplication flips the extremes. To get a peak `max_prod[i][j]`, we must multiply our negative grid value by the most *negative* (minimal) previous value. To get the `min_prod[i][j]`, we multiply it by the most positive (maximal) previous value.

### Step 4: Final Result
```cpp
if (max_prod[m-1][n-1] < 0) {
    return -1;
}
return max_prod[m-1][n-1] % MOD;
```
- We only perform the modulo operation at the end on the ultimate maximum product (this ensures we evaluate products based on full value rather than wrapping properties midway).
- If the top product at the destination cell is negative, there is no non-negative product possible. Thus, return `-1`.
- Otherwise, return `max_prod[m-1][n-1] % MOD`.

## Complexity Analysis
- **Time Complexity:** $O(m \times n)$. We traverse every cell in the matrix once.
- **Space Complexity:** $O(m \times n)$. We use two extra tables of size $m \times n$ (`max_prod` and `min_prod`). Given the maximum grid dimension constraint is bounds as $15 \times 15$, this equates to completely negligible memory usage.
