# [1009. Complement of Base 10 Integer](https://leetcode.com/problems/complement-of-base-10-integer/description/?envType=daily-question&envId=2026-03-06)

## Intuition

The problem asks us to find the complement of a base-10 integer. The complement is obtained by flipping all `0`s to `1`s and `1`s to `0`s in its binary representation. This is exactly what the bitwise NOT operator (`~`) does, but it flips all 32 bits of an integer. We only want to flip the bits that correspond to the binary representation of `n`. Therefore, we can create a `mask` that has `1`s exactly for the length of the binary representation of `n`, and apply it to `~n` using bitwise AND (`&`).

## Approach

1. **Edge Case**: If `n == 0`, its binary representation is `"0"`, and its complement is `"1"`. Return `1`.
2. **Find the Mask**: Create a variable `mask` initialized to `0`. We also use a temporary variable `m` to simulate finding the length of `n`.
3. In a loop, as long as `m != 0`, we shift `mask` left by 1 and set the least significant bit to `1` (`mask = (mask << 1) | 1`), and then we right-shift `m` by 1 (`m = m >> 1`). This builds a mask of all `1`s of the same length as `n`.
4. **Calculate Complement**: Perform `~n & mask` to get the final complemented value. The `~n` flips all 32 bits, and the `& mask` ensures we only consider the relevant bits.

## Complexity

- **Time Complexity:** $O(\log n)$, as we process the bits of `n` by shifting it right. The number of bits is proportional to $\log_2(n)$.
- **Space Complexity:** $O(1)$, since we only use a few integer variables.
