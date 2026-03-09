# Approach: Tracking Rightmost Positions

To get the lexicographically largest string with at most one swap, we want to replace an early digit with the largest possible digit that appears later in the string. If there are multiple occurrences of that largest digit, we should pick its rightmost occurrence (the one with the largest index). This guarantees that we make the resulting string as large as possible.

## Steps:

1. Create an array `last` of size 10 to store the index of the rightmost occurrence of each digit (0-9) in the string `s`.
2. Iterate through the string from left to right to build this `last` array.
3. Then iterate through the string again from left to right (using index `i`).
4. For each character `s[i]`, iterate backwards through the digits `d` from 9 down to `s[i] - '0' + 1`.
5. If we find a higher digit `d` whose rightmost occurrence index `last[d]` is greater than `i`, we have found our swap. We swap `s[i]` with `s[last[d]]`, and immediately break out of all loops since we are only allowed at most one swap.
6. Return the string `s`.

## Complexity:

- **Time Complexity:** $O(|s|)$, where $|s|$ is the length of the string. The first pass to find rightmost indices takes $O(|s|)$. The second loop takes at most $O(|s| \times 10)$, which simplifies to $O(|s|)$.
- **Space Complexity:** $O(1)$, as we only use an array `last` of fixed size 10 to store indices.
