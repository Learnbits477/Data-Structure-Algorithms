# Max sum in the configuration

**Difficulty:** Medium
**Accuracy:** 36.56%
**Points:** 4

## Problem Description

Given an integer array `arr[]`. Find the maximum value of the sum of `i*arr[i]` for all `0 <= i <= arr.size()-1`. The only operation allowed is to rotate (clockwise or counterclockwise) the array any number of times.

## Examples

### Example 1

**Input:** `arr[] = [3, 1, 2, 8]`
**Output:** `29`
**Explanation:**
Out of all the possible configurations by rotating the elements:
`arr[] = [3, 1, 2, 8]`, sum = `3*0 + 1*1 + 2*2 + 8*3 = 29`.
This is the maximum.

### Example 2

**Input:** `arr[] = [1, 2, 3]`
**Output:** `8`
**Explanation:**
Out of all the possible configurations by rotating the elements:
`arr[] = [1, 2, 3]`, sum = `1*0 + 2*1 + 3*2 = 8`.
This is the maximum.

### Example 3

**Input:** `arr[] = [4, 13]`
**Output:** `13`

## Constraints

- `1 <= arr.size() <= 10^4`
- `1 <= arr[i] <= 20`
