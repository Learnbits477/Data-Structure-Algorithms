# 💡 Approach — Visit Leaves with Budget

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 50.05%](https://img.shields.io/badge/Accuracy-50.05%25-orange?style=for-the-badge)
![Submissions: 48K+](https://img.shields.io/badge/Submissions-48K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Company: Oracle](https://img.shields.io/badge/Company-Oracle-red?style=for-the-badge)
![Topic: Tree](https://img.shields.io/badge/Topic-Tree-blue?style=for-the-badge)
![Topic: Queue](https://img.shields.io/badge/Queue-blue?style=for-the-badge)
![Topic: BFS](https://img.shields.io/badge/BFS-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Level-Order (BFS) Greedy Strategy:**
> - The cost of visiting any leaf node is directly equal to its level (depth) in the tree.
> - To **maximize the total number of leaves** visited within a fixed budget $k$, we must greedily choose leaves that have the **minimum levels** first (i.e. cheapest leaves first).
> - **Breadth-First Search (BFS)** naturally traverses tree nodes level by level in non-decreasing order of their depths ($1, 2, 3, \dots$).
> - As a result, leaves encountered during BFS are automatically discovered in non-decreasing order of cost.
> - Whenever a leaf node at `level` is encountered:
>   - If the remaining budget $k \ge \text{level}$, we deduct `level` from $k$ and increment our count.
>   - If $k < \text{level}$, no further leaves can be afforded (since all subsequent leaves in BFS will have cost $\ge \text{level}$), so we can immediately terminate the search and return the count.

---

## 🔩 Step-by-Step Breakdown

1. **Base Case Check**:
   - If the tree is empty (`root == nullptr`), return `0`.

2. **Initialize BFS Queue**:
   - Create a queue of pairs: `queue<pair<Node*, int>> q`, where each element stores a pointer to a tree node and its 1-based level.
   - Push `{root, 1}` into the queue.
   - Initialize `count = 0`.

3. **Level-Order Traversal**:
   - While `q` is not empty:
     - Pop the front pair `(node, level)`.
     - **Leaf Detection**: If `node->left == nullptr` and `node->right == nullptr`:
       - If $k \ge \text{level}$:
         - Subtract `level` from $k$: `k -= level`.
         - Increment `count++`.
       - Else:
         - Budget is insufficient to visit this leaf. Since any subsequent leaf in BFS will have a depth $\ge \text{level}$, we can terminate immediately (`break`).
     - **Queue Children**:
       - If `node->left` exists, push `{node->left, level + 1}`.
       - If `node->right` exists, push `{node->right, level + 1}`.

4. **Return Result**:
   - Return `count`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A["Start: getCount(root, k)"] --> B{"root == nullptr?"}
    B -- "Yes" --> C["Return 0 🏁"]
    B -- "No" --> D["Initialize queue q with {root, 1}<br/>count = 0"]
    
    D --> E{"Is q empty?"}
    E -- "Yes" --> F["Return count 🏁"]
    E -- "No" --> G["Pop {node, level} from q"]
    
    G --> H{"Is node a leaf?<br/>(!left && !right)"}
    H -- "Yes" --> I{"k >= level?"}
    I -- "Yes" --> J["k -= level<br/>count++"]
    I -- "No" --> K["Budget exhausted for level!<br/>Break loop ⏹️"]
    K --> F
    J --> L["Continue to next in queue"]
    
    H -- "No" --> M{"node->left != nullptr?"}
    M -- "Yes" --> N["q.push({node->left, level + 1})"]
    M -- "No" --> O{"node->right != nullptr?"}
    N --> O
    O -- "Yes" --> P["q.push({node->right, level + 1})"]
    O -- "No" --> L
    P --> L
    L --> E
```

---

## 🏃‍♂️ Dry Run

### Example 1: `root = [10, 8, 2, 3, N, 3, 6, N, N, N, 4]`, $k = 8$

```
Level 1:           10
                 /    \
Level 2:        8      2
               /      / \
Level 3:      3      3   6
                      \
Level 4:               4
```

| Step | Node | Level | Is Leaf? | Action | Remaining Budget $k$ | Count |
|:---:|:---:|:---:|:---:|:---|:---:|:---:|
| 1 | `10` | 1 | No | Push `8` (L2), `2` (L2) | 8 | 0 |
| 2 | `8` | 2 | No | Push `3` (L3) | 8 | 0 |
| 3 | `2` | 2 | No | Push `3` (L3), `6` (L3) | 8 | 0 |
| 4 | `3` (left) | 3 | **Yes** | $8 \ge 3 \implies 8 - 3 = 5$ | 5 | **1** |
| 5 | `3` (right) | 3 | No | Push `4` (L4) | 5 | 1 |
| 6 | `6` | 3 | **Yes** | $5 \ge 3 \implies 5 - 3 = 2$ | 2 | **2** |
| 7 | `4` | 4 | **Yes** | $2 < 4 \implies$ Cannot afford! Break. | 2 | **2** |

- **Final Answer:** `2` ✅

---

## 📊 Complexity Analysis

| Complexity Metric | Estimation | Rationale |
| :--- | :---: | :--- |
| **Time Complexity** | $\mathcal{O}(n)$ | In the worst case, each node is pushed and popped from the BFS queue at most once. |
| **Auxiliary Space** | $\mathcal{O}(n)$ | The BFS queue holds at most $\mathcal{O}(w) = \mathcal{O}(n)$ nodes simultaneously, where $w$ is the maximum width of the binary tree. |

---

> *"Greedily choosing leaves in ascending order of depth guarantees maximum count under a bounded budget; BFS provides that exact ordering for free."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../230_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../232_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
