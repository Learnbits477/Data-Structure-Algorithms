# [3740. Minimum Distance Between Three Equal Elements I](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/)

**Medium**

---

## Problem Statement

You are given an integer array `nums`.

A tuple `(i, j, k)` of three **distinct** indices is considered **good** if the elements at these indices in the array `nums` are equal:
`nums[i] == nums[j] == nums[k]`

The **distance** of a good tuple `(i, j, k)` is defined as the sum of the absolute differences between all pairs of indices:
`distance = |i - j| + |j - k| + |k - i|`

Return the **minimum** possible distance of a good tuple. If no such good tuple exists, return `-1`.

---

## Examples

### Example 1:
**Input**: `nums = [1, 1, 2, 1, 1]`  
**Output**: `6`  
**Explanation**:  
Possible good tuples include:
- `(0, 1, 3)`: distance = `|0-1| + |1-3| + |3-0| = 1 + 2 + 3 = 6`.
- `(1, 3, 4)`: distance = `|1-3| + |3-4| + |4-1| = 2 + 1 + 3 = 6`.
- `(0, 1, 4)`: distance = `|0-1| + |1-4| + |4-0| = 1 + 3 + 4 = 8`.
- `(0, 3, 4)`: distance = `|0-3| + |3-4| + |4-0| = 3 + 1 + 4 = 8`.

The minimum distance among these is `6`.

### Example 2:
**Input**: `nums = [1, 2, 3]`  
**Output**: `-1`  
**Explanation**:  
There are no three indices with the same value in the array.

### Example 3:
**Input**: `nums = [1, 1, 1]`  
**Output**: `4`  
**Explanation**:  
The only good tuple is `(0, 1, 2)`: distance = `|0-1| + |1-2| + |2-0| = 1 + 1 + 2 = 4`.

---

## Constraints:
- `3 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
