# 2058. [Find the Minimum and Maximum Number of Nodes Between Critical Points](https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 71.3%](https://img.shields.io/badge/Acceptance-71.3%25-green?style=for-the-badge)
![Submissions: 368.8K](https://img.shields.io/badge/Submissions-368.8K-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Linked%20List-blue?style=for-the-badge)

---

## 🧩 Problem Description

A **critical point** in a linked list is defined as either a **local maxima** or a **local minima**.

- A node is a **local maxima** if the current node has a value **strictly greater** than the previous node and the next node.
- A node is a **local minima** if the current node has a value **strictly smaller** than the previous node and the next node.

> **Note:** A node can only be a local maxima/minima if there exists **both** a previous node and a next node. The first and last nodes can never be critical points.

Given a linked list `head`, return an array of length 2 containing `[minDistance, maxDistance]` where:
- `minDistance` is the minimum distance between any two distinct critical points, and
- `maxDistance` is the maximum distance between any two distinct critical points.

If there are fewer than two critical points, return `[-1, -1]`.

---

## 📌 Examples

**Example 1:**
```text
Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].
```

**Example 2:**
```text
Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: 
There are three critical points (1-indexed positions):
- Node at index 3 (value 1): Local minima (1 < 3 and 1 < 2).
- Node at index 5 (value 5): Local maxima (5 > 2 and 5 > 1).
- Node at index 6 (value 1): Local minima (1 < 5 and 1 < 2).

The minimum distance is between index 5 and index 6: 6 - 5 = 1.
The maximum distance is between index 3 and index 6: 6 - 3 = 3.
```

**Example 3:**
```text
Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: 
There are two critical points (1-indexed positions):
- Node at index 2 (value 3): Local maxima (3 > 1 and 3 > 2).
- Node at index 5 (value 3): Local maxima (3 > 2 and 3 > 2).

Both minimum and maximum distances are between index 2 and index 5: 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.
```

---

## 📐 Constraints

- The number of nodes in the list is in the range $[2, 10^5]$.
- $1 \le \text{Node.val} \le 10^5$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../215_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../217_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
