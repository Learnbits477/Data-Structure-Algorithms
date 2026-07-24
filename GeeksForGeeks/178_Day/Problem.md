# [178. Longest Consecutive Path in Binary tree](https://www.geeksforgeeks.org/problems/longest-consecutive-sequence-in-binary-tree/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 30.58%](https://img.shields.io/badge/Accuracy-30.58%25-orange?style=for-the-badge)
![Submissions: 26K+](https://img.shields.io/badge/Submissions-26K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given the root of a Binary Tree, find the length of the longest path consisting of connected nodes such that each next node has a value exactly 1 greater than its parent.

The path must move from parent to child only and follow increasing consecutive values.

If no such path exists, return -1.

---

## 📌 Examples

### Example 1
**Input:**
```text
root[] = [1, 2, 3]
```
**Output:** 
```text
2
```
**Explanation:** 
Longest sequence is 1 -> 2. So the answer for this test case is 2.

### Example 2
**Input:** 
```text
root[] = [10, 20, 30, 40, N, 60, 90]
```
**Output:** 
```text
-1
```
**Explanation:** 
For the above test case, no sequence is possible. So the output is -1.

---

## 📐 Constraints

- $1 \le \text{no. of nodes in root} \le 10^5$
- $1 \le \text{root.node->data} \le 10^5$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $O(N)$ |
| 💾 Auxiliary Space | $O(H)$ (Height of the tree) |

---

## 🏷️ Topic Tags

<div align="center">

![DFS](https://img.shields.io/badge/DFS-3498DB?style=for-the-badge)
![Binary Tree](https://img.shields.io/badge/Binary%20Tree-9B59B6?style=for-the-badge)
![Data Structures](https://img.shields.io/badge/Data%20Structures-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../177_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../179_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
