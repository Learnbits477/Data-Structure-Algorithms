# [2840. Check if Strings Can be Made Equal With Operations II](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/?envType=daily-question&envId=2026-03-30)

## Problem Intuition

The core of the problem lies in understanding the constraints of the swap operation. We can swap characters at indices `i` and `j` if `|i - j|` is even. 

An even difference between two indices means both indices must have the same parity (either both are even or both are odd).
- If `i` is even, `j = i + even_number` will also be even.
- If `i` is odd, `j = i + even_number` will also be odd.

This implies:
1. Characters at **even indices** can be moved to any other **even index**.
2. Characters at **odd indices** can be moved to any other **odd index**.
3. A character at an even index **cannot** move to an odd index, and vice versa.

## Core Strategy

To determine if `s1` can be transformed into `s2`, we simply need to check if:
1. The multisets of characters at even positions in both strings are identical.
2. The multisets of characters at odd positions in both strings are identical.

If these two conditions hold, we can rearrange the characters in `s1` at even indices to match `s2` at even indices, and do the same for odd indices.

## Step-by-Step Implementation

We can break down the solution into three main parts:

### 1. Initializing Frequency Arrays
We need four frequency arrays (one for even and odd positions in both strings) to count occurrences of each character ('a' to 'z').

```cpp
vector<int> countEven1(26, 0), countOdd1(26, 0);
vector<int> countEven2(26, 0), countOdd2(26, 0);
```

### 2. Traversal and Counting
Iterate through the length of the strings. If an index is even, increment the corresponding 'even' frequency array; otherwise, increment the 'odd' one.

```cpp
int n = s1.length();
for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
        countEven1[s1[i] - 'a']++;
        countEven2[s2[i] - 'a']++;
    } else {
        countOdd1[s1[i] - 'a']++;
        countOdd2[s2[i] - 'a']++;
    }
}
```

### 3. Comparison
Finally, check if the character distributions for even and odd positions match between the two strings.

```cpp
return (countEven1 == countEven2) && (countOdd1 == countOdd2);
```

## Complexity Analysis

- **Time Complexity:** $O(n)$, where $n$ is the length of the strings. We traverse the strings exactly once.
- **Space Complexity:** $O(1)$, since we use four arrays of fixed size 26, which does not depend on the input size $n$.
