# [2130. Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/?envType=daily-question&envId=2026-06-11)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 82.0%](https://img.shields.io/badge/Acceptance-82.0%25-brightgreen?style=for-the-badge)
![Submissions: 640.7K](https://img.shields.io/badge/Submissions-640.7K-blue?style=for-the-badge)
![Topics: Linked List | Two Pointers | Stack](https://img.shields.io/badge/Topics-Linked%20List%20%7C%20Two%20Pointers%20%7C%20Stack-purple?style=for-the-badge)

</div>

---

## 🧩 Problem Description

In a linked list of size `n`, where `n` is **even**, the `i`-th node **(0-indexed)** of the linked list is known as the **twin** of the `(n-1-i)`-th node, if `0 <= i <= (n / 2) - 1`.

- For example, if `n = 4`, then node `0` is the twin of node `3`, and node `1` is the twin of node `2`. These are the only nodes with twins for `n = 4`.

The **twin sum** is defined as the sum of a node and its twin.

Given the `head` of a linked list with **even length**, return the **maximum twin sum** of the linked list.

---

## 📌 Examples

### Example 1
```
Input:  head = [5, 4, 2, 1]
Output: 6
```
**Explanation:**
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively.
- Twin sum of node 0 = 5 + 1 = 6
- Twin sum of node 1 = 4 + 2 = 6

Maximum twin sum = **6**

---

### Example 2
```
Input:  head = [4, 2, 2, 3]
Output: 7
```
**Explanation:**
- Node 0 twin of node 3 → 4 + 3 = 7
- Node 1 twin of node 2 → 2 + 2 = 4

Maximum twin sum = **max(7, 4) = 7**

---

### Example 3
```
Input:  head = [1, 100000]
Output: 100001
```
**Explanation:**
Only one twin pair → 1 + 100000 = **100001**

---

## 📐 Constraints

$$2 \leq n \leq 10^5 \quad \text{(n is even)}$$

$$1 \leq \text{Node.val} \leq 10^5$$

---

## ⏱️ Expected Complexities

| Complexity | Value  |
|:----------:|:------:|
| 🕐 Time    | O(n)   |
| 💾 Space   | O(1)   |

> **O(1) space** is achievable via in-place reversal of the second half; O(n) via a stack or array.

---

## 🏷️ Topic Tags

<div align="center">

![Linked List](https://img.shields.io/badge/Linked%20List-0A66C2?style=for-the-badge)
![Two Pointers](https://img.shields.io/badge/Two%20Pointers-6DB33F?style=for-the-badge)
![Stack](https://img.shields.io/badge/Stack-FF6B35?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../137_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../139_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
