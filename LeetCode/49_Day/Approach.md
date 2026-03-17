# Approach

## Intuition
The problem asks for the largest submatrix of 1s after rearranging the columns. Since we can rearrange columns in any order, we can think of each row as the base of a set of histogram bars. 
For each cell `(i, j)`, if it contains a `1`, it can be part of a vertical sequence of 1s. We can first calculate the height of consecutive 1s ending at each cell in a column.
After calculating these heights, for any given row, we have a set of heights of 1s resting on that row. Because we can rearrange the columns freely, to maximize the area of the submatrix, we can sort the heights in this row. Sorting groups the larger heights together, allowing us to easily calculate the maximum possible rectangle area ending at that row.

## Approach Steps
1. **Calculate Column Heights:** Iterate through the matrix starting from the second row (index 1). If a cell `matrix[i][j]` is 1, add the value from the cell directly above it `matrix[i-1][j]`. This updates the cell to represent the consecutive number of 1s in that column ending at row `i`.
2. **Sort and Calculate Area:** Iterate through each row of the updated matrix.
   - For each row, sort the heights in ascending order.
   - Iterate through the sorted heights. For a height at index `j`, the maximum width of a rectangle that can be formed with at least this height is `total_columns - j`.
   - The area formed is `height * width`. Keep track of the maximum area across all rows and columns.
3. Return the maximum area found.

## Complexity
- Time complexity: $O(R \cdot C \log C)$
  - $R$ is the number of rows and $C$ is the number of columns.
  - Updating the matrix takes $O(R \cdot C)$ time.
  - Sorting each row takes $O(C \log C)$ time, and we do this for $R$ rows, taking $O(R \cdot C \log C)$ time.
  - The total time complexity is dominated by the sorting step.
- Space complexity: $O(1)$
  - We modify the input `matrix` directly to store the heights, requiring no extra space other than variables for iteration and area calculation. The sorting algorithm itself may take $O(\log C)$ recursive stack space depending on the implementation.
