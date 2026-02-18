# Approach: Check Alternating Bits

## Intuition

If a number has alternating bits (e.g., `10101`), then shifting it right by 1 bit (`01010`) and XORing with the original number will result in a number with all bits set to 1 (`11111`).

## Algorithm

1. Calculate `x = n ^ (n >> 1)`.
2. Check if `x` contains all 1s.
   - We can do this by checking if `x & (x + 1) == 0`.
   - For example, if `x` is `111` (7), `x + 1` is `1000` (8), and `7 & 8 == 0`.

## Example

**Input:** `n = 5` (101)

1. `n >> 1` = `010` (2)
2. `x = n ^ (n >> 1)` = `101 ^ 010` = `111` (7)
3. `x + 1` = `8` (1000)
4. `x & (x + 1)` = `0111 & 1000` = `0`
5. Return `true`.

**Input:** `n = 7` (111)

1. `n >> 1` = `011` (3)
2. `x = n ^ (n >> 1)` = `111 ^ 011` = `100` (4)
3. `x + 1` = `5` (101)
4. `x & (x + 1)` = `100 & 101` = `100` != `0`
5. Return `false`.

## Complexity Analysis

- **Time Complexity:** O(1) - Bitwise operations are constant time.
- **Space Complexity:** O(1) - No extra space used.
