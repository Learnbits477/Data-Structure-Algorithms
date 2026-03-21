# Approach for 3643. Flip Square Submatrix Vertically

## Problem Statement
Given an `m x n` integer matrix `grid`, and three integers `x`, `y`, and `k`, representing the top-left corner and size of a square submatrix, flip the submatrix by reversing the order of its rows vertically. Return the updated matrix.

## Intuition
The problem asks us to reverse the rows of a specific submatrix. The submatrix starts at row `x` and column `y`, and has a size of `k x k`. To reverse the rows vertically, we can simply swap the entire rows of the submatrix or iteratively swap corresponding elements. Specifically, we swap row `x + i` with row `x + k - 1 - i` for the elements in columns from `y` to `y + k - 1`.

## Approach
1. We iterate `i` from `0` to `k / 2 - 1`. These represent the relative row indices from the top of the submatrix that need to be swapped with the corresponding bottom rows.
2. For each `i`, the top row in the submatrix is `grid[x + i]` and the bottom row is `grid[x + k - 1 - i]`.
3. We loop `j` from `0` to `k - 1` to target each column of the submatrix independently. The actual column index in the main grid is `y + j`.
4. Swap `grid[x + i][y + j]` with `grid[x + k - 1 - i][y + j]`.
5. After `k / 2` complete row swaps, the submatrix has been flipped vertically. We return the modified `grid`.

## Complexity
- **Time Complexity:** `O(k^2)`. We iterate through `k / 2` rows and `k` columns of the submatrix, performing a constant time swap operation `O(1)` for each element. In total, this executes `(k / 2) * k = (k^2) / 2` operations. For the maximum constraint `k <= 50`, this takes at most around `1250` operations, well within the typical limit of $10^8$ operations per second.
- **Space Complexity:** `O(1)`. We flip the elements of the matrix in place, swapping them directly in the given 2D array, so no extra space or additional memory allocation is needed.
