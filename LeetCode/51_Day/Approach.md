# Approach for 3212. Count Submatrices With Equal Frequency of X and Y

## Intuition
The problem asks us to find the number of submatrices starting from the top-left corner `(0, 0)` that have an equal positive number of 'X's and 'Y's. A submatrix starting from `(0, 0)` to `(i, j)` has its properties defined completely by its bottom-right corner `(i, j)`.

To do this efficiently, we can use a 2D prefix sum technique to keep track of the occurrences of `'X'` and `'Y'` in any submatrix securely rooted at `(0, 0)`.

## Algorithm
1. Keep a 2D tracking mechanism or DP arrays to store the count of 'X's and 'Y's for submatrices formed from `(0, 0)` to `(i, j)`.
2. For each cell `(i, j)`, we calculate the prefix occurrences of `'X'` and `'Y'`.
3. To reduce space complexity, since the `(i, j)` counts only rely on the current row and the previous row (`i-1`), we can iterate down the grid saving the prefix sum in an array of pairs.
4. For each cell `(i, j)`, update its column prefix counts recursively: `prefix[j].X = prefix[j].X + current_row_X` and `prefix[j].Y = prefix[j].Y + current_row_Y`
5. If at any `(i, j)`, the cumulative `'X'` count is strictly greater than 0 and equals the `'Y'` count, we increment our answer counter.
6. Return the answer properly.

## Complexity
- **Time Complexity:** $O(m \times n)$, where $m$ and $n$ are the array dimensions. We process each cell exactly once.
- **Space Complexity:** $O(n)$, since we only keep a prefix sum of the elements tracked up to each column dynamically.
