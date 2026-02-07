# Approach: Greedy / Dynamic Programming

## Intuition

The problem asks for the minimum deletions to make the string balanced. A string is balanced if there is no 'b' before 'a'. This means the string must look like some number of 'a's followed by some number of 'b's (e.g., "aaabbb", "aaa", "bbb", "").

We can iterate through the string and maintain the state of minimum deletions required.

## Algorithm

We can use a simple variable-based dynamic programming or greedy approach.
Let's maintain:

1. `b_count`: The number of 'b's encountered so far.
2. `min_deletions`: The minimum deletions required to make the prefix balanced.

As we iterate through characters of string `s`:

- If we encounter `'b'`, it doesn't immediately cause an imbalance. We just increment `b_count`.
- If we encounter `'a'`, we have a potential conflict with all the `'b'`s seen so far. We have two choices to resolve this:
    1. **Delete this 'a'**: The cost increases by 1 (`min_deletions + 1`).
    2. **Keep this 'a'**: To keep this 'a' valid, we must have deleted all preceding 'b's. The cost would be `b_count`.

    We take the minimum of these two options: `min_deletions = min(min_deletions + 1, b_count)`.

## complexity Analysis

- **Time Complexity:** $O(N)$, where $N$ is the length of the string. We iterate through the string once.
- **Space Complexity:** $O(1)$, as we only use a few integer variables.
