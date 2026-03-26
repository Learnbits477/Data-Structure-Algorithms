# Approach for 3548. Equal Sum Grid Partition II

## 1. Initial Computations

First, calculate the total sum of all elements in the grid. Simultaneously, compute the sum of each row and column to enable fast $\mathcal{O}(1)$ subgrid sum calculations. We also find `MAX_VAL` to size our indexing arrays dynamically.

```cpp
int m = grid.size();
int n = grid[0].size();
long long total_sum = 0;
vector<long long> row_sum(m, 0), col_sum(n, 0);
int MAX_VAL = 0;

for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        MAX_VAL = max(MAX_VAL, grid[i][j]);
        row_sum[i] += grid[i][j];
        col_sum[j] += grid[i][j];
        total_sum += grid[i][j];
    }
}
```

## 2. Precomputing Existence Arrays

To optimally check if a specific value exists in a section, we precompute four boundary arrays: `min_r`, `max_r`, `min_c`, and `max_c`. These store the minimum and maximum row/column limits where a particular value `v` appears.

```cpp
vector<int> min_r(MAX_VAL + 1, 1e9);
vector<int> max_r(MAX_VAL + 1, -1);
vector<int> min_c(MAX_VAL + 1, 1e9);
vector<int> max_c(MAX_VAL + 1, -1);

for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        int v = grid[i][j];
        min_r[v] = min(min_r[v], i);
        max_r[v] = max(max_r[v], i);
        min_c[v] = min(min_c[v], j);
        max_c[v] = max(max_c[v], j);
    }
}
```

## 3. Horizontal Cuts

We iterate through all possible horizontal cuts (after row `r`). We maintain `S_top` and compute `S_bottom`. If they differ, we determine the required `diff` to eliminate from the strictly larger section.

A core **Graph Theory** insight ensures cell validness: 

- Any graph $\ge 2 \times 2$ is biconnected (any single cell can be safely discounted).
- If the section is a 1D vector ($1 \times K$ or $K \times 1$), then only its outer two **endpoints** can be safely discounted to remain connected.

```cpp
long long S_top = 0;
for (int r = 0; r < m - 1; r++) {
    S_top += row_sum[r];
    long long S_bottom = total_sum - S_top;
    
    if (S_top == S_bottom) return true;
    
    // If Top section is larger, we must remove 'diff' from Top
    if (S_top > S_bottom) {
        long long diff = S_top - S_bottom;
        if (diff <= MAX_VAL) {
            // Check 1D cut cases vs 2D biconnected cases
            if (n == 1) {
                if (diff == grid[0][0] || diff == grid[r][0]) return true;
            } else if (r == 0) {
                if (diff == grid[0][0] || diff == grid[0][n-1]) return true;
            } else {
                if (min_r[diff] <= r) return true; // Safe to remove any cell
            }
        }
    } 
    // Similar logic if Bottom section is larger
    else {
        long long diff = S_bottom - S_top;
        if (diff <= MAX_VAL) {
            if (n == 1) {
                if (diff == grid[r+1][0] || diff == grid[m-1][0]) return true;
            } else if (r == m - 2) {
                if (diff == grid[m-1][0] || diff == grid[m-1][n-1]) return true;
            } else {
                if (max_r[diff] >= r + 1) return true;
            }
        }
    }
}
```

## 4. Vertical Cuts

We identically iterate through vertical cuts representing columns `c` to form Left and Right sections.

```cpp
long long S_left = 0;
for (int c = 0; c < n - 1; c++) {
    S_left += col_sum[c];
    long long S_right = total_sum - S_left;
    
    if (S_left == S_right) return true;
    
    // Left section checks
    if (S_left > S_right) {
        long long diff = S_left - S_right;
        if (diff <= MAX_VAL) {
            if (m == 1) {
                if (diff == grid[0][0] || diff == grid[0][c]) return true;
            } else if (c == 0) {
                if (diff == grid[0][0] || diff == grid[m-1][0]) return true;
            } else {
                if (min_c[diff] <= c) return true;
            }
        }
    } 
    // Right section checks
    else {
        long long diff = S_right - S_left;
        if (diff <= MAX_VAL) {
            if (m == 1) {
                if (diff == grid[0][c+1] || diff == grid[0][n-1]) return true;
            } else if (c == n - 2) {
                if (diff == grid[0][n-1] || diff == grid[m-1][n-1]) return true;
            } else {
                if (max_c[diff] >= c + 1) return true;
            }
        }
    }
}
```

## 5. Complexity

- **Time Complexity:** $\mathcal{O}(m \times n)$
  Iterating over the grid to calculate limits and prefix sums, then utilizing $O(1)$ sub-checks yields the theoretical boundary minimum timeline.
- **Space/Auxiliary Complexity:** $\mathcal{O}(\max(grid) + m + n)$
  Required for caching horizontal/vertical coordinates globally. Extends to purely contiguous array memory.
