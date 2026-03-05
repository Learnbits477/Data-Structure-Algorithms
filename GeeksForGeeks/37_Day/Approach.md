# Approach

We can solve this problem using the Sliding Window technique with two pointers, `l` (left) and `r` (right), and a frequency array to keep track of the number of distinct characters in the current window.

1.  Initialize a frequency array `count` of size 26 to `0`. Use `unique_count` to keep track of the number of distinct characters in the current window. Initialize `max_len` to `-1`.
2.  Iterate over the string `s` using the right pointer `r` from `0` to the end of the string.
3.  For each character `s[r]`, if it appears for the first time in the current window (i.e., its frequency in the `count` array is `0`), increment `unique_count`. Then, increment the frequency of `s[r]` in `count`.
4.  If `unique_count` exceeds `k`, it means the window has more than `k` distinct characters. We need to shrink the window from the left by moving the `l` pointer until `unique_count` becomes equal to (or less than) `k`.
    - While `unique_count > k`, decrement the frequency of `s[l]`.
    - If the frequency of `s[l]` becomes `0`, decrement `unique_count`.
    - Increment `l`.
5.  If `unique_count` is exactly equal to `k`, update `max_len` with the maximum of the current `max_len` and the window size `(r - l + 1)`.
6.  Continue this process until `r` reaches the end of the string.
7.  Return `max_len`.

**Time Complexity:** O(N), where N is the length of the string. Both `l` and `r` traverse the string at most once.
**Space Complexity:** O(1), since the size of the frequency array `count` is fixed to `26` for lowercase English letters.
