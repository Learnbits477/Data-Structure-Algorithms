# [Painting the Fence](https://www.geeksforgeeks.org/problems/painting-the-fence3727/1)

## Problem Description

Given a fence with `n` posts and `k` colours, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colours.

Answers are guaranteed to be fit into a 32 bit integer.

### Examples

**Input:** `n = 3`, `k = 2` 
**Output:** `6`
**Explanation:** Let the 2 colours be 'R' and 'B'. We have following possible combinations:
1. RRB
2. RBR
3. RBB
4. BRR
5. BRB
6. BBR

**Input:** `n = 2`, `k = 4` 
**Output:** `16`
**Explanation:** After coloring first post with 4 possible combinations, you can still color next posts with all 4 colors. Total possible combinations will be 4x4=16

### Constraints

- `1 ≤ n ≤ 300`
- `1 ≤ k ≤ 10^5`
- **Expected Time Complexity:** $O(n)$
- **Expected Auxiliary Space:** $O(n)$ (Can be optimized to $O(1)$)
