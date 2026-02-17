# Approach

The problem asks us to find all possible times (Hours: 0-11, Minutes: 0-59) such that the total number of set bits in the binary representation of the hour and minute equals `turnedOn`.

## Naive Approach / Iteration

Since the number of hours (0-11) and minutes (0-59) is small (12 \* 60 = 720 possibilities), we can simply iterate through all possible pairs of `(h, m)`.

1. Iterate `h` from 0 to 11.
2. Iterate `m` from 0 to 59.
3. Calculate the number of set bits in `h` and `m`.
   - We can use `__builtin_popcount(h)` and `__builtin_popcount(m)` in C++.
4. If `popcount(h) + popcount(m) == turnedOn`:
   - Format the time string.
   - Hours don't need leading zeros.
   - Minutes need to be two digits (e.g., if `m < 10`, prepend "0").
   - Add strictly formatted "h:mm" to the result list.

## Complexity

- **Time Complexity:** O(1), as we iterate a fixed number of times (12 \* 60).
- **Space Complexity:** O(1), ignoring the space for the output list.
