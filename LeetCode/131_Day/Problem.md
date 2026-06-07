# [2196. Create Binary Tree From Descriptions](https://leetcode.com/problems/create-binary-tree-from-descriptions/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 82.2%](https://img.shields.io/badge/Acceptance-82.2%25-green?style=for-the-badge)
![Submissions: 225.5K](https://img.shields.io/badge/Submissions-225.5K-blue?style=for-the-badge)
![Topics: Array | Hash Table | Tree | Binary Tree](https://img.shields.io/badge/Topics-Array%20%7C%20Hash%20Table%20%7C%20Tree%20%7C%20Binary%20Tree-lightgrey?style=for-the-badge)

## 🧩 Problem Description
You are given a 2D integer array `descriptions` where `descriptions[i] = [parent_i, child_i, isLeft_i]` indicates that `parent_i` is the parent of `child_i` in a binary tree of unique values. Furthermore:

- If `isLeft_i == 1`, then `child_i` is the left child of `parent_i`.
- If `isLeft_i == 0`, then `child_i` is the right child of `parent_i`.

Construct the binary tree described by `descriptions` and return its root.

The test cases will be generated such that the binary tree is valid.

## 📌 Examples

**Example 1:**
```text
Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram:
       50
      /  \
    20    80
   /  \   /
  15  17 19
```

**Example 2:**
```text
Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram:
     1
    /
   2
    \
     3
    /
   4
```

## 📐 Constraints
- $$1 \le descriptions.length \le 10^4$$
- $$descriptions[i].length == 3$$
- $$1 \le parent_i, child_i \le 10^5$$
- $$0 \le isLeft_i \le 1$$
- The binary tree described by `descriptions` is valid.

## ⏱️ Expected Complexities
| Parameter | Complexity |
|:---:|:---:|
| **Time Complexity** | $$O(N)$$ |
| **Auxiliary Space** | $$O(N)$$ |

## 🏷️ Topic Tags
`Array`, `Hash Table`, `Tree`, `Binary Tree`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../130_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../132_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
