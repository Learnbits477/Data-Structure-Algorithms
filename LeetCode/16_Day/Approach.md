# Approach: Optimized Brute Force

## Intuition

The problem asks for the longest valid balanced substring. A balanced substring means all distinct characters strictly appear the same number of times.
The constraints are $N \le 1000$, which suggests that an $O(N^2)$ algorithm should be acceptable.

We can iterate over all possible starting positions of a substring and for each start, extend the substring to the right. As we extend, we maintain the frequency of each character.

## Algorithm

1. Initialize `maxLen = 0`.
2. Iterate `i` from `0` to `n-1` (start index).
3. Initialize a frequency map (or array of size 26) `count` to zeros.
4. Maintain `maxFreq` (maximum frequency of any character in the current window) and `distinctCount` (number of unique characters).
5. Iterate `j` from `i` to `n-1` (end index).
    - Update the frequency of `s[j]`.
    - If `count[s[j]]` becomes 1, increment `distinctCount`.
    - Update `maxFreq` with `count[s[j]]`.
    - **Check Condition:** If `distinctCount * maxFreq == (j - i + 1)`, it means all present characters have the same frequency (which must be `maxFreq`).
    - If valid, update `maxLen = max(maxLen, j - i + 1)`.
6. Return `maxLen`.

## Complexity

- **Time Complexity:** $O(N^2)$, where $N$ is the length of the string. We have nested loops, and inside the inner loop, all operations are $O(1)$.
- **Space Complexity:** $O(1)$ (or $O(26)$) for the frequency array.
