# 1404. Number of Steps to Reduce a Number in Binary Representation to One

[Problem Link](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/)

**Difficulty**: Medium

Given the binary representation of an integer as a string `s`, return the number of steps to reduce it to `1` under the following rules:

- If the current number is **even**, divide it by `2`.
- If the current number is **odd**, add `1` to it.

It is guaranteed that you can always reach `1` for all test cases.

### Examples

**Input**: `s = "1101"`
**Output**: `6`
**Explanation**: `"1101"` corresponds to `13`.

- Step 1) 13 is odd → add 1 → 14
- Step 2) 14 is even → divide by 2 → 7
- Step 3) 7 is odd → add 1 → 8
- Step 4) 8 is even → divide by 2 → 4
- Step 5) 4 is even → divide by 2 → 2
- Step 6) 2 is even → divide by 2 → 1

**Input**: `s = "10"`
**Output**: `1`
**Explanation**: `"10"` corresponds to `2`. Step 1) divide by 2 → 1.

**Input**: `s = "1"`
**Output**: `0`

### Constraints

- `1 <= s.length <= 500`
- `s` consists of characters `'0'` or `'1'`
- `s[0] == '1'`
