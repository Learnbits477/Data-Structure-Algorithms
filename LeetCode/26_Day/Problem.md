# 868. Binary Gap

**Difficulty:** Easy
**Topics:** Bit Manipulation
**Link:** [LeetCode 868](https://leetcode.com/problems/binary-gap/)

---

## Problem Statement

Given a positive integer `n`, find and return the **longest distance** between any two **adjacent 1's** in the binary representation of `n`. If there are no two adjacent 1's, return `0`.

Two 1's are **adjacent** if there are only 0's separating them (possibly no 0's). The distance between two 1's is the absolute difference between their bit positions.

---

## Examples

### Example 1

```
Input:  n = 22
Output: 2
Explanation: 22 in binary is "10110".
  - Adjacent pair at positions 4 & 2 → distance = 2
  - Adjacent pair at positions 2 & 1 → distance = 1
  The largest distance is 2.
```

### Example 2

```
Input:  n = 8
Output: 0
Explanation: 8 in binary is "1000".
  There are no adjacent pairs of 1's → return 0.
```

### Example 3

```
Input:  n = 5
Output: 2
Explanation: 5 in binary is "101".
  Adjacent pair at positions 2 & 0 → distance = 2.
```

---

## Constraints

- `1 <= n <= 10^9`
