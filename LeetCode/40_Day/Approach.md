# Approach for Find Unique Binary String

## Cantor's Diagonalization

The problem asks us to find a binary string of length `n` that is not present in an array `nums` of `n` unique binary strings of length `n`.

A very elegant and efficient way to solve this is using **Cantor's Diagonalization Argument**.
The idea is to construct a new string character by character such that the `i`-th character of the new string is different from the `i`-th character of the `i`-th string in `nums`.

Since the new string differs from the 1st string at index 0, from the 2nd string at index 1, ..., and from the `n`-th string at index `n-1`, it is guaranteed to be different from every string in the `nums` array.

### Complexity

- **Time Complexity:** `O(n)` where `n` is the number of strings. We iterate over the array exactly once, accessing the `i`-th character of the `i`-th string.
- **Space Complexity:** `O(1)` or `O(n)` if considering the space required to store the resulting string of length `n`.
