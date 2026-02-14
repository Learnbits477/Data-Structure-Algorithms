# Approach for Champagne Tower

## Problem Understanding

We need to simulate pouring champagne into a pyramid of glasses. Each glass holds 1 cup. Excess overflows equally to the two glasses directly below it. We need to find the amount in a specific glass at `(query_row, query_glass)`.

## Simulation Approach

Since `query_row` is small (up to 99), we can simulate the process row by row.
We can use a 2D array `tower` where `tower[i][j]` represents the amount of champagne that flows into glass `(i, j)`.

1. Initialize `tower[0][0] = poured`.
2. Iterate through each row `i` from 0 to `query_row`.
3. For each glass `j` in row `i`:
   - If `tower[i][j] > 1`, it overflows.
   - The excess amount is `excess = tower[i][j] - 1`.
   - This excess is split equally between the two glasses below: `tower[i+1][j]` and `tower[i+1][j+1]`.
   - `tower[i][j]` itself retains 1 cup (it is full).
   - `tower[i+1][j] += excess / 2.0`
   - `tower[i+1][j+1] += excess / 2.0`
4. The answer for `(query_row, query_glass)` is `min(1.0, tower[query_row][query_glass])`. We take the minimum because the simulation might accumulate more than 1 in the target glass if we continue processing, or simply because the accumulated value represents total flow through it, but it can only hold 1. Wait, actually, in our simulation, if we process row by row, `tower[i][j]` stores the total amount poured _into_ it. So at the end, if `tower[query_row][query_glass] > 1`, it means it's full and overflowing, so it holds 1. If it's <= 1, it holds that exact amount.

## Complexity

- **Time Complexity:** O(R^2), where R is `query_row`. We process roughly R\*R/2 glasses. Since R <= 99, this is very fast (~5000 operations).
- **Space Complexity:** O(R^2) for the 2D array. We can optimize to O(R) using two rows, but O(R^2) is sufficient and simpler given the constraints.
