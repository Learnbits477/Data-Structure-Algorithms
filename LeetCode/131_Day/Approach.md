# 💡 Approach — Create Binary Tree From Descriptions

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 82.2%](https://img.shields.io/badge/Acceptance-82.2%25-green?style=for-the-badge)
![Submissions: 225.5K](https://img.shields.io/badge/Submissions-225.5K-blue?style=for-the-badge)
![Topics: Array | Hash Table | Tree | Binary Tree](https://img.shields.io/badge/Topics-Array%20%7C%20Hash%20Table%20%7C%20Tree%20%7C%20Binary%20Tree-lightgrey?style=for-the-badge)

> [!TIP]
> **Core Insight:** 
> 1. Use a hash map (`unordered_map<int, TreeNode*>`) to store and retrieve created nodes on the fly. This enables linking parents and children in $$O(1)$$ time.
> 2. To identify the root node, keep track of all child node values in a hash set. Since every node in a valid binary tree has exactly one parent except the root, the root will be the only node in the hash map that is **never** recorded as a child.

## 🔩 Step-by-Step Breakdown
1. **Track Nodes and Children:** Maintain an `unordered_map<int, TreeNode*>` to link integer values with their corresponding node pointers, and an `unordered_set<int>` to record all child values.
2. **Build the Tree:** Iterate through the `descriptions` list. For each `[parentVal, childVal, isLeft]`:
   - Retrieve the `parent` node from the map (or create it if it doesn't exist yet).
   - Retrieve the `child` node from the map (or create it if it doesn't exist yet).
   - Link the parent and child: if `isLeft == 1`, set `parent->left = child`; otherwise, set `parent->right = child`.
   - Insert `childVal` into the children set.
3. **Identify the Root:** Iterate through all created nodes in the map. The node whose value is **not** present in the children set is the root of the tree. Return this node.

## 🔄 Mermaid Flowchart
```mermaid
flowchart TD
    A[Start: createBinaryTree] --> B["Initialize nodeMap and children set"]
    B --> C["Loop: For each desc in descriptions"]
    C --> D["Get or create parentNode & childNode"]
    D --> E{"isLeft == 1?"}
    E -- Yes --> F["parentNode->left = childNode"]
    E -- No --> G["parentNode->right = childNode"]
    F --> H["Insert childVal into children set"]
    G --> H
    H --> C
    C -- Loop Done --> I["Find nodeVal in nodeMap NOT in children set"]
    I --> J["Return root node"]
```

## 📊 Complexity Analysis
| Complexity | Analysis |
|:---:|:---|
| **Time Complexity** | $$O(N)$$ — We iterate through the list of `descriptions` of size $$N$$ once. Finding/inserting in `unordered_map` and `unordered_set` takes $$O(1)$$ on average. Identifying the root requires a scan of the hash map which contains at most $$N + 1$$ nodes. |
| **Auxiliary Space** | $$O(N)$$ — We store at most $$N + 1$$ unique nodes in `nodeMap` and at most $$N$$ child values in the `children` set. |

> *"The structure of a tree is defined not by its height, but by the strength of its roots."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../130_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../132_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
