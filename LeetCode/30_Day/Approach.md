# Approach - Number of Steps to Reduce a Binary Number to One

### Method: Bit Manipulation on String (Right to Left)

Instead of converting the binary string to an integer (which can overflow for large inputs up to 500 bits), we simulate the operations **directly on the binary string** from right to left.

Key observations:

- **Even** number → last bit is `0` → dividing by 2 = right shift = remove last bit → **1 step**
- **Odd** number → last bit is `1` → adding 1 may cause a carry propagation through consecutive `1`s

**Algorithm:**

1. Start from the rightmost bit with a `carry = 0`.
2. Traverse from `i = n-1` down to `i = 1` (stop at index 1, since index 0 is always `'1'` = leading bit):
   - Compute `bit = (s[i] - '0') + carry`
   - If `bit % 2 == 1` (odd) → we need to add 1 → steps += 2 (one for add, one for divide), carry = 1
   - If `bit % 2 == 0` (even) → we just divide → steps += 1, carry stays same
3. Add `carry` to steps at the end (in case the leading bit causes a final carry/extra step).

### Complexity

- **Time Complexity:** `O(N)` — single pass over the string
- **Space Complexity:** `O(1)` — no extra space used
