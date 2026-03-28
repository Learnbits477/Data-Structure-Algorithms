# Approach - Find the String with LCP

## Problem Analysis

The goal is to find the lexicographically smallest string that satisfies the given `lcp` matrix. `lcp[i][j]` is the length of the longest common prefix of the substrings `word[i...n-1]` and `word[j...n-1]`.

## Greedy Construction

Since we need the lexicographically smallest string, we should prioritize using earlier characters in the alphabet ('a', then 'b', etc.).

### Step 1: Character Assignment

We iterate through the indices and assign characters. If `lcp[i][j] > 0`, then `s[i]` and `s[j]` must be the same.

```cpp
for (int i = 0; i < n; ++i) {
    if (s[i] == '\0') {
        if (next_char > 'z') return "";
        for (int j = i; j < n; ++j) {
            if (lcp[i][j] > 0) s[j] = next_char;
        }
        next_char++;
    }
}
```

## Verification

The lazy greedy assignment only ensures $word[i] == word[j]$ if $lcp[i][j] > 0$. We must verify the constructed string:

### Step 2: LCP Calculation and Comparison

We compute the LCP matrix for the generated string using dynamic programming from the bottom-right and compare it with the input matrix.

```cpp
for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
        if (s[i] == s[j]) {
            computed_lcp[i][j] = 1 + computed_lcp[i + 1][j + 1];
        } else {
            computed_lcp[i][j] = 0;
        }
        if (computed_lcp[i][j] != lcp[i][j]) return "";
    }
}
```

## Complexity

* **Time Complexity**: $O(n^2)$ for both construction and verification.
* **Space Complexity**: $O(n^2)$ for the DP table (where $n \le 1000$).
