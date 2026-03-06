# Approach for Check if Binary String Has at Most One Segment of Ones

## Intuition

The problem states that the string `s` contains no leading zeros, which implies `s` always starts with `'1'` (i.e., `s[0] == '1'`).
Since we want to check if the string has at most one segment of ones, all the ones must be part of that initial block starting from the first character.
If there's any other segment of ones, the string must contain a `'0'` followed by a `'1'` somewhere. Thus, checking for existence of the substring `"01"` in `s` is sufficient. If `"01"` exists, there are multiple segments of ones. Otherwise, there is at most one.

## Algorithm

1. Check if the substring `"01"` is present in the string `s`.
2. Return `true` if it is not present, otherwise return `false`.

## Complexity

- **Time Complexity:** $O(N)$, where $N$ is the length of the string `s`. We scan the string once to find `"01"`.
- **Space Complexity:** $O(1)$. We do not use any extra space that scales with input size.
