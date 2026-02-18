# Count Inversions

[Problem Link](https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1)

**Difficulty:** Medium  
**Accuracy:** 16.93%  
**Submissions:** 744K+  
**Points:** 4

## Problem Description

Given an array of integers `arr[]`. You have to find the Inversion Count of the array.

**Note:** Inversion count is the number of pairs of elements `(i, j)` such that `i < j` and `arr[i] > arr[j]`.

## Examples

**Input:** `arr[] = [2, 4, 1, 3, 5]`  
**Output:** `3`  
**Explanation:** The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

**Input:** `arr[] = [2, 3, 4, 5, 6]`  
**Output:** `0`  
**Explanation:** As the sequence is already sorted so there is no inversion count.

**Input:** `arr[] = [10, 10, 10]`  
**Output:** `0`  
**Explanation:** As all the elements of array are same, so there is no inversion count.

## Constraints

- $1 \le arr.size() \le 10^5$
- $1 \le arr[i] \le 10^4$
