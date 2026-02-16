# Approach: Reverse Bits

## Intuition

The problem asks us to reverse the bits of a 32-bit unsigned integer. This can be achieved by iterating through all 32 bits of the input integer `n`, extracting the `i`-th bit, and placing it in the `(31-i)`-th position in the result.

## Algorithm

1. Initialize a variable `res` (result) to 0.
2. Loop from `i = 0` to `31`:
    - Extract the `i`-th bit of `n` using `(n >> i) & 1`.
    - Shift this extracted bit to the `(31-i)`-th position by left shifting `((n >> i) & 1) << (31 - i)`.
    - Add (or bitwise OR) this shifted bit to `res`.
3. Return `res`.

Alternatively, we can iterate and build `res` bit by bit:

1. Initialize `res = 0`.
2. Loop `i` from 0 to 31:
    - Shift `res` to the left by 1: `res = res << 1`.
    - If the current LSB of `n` is 1 (`n & 1`), add 1 to `res` (or `res = res | 1` or `res++` or `res ^= 1`).
    - Shift `n` to the right by 1: `n = n >> 1`.
3. Return `res`.

## Complexity Analysis

- **Time Complexity:** O(1), since we always iterate 32 times regardless of the input value.
- **Space Complexity:** O(1), as we only use a few variables for storage.

## Code Implementation

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 1) {
                res |= (1 << (31 - i));
            }
        }
        return res;
    }
};
```
