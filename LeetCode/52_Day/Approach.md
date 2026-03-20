# Approach for 3567. Minimum Absolute Difference in Sliding Submatrix

## Problem Statement
Given an `m x n` integer matrix `grid` and an integer `k`, compute the return a 2D array `ans` where `ans[i][j]` contains the minimum absolute difference between distinct elements in the `k x k` submatrix with top-left corner at `(i, j)`. If all elements in the submatrix are the same, the answer should be `0`.

## Intuition
A naive brute-force approach processes each `k x k` submatrix by checking all pairs uniquely within the submatrix (`O(k^4)` per submatrix). Since `m, n <= 30` and `k <= 30`, this takes too many operations and could lead to Time Limit Exceeded (TLE). 
A better intuition is to realize that the minimum absolute difference between elements is always found between two adjacent elements when the elements are sorted. By extracting the elements of each submatrix into a 1D vector and sorting them, we can find the minimum absolute difference between distinct adjacent elements in `O(K^2 \log K)` time per submatrix.

## Approach
1. Initialize a 2D `ans` vector of dimensions `(m - k + 1) x (n - k + 1)`.
2. Allocate a 1D `vals` vector of size `k * k` outside the loops to avoid repeated reallocations.
3. For each possible top-left cell `(i, j)` of a `k x k` submatrix:
   - Extract the entire submatrix elements into the `vals` vector sequentially.
   - Sort the `vals` vector in ascending order.
   - Initialize `minDiff` to `INT_MAX`.
   - Iterate through `vals` from `p = 1` to `p < k * k`. Whenever `vals[p] != vals[p - 1]`, update `minDiff` with `min(minDiff, vals[p] - vals[p - 1])`.
   - If `minDiff` remains `INT_MAX` (meaning all items were the same), set `ans[i][j] = 0`. Otherwise, set `ans[i][j] = minDiff`.
4. Return the `ans` matrix.

## Complexity
- **Time Complexity:** `O((M - K + 1) * (N - K + 1) * K^2 \log(K^2))`. The outer loops run for each sliding window position. For each window, sorting takes `O(K^2 \log(K^2))` and sequential traversal takes `O(K^2)`. Since `M \le 30` and `N \le 30`, `K \le 30`, total operations are nicely bounded around `8 \times 10^6`, completely satisfying the standard 1-second `10^8` C++ execution limit.
- **Space Complexity:** `O(K^2)` for storing the `vals` array for sorting elements of individual submatrices. The `ans` output matrix is technically `O((M-K+1) * (N-K+1))` space. Overall auxiliary space apart from the result structure is `O(K^2)`.
