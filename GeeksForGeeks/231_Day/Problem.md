# 231. [Visit Leaves with Budget](https://www.geeksforgeeks.org/problems/leaf-under-budget/1)

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
![Topic: Tree](https://img.shields.io/badge/Topic:-Tree-blue?style=for-the-badge)
![Topic: Queue](https://img.shields.io/badge/Queue-blue?style=for-the-badge)
![Topic: BFS](https://img.shields.io/badge/BFS-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given a binary tree and an integer `k`, where you start from the root at level $1$.
The cost of visiting a leaf node is equal to the level of that leaf node.
You can visit any number of leaf nodes, but the total cost of visiting them must not exceed `k`.

Return the **maximum number of leaf nodes** that can be visited within the given budget `k`.

---

## 📌 Examples

**Example 1:**

```text
Input: 
       10
      /  \
     8    2
    /    / \
   3    3   6
         \
          4
k = 8
Output: 2
Explanation:
- Leaf node 3 (left subtree) is at level 3. Cost = 3.
- Leaf node 4 (right subtree) is at level 4. Cost = 4.
- Leaf node 6 (right subtree) is at level 3. Cost = 3.
To maximize the number of visited leaves, choose the two cheapest leaves:
Cost = 3 + 3 = 6 ≤ 8.
Thus, the maximum number of leaf nodes that can be visited is 2.
```

**Example 2:**

```text
Input: 
       1
      / \
     2   3
    / \ / \
   4  5 6  7
k = 5
Output: 1
Explanation:
The leaf nodes are 4, 5, 6, and 7, and all are at level 3.
Visiting each leaf costs 3.
With a budget of 5, we can visit only one leaf because:
3 ≤ 5, but 3 + 3 = 6 > 5.
Thus, the maximum number of leaf nodes that can be visited is 1.
```

**Example 3:**

```text
Input: 
       1
k = 1
Output: 1
Explanation:
The root node is also a leaf node and is at level 1.
Therefore, its visiting cost is 1.
Thus, the maximum number of leaf nodes that can be visited is 1.
```

---

## 📐 Constraints

- $1 \le \text{number of nodes} \le 10^5$
- $1 \le \text{node values} \le 10^5$
- $1 \le k \le 10^4$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../230_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../232_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
