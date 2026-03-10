<h2><a href="https://www.geeksforgeeks.org/problems/subarrays-with-first-element-minimum/1">Subarrays with First Element Minimum</a></h2>

## Problem Description

You are given an integer array `arr[]`. Your task is to count the number of subarrays where the first element is the minimum element of that subarray.

**Note:** A subarray is valid if its first element is not greater than any other element in that subarray.

### Examples

**Example 1:**

```
Input: arr[] = [1, 2, 1]
Output: 5
Explanation:
All possible subarrays are:
[1], [1, 2], [1, 2, 1], [2], [2, 1], [1]
Valid subarrays are:
[1], [1, 2], [1, 2, 1], [2], [1] -> total 5
```

**Example 2:**

```
Input: arr[] = [1, 3, 5, 2]
Output: 8
Explanation:
Valid subarrays are: [1], [1, 3], [1, 3, 5], [1, 3, 5, 2], [3], [3, 5], [5], [2] -> total 8
```

### Constraints

- $1 \le \text{arr.size()} \le 5\times10^4$
- $1 \le arr[i] \le 10^5$
