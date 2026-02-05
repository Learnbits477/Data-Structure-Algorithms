# Transformed Array

## Problem Description

You are given an integer array `nums` representing a circular array. You need to create a new array `result` of the same size, where for each index `i`:

1. If `nums[i] > 0`: Move `nums[i]` steps to the right in the circular array. The value at the new index becomes `result[i]`.
2. If `nums[i] < 0`: Move `abs(nums[i])` steps to the left in the circular array. The value at the new index becomes `result[i]`.
3. If `nums[i] == 0`: The value stays the same, so `result[i] = nums[i]`.

Return the `result` array.

## Examples

### Example 1

**Input:** `nums = [3, -2, 1, 1]`
**Output:** `[1, 1, 1, 3]`
**Explanation:**

- For `nums[0] = 3`: Move 3 steps right from index 0 -> index 3. `result[0] = nums[3] = 1`.
- For `nums[1] = -2`: Move 2 steps left from index 1 -> index 3 (1 -> 0 -> 3). `result[1] = nums[3] = 1`.
- For `nums[2] = 1`: Move 1 step right from index 2 -> index 3. `result[2] = nums[3] = 1`.
- For `nums[3] = 1`: Move 1 step right from index 3 -> index 0. `result[3] = nums[0] = 3`.

### Example 2

**Input:** `nums = [-1, 4, -1]`
**Output:** `[-1, -1, 4]`
**Explanation:**

- For `nums[0] = -1`: Move 1 step left from index 0 -> index 2. `result[0] = nums[2] = -1`.
- For `nums[1] = 4`: Move 4 steps right from index 1 -> index 2 (1 -> 2 -> 0 -> 1 -> 2). `result[1] = nums[2] = -1`.
- For `nums[2] = -1`: Move 1 step left from index 2 -> index 1. `result[2] = nums[1] = 4`.

## Constraints

- `1 <= nums.length <= 100`
- `-100 <= nums[i] <= 100`
