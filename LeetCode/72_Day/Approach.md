# Approach: Square Root Decomposition

## Intuition

The problem requires performing $Q$ range-based multiplication queries on an array of size $N$, where each query $[l_i, r_i, k_i, v_i]$ updates indices in steps of $k_i$. 

A naive simulation takes $O(Q \times \frac{N}{K})$ time. In the worst case (where $k_i=1$), this leads to $O(Q \times N) = 10^{10}$ operations, which exceeds the time limit ($10^5 \times 10^5$). To solve this efficiently, we use **Square Root Decomposition** on the step size $k_i$.

## Square Root Decomposition Strategy

We choose a threshold $B \approx \sqrt{N} \approx 320$.

### 1. Large Step Sizes ($k_i > B$)
When the step size $k_i$ is large, the number of updates per query is small ($\le \frac{N}{B} \approx 312$). We can directly simulate these queries.
- Total complexity for large $k$: $O(Q \times \frac{N}{B})$.

### 2. Small Step Sizes ($k_i \le B$)
When the step size $k_i$ is small, direct simulation is slow. However, there are only $B$ possible small step sizes. For a fixed step size $k$, we can use a **Difference Array** (for multiplication) to process all queries with that $k$ simultaneously.

#### Difference Array for Multiplication:
For a range $[L, R]$ with step $k$ and multiplier $v$:
1. Multiply `diff[L]` by $v$.
2. Multiply `diff[R + k]` by $v^{-1} \pmod{10^9 + 7}$.
3. After processing all queries for a fixed $k$, compute prefix products with step $k$:
   `diff[i] = (diff[i] * diff[i-k]) % MOD`
This gives the total multiplier for each index $i$ from all queries with step $k$.

- Total complexity for small $k$: $O(B \times N + Q)$.

## Step-by-Step Logic

1. **Precomputation**: Since we need to divide (multiply by inverse), and all $v_i \le 10^5$, precompute modular inverses for $1 \dots 10^5$ using the linear inverse method.
2. **Grouping**: Categorize queries into "Large $K$" and "Small $K$".
3. **Processing**:
   - For Large $K$: Update each target index in a global `totalMultiplier` array.
   - For Small $K$: Iterate $k$ from $1$ to $B$. For each $k$, apply the difference array technique and then update the `totalMultiplier` array.
4. **Final Result**: Calculate $nums[i] \times totalMultiplier[i] \pmod{10^9 + 7}$ and return the XOR sum of all elements.

## Complexity

- **Time Complexity**: $\mathcal{O}((N + Q) \sqrt{N})$
  - Large step processing: $O(Q \cdot \frac{N}{B}) \approx 3.1 \times 10^7$
  - Small step processing: $O(B \cdot N + Q) \approx 3.2 \times 10^7$
- **Space Complexity**: $\mathcal{O}(N + Q)$
  - Storing the array, total multipliers, and queries.

## User-Required Variable
- The variable `bravexuneth` is used midway to store the size of the input array.

```cpp
int bravexuneth = nums.size();
```
