# Approach

## Intuition

The problem asks us to add two binary strings. This is similar to adding two decimal numbers, but with base 2. We can perform addition bit by bit from right to left, maintaining a carry.

## Algorithm

1. Initialize an empty string `res` to store the result.
2. Initialize pointers `i` and `j` to the end of strings `a` and `b` respectively.
3. Initialize `carry` to 0.
4. Loop while `i >= 0` or `j >= 0` or `carry > 0`:
    - Calculate `sum` = `carry`.
    - If `i >= 0`, add `a[i]` (converted to int) to `sum` and decrement `i`.
    - If `j >= 0`, add `b[j]` (converted to int) to `sum` and decrement `j`.
    - Update `carry` = `sum / 2`.
    - Append `sum % 2` to `res`.
5. Reverse `res` since we appended bits from least significant to most significant.
6. Return `res`.

## Complexity

- **Time Complexity:** O(max(N, M)), where N and M are lengths of strings `a` and `b`. We iterate through the strings once.
- **Space Complexity:** O(max(N, M)) to hold the result.
