# 207. [Number of Turns in Binary Tree](https://www.geeksforgeeks.org/problems/number-of-turns-in-binary-tree/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 42.63%](https://img.shields.io/badge/Acceptance-42.63%25-green?style=for-the-badge)
![Submissions: 27K+](https://img.shields.io/badge/Submissions-27K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Tree-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Binary%20Tree-blue?style=for-the-badge)
![Company](https://img.shields.io/badge/Company-Amazon-black?style=for-the-badge)
![Company](https://img.shields.io/badge/Samsung-black?style=for-the-badge)

## 🧩 Problem Description

Given the `root` of a binary tree and the values of its two nodes `p` and `q`, count the number of turns required to travel from node `p` to `q`.

A turn occurs whenever the direction of movement changes from **left to right** or **right to left** while traversing the tree.

If the path between the two nodes does not involve any turns (i.e., the nodes lie on the same straight path), return `-1`.

> **Note:** All node values in the binary tree are distinct.

## 📌 Examples

**Example 1:**
```text
          1
        /   \
       2     3
     /   \  /  \
    4     5 6   7
   /       / \
  8       9  10

Input: root[] = [1, 2, 3, 4, 5, 6, 7, 8, N, N, N, 9, 10], p = 5, q = 10
Output: 4
Explanation: The path from node 5 to node 10 is: 5 -> 2 -> 1 -> 3 -> 6 -> 10.
Direction changes occur at nodes 2, 1, 3, and 6. Therefore, the number of turns is 4.
```

**Example 2:**
```text
Input: root[] = [1, 2, 3, 4, 5, 6, 7, 8, N, N, N, 9, 10], p = 1, q = 4
Output: -1
Explanation: The path from node 1 to node 4 is: 1 -> 2 -> 4 (all left moves).
No turn is required since they are in a straight line.
```

**Example 3:**
```text
Input: root[] = [1, 2, 3, 4, 5, 6, 7, 8, N, N, N, 9, 10], p = 1, q = 10
Output: 2
Explanation: The path from node 1 to node 10 is: 1 -> 3 -> 6 -> 10.
Direction changes occur at nodes 3 and 6. Therefore, the number of turns is 2.
```

## 📐 Constraints
- $1 \le n \le 10^4$ ($n$ is the number of nodes)
- $1 \le \text{node}\to\text{data} \le 10^4$
- $1 \le p, q \le n$

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time** | $\mathcal{O}(n)$ |
| **Space** | $\mathcal{O}(h)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../206_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../208_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
