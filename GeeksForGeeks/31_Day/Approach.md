# Approach: 2D Prefix Sum

## Intuition

We need to count all **square** submatrices (not just any rectangle) with sum equal to `x`.

For each possible square size `k` (from `1` to `min(n, m)`), we count how many `k×k` submatrices have sum equal to `x`.

To compute the sum of any submatrix in O(1), we precompute a **2D prefix sum** array.

---

## Algorithm

### Step 1: Build 2D Prefix Sum

Define `pre[i][j]` = sum of all elements in the submatrix from `(0,0)` to `(i-1, j-1)` (1-indexed).

```cpp
vector<vector<int>> pre(n+1, vector<int>(m+1, 0));
for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
        pre[i][j] = mat[i-1][j-1]
                  + pre[i-1][j]
                  + pre[i][j-1]
                  - pre[i-1][j-1];
    }
}
```

### Step 2: getSum — O(1) Submatrix Sum Query

Sum of submatrix from `(r1, c1)` to `(r2, c2)` (0-indexed):

```cpp
auto getSum = [&](int r1, int c1, int r2, int c2) {
    return pre[r2+1][c2+1]
         - pre[r1][c2+1]
         - pre[r2+1][c1]
         + pre[r1][c1];
};
```

### Step 3: Iterate Over All Square Submatrices

For each size `k` from `1` to `min(n, m)`:

```cpp
for(int k = 1; k <= min(n, m); k++) {
    for(int i = 0; i + k <= n; i++) {
        for(int j = 0; j + k <= m; j++) {
            if(getSum(i, j, i+k-1, j+k-1) == x)
                count++;
        }
    }
}
```

- Slide a `k×k` window over the matrix using top-left corner `(i, j)`
- Use `getSum` to compute the submatrix sum in O(1)
- If sum == `x`, increment count

---

## Complexity Analysis

| Metric | Value               |
| ------ | ------------------- |
| Time   | O(min(n,m) × n × m) |
| Space  | O(n × m)            |

Since `n, m ≤ 100`, this is at most O(100 × 100 × 100) = O(10⁶), which is very efficient.

---

## Dry Run

```text
mat = [[1, 1, 1],
       [1, 1, 1],
       [1, 1, 1]]
x = 4

k=1: All 1×1 cells have sum=1 ≠ 4 → count = 0

k=2: Check all 2×2 submatrices (top-left corners):
     (0,0): 1+1+1+1 = 4 ✓  → count = 1
     (0,1): 1+1+1+1 = 4 ✓  → count = 2
     (1,0): 1+1+1+1 = 4 ✓  → count = 3
     (1,1): 1+1+1+1 = 4 ✓  → count = 4

k=3: Only one 3×3 submatrix, sum = 9 ≠ 4 → count = 4

Final Answer: 4 ✓
```

---

## Key Insight

- We only consider **square** submatrices (`k×k`), not arbitrary rectangles.
- The 2D prefix sum makes each `getSum` query O(1), allowing us to check all squares efficiently.
- Top-left corner `(i, j)` and bottom-right corner `(i+k-1, j+k-1)` define each `k×k` square.
