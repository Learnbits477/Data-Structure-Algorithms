# Approach: Direct Simulation

## Intuition

The problem requires performing range-based multiplication queries on an array and returning the final bitwise XOR sum. Given the constraints ($N, Q \le 1000$), a direct simulation is efficient enough. The total number of multiplications across all queries will be at most $O(N \times Q) \approx 10^6$, which fits comfortably within the time limit.

## Step-by-Step Logic

### 1. Processing Queries
For each query $[l_i, r_i, k_i, v_i]$, we iterate through the array at specific intervals:
- Starting point: `li`
- Jump size: `ki`
- End limit: `ri`

### 2. Modulo Multiplication
For each targeted index, we update the value:
`nums[idx] = (nums[idx] * vi) % (10^9 + 7)`
Since `nums[idx]` can be up to $10^9$ and `vi` up to $10^5$, their product can exceed $2^{31}-1$. We use `long long` for the multiplication to avoid overflow before applying the modulo.

```cpp
nums[idx] = (1LL * nums[idx] * vi) % 1000000007;
```

### 3. Final XOR Sum
Once all queries are processed, we iterate through the final array and calculate the XOR sum of all elements.

```cpp
int result = 0;
for (int num : nums) {
    result ^= num;
}
```

## Complexity

- **Time Complexity:** $\mathcal{O}(Q \times N)$
  - Each of the $Q$ queries can traverse up to $N/K$ elements. In the worst case ($K=1$), we visit $N$ elements per query.
- **Space Complexity:** $\mathcal{O}(1)$
  - The array is modified in-place, and only a constant amount of extra memory is used for iteration and result storage.
