# Approach: Dynamic Programming

## Intuition
The problem tasks us with finding the maximum path sum from the top-left to the bottom-right of a grid. However, we have a "power-up": the ability to neutralize up to two negative cells (robbers). Therefore, at any cell `(i, j)`, we need to track not only our position but also how many neutralizations `k` (0, 1, or 2) we have used so far. This calls for a 3D Dynamic Programming array.

## Step-by-Step Implementation

### Step 1: Initialize the DP Table
We allocate a 3D DP array `dp[i][j][k]`, where `i` and `j` represent the position on the grid, and `k` designates exactly how many neutralizations were executed. We fill it with `-INF` initially since some states may be unreachable.

```cpp
int m = coins.size();
int n = coins[0].size();
const int INF = 1e9;

// dp[i][j][k] represents the max profit at (i, j) using exactly k neutralizations.
vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -INF)));
```

### Step 2: Base Cases
We initialize the starting cell `(0, 0)`. If the starting cell is a positive coin or `0`, we just collect it utilizing `0` neutralizations. If it's a negative value (robber), we can choose to neutralize it locally immediately, requiring `1` neutralization to earn a profit of `0`.

```cpp
// Base case initialization for the starting cell
dp[0][0][0] = coins[0][0];
if (coins[0][0] < 0) {
    dp[0][0][1] = 0;
}
```

### Step 3: Iterate and Pull from Previous Cells
Since the robot can only move **Right** and **Down**, we can iterate over the grid logically array by array using nested loops. For any valid `(i, j)`, the most profitable path so far must originate from its top neighbor `(i - 1, j)` or its left neighbor `(i, j - 1)` containing the equivalent amount of `k` neutralizations.

```cpp
for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
        if (i == 0 && j == 0) continue; // Skip starting cell
        
        for (int k = 0; k < 3; ++k) {
            // Find the maximum from reachable neighbor cells (top and left)
            int prev = -INF;
            if (i > 0) prev = max(prev, dp[i - 1][j][k]);
            if (j > 0) prev = max(prev, dp[i][j - 1][k]);
```

### Step 4: Option A - Move normally (No Neutralization Used Here)
If previous paths were theoretically accessible (`prev != -INF`), we assess what happens if we simply step into the current grid cell without trying to shield ourselves. We earn the default `coins[i][j]`.

```cpp
            // Case 1: Do not use a neutralization at the current cell.
            if (prev != -INF) {
                dp[i][j][k] = max(dp[i][j][k], prev + coins[i][j]);
            }
```

### Step 5: Option B - Neutralize Current Cell
If the cell presently houses a robber (`coins[i][j] < 0`) and our currently iterated `k > 0` (meaning this step uses a neutralization), we can safely "cancel out" the loss by using a charge. Using a charge translates to querying the prior neighbor cells for the maximum sum with `k - 1` neutralizations. We add zero monetary value.

```cpp
            // Case 2: Use a neutralization at the current cell.
            if (coins[i][j] < 0 && k > 0) {
                int prev_k = -INF;
                if (i > 0) prev_k = max(prev_k, dp[i - 1][j][k - 1]);
                if (j > 0) prev_k = max(prev_k, dp[i][j - 1][k - 1]);
                
                if (prev_k != -INF) {
                    dp[i][j][k] = max(dp[i][j][k], prev_k);
                }
            }
        }
    }
}
```

### Step 6: Find Maximum Across Final States
Once iteration reaches the bottom-right coordinate `(m - 1, n - 1)`, our final answer can be fetched. Since any total number of completed neutralizations (0, 1, or 2) is applicable, we check all of them via `k` and seize the maximum.

```cpp
// Final aggregate answer across all utilization combinations
int ans = -INF;
for (int k = 0; k < 3; ++k) {
    ans = max(ans, dp[m - 1][n - 1][k]);
}
return ans;
```

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(m \times n \times 3) = \mathcal{O}(m \cdot n)$. Evaluating cells up to a limit grid of $500 \times 500 \times 3$, resulting in negligible constants (under $10^6$ operations) resolving practically instantaneously in C++.
- **Space Complexity:** $\mathcal{O}(m \cdot n)$ to preserve the complete 3D DP state memory, taking approximately 3MB.
