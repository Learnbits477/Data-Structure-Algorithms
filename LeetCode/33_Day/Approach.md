# Approach

- [Problem Source](https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/?envType=daily-question&envId=2026-03-01)

## Intuition

The problem asks for the minimum number of deci-binary numbers (numbers consisting only of 0s and 1s) needed to sum up to a given string `n`.
Since each deci-binary number can contribute at most `1` to any digit position of `n` in a single addition, the digit with the maximum value in `n` dictates how many deci-binary numbers we need at the very least.

For example, if the maximum digit in `n` is `3` (e.g., in "32"), we need at least 3 numbers to sum up to `3` using only `1`s (1+1+1). The other smaller digits can simply be formed by having fewer `1`s across those 3 numbers (e.g., to form `2`, two numbers will have a `1` at that position, and the third will have a `0`).

Thus, the problem boils down to finding the maximum digit in the string `n`.

## Algorithm

1. Initialize a variable `max_digit` to 0.
2. Iterate through each character `c` in the string `n`.
3. Update `max_digit` to be the maximum of its current value and the integer value of `c` (`c - '0'`).
4. (Optional Optimization) If `max_digit` reaches 9, we can break out of the loop early since 9 is the maximum possible digit.
5. Return `max_digit`.

## Complexity

- **Time Complexity:** $O(L)$, where $L$ is the length of the string `n`. We iterate through the string of digits at most once.
- **Space Complexity:** $O(1)$, as we only keep track of a single variable for the maximum digit.
