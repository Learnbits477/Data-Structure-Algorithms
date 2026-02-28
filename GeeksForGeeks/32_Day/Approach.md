# Approach: Two Pointers

Since both given arrays are already sorted, we can use the two-pointer technique to solve this problem efficiently.

1.  **Initialize Pointers:**
    - Let `l` be the pointer for the first array `arr1`, starting at the beginning (`l = 0`).
    - Let `r` be the pointer for the second array `arr2`, starting at the end (`r = arr2.size() - 1`).
2.  **Track Closest Pair:**
    - We maintain a variable `diff` initialized to infinity (`INT_MAX`) to track the minimum absolute difference between `x` and the current pair's sum.
    - We also variables `res_l` and `res_r` to store the indices of the elements forming the closest pair.
3.  **Iterate:**
    - While `l < arr1.size()` and `r >= 0`:
      - Calculate the sum of the current pair: `sum = arr1[l] + arr2[r]`.
      - If the absolute difference `abs(x - sum)` is strictly smaller than our current minimum `diff`, we update `diff`, `res_l`, and `res_r`.
      - If the `sum > x`, we need to decrease the sum to get closer to `x`. Since the arrays are sorted, we can achieve this by decrementing the pointer of the second array (`r--`).
      - If the `sum <= x`, we need to increase the sum to get closer to `x`. We do this by incrementing the pointer of the first array (`l++`).
4.  **Result:**
    - After the loop terminates, return the elements at the stored indices: `[arr1[res_l], arr2[res_r]]`.

## Complexity

- **Time Complexity:** `O(N + M)` where `N` is the size of `arr1` and `M` is the size of `arr2`. In the worst-case scenario, we traverse both arrays exactly once.
- **Space Complexity:** `O(1)` as we only use a few extra variables for pointers and tracking the minimum difference, requiring constant extra space.
