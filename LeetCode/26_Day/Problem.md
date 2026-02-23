# 1461. Check If a String Contains All Binary Codes of Size K

**Difficulty:** Medium  
**Topic:** Hashing, Bit Manipulation, String  
**Source:** [LeetCode](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/?envType=daily-question&envId=2026-02-23)

---

## Problem Statement

Given a binary string `s` and an integer `k`, return `true` if every binary code of length `k` is a substring of `s`. Otherwise, return `false`.

---

## Examples

### Example 1

```
Input:  s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11".
             They can all be found as substrings at indices 0, 1, 3 and 2 respectively.
```

### Example 2

```
Input:  s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", both exist as substrings.
```

### Example 3

```
Input:  s = "0110", k = 2
Output: false
Explanation: The binary code "00" of length 2 does not exist in the string.
```

---

## Constraints

- `1 <= s.length <= 5 * 10^5`
- `s[i]` is either `'0'` or `'1'`
- `1 <= k <= 20`
