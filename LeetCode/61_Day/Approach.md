# [Approach - Check if Strings Can be Made Equal With Operations I](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/)

## Problem Understanding

- We are given two strings `s1` and `s2` of length 4.
- We can swap characters in a string at indices `i` and `j` if `|i - j| = 2`.
- Since the strings have length 4, the only possible swaps are:
  - `s[0]` with `s[2]`
  - `s[1]` with `s[3]`
- We can perform these swaps any number of times.

## Logic

- Because we can swap `s[0]` and `s[2]` any number of times, we can essentially place either of the two characters in index 0 and the other in index 2.
- Similarly, we can swap `s[1]` and `s[3]` to place either in index 1 and the other in index 3.
- Thus, `s1` can be made equal to `s2` if and only if:
  1. The multiset of characters at indices {0, 2} in `s1` is identical to the multiset of characters at indices {0, 2} in `s2`.
  2. The multiset of characters at indices {1, 3} in `s1` is identical to the multiset of characters at indices {1, 3} in `s2`.

## Implementation Details

- For indices {0, 2}:
  - Check if `(s1[0] == s2[0] && s1[2] == s2[2])` OR `(s1[0] == s2[2] && s1[2] == s2[0])`.
- Repeat similar logic for indices {1, 3}.
- If both conditions are met, return `true`; otherwise, return `false`.

## Complexity

- **Time Complexity:** O(1), as the strings are always of length 4.
- **Space Complexity:** O(1).

---

### Implementation (C++)

```cpp
/*
 * Problem: 2839. Check if Strings Can be Made Equal With Operations I
 * Link: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
```
