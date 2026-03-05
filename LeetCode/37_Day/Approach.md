# Approach

## Intuition

An alternating binary string of length `n` can only start with `'0'` or `'1'`. Therefore, there are only two possible target strings:

1. `010101...`
2. `101010...`

Notice that every character in the first target string is exactly the opposite of the character at the same position in the second target string. Consequently, if we need `k` operations to convert the given string to the first target string, we will need exactly `n - k` operations to convert it to the second target string (where `n` is the length of the string).

## Steps

1. Initialize a counter `ops` to 0.
2. Iterate through the string `s` with an index `i` from `0` to `n-1`.
3. Check if the character `s[i]` matches the expected character for the `"010101..."` pattern. In this pattern, characters at even indices should be `'0'` and characters at odd indices should be `'1'`.
   - The expected character for index `i` in the first pattern is `i % 2 == 0 ? '0' : '1'`.
4. If `s[i]` does not match the expected character, increment the `ops` counter.
5. After calculating `ops` (operations needed for the first pattern), the operations needed for the second pattern (`"101010..."`) will be `n - ops`.
6. Return the minimum of `ops` and `n - ops`.

## Complexity

- **Time Complexity:** $O(n)$, where $n$ is the length of the string `s`. We iterate through the string exactly once.
- **Space Complexity:** $O(1)$, as we only use a few variables for counting.
