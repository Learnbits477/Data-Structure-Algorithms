# [116. Transform to Sum Tree](https://www.geeksforgeeks.org/problems/transform-to-sum-tree/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 70.5%](https://img.shields.io/badge/Accuracy-70.5%25-blue?style=for-the-badge)
![Submissions: 82K+](https://img.shields.io/badge/Submissions-82K%2B-purple?style=for-the-badge)

---

### 🏢 Companies
- ![Amazon](https://img.shields.io/badge/Amazon-FF9900?style=flat-square&logo=amazon&logoColor=white)
 ![Microsoft](https://img.shields.io/badge/Microsoft-0078D4?style=flat-square&logo=microsoft&logoColor=white)
 ![Samsung](https://img.shields.io/badge/Samsung-1428A0?style=flat-square&logo=samsung&logoColor=white)
![FactSet](https://img.shields.io/badge/FactSet-003057?style=flat-square&logoColor=white)
 ![Walmart](https://img.shields.io/badge/Walmart-0071DC?style=flat-square&logo=walmart&logoColor=white)

---

## 🧩 Problem Description

Given a root of a binary tree with $n$ nodes, where each node may contain positive or negative values, convert it into a tree such that each node’s new value is equal to the sum of all values in its left and right subtrees (based on the original tree). For leaf nodes, update their values to $0$.

---

## 📌 Examples

### Example 1

**Input:**
```text
          10
        /    \
      -2      6
      / \    / \
     8  -4  7   5
```

**Output:**
```text
          20
        /    \
       4     12
      / \    / \
     0   0  0   0
```

**Explanation:**
- **Leaf nodes update:** The leaf nodes $8, -4, 7, 5$ are changed to $0$ since they have no children.
- **Update internal nodes:**
  - Left child: $8 + (-4) = 4$
  - Right child: $7 + 5 = 12$
- **Update root node:**
  - Root = sum of left and right subtree values = $4 + 12 = 20$

---

## 📐 Constraints

- $1 \le n \le 10^4$
- Node values can be positive or negative.

---

## ⏱️ Expected Complexities

| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(h)$, where $h$ is the height of the tree |

---

## 🏷️ Topic Tags

- `Tree`
- `Depth First Search`
- `Breadth First Search`
- `Recursion`
- `Algorithms`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../115_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../117_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
