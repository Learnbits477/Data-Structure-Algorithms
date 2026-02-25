# Longest Subarray with Majority Greater than K

**Difficulty:** Medium  
**Accuracy:** 52.63%  
**Submissions:** 28K+  
**Points:** 4

## Problem Statement

Given an array `arr[]` and an integer `k`, the task is to find the **length of the longest subarray** in which the count of elements **greater than k** is more than the count of elements **less than or equal to k**.

## Examples

### Example 1

```
Input:  arr[] = [1, 2, 3, 4, 1], k = 2
Output: 3
Explanation: The subarray [2, 3, 4] or [3, 4, 1] satisfies the given condition.
             There is no subarray of length 4 or 5 which holds the condition.
```

### Example 2

```
Input:  arr[] = [6, 5, 3, 4], k = 2
Output: 4
Explanation: In subarray [6, 5, 3, 4], there are 4 elements > 2 and 0 elements <= 2.
```

## Constraints

- `1 ≤ arr.size() ≤ 10^6`
- `1 ≤ arr[i] ≤ 10^6`
- `0 ≤ k ≤ 10^6`

## Source

[GeeksForGeeks – Longest Subarray with Majority Greater than K](https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1)
