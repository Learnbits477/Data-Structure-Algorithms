# 2265. [Count Nodes Equal to Average of Subtree](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 86.9%](https://img.shields.io/badge/Acceptance-86.9%25-brightgreen?style=for-the-badge)
![Submissions: 237.5K+](https://img.shields.io/badge/Submissions-237.5K%2B-blue?style=for-the-badge)
![Topic: Tree](https://img.shields.io/badge/Topic-Tree-blue?style=for-the-badge)
![Topic: Depth--First%20Search](https://img.shields.io/badge/Topic-Depth--First%20Search-blue?style=for-the-badge)
![Topic: Binary%20Tree](https://img.shields.io/badge/Topic-Binary%20Tree-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given the `root` of a binary tree, return the number of nodes where the value of the node is equal to the **average** of the values in its **subtree**.

**Note:**
- The **average** of $n$ elements is the **sum** of the $n$ elements divided by $n$ and **rounded down** to the nearest integer (i.e., $\lfloor \frac{\text{sum}}{n} \rfloor$).
- A **subtree** of `root` is a tree consisting of `root` and all of its descendants.

---

## 📌 Examples

**Example 1:**

```text
       4
     /   \
    8     5
   / \     \
  0   1     6

Input: root = [4,8,5,0,1,null,6]
Output: 5
Explanation: 
- For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
- For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
- For the node with value 0: The average of its subtree is 0 / 1 = 0.
- For the node with value 1: The average of its subtree is 1 / 1 = 1.
- For the node with value 6: The average of its subtree is 6 / 1 = 6.
Total nodes meeting the condition = 5.
```

**Example 2:**

```text
   1

Input: root = [1]
Output: 1
Explanation: For the node with value 1: The average of its subtree is 1 / 1 = 1.
```

---

## 📐 Constraints

- The number of nodes in the tree is in the range $[1, 1000]$.
- $0 \le \text{Node.val} \le 1000$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(N)$ |
| **Auxiliary Space** | $\mathcal{O}(H)$ where $H$ is the height of the tree ($\mathcal{O}(N)$ worst-case, $\mathcal{O}(\log N)$ balanced) |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../225_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../227_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
