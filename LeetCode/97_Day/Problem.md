# [48. Rotate Image](https://leetcode.com/problems/rotate-image/)

---

## 🔗 Related Files

| File | Description |
|:-----|:------------|
| [Approach.md](Approach.md) | Transpose and Reverse logic explanation |
| [Solution.cpp](Solution.cpp) | In-place rotation implementation |
| [Main.cpp](Main.cpp) | Test driver for matrix rotation |

---

## 📝 Problem Description

You are given an $n \times n$ 2D matrix representing an image, rotate the image by **90 degrees (clockwise)**.

You have to rotate the image **in-place**, which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.

---

## 📥 Example 1
**Input:** `matrix = [[1,2,3],[4,5,6],[7,8,9]]`  
**Output:** `[[7,4,1],[8,5,2],[9,6,3]]`  

## 📥 Example 2
**Input:** `matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]`  
**Output:** `[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]`  

---

## 🛠️ Constraints
- $n == matrix.length == matrix[i].length$
- $1 \le n \le 20$
- $-1000 \le matrix[i][j] \le 1000$

---

## 📊 Performance Expectation
- **Time Complexity:** $O(N^2)$ where $N$ is the side length of the matrix.
- **Space Complexity:** $O(1)$ (In-place modification).

---

## 🌐 References
- [LeetCode Problem](https://leetcode.com/problems/rotate-image/)
