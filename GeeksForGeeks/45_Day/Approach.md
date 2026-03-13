# Approach for Generate IP Addresses

## Problem Analysis
We need to generate all possible valid IPv4 addresses from a given string of digits `s`.
A valid IPv4 address consists of exactly 4 parts, separated by dots.
Each part:
1. Must be a number between `0` and `255` (inclusive).
2. Cannot have leading zeros unless the part is exactly `"0"`.

Since the required output is all valid combinations and the string length is small (up to 16), **Backtracking** is an ideal and standard approach.

## Backtracking Strategy
1. We use a recursive function `solve(index, parts, current_ip)` that explores forming valid parts from the string using the characters starting at `index`.
2. `parts` keeps track of how many parts we have formed so far.
3. `current_ip` stores the IP string built up to the current stage.
4. From the `index`, we try to form parts of length `1`, `2`, and `3`:
   - Extract the substring `num`.
   - Check its validity: it must be `≤ 255`.
   - If valid, recursively call `solve` with updated parameters: `index = i + 1`, `parts = parts + 1`, `current_ip = current_ip + num + "."`.
   - To handle the leading zero constraint, if the first character of `num` is `'0'`, we must `break` after the first iteration to prevent forming invalid numbers like `"01"`, `"00"`, etc.
5. Base Case:
   - If `index == s.length()` and `parts == 4`, it means we have successfully consumed the entire string and formed exactly 4 parts. The `current_ip` is appended to our results (after removing the trailing dot).
   - If we reach the end of the string (`index == s.length()`) but `parts < 4`, or if we have `parts == 4` but haven't reached the end of the string, the configuration is invalid, and we backtrack (return).

## Complexity
- **Time Complexity:** $O(3^4) = O(1)$ since an IP address has exactly 4 parts and each part can be at most 3 digits long. In the worst case, we explore up to 3 branches for 4 levels. This is a very small constant number of operations. String operations take tiny constant time. Overall, constant time complexity $O(1)$.
- **Space Complexity:** $O(1)$ auxiliary space except for the space required to store the valid IP combinations in the result list `res`, and the recursion call stack which goes up to a maximum depth of 4.
