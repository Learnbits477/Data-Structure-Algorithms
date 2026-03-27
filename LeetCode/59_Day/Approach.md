# Approach - Matrix Similarity After Cyclic Shifts

## Intuition

The problem asks whether a matrix remains identical after each row is cyclically shifted $k$ times (left for even-indexed rows, right for odd-indexed rows).

### Key Insight

A cyclic shift of 1 position $k$ times is equivalent to a single cyclic shift of $k$ positions.

Let $n$ be the number of columns (length of each row).

- A left cyclic shift of $k$ positions moves the element at index $j$ to $(j - k) \pmod n$.
- A right cyclic shift of $k$ positions moves the element at index $j$ to $(j + k) \pmod n$.

For a row to be identical after a cyclic shift, the element at the new position must be equal to the element at the original position.
However, a more direct way to look at it is:
For any cyclic shift (left or right) of magnitude $k$ to result in the same row, every element $mat[i][j]$ must satisfy:
$$mat[i][j] = mat[i][(j + k) \pmod n]$$

This is because if the row is periodic with a period that divides $k$, then any shift by $k$ (left or right) will result in the same row.

### Why the direction doesn't matter?

If $mat[i][j] = mat[i][(j + k) \pmod n]$ for all $j$, then the row repeats every $k$ positions (circularly).

- Shifting right by $k$: element at $j$ moves to $(j+k) \pmod n$. Since $mat[i][j] = mat[i][(j+k) \pmod n]$, the row remains the same.
- Shifting left by $k$: element at $j$ moves to $(j-k) \pmod n$. By symmetry, if $j'$ is $(j-k) \pmod n$, then $j$ is $(j'+k) \pmod n$. So $mat[i][j'] = mat[i][(j'+k) \pmod n] = mat[i][j]$. Thus the row remains the same.

Therefore, we only need to check if $mat[i][j] == mat[i][(j + k) \pmod n]$ for all $i, j$.

## Step-by-Step Code Explanation

1. **Obtain Matrix Dimensions**:
   - Store the number of rows as `m` and columns as `n`.

2. **Normalize `k`**:
   - Use `k %= n` because shifting a row of length `n` by `n` positions results in the same row. This keeps `k` within the bounds $[0, n-1]$.

3. **Handle Edge Case ($k=0$)**:
   - If `k` is 0, the matrix remains identical, so return `true` immediately.

4. **Iterate Through Each Cell**:
   - Outer loop for each row `i` and inner loop for each column `j`.

5. **Compare Elements**:
   - Check if `mat[i][j]` is equal to `mat[i][(j + k) % n]`.
   - If any pair doesn't match, return `false` immediately.

6. **Final Result**:
   - If all elements match their shifted counterparts, return `true`.

## Complexity

- **Time Complexity:** $O(m \times n)$, where $m$ is the number of rows and $n$ is the number of columns. We iterate through every cell once.
- **Space Complexity:** $O(1)$, as we only use a few variables.
