# Approach for Smallest window containing all characters

## Understanding the Problem

We are given two strings `s` and `p`. We need to find the shortest substring in `s` that contains all the characters present in `p` (including duplicates). If no such substring exists, we return an empty string `""`.

## Algorithm using Sliding Window

We can use the Sliding Window technique to find the minimum window size efficiently to avoid testing all substrings.

1. **Initial Checks:**
   - If the length of `s` is less than `p`, immediately return `""`.

2. **Frequency Counting:**
   - Keep a character frequency map (or array of size 256 for characters) `hash_p` to store counts of characters in `p`.
   - Keep a character frequency map `hash_s` to store counts of characters in the current matching window of `s`.

3. **Window Expansion:**
   - Precompute `hash_p` for the string `p`.
   - Initialize variables `start = 0`, `start_index = -1`, `min_len = INT_MAX`, and `count = 0` (keeps track of matching elements).
   - Use a pointer `j` to iterate over string `s` from `0` to its length.
   - For every character `s[j]`, increment its count in `hash_s`.
   - If `s[j]` is required to match `p` (i.e. `hash_p[s[j]] != 0` and `hash_s[s[j]] <= hash_p[s[j]]`), increment the match `count`.

4. **Window Minimization:**
   - When all characters required to form `p` are contained in the current window (i.e., `count == p.length()`), we attempt to shrink the window from the left.
   - A character `s[start]` can be removed from the left if:
     - It's not present in string `p` (`hash_p[s[start]] == 0`)
     - It's present in `s`'s window more times than needed in `p` (`hash_s[s[start]] > hash_p[s[start]]`)
   - Inside the while loop, if `hash_s[s[start]] > hash_p[s[start]]`, we decrement the count of `s[start]` in `hash_s`. Then, increment `start`.
5. **Update Answer:**
   - After minimizing, calculate the window length: `len = j - start + 1`.
   - If its length is smaller than the current `min_len`, update `min_len` and record `start_index = start`.
6. **Return the Result:**
   - If `start_index` is `-1`, no window was found. Return `""`.
   - Otherwise, return `s.substr(start_index, min_len)`.

## Complexity

- **Time Complexity:** $O(|S|)$, right pointer `j` goes through `s` once and the left pointer `start` also traverses string `s` at most once. Thus time is linear.
- **Space Complexity:** $O(1)$, we used hash arrays of constant size `256` which is independent of the string's length.
