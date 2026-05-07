# [Check if subtree](https://www.geeksforgeeks.org/problems/check-if-subtree/1)
---
## Navigation
<div align="center">

| [📝 Problem](Problem.md) | [💡 Approach](Approach.md) | [💻 Solution](Solution.cpp) | [🚀 Main](Main.cpp) |
| :---: | :---: | :---: | :---: |

</div>

---

## Metadata

- **Difficulty:** Medium | **Accuracy:** 24.34% | **Submissions:** 155K+ | **Points:** 4 | **Average Time:** 45m

---
## Problem Description

Given two binary trees with roots `root1` (for tree T) and `root2` (for tree S), each containing at most N nodes. Determine whether tree S is a subtree of tree T.

Return **true** if S is a subtree of T, otherwise return **false**.

> **Note:** A tree S is considered a subtree of T if there exists a node in T such that the subtree rooted at that node is identical to S. Two trees are identical if they have the same structure and the same node values.
---
## Examples

### Example 1:

**Input:**

```text
root1 = [1, 2, 3, N, N, 4], root2 = [3, 4]
```

**Output:** `true`  
**Explanation:** In the tree rooted at root1, the subtree starting at node 3 is identical to the tree rooted at root2 (same structure and node values). Hence, root2 is a subtree of root1, so the output is true.

### Example 2:

**Input:**

```text
root1 = [26, 10, N, 20, 30, 40, 60], root2 = [26, 10, N, 20, 30, 40, 60]
```

**Output:** `true`  
**Explanation:** Both root1 and root2 represent identical trees. So, root2 is a subtree of root1, and the output is true.

---
## Constraints

- $1 \le n \le 10^3$
- $1 \le \text{value of nodes} \le 10^4$

---

<p align="center">
  <b>Happy Coding! 🚀</b>
</p>
