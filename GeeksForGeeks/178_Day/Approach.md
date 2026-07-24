# 💡 Approach — Longest Consecutive Path in Binary tree

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |

</div>

---

## 🎯 Core Insight

> [!TIP]
> **Depth-First Search (DFS) for Consecutive Paths**
> 
> 1. **Path Movement Constraint**: The consecutive path must only move from **parent to child** and follow **increasing consecutive values** (value of child = value of parent + 1).
> 2. **Recursive Traversal**:
>    - We traverse the tree using a Depth-First Search (DFS).
>    - At each node, we check if the current node's value matches the `expectedValue` (which is `parentValue + 1`).
>    - If it matches: we increment the `currentLength` of the consecutive path.
>    - If it does not match: we reset `currentLength` to `1` because a new path starts from this node.
> 3. **Global Maximum**:
>    - We keep track of the maximum sequence length `maxLength` found across all paths traversed.
> 4. **No Sequence Case**:
>    - If the longest consecutive sequence has length $\le 1$, it means no consecutive path of at least 2 nodes exists. According to problem specifications, we return `-1`.

---

## 🔩 Step-by-Step Breakdown

### 1. DFS Helper Function
We define a recursive helper function `dfs(Node* root, int currentLength, int expectedValue, int& maxLength)`:
- **Base Case**: If `root == nullptr`, return immediately.
- **Extend or Reset Path**:
  - If `root->data == expectedValue`: `currentLength++`.
  - Else: `currentLength = 1` (starting a new path).
- **Update Maximum**: Update `maxLength = max(maxLength, currentLength)`.
- **Recursive Subproblems**:
  - Traverse left child: `dfs(root->left, currentLength, root->data + 1, maxLength)`.
  - Traverse right child: `dfs(root->right, currentLength, root->data + 1, maxLength)`.

### 2. Main Entry Point
In `longestConsecutive(Node* root)`:
- If `root == nullptr`, return `-1`.
- Initialize `maxLength = 0`.
- Call `dfs(root, 0, root->data, maxLength)`.
- Return `maxLength > 1 ? maxLength : -1`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start(["Start: longestConsecutive(root)"]) --> CheckNull{"root == nullptr?"}
    CheckNull -- "Yes" --> RetMinusOne["Return -1"]
    CheckNull -- "No" --> Init["Initialize maxLength = 0\nCall dfs(root, 0, root->data, maxLength)"]
    
    Init --> DFS["dfs(node, currentLength, expectedValue, maxLength)"]
    DFS --> CheckNodeNull{"node == nullptr?"}
    CheckNodeNull -- "Yes" --> RetDFS["Return"]
    
    CheckNodeNull -- "No" --> Match{"node->data == expectedValue?"}
    Match -- "Yes" --> Inc["currentLength = currentLength + 1"]
    Match -- "No" --> Reset["currentLength = 1"]
    
    Inc --> UpdMax["maxLength = max(maxLength, currentLength)"]
    Reset --> UpdMax
    
    UpdMax --> RecurLeft["Recur Left: dfs(node->left, currentLength, node->data + 1, maxLength)"]
    RecurLeft --> RecurRight["Recur Right: dfs(node->right, currentLength, node->data + 1, maxLength)"]
    RecurRight --> RetDFS
    
    DFS --> CheckMax{"maxLength > 1?"}
    CheckMax -- "Yes" --> RetMax["Return maxLength"]
    CheckMax -- "No" --> RetMinusOne
    
    RetMinusOne --> End(["End"])
    RetMax --> End
```

---

## 🧮 Dry Run

### Dry Run 1: Example 1 (`root = [1, 2, 3]`)

* **Initial state**: `maxLength = 0`
* **DFS Call Stack Progression**:

| Call Depth | Node | `currentLength` (In) | `expectedValue` | Action & Condition | `currentLength` (Out) | `maxLength` |
| :---: | :---: | :---: | :---: | :--- | :---: | :---: |
| **1** | `1` | `0` | `1` | `1 == 1`. Increment path. Recur left/right. | `1` | `1` |
| **2 (Left)** | `2` | `1` | `2` | `2 == 2`. Increment path. Recur left/right. | `2` | `2` |
| **3 (Left-Left)** | `nullptr` | `2` | `3` | Base Case: return. | — | `2` |
| **3 (Left-Right)** | `nullptr` | `2` | `3` | Base Case: return. | — | `2` |
| **2 (Right)** | `3` | `1` | `2` | `3 != 2`. Reset path. Recur left/right. | `1` | `2` |
| **3 (Right-Left)** | `nullptr` | `1` | `4` | Base Case: return. | — | `2` |
| **3 (Right-Right)** | `nullptr` | `1` | `4` | Base Case: return. | — | `2` |

* **Final Result**: `maxLength = 2`. Since `maxLength > 1`, return **`2`**.

---

### Dry Run 2: Example 2 (`root = [10, 20, 30, 40, N, 60, 90]`)

* **Initial state**: `maxLength = 0`
* **DFS Call Stack Progression**:

| Call Depth | Node | `currentLength` (In) | `expectedValue` | Action & Condition | `currentLength` (Out) | `maxLength` |
| :---: | :---: | :---: | :---: | :--- | :---: | :---: |
| **1** | `10` | `0` | `10` | `10 == 10`. Increment path. Recur left/right. | `1` | `1` |
| **2 (Left)** | `20` | `1` | `11` | `20 != 11`. Reset path. Recur left/right. | `1` | `1` |
| **3 (Left-Left)** | `40` | `1` | `21` | `40 != 21`. Reset path. Recur left/right. | `1` | `1` |
| **4 (Left-Left-Left)** | `nullptr` | `1` | `41` | Base Case: return. | — | `1` |
| **4 (Left-Left-Right)** | `nullptr` | `1` | `41` | Base Case: return. | — | `1` |
| **3 (Left-Right)** | `nullptr` | `1` | `21` | Base Case: return. | — | `1` |
| **2 (Right)** | `30` | `1` | `11` | `30 != 11`. Reset path. Recur left/right. | `1` | `1` |
| **3 (Right-Left)** | `60` | `1` | `31` | `60 != 31`. Reset path. Recur left/right. | `1` | `1` |
| **3 (Right-Right)** | `90` | `1` | `31` | `90 != 31`. Reset path. Recur left/right. | `1` | `1` |

* **Final Result**: `maxLength = 1`. Since `maxLength > 1` is false, return **`-1`**.

---

## ⏱️ Complexity Analysis

- **Time Complexity**: $O(N)$ because we visit each node in the binary tree exactly once during the DFS traversal.
- **Auxiliary Space**: $O(H)$ where $H$ is the height of the binary tree. This space is used by the recursion call stack, which is $O(N)$ in the worst case (skewed tree) and $O(\log N)$ in the best case (balanced tree).

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../177_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../179_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
