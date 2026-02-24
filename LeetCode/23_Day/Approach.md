# Approach - Count Binary Substrings

## Intuition

The key observation is:

- Any valid substring consists of consecutive 0s followed by consecutive 1s (or vice versa).
- At each transition boundary (0→1 or 1→0), the number of valid substrings we can form is `min(prev_group_count, curr_group_count)`.

---

## Algorithm: Group Counting (Two Pointer)

### Steps

1. Count the length of consecutive groups of '0's and '1's.
2. Traverse the string and maintain `prev` (count of previous group) and `curr` (count of current group).
3. When the character changes:
   - Add `min(prev, curr)` to the result.
   - Set `prev = curr`, reset `curr = 1`.
4. After the loop, add `min(prev, curr)` for the last group.

### Why `min(prev, curr)`?

At each transition, valid substrings start from the boundary and extend symmetrically into both groups. The number of such substrings is bounded by the smaller group.

**Example:** `"0011"` → group of 2 zeros, group of 2 ones → `min(2, 2) = 2` → substrings: `"01"`, `"0011"`

---

## Complexity Analysis

| Metric               | Value                             |
| -------------------- | --------------------------------- |
| **Time Complexity**  | O(n) — single pass through string |
| **Space Complexity** | O(1) — only a few variables used  |

---

## Walkthrough

```
s = "00110011"

Index: 0  1  2  3  4  5  6  7
Char:  0  0  1  1  0  0  1  1

Groups: [2 zeros, 2 ones, 2 zeros, 2 ones]

Transitions:
- zeros→ones: min(2,2) = 2 → result = 2
- ones→zeros: min(2,2) = 2 → result = 4
- zeros→ones: min(2,2) = 2 → result = 6

Output: 6 ✓
```
