# 237. [Check Level Anagrams in Binary Trees](https://www.geeksforgeeks.org/problems/check-if-all-levels-of-two-trees-are-anagrams-or-not/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 56.88%](https://img.shields.io/badge/Accuracy-56.88%25-orange?style=for-the-badge)
![Submissions: 23K+](https://img.shields.io/badge/Submissions-23K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: Tree](https://img.shields.io/badge/Topic-Tree-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given the roots of two binary trees `root1` and `root2`, check whether the nodes at every corresponding level of the two trees are **anagrams** of each other.

Two levels are considered anagrams if they contain the **same node values with the same frequencies**, regardless of their order.

Return `true` if all corresponding levels are anagrams of each other, otherwise return `false`.

---

## 📌 Examples

**Example 1:**

```text
Input: root1 = [1, 3, 2, N, N, 5, 4], root2 = [1, 2, 3, 4, 5, N, N]
Output: true
Explanation:
Level 0: [1] and [1] -> Anagrams
Level 1: [3, 2] and [2, 3] -> Anagrams
Level 2: [5, 4] and [4, 5] -> Anagrams
The node values at every corresponding level are anagrams of each other. Hence, the answer is true.
```

**Example 2:**

```text
Input: root1 = [1, 2, 3, 5, 4], root2 = [1, 2, 4, 5, 3]
Output: false
Explanation:
Level 0: [1] and [1] -> Anagrams
Level 1: [2, 3] and [2, 4] -> Not Anagrams (3 != 4)
Since the node values at level 1 are not anagrams, the answer is false.
```

---

## 📐 Constraints

- $1 \le \text{size of binary tree} \le 10^5$
- $1 \le \text{node.data} \le 10^6$
- The character `'N'` represents a null child.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../236_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../238_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
