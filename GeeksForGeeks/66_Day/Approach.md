# Approach for Print Diagonally

## Problem Analysis

We are given an `n x n` matrix and need to traverse it diagonally (specifically anti-diagonals) starting from the top-left corner to the bottom-right corner.
For an `n x n` matrix, the elements on the same anti-diagonal have the same sum of their indices `(i + j)`. A `n x n` matrix possesses `2 * n - 1` anti-diagonals in total. 
The traversal order dictates that we move element by element in an anti-diagonal fashion, starting at the 0th row elements, moving down and to the left, and then continuing for the elements of the last column.

## Approach

We can systematically collect elements from each anti-diagonal in essentially two sequential steps:

1.  **Iterate through all columns in the first row (`row = 0`)**: 
    *   This provides the starting points for the first `n` anti-diagonals.
    *   For each column `col` from `0` to `n - 1`, the starting point is `matrix[0][col]`.
    *   We traverse the anti-diagonal incrementally by increasing the row index (`row++`) and decreasing the column index (`col--`). We append the elements until we go out of bounds of the matrix.

    ```cpp
    // Traverse the first row anti-diagonals
    for (int col = 0; col < n; ++col) {
        int i = 0;
        int j = col;
        while (i < n && j >= 0) {
            result.push_back(matrix[i][j]);
            i++;
            j--;
        }
    }
    ```

2.  **Iterate through the remaining rows in the last column (`col = n - 1`)**:
    *   This will give us the starting points for the remaining `n - 1` anti-diagonals.
    *   For each row `row` from `1` to `n - 1`, the starting element is `matrix[row][n - 1]`.
    *   Similarly, we continue moving diagonally by incrementing the row index (`row++`) and decrementing the column index (`col--`). Again, we append elements until we run out of bounds.

    ```cpp
    // Traverse the last column anti-diagonals (skip the first element/row)
    for (int row = 1; row < n; ++row) {
        int i = row;
        int j = n - 1;
        while (i < n && j >= 0) {
            result.push_back(matrix[i][j]);
            i++;
            j--;
        }
    }
    ```

## Complexity Assessment

-   **Time Complexity:** $\mathcal{O}(n^2)$ where $n$ is the dimension of the matrix. We traverse each element exactly once, leading directly to a quadratic time complexity.
-   **Space Complexity:** $\mathcal{O}(n^2)$, given that we allocate a contiguous auxiliary array to store the sequence of elements and return it. Without considering the size of the returned structure, it would be $\mathcal{O}(1)$ supplementary space.

