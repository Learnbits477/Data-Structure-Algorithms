# Approach: Last Moment Before All Ants Fall Out of a Plank

## Intuition

The key observation in this problem is that when two ants meet and reverse direction, it is effectively equivalent to them simply passing through each other without changing direction.
Imagine the ants have identities. If ant A (moving right) hits ant B (moving left), and they swap directions, now the "entity" moving right is B and the "entity" moving left is A. But since all ants are identical and move at the same speed, we can just pretend they walked past each other.

Therefore, the problem simplifies to calculating how long it takes for each ant to reach the end of the plank it is facing, and finding the maximum of these times.

## Algorithm

1. Initialize `ans = 0`.
2. For each position `x` in the `left` array:
   - The time to reach the left end (0) is `x`.
   - Update `ans = max(ans, x)`.
3. For each position `x` in the `right` array:
   - The time to reach the right end (`n`) is `n - x`.
   - Update `ans = max(ans, n - x)`.
4. Return `ans`.

## Complexity Analysis

- **Time Complexity:** O(L + R), where L is the number of ants moving left and R is the number of ants moving right. We iterate through both arrays once.
- **Space Complexity:** O(1), as we only use a variable to store the maximum time.
