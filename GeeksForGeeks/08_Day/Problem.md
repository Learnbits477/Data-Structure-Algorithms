# Last Moment Before All Ants Fall Out of a Plank

## Problem Statement

We have a wooden plank of the length `n` units. Some ants are walking on the plank, each ant moves with a speed of 1 unit per second. Some of the ants move to the left, the other move to the right.

When two ants moving in two different directions meet at some point, they change their directions and continue moving again. Assume changing directions does not take any additional time.

When an ant reaches one end of the plank at a time `t`, it falls out of the plank immediately.

Given an integer `n` and two integer arrays `left` and `right`, the positions of the ants moving to the left and the right, return the moment when the last ant(s) fall out of the plank.

## Examples

### Example 1

**Input:**
n = 4, left = [4, 3], right = [0, 1]
**Output:**
4
**Explanation:**

- Ant at 4 -> left (reaches 0 in 4s)
- Ant at 3 -> left (reaches 0 in 3s)
- Ant at 0 -> right (reaches 4 in 4s)
- Ant at 1 -> right (reaches 4 in 3s)
The last moment is 4.

### Example 2

**Input:**
n = 7, left = [], right = [0, 1, 2, 3, 4, 5, 6, 7]
**Output:**
7
**Explanation:**
All ants are moving to the right. The ant at index 0 needs 7 seconds to fall.

## Constraints

- `1 <= n <= 10^4`
- `0 <= left.length <= n + 1`
- `0 <= left[i] <= n`
- `0 <= right.length <= n + 1`
- `0 <= right[i] <= n`
- `1 <= left.length + right.length <= n + 1`
- All values of `left` and `right` are unique, and each value can appear only in one of the two arrays.
