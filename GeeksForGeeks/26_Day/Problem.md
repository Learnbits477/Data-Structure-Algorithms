# Count Subarrays with given XOR

**Difficulty:** Medium
**Accuracy:** 58.86%
**Submissions:** 84K+
**Points:** 4

---

## Problem Statement

Given an array of integers `arr[]` and a number `k`, count the number of subarrays having XOR of their elements as `k`.

> **Note:** It is guaranteed that the total count will fit within a 32-bit integer.

---

## Examples

### Example 1

```
Input:  arr[] = [4, 2, 2, 6, 4], k = 6
Output: 4
```

**Explanation:** The subarrays having XOR of their elements as 6 are `[4, 2]`, `[4, 2, 2, 6, 4]`, `[2, 2, 6]`, and `[6]`. Hence, the answer is 4.

### Example 2

```
Input:  arr[] = [5, 6, 7, 8, 9], k = 5
Output: 2
```

**Explanation:** The subarrays having XOR of their elements as 5 are `[5]` and `[5, 6, 7, 8, 9]`. Hence, the answer is 2.

### Example 3

```
Input:  arr[] = [1, 1, 1, 1], k = 0
Output: 4
```

**Explanation:** The subarrays are `[1, 1]`, `[1, 1]`, `[1, 1]` and `[1, 1, 1, 1]`.

---

## Constraints

- `1 ≤ arr.size() ≤ 10^5`
- `0 ≤ arr[i] ≤ 10^5`
- `0 ≤ k ≤ 10^5`

---

## Source

[GeeksForGeeks - Count Subarrays with given XOR](https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1)
