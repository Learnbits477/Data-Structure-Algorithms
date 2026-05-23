# 💡 Approach — Transform to Sum Tree

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 70.5%](https://img.shields.io/badge/Accuracy-70.5%25-blue?style=for-the-badge)
![Submissions: 82K+](https://img.shields.io/badge/Submissions-82K%2B-purple?style=for-the-badge)

### 🏢 Companies
- ![Amazon](https://img.shields.io/badge/Amazon-FF9900?style=flat-square&logo=amazon&logoColor=white)
 ![Microsoft](https://img.shields.io/badge/Microsoft-0078D4?style=flat-square&logo=microsoft&logoColor=white)
 ![Samsung](https://img.shields.io/badge/Samsung-1428A0?style=flat-square&logo=samsung&logoColor=white)
 ![FactSet](https://img.shields.io/badge/FactSet-003057?style=flat-square&logoColor=white)
 ![Walmart](https://img.shields.io/badge/Walmart-0071DC?style=flat-square&logo=walmart&logoColor=white)

---

> [!TIP]
> **Core Insight:**  
> For any node in the tree, its new value is the sum of all values in its left and right subtrees in the original tree.
> 
> If we process the tree using a **Post-order Traversal (Bottom-Up DFS)**:
> 1. We first compute the sum of the left and right subtrees recursively.
> 2. The original sum of the subtree rooted at `root` is: `original_value(root) + sum_of_left_subtree + sum_of_right_subtree`.
> 3. The new value of the `root` node should be updated to: `sum_of_left_subtree + sum_of_right_subtree`.
> 4. We return the original sum of this subtree back to the parent so that the parent can compute its own new value.

---

## 🔩 Step-by-Step Breakdown

### Step 1: Base Case for Null Nodes
- If the current node is `nullptr`, return $0$ as it has no value.

### Step 2: Recursive Subtree Summation
- Recursively call the transform function on the left child to get the total original sum of the left subtree: `leftSum = transform(root->left)`.
- Recursively call the transform function on the right child to get the total original sum of the right subtree: `rightSum = transform(root->right)`.

### Step 3: Update Current Node Value
- Store the original value of the current node: `oldVal = root->data`.
- Update the current node's value to the sum of the left and right subtree sums: `root->data = leftSum + rightSum`.

### Step 4: Return Subtree Total Sum
- Return the sum of all original node values in the subtree rooted at the current node, which is `root->data + oldVal` (new node value + old node value).

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A([Start: Node* root]) --> B{root == nullptr?}
    B -- Yes --> C[Return 0]
    B -- No --> D["Store oldVal = root->data"]
    D --> E["Recursively solve left subtree: leftSum = transform(root->left)"]
    E --> F["Recursively solve right subtree: rightSum = transform(root->right)"]
    F --> G["Update node value: root->data = leftSum + rightSum"]
    G --> H["Return subtree sum: root->data + oldVal"]
    C --> I([End])
    H --> I
```

---

## 📊 Complexity Analysis

| Type | Complexity | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $O(n)$ | We visit each node of the binary tree exactly once. |
| **Auxiliary Space** | $O(h)$ | The space is used by the recursion call stack, which is proportional to the height of the tree $h$. In the worst case (skewed tree), $h = O(n)$; in the best case (balanced tree), $h = O(\log n)$. |

---

> *"Recursion is the root of elegance in data structures."* — Unknown

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../115_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../117_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
