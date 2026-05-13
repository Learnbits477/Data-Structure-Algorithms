# 🚀 Approach: Size of Binary Tree

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

## 💡 Intuition
The size of a binary tree can be defined recursively:
1.  If the tree is empty (root is `NULL`), its size is **0**.
2.  If the tree is not empty, its size is **1** (for the root node) plus the **size of the left subtree** and the **size of the right subtree**.

This follows a **Post-order Traversal** pattern where we process the children before finalizing the result for the parent.

---

## 🛠️ Step-by-Step Logic

1.  **Base Case**: 
    - Check if the current `node` is `NULL`.
    - If yes, return `0`.
2.  **Recursive Calls**:
    - Calculate the size of the left child: `leftSize = getSize(node->left)`.
    - Calculate the size of the right child: `rightSize = getSize(node->right)`.
3.  **Combine Results**:
    - Return `1 + leftSize + rightSize`.

---

## 🔍 Dry Run Example
**Input Tree**:
```
      1
    /   \
   2     3
```

1.  `getSize(1)` calls `getSize(2)` and `getSize(3)`.
2.  `getSize(2)` calls `getSize(NULL)` (left) and `getSize(NULL)` (right).
    - `getSize(NULL)` returns 0.
    - `getSize(2)` returns $1 + 0 + 0 = \mathbf{1}$.
3.  `getSize(3)` calls `getSize(NULL)` (left) and `getSize(NULL)` (right).
    - `getSize(NULL)` returns 0.
    - `getSize(3)` returns $1 + 0 + 0 = \mathbf{1}$.
4.  `getSize(1)` returns $1 + 1 + 1 = \mathbf{3}$.

---

## 📊 Visual Flow

```mermaid
graph TD
    A[Node 1] --> B[Node 2]
    A --> C[Node 3]
    B --> D[NULL]
    B --> E[NULL]
    C --> F[NULL]
    C --> G[NULL]

    subgraph Calculation["Size Calculation"]
    direction BT
    D1[Size: 0] -.-> B
    E1[Size: 0] -.-> B
    B -- "1 + 0 + 0" --> B_Res[Size: 1]
    
    F1[Size: 0] -.-> C
    G1[Size: 0] -.-> C
    C -- "1 + 0 + 0" --> C_Res[Size: 1]
    
    B_Res -.-> A
    C_Res -.-> A
    A -- "1 + 1 + 1" --> Final[Total Size: 3]
    end

    style Final fill:#f9f,stroke:#333,stroke-width:2px
    style Calculation fill:#f0f4f8,stroke:#d1d5db,stroke-dasharray: 5 5
```

---

## ⌛️ TimeComplexity Analysis

### ⏱️ Time Complexity: $O(N)$
- We visit each node exactly once during the recursive traversal. $N$ is the total number of nodes.

### 空间 Complexity: $O(H)$
- In the worst case (skewed tree), the recursion stack can go up to $N$ levels.
- In the best case (balanced tree), the stack depth is $O(\log N)$.
- $H$ represents the height of the tree.

---

## 🏆 Key Takeaway
Recursion is the most natural way to traverse tree structures. The "Divide and Conquer" strategy allows us to solve the problem for sub-problems (subtrees) and combine them easily.


<div align="center">
Happy Coding! 🚀
Happy Coding! 🚀 <br>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Twitter%20%2F%20X-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
</div>
