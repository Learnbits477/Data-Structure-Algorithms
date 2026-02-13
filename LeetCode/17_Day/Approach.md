# Approach: Longest Balanced Substring II

The problem asks for the longest substring where all _distinct_ characters appear the same number of times. Since the string only contains 'a', 'b', and 'c', the number of distinct characters in any substring can be 1, 2, or 3.

We can solve this by considering each case separately and taking the maximum length found.

## Case 1: 1 Distinct Character

The substring must consist of only one type of character (e.g., "aaaa").

- **Algorithm:** Iterate through the string and find the longest contiguous segment of identical characters.
- **Example:** "aaabb" -> max length 3 ("aaa").

## Case 2: 2 Distinct Characters

The substring must consist of exactly two types of characters (e.g., 'a' and 'b') appearing the same number of times. The third character must NOT be present.

- **Pairs to check:** (a, b), (b, c), (c, a).
- **Algorithm for pair (u, v) ignoring w:**
  1. Iterate through `s`.
  2. If we encounter `w`, the current substring is invalid. Reset counters and start a new potential substring after this position.
  3. Maintain the balance `bal = count(u) - count(v)`.
  4. Use a hash map (or array) `seen` to store the first index where each `bal` occurred. Initialize `seen[0] = -1`.
  5. If `bal` has been seen before at index `j`, then the substring `s[j+1...i]` has `count(u) == count(v)`. Update max length `i - j`.
  6. If `bal` has not been seen, store `seen[bal] = i`.
- This is equivalent to finding the longest subarray with sum 0 if we map `u -> 1` and `v -> -1`.

## Case 3: 3 Distinct Characters

The substring must consist of 'a', 'b', and 'c', all appearing the same number of times.

- **Algorithm:**
  1. Iterate through `s` and maintain running counts `ca`, `cb`, `cc`.
  2. We want a substring `s[j+1...i]` where `ca[i]-ca[j] == cb[i]-cb[j] == cc[i]-cc[j]`.
  3. This condition is equivalent to:
     `ca[i] - cb[i] == ca[j] - cb[j]` AND `cb[i] - cc[i] == cb[j] - cc[j]`.
  4. Store the pair of differences `diffs = {ca - cb, cb - cc}` in a map `seen`.
  5. Initialize `seen[{0, 0}] = -1`.
  6. At each index `i`, check if the current `diffs` pair has been seen before at index `j`.
  7. If yes, the substring `s[j+1...i]` has equal counts of a, b, and c. Since count must be same and length > 0, each count must be > 0, ensuring 3 distinct characters.
  8. Update max length `i - j`.

## Complexity

- **Time Complexity:** O(N). Each pass (Case 1, three Case 2s, Case 3) takes O(N) time.
- **Space Complexity:** O(N) to store the hash maps for indices.

## Implementation Details

We can implement this using helper functions to keep the code clean.

- `solve1(s)`: solves for 1 distinct char.
- `solve2(s, char c1, char c2, char forbidden)`: solves for 2 distinct chars.
- `solve3(s)`: solves for 3 distinct chars.
  The final answer is `max(solve1, solve2(a,b,c), solve2(b,c,a), solve2(a,c,b), solve3)`.
