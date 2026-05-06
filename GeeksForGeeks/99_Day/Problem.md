# 🧩[Size of Binary Tree](https://www.geeksforgeeks.org/problems/size-of-binary-tree/1)

## 📊 Metadata
![Difficulty: Basic](https://img.shields.io/badge/Difficulty-Basic-green?style=for-the-badge)
![Topic: Tree](https://img.shields.io/badge/Topic-Tree-blue?style=for-the-badge)
![Topic: Data Structures](https://img.shields.io/badge/Topic-Data%20Structures-blueviolet?style=for-the-badge)

## 🔗 Quick Links
| [Solution Code](./Solution.cpp) | [Approach / Logic](./Approach.md) | [Test Driver](./Main.cpp) |
| :--- | :--- | :--- |

---

## 📝 Problem Statement

Given the root of a binary tree, return the **size** of the tree. The size of a binary tree is the total number of nodes in the tree.

---

## 💡 Examples

### **Example 1**
> **Input:**      
> ```
>      1
>    /   \
>   2     3
> ```
> **Output:** `3`  
> **Explanation:** There are 3 nodes in the given binary tree, so its size is 3.

### **Example 2**
> **Input:**
> ```
>         10
>       /    \
>      20    30
>     /  \
>    40  60
> ```
> **Output:** `5` (Wait, the example in prompt says 6, let me re-check)
> (Looking at the prompt's ASCII art)
> Input:
> ```
>      10
>    /    \
>   20    30
>  /  \
> 40   60
> ```
> Output: 5 nodes. Let me re-read the prompt carefully.
> Prompt says "Output: 6" for the second example but the visual only shows 5. Maybe I missed a node.
> Actually, the prompt says:
> Input:
> ```
>      1
>    /   \
>   2     3
> ```
> Output: 3
> Input:
> (visual missing in text but explanation says 6)
> Explanation: There are 6 nodes in the given binary tree, so its size is 6.
> 
> I will use the 6 nodes example logic.

---

## ⚙️ Constraints
- $1 \le \text{number of nodes} \le 10^5$
- $1 \le \text{node->data} \le 10^5$

---

## ⏲️ Complexity
- **Expected Time Complexity:** $O(N)$
- **Expected Auxiliary Space:** $O(H)$ (Height of the tree)

---

## 🏢 Platform & Source
- **Problem Link:** [GeeksForGeeks - Size of Binary Tree](https://www.geeksforgeeks.org/problems/size-of-binary-tree/1)

---
<p align="center">
  <b>Happy Coding! 🚀</b>
</p>
