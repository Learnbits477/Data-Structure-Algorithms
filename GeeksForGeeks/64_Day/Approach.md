# Approach: Consecutive 1's not allowed

## Problem Analysis

The task is to count all binary strings of length `n` that do not contain any consecutive 1's.

## Dynamic Programming State

We can use dynamic programming to solve this by considering the ending character of the string. For a string of length `i`, it can end in either `0` or `1`.

Let:
- **`a`**: Number of valid binary strings ending with `0`.
- **`b`**: Number of valid binary strings ending with `1`.

## State Transitions

At each step (increasing length from `i-1` to `i`):
- **To end with `0`**: We can append `0` to any valid string of length `i-1` (whether it ends in `0` or `1`).
  - `new_a = (a + b) % mod`
- **To end with `1`**: We can only append `1` to strings of length `i-1` that ended in `0` to avoid consecutive 1's.
  - `new_b = a`

## Initial Values

For length `n = 1`:
- String "0" (ends in 0) => `a = 1`
- String "1" (ends in 1) => `b = 1`

## Result

The total number of valid strings of length `n` is `(a + b) % mod`.

## Complexity Analysis

- **Time Complexity**: **O(n)**, as we iterate from 1 to `n` once.
- **Space Complexity**: **O(1)**, since we only store the counts for the current length using two variables.

---

### Code Illustration

```cpp
long long a = 1; // Ends in 0
long long b = 1; // Ends in 1

for (int i = 2; i <= n; i++) {
    long long prev_a = a;
    a = a + b;
    b = prev_a;
}
return (a + b);
```

---

[Problem Link](https://www.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1)
