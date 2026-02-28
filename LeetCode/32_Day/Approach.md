# Approach for 1680. Concatenation of Consecutive Binary Numbers

## Intuition

The problem asks us to concatenate the binary strings of numbers from `1` to `n` and find the decimal value modulo `10^9 + 7`.
When we concatenate the binary representation of a number `X` to the existing result `ans`, it is equivalent to shifting the binary representation of `ans` to the left by the number of bits in `X`, and then adding `X`.

## Algorithm

1. Initialize `ans = 0` and `MOD = 10^9 + 7`.
2. Iterate `i` from `1` to `n`.
3. To efficiently find the number of bits in `i`, maintain a variable `len` which keeps track of the current bit length. We increment `len` whenever `i` is a power of 2 (i.e., `(i & (i - 1)) == 0`), because powers of 2 (1, 2, 4, 8, ...) are exactly the points at which the binary string length increases by 1.
4. Update `ans`: shift `ans` left by `len` bits, perform bitwise OR with `i` (or add `i`), and take modulo `MOD`.
   - `ans = ((ans << len) | i) % MOD`
5. Return the final `ans` converted to an integer.

## Complexity

- **Time Complexity:** $O(n)$, we only iterate from `1` to `n` once and perform bitwise operations which take $O(1)$ time.
- **Space Complexity:** $O(1)$, only using a few extra variables for accumulation.
