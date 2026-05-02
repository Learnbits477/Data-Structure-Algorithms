# Count Subset With Target Sum II

## Problem Statement

Given an array `arr[]` and an integer `k`, find the count of subsets whose sum is equal to `k`.

**Note:** It is guaranteed that the number of valid subsets will fit within a 32-bit integer.

### Examples

**Example 1:**
> **Input:** `arr[] = [1, 3, 2]`, `k = 3`
> **Output:** `2`
> **Explanation:** The two subsets whose sum is equal to `k` are `[1, 2]` and `[3]`.

**Example 2:**
> **Input:** `arr[] = [4, 2, 3, 1, 2]`, `k = 4`
> **Output:** `3`
> **Explanation:** The three subsets whose sum is equal to `k` are `[4]`, `[2, 2]` and `[3, 1]`.

**Example 3:**
> **Input:** `arr[] = [10, 20, 30]`, `k = 25`
> **Output:** `0`
> **Explanation:** No subset exists with a sum equal to `k`.

### Constraints:
- `1 <= arr.size() <= 40`
- `-10^7 <= arr[i], k <= 10^7`

## Related Files
- [Approach Explanation](Approach.md)
- [C++ Solution](Solution.cpp)
- [Main Driver File](Main.cpp)

---
*Source: [GeeksForGeeks - Count Subset With Target Sum II](https://www.geeksforgeeks.org/problems/count-the-subset-with-sum-equal-to-k/1)*
