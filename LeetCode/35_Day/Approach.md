# Approach

We can solve this problem using recursion based on the structural properties of $S_n$.

## Observations:

The string $S_n$ is constructed as: $S_{n-1} + \text{"1"} + \text{reverse}(\text{invert}(S_{n-1}))$.
The length of $S_n$ is $2^n - 1$.
The middle character of $S_n$ is always '1' (at position $2^{n-1}$).
The first half of $S_n$ is exactly $S_{n-1}$.
The second half of $S_n$ is the reverse and inverted version of $S_{n-1}$.

Therefore, to find the $k$-th bit in $S_n$:

1.  **Base Case:** If $n = 1$, the string is "0", so we return '0'.
2.  **Middle Bit:** If $k$ is exactly the middle position, $k = 2^{n-1}$, we return '1'.
3.  **First Half:** If $k < 2^{n-1}$, the bit is within the first half, which is identical to $S_{n-1}$. We simply recursively call the function for $S_{n-1}$ with the same $k$: `findKthBit(n - 1, k)`.
4.  **Second Half:** If $k > 2^{n-1}$, the bit is in the second half. Since the second half is reversed and inverted, the bit at position $k$ in $S_n$ corresponds to the bit at position $2^n - k$ in $S_{n-1}$, but inverted. So, we recursively find the bit at position $2^n - k$ in $S_{n-1}$ and invert the result. `length - k + 1` corresponds to $2^n - 1 - k + 1 = 2^n - k$.

## Complexity:

- **Time Complexity:** $\mathcal{O}(n)$, as each recursive step reduces $n$ by $1$ and takes $\mathcal{O}(1)$ time. Since $n \le 20$, it takes at most 20 steps.
- **Space Complexity:** $\mathcal{O}(n)$ due to the call stack size limit, which is bounded by $20$.
