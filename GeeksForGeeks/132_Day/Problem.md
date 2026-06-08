# [132. Delete Nodes with Greater on Right](https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 35.51%](https://img.shields.io/badge/Accuracy-35.51%25-green?style=for-the-badge)
![Submissions: 158K+](https://img.shields.io/badge/Submissions-158K+-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topics: Linked List | Data Structures](https://img.shields.io/badge/Topics-Linked%20List%20%7C%20Data%20Structures-lightgrey?style=for-the-badge)

## 🧩 Problem Description
Given a singly linked list, remove all nodes that have a node with a greater value anywhere to their right in the list. Return the head of the modified linked list.

## 📌 Examples

**Example 1:**
```text
Input: LinkedList = 12->15->10->11->5->6->2->3
Output: 15->11->6->3
Explanation: Since 12, 10, 5 and 2 are the elements which have greater elements on the following nodes, after deleting them, the linked list would be 15->11->6->3.
```

**Example 2:**
```text
Input: LinkedList = 10->20->30->40->50->60
Output: 60
Explanation: All the nodes except the last node have a greater value node on their right, so all the nodes except the last node must be removed.
```

## 📐 Constraints
- $$1 \le \text{size of linked list} \le 10^6$$
- $$1 \le \text{element of linked list} \le 10^6$$

## ⏱️ Expected Complexities
| Parameter | Complexity |
|:---:|:---:|
| **Time Complexity** | $$O(n)$$ |
| **Auxiliary Space** | $$O(1)$$ |

## 🏷️ Topic Tags
`Linked List`, `Data Structures`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../131_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../133_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
