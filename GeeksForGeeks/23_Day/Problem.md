# Missing Element in Range

**Difficulty:** Medium
**Accuracy:** 55.45%
**Submissions:** 22K+
**Points:** 4
**Average Time:** 20m

## Problem Statement

Given an array `arr[]` of integers and a range `[low, high]`, find all the numbers within the range that are not present in the array. Return the missing numbers in sorted order.

## Examples

**Example 1:**

```
Input:  arr[] = [10, 12, 11, 15], low = 10, high = 15
Output: [13, 14]
Explanation: Numbers 13 and 14 lie in the range [10, 15] but are not present in the array.
```

**Example 2:**

```
Input:  arr[] = [1, 4, 11, 51, 15], low = 50, high = 55
Output: [50, 52, 53, 54, 55]
Explanation: Numbers 50, 52, 53, 54 and 55 lie in the range [50, 55] but are not present in the array.
```

## Constraints

- `1 ≤ arr.size(), low, high ≤ 10^5`
- `1 ≤ arr[i] ≤ 10^5`

## Source

[GeeksForGeeks - Missing Element in Range](https://www.geeksforgeeks.org/problems/missing-element-in-range/1)
