# 205. [Node and Ancestor Max Diff](https://www.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 34.95%](https://img.shields.io/badge/Acceptance-34.95%25-green?style=for-the-badge)
![Submissions: 82K+](https://img.shields.io/badge/Submissions-82K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Tree-blue?style=for-the-badge)
![Company](https://img.shields.io/badge/Company-Amazon-black?style=for-the-badge)

## 🧩 Problem Description

Given the root of a binary tree, find the maximum difference between an ancestor node $A$ and its descendant node $B$, i.e., maximize $A.data - B.data$.

## 📌 Examples

**Example 1:**
```text
Input: root[] = [2, 5, 1]

      5
    /  \
   2    1

Output: 4
Explanation: The maximum difference we can get is 4, which is between ancestor 5 and descendant 1 (5 - 1 = 4).
```

**Example 2:**
```text
Input: root[] = [1, 2, 3, N, N, N, 7]

        1
      /   \
     2     3
            \
             7

Output: -1
Explanation: The maximum difference we can get is -1, which is between ancestor 1 and descendant 2 (1 - 2 = -1).
```

## 📐 Constraints
- $2 \le \text{Number of nodes in root} \le 10^4$
- $0 \le \text{root.node->data} \le 10^5$
- $2 \le \text{Number of edges} \le 10^4$

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time** | $\mathcal{O}(n)$ |
| **Space** | $\mathcal{O}(n)$ (Auxiliary stack space) |
---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../204_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../206_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
