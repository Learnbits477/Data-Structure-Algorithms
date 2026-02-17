# Maximum number of overlapping Intervals

[GeeksForGeeks Link](https://www.geeksforgeeks.org/problems/intersecting-intervals/1)

**Difficulty:** Hard
**Accuracy:** 33.28%
**Submissions:** 6K+
**Points:** 8

You are given an array of intervals `arr[][]`, where each interval is represented by two integers `[start, end]` (inclusive). Return the maximum number of intervals that overlap at any point in time.

## Examples

### Example 1

**Input:** `arr[][] = [[1, 2], [2, 4], [3, 6]]`
**Output:** `2`
**Explanation:** The maximum overlapping intervals are 2 (between (1, 2) and (2, 4) or between (2, 4) and (3, 6))

### Example 2

**Input:** `arr[][] = [[1, 8], [2, 5], [5, 6], [3, 7]]`
**Output:** `4`
**Explanation:** The maximum overlapping intervals are 4 (between (1, 8), (2, 5), (5, 6) and (3, 7))

## Constraints

- `2 ≤ arr.size() ≤ 2 * 10^4`
- `1 ≤ arr[i][0] < arr[i][1] ≤ 4*10^6`
