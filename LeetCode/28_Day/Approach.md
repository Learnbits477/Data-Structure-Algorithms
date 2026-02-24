# Approach - Sum of Root To Leaf Binary Numbers

## Intuition

Each root-to-leaf path forms a binary number. As we travel down the tree, we can maintain the current number being formed by:

- **Left-shifting** the accumulated value by 1 bit (multiply by 2)
- **OR-ing** (or adding) the current node's value

When we reach a leaf node, we add the accumulated value to the total sum.

---

## Approach: DFS (Preorder Traversal)

We perform a **DFS** and pass the current accumulated binary number down the recursion.

At each node:

1. `current = (current << 1) | node->val` — shift left and append current bit
2. If it's a leaf node → add `current` to the answer
3. Otherwise → recurse on left and right children

### Steps:

1. Start DFS from root with `current = 0`
2. Update: `current = current * 2 + node->val`
3. At leaf: return `current`
4. Otherwise: return `dfs(left, current) + dfs(right, current)`

---

## Complexity Analysis

| Complexity | Value |
| ---------- | ----- |
| Time       | O(N)  |
| Space      | O(H)  |

- **N** = number of nodes in the tree
- **H** = height of the tree (O(log N) for balanced, O(N) worst case)
- Space is used by the recursion stack.

---

## Why This Works

Binary numbers are formed MSB to LSB as we go root to leaf. By shifting the accumulated value left and inserting the new bit at the LSB position at each level, we correctly reconstruct the binary number for every root-to-leaf path.
