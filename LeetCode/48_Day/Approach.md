# Approach for 1878. Get Biggest Three Rhombus Sums in a Grid

### Iteration with Diagonal Prefix Sums

1. **Precompute Diagonal Prefix Sums**:
   - To avoid recalculating the sum of edges for every rhombus size, we can precompute prefix sums along the two diagonal directions.
   - Let `d1` be the prefix sum for diagonals running from Top-Left to Bottom-Right (`\`). `d1[i+1][j+1] = d1[i][j] + grid[i][j]`.
   - Let `d2` be the prefix sum for diagonals running from Top-Right to Bottom-Left (`/`). `d2[i+1][j+1] = d2[i][j+2] + grid[i][j]`.

2. **Iterate Over All Possible Centers and Radii (`L`)**:
   - For each center `(i, j)`, the "radius" (or distance from the center to its corners) `L` can start from `0`. 
   - `L = 0` means an area 0 rhombus which consists of only the cell `(i, j)` itself.
   - For `L > 0`, the corners are: top `(i - L, j)`, right `(i, j + L)`, bottom `(i + L, j)`, and left `(i, j - L)`.

3. **Calculate the Perimeter Sum in `O(1)`**:
   - Using the precomputed `d1` and `d2` arrays, we can find the sum of any diagonal segment in `O(1)` time.
   - We query the 4 edges. To avoid over-counting the corners, we can calculate the 4 edge sums excluding one endpoint each, and then manually add the 4 corners:
     - Top to Right edge (excluding Top corner).
     - Right to Bottom edge (excluding Right corner).
     - Bottom to Left edge (excluding Bottom corner).
     - Left to Top edge (excluding Left corner).

4. **Store the Unique Sums**:
   - Maintain three distinct integers `top1`, `top2`, and `top3` to exclusively track the top three distinct sums observed so far.
   - Update these three integers in `O(1)` time for every rhombus sum computed.
   
5. **Get Top 3**:
   - Return an output array comprising `top1`, `top2`, and `top3`.

### Complexity
- **Time Complexity:** `O(m * n * min(m, n))`. Precomputing the two prefix sum arrays takes `O(m * n)`. Then, we iterate over `m * n` centers, and for each center, we check up to `min(m, n) / 2` radii `L`. Due to prefix sums, the perimeter calculation is `O(1)` rather than `O(L)`. Thus, we shave off a factor of `min(m, n)` from the innermost loop.
- **Space Complexity:** `O(m * n)` to store the two diagonal prefix sum arrays `d1` and `d2`.
