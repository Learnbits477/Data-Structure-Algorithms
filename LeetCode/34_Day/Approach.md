# Approach

1. **Calculate Trailing Zeros:** For each row, count the number of continuous zeros at the end. Store these counts in an array, say `zeros`.
2. **Greedy Swapping:** Iterate through each row `i` from `0` to `n-1`. For a valid grid, the `i`-th row must have at least `n - 1 - i` trailing zeros.
3. **Find the First Valid Row:** Starting from the current row `i`, search downwards (index `j` from `i` to `n-1`) for the first row that satisfies the condition `zeros[j] >= n - 1 - i`.
   - Why the _first_ one? Because greedily picking the closest valid row minimizes the number of swaps for the current step and leaves other valid rows in the best possible relative order for subsequent steps.
4. **Swap and Count:** Once found, bubble this row up to position `i` by repeatedly swapping it with the row above it, incrementing the swap counter each time. Update the `zeros` array to reflect these swaps.
5. **No Valid Row:** If no such row `j` is found for a row `i`, it's impossible to make the grid valid, so return `-1`.

### Complexity

- **Time Complexity:** $O(n^2)$, where $n$ is the number of rows/columns. Counting zeros takes $O(n^2)$, and the greedy swapping takes at most $O(n^2)$ swaps in the worst case.
- **Space Complexity:** $O(n)$ to store the number of trailing zeros for each row.
