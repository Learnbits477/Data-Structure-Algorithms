# 🧩 [1861. Rotating the Box](https://leetcode.com/problems/rotating-the-box/description/)

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Two Pointers](https://img.shields.io/badge/Topic-Two%20Pointers-blue?style=for-the-badge)
![Topic: Matrix](https://img.shields.io/badge/Topic-Matrix-blueviolet?style=for-the-badge)

## 🔗 Quick Links
| [Solution Code](./Solution.cpp) | [Approach / Logic](./Approach.md) | [Test Driver](./Main.cpp) |
| :--- | :--- | :--- |

---

## 📝 Problem Statement

You are given an `m x n` matrix of characters `boxGrid` representing a side-view of a box. Each cell of the box is one of the following:

- A stone `'#'`
- A stationary obstacle `'*'`
- Empty `'.'`

The box is **rotated 90 degrees clockwise**, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does **not** affect the obstacles' positions, and the inertia from the box's rotation does **not** affect the stones' horizontal positions.

It is **guaranteed** that each stone in `boxGrid` rests on an obstacle, another stone, or the bottom of the box.

Return an `n x m` matrix representing the box after the rotation described above.

---

## 💡 Examples

### **Example 1**
> **Input:** `boxGrid = [["#",".","#"]]`  
> **Output:** `[["."],["#"],["#"]]`  
> **Explanation:** The box is rotated 90 degrees clockwise. The stone at `(0,0)` falls to `(2,0)`.

### **Example 2**
> **Input:** `boxGrid = [["#",".","*","."],["#","#","*","."]]`  
> **Output:** `[["#","."],["#","#"],["*","*"],[".","."]]`

### **Example 3**
> **Input:** `boxGrid = [["#","#","*",".","*","."],["#","#","#","*",".","."],["#","#","#",".","#","."]]`  
> **Output:** `[[".","#","#"],[".","#","#"],["#","#","*"],["#","*","."],[["#",".","*"],["#",".","."]]`

---

## ⚙️ Constraints
- $m = \text{boxGrid.length}$
- $n = \text{boxGrid[i].length}$
- $1 \le m, n \le 500$
- `boxGrid[i][j]` is either `'#'`, `'*'`, or `'.'`.

---

## ⏲️ Complexity
- **Expected Time Complexity:** $O(M \times N)$
- **Expected Auxiliary Space:** $O(M \times N)$ (for the result matrix)

---

## 🏢 Platform & Source
- **Problem Link:** [LeetCode - Rotating the Box](https://leetcode.com/problems/rotating-the-box/description/)
- **Contest:** Biweekly Contest 52

---
<p align="center">
  <b>Happy Coding! 🚀</b>
</p>
