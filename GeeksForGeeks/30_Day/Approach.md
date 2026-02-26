## Approach for Isomorphic Strings

### Method: Bidirectional HashMap Mapping

To determine if two strings are isomorphic, we need a **two-way** mapping:

- Every character in `s1` maps to exactly one character in `s2`.
- Every character in `s2` maps to exactly one character in `s1`.

We use two `unordered_map<char, char>` — `s1ToS2` and `s2ToS1` — to store both directions of the mapping.

1. Iterate through both strings simultaneously, getting `c1 = s1[i]` and `c2 = s2[i]`.
2. For the **s1 → s2** direction:
   - If `c1` is already mapped, check that `s1ToS2[c1] == c2`. If not, return `false`.
   - Otherwise, add `s1ToS2[c1] = c2`.
3. For the **s2 → s1** direction:
   - If `c2` is already mapped, check that `s2ToS1[c2] == c1`. If not, return `false`.
   - Otherwise, add `s2ToS1[c2] = c1`.
4. If the loop completes, return `true`.

### Complexity

- **Time Complexity:** `O(N)`, where `N` is the length of the strings. We iterate through the strings exactly once.
- **Space Complexity:** `O(1)` or `O(256)`, as the size of the mapping arrays is constant (independent of `N`).
