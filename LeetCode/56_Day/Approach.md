# Approach: Prefix and Suffix Products

This problem requires us to compute the product of all elements in the matrix except the one at `(i, j)`, modulo `12345`. This is very similar to the classic "Product of Array Except Self" problem, adapted for a 2D matrix. 

Since the modulo operation is required, taking the total product and dividing it by `grid[i][j]` is problematic because `12345` is not a prime number, which means the modular inverse might not exist for some numbers. Instead, we can calculate the prefix product and suffix product for each cell.

### Step-by-Step Approach with Code:

**Step 1: Initialization**
We start by extracting the dimensions of the grid and creating an output matrix `p` of the same dimensions. We'll use this matrix to temporarily store prefix products.

```cpp
int n = grid.size();
int m = grid[0].size();
vector<vector<int>> p(n, vector<int>(m));
```

**Step 2: Calculate Prefix Products**
We traverse the matrix from top-left to bottom-right conceptually treating it as a flat 1D sequence. We maintain a running product `pref` (initialized to 1). For each cell `(i, j)`, we assign the current `pref` into `p[i][j]`, and then update `pref` by multiplying it with the current cell's value and taking the modulo.

```cpp
long long pref = 1;

for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        // Store current prefix product
        p[i][j] = pref;
        // Update prefix product for the next cell
        pref = (pref * (grid[i][j] % 12345)) % 12345;
    }
}
```

**Step 3: Calculate Suffix Products (In-Place)**
Next, we traverse the matrix backwards—from bottom-right to top-left. We maintain a running product `suff` (initialized to 1). We multiply the current prefix product stored in `p[i][j]` by `suff` to get the final result for that cell. Then, we update `suff` for the next previous cell.

```cpp
long long suff = 1;

for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
        // Multiply existing prefix product by current suffix product
        p[i][j] = (p[i][j] * suff) % 12345;
        // Update suffix product for the preceding cell
        suff = (suff * (grid[i][j] % 12345)) % 12345;
    }
}
```

**Step 4: Return the Result**
The matrix `p` now holds the correct product combinations.

```cpp
return p;
```

### Complexity:
- **Time Complexity:** `O(N * M)` because we traverse the matrix twice (one forward pass, one backward pass).
- **Space Complexity:** `O(1)` auxiliary space (excluding the output matrix `p`), since we only use variables `pref` and `suff` for running calculations.
