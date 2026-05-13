# [Top View of Binary Tree](https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 38.43%](https://img.shields.io/badge/Accuracy-38.43%25-red?style=for-the-badge)
![Submissions: 438K+](https://img.shields.io/badge/Submissions-438K%2B-lightgrey?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)
![Avg Time: 45m](https://img.shields.io/badge/Avg%20Time-45m-informational?style=for-the-badge)
![Topic: Tree](https://img.shields.io/badge/Topic-Tree-blue?style=for-the-badge)
![Topic: Data Structures](https://img.shields.io/badge/Topic-Data%20Structures-blueviolet?style=for-the-badge)

---

## 🧩 Problem Description

You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

> **Note:**
> - Return the nodes from the leftmost node to the rightmost node.
> - If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view.

---

## 📌 Examples

### Example 1

```text
Input: root = [1, 2, 3]
Output: [2, 1, 3]
Explanation: The Green colored nodes represents the top view in the below Binary tree.
      1
    /   \
   2     3
```

### Example 2

```text
Input: root = [10, 20, 30, 40, 60, 90, 100]
Output: [40, 20, 10, 30, 100]
Explanation: The Green colored nodes represents the top view in the below Binary tree.
           10
         /    \
       20      30
      /  \    /  \
    40   60  90  100
```

---

## 📐 Constraints

$$1 \leq \text{number of nodes} \leq 10^5$$

$$1 \leq \text{node}\rightarrow\text{data} \leq 10^5$$

---

## ⏱️ Expected Complexities

| Metric          | Complexity   |
|-----------------|--------------|
| Time Complexity | $O(N \log N)$|
| Auxiliary Space | $O(N)$       |

---

## 🏷️ Topic Tags

`Tree` &nbsp; `Data Structures` &nbsp; `Breadth-First Search (BFS)`

---
<div align="center">
Happy Coding! 🚀 <br>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Twitter%20%2F%20X-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
</div>
