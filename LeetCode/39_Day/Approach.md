# Approach

## Intuition

The problem allows us to perform two operations:

1. Cyclic shift: moving the first character to the end.
2. Character flip: changing '0' to '1' or '1' to '0'.

A crucial observation is that performing cyclic shifts on a string `s` is equivalent to sliding a window of length `n` (where `n = s.length()`) over the concatenated string `s + s`.

There are only two possible valid alternating target strings of length `2n` (or infinitely long):

- Target 1 starts with '1': `"101010..."`
- Target 2 starts with '0': `"010101..."`

By computing the differences between the characters of `s + s` and these two infinite alternating target strings using a sliding window of length `n`, we can find the minimum number of flips needed without actually performing any string modifications.

## Algorithm

1. Let `n` be the length of the string `s`. We can simulate sliding over `s + s` by looping `i` from `0` to `2 * n - 1` and returning `s[i % n]`.
2. Maintain two difference counters: `diff1` for the first alternating sequence (starting with '1') and `diff2` for the second (starting with '0').
3. For each index `i`:
   - Determine the expected characters for the targets at index `i`: `alt1 = (i % 2 == 0) ? '1' : '0'` and `alt2 = (i % 2 == 0) ? '0' : '1'`.
   - If `s[i % n] != alt1`, increment `diff1`.
   - If `s[i % n] != alt2`, increment `diff2`.
4. If the window has exceeded size `n` (which happens when `i >= n`), we need to shrink it by removing the element at `i - n`.
   - Calculate what the expected characters were for index `i - n`.
   - If `s[(i - n) % n]` didn't match the expectation, decrement the respective difference counter.
5. If the window size is exactly `n` (which happens when `i >= n - 1`), record the minimum of `diff1` and `diff2` to update our global answer.

## Complexity

- **Time Complexity:** $O(N)$, where $N$ is the length of `s`, since we just cycle $2N$ times handling math checking.
- **Space Complexity:** $O(1)$, since we don't physically create the string `s + s` or any full target string arrays. We determine the needed character mathematically on-the-fly.
