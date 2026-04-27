# [Smallest window containing 0, 1 and 2](https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1)

## Description

Given a string `s` consisting only of the characters `'0'`, `'1'` and `'2'`, determine the length of the smallest substring that contains all three characters at least once.

If no such substring exists, return `-1`.

## Examples

**Example 1:**
```
Input: s = "10212"
Output: 3
Explanation: The substring "102" is the shortest substring that contains all three characters '0', '1', and '2', so the answer is 3.
```

**Example 2:**
```
Input: s = "12121"
Output: -1
Explanation: The character '0' is not present in the string, so no substring can contain all three characters '0', '1', and '2'. Hence, the answer is -1.
```

## Constraints:
- `1 ≤ s.size() ≤ 10^5`

<hr>

## Links
- [Solution](./Solution.cpp)
- [Approach](./Approach.md)
- [Main](./main.cpp)
