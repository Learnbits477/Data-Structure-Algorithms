# [2095. Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 60.5%](https://img.shields.io/badge/Acceptance-60.5%25-brightgreen?style=for-the-badge)
![Submissions: 1.7M+](https://img.shields.io/badge/Submissions-1.7M%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given the **head** of a linked list. **Delete the middle node**, and return the head of the modified linked list.

The **middle node** of a linked list of size **n** is the **⌊n/2⌋th node** from the start using **0-based indexing**, where ⌊x⌋ denotes the largest integer less than or equal to x.

| List Size (n) | 1 | 2 | 3 | 4 | 5 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| Middle Index | 0 | 1 | 1 | 2 | 2 |

---

## 📌 Examples

### Example 1
```
Input:  head = [1, 3, 4, 7, 1, 2, 6]
Output: [1, 3, 4, 1, 2, 6]
```
**Explanation:** n = 7, middle index = ⌊7/2⌋ = **3** (value 7). Remove it.

---

### Example 2
```
Input:  head = [1, 2, 3, 4]
Output: [1, 2, 4]
```
**Explanation:** n = 4, middle index = ⌊4/2⌋ = **2** (value 3). Remove it.

---

### Example 3
```
Input:  head = [2, 1]
Output: [2]
```
**Explanation:** n = 2, middle index = ⌊2/2⌋ = **1** (value 1). Remove it.

---

## 📐 Constraints

$$1 \leq \text{number of nodes} \leq 10^5$$

$$1 \leq \text{Node.val} \leq 10^5$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
|:----------:|:-----:|
| 🕐 Time    | $O(n)$ |
| 💾 Space   | $O(1)$ |

---

## 🏷️ Topic Tags

<div align="center">

![Linked List](https://img.shields.io/badge/Linked%20List-0A9EDC?style=for-the-badge)
![Two Pointers](https://img.shields.io/badge/Two%20Pointers-6C3483?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../138_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../140_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
