# Walkthrough: Longest Balanced Substring I

## Problem Understanding

We need to find the length of the longest substring where every character appearing in it appears the same number of times.

## Approach

Since $N \le 1000$, we can use an $O(N^2)$ approach.
We iterate through all possible starting positions $i$ and expanding to $j$.
We maintain the count of each character, the number of distinct characters, and the maximum frequency observed so far.
The condition for a substring to be balanced is `distinctCount * maxFreq == length`.

## Code Structure

- **Solution.cpp**: Contains the `Solution` class with `longestBalanced` method and a `main` function to run test cases.
- **Problem.md**: Description of the problem directly from LeetCode.
- **Approach.md**: Explanation of the $O(N^2)$ algorithm.

## Verification

The solution includes a `main` function with the provided examples.

- **Test 1**: `s = "abbac"` -> Output: 4. Correct ("abba").
- **Test 2**: `s = "zzabccy"` -> Output: 4. Correct ("zabc").
- **Test 3**: `s = "aba"` -> Output: 2. Correct ("ab" or "ba").

## Execution Results

```
Test 1: 4 Expected: 4
Test 2: 4 Expected: 4
Test 3: 2 Expected: 2
```

The logic works by checking every possible substring efficiently.
