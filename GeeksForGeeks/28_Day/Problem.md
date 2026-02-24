# Longest Span in two Binary Arrays

**Difficulty:** Medium  
**Accuracy:** 48.22%  
**Submissions:** 29K+  
**Points:** 4  
**Source:** [GeeksForGeeks](https://www.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1)

---

## Problem Statement

Given two binary arrays, `a1[]` and `a2[]` of equal length. Find the length of **longest common span (i, j)**, where `i <= j` such that:

```
a1[i] + a1[i+1] + .... + a1[j] = a2[i] + a2[i+1] + ... + a2[j]
```

---

## Examples

### Example 1

```
Input:  a1[] = [0, 1, 0, 0, 0, 0], a2[] = [1, 0, 1, 0, 0, 1]
Output: 4
Explanation: The longest span with same sum is from index 1 to 4 (0-based indexing).
```

### Example 2

```
Input:  a1[] = [0, 1, 0, 1, 1, 1, 1], a2[] = [1, 1, 1, 1, 1, 0, 1]
Output: 6
Explanation: The longest span with same sum is from index 1 to 6 (0-based indexing).
```

### Example 3

```
Input:  a1[] = [0, 0, 0], a2[] = [1, 1, 1]
Output: 0
Explanation: There is no span where the sum of elements in a1[] and a2[] is equal.
```

---

## Constraints

- `1 ≤ a1.size() = a2.size() ≤ 10^6`
- `0 ≤ a1[i], a2[i] ≤ 1`

---

## Expected Complexities

- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

**Topic Tags:** Array, Hash Map, Prefix Sum
