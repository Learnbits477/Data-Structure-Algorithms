# 🧩[Sum of XOR of All Pairs](https://www.geeksforgeeks.org/problems/sum-of-xor-of-all-pairs0723/1)

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Topic: Bit Manipulation](https://img.shields.io/badge/Topic-Bit%20Manipulation-blue?style=for-the-badge)
![Topic: Mathematics](https://img.shields.io/badge/Topic-Mathematics-blueviolet?style=for-the-badge)

## 🔗 Quick Links
| [Solution Code](./Solution.cpp) | [Approach / Logic](./Approach.md) | [Test Driver](./Main.cpp) |
| :--- | :--- | :--- |

---

## 📝 Problem Statement

Given an integer array `arr[]` of size `n`, compute the **sum of the bitwise XOR** for all distinct pairs of elements. 

Specifically, you need to calculate the total sum of `(arr[i] XOR arr[j])` for every pair of indices `(i, j)` such that $0 \le i < j < n$.

---

## 💡 Examples

### **Example 1**
> **Input:** `arr[] = [7, 3, 5]`  
> **Output:** `12`  
> **Explanation:**  
> - `7 ^ 3 = 4`  
> - `7 ^ 5 = 2`  
> - `3 ^ 5 = 6`  
> **Sum:** $4 + 2 + 6 = \mathbf{12}$

### **Example 2**
> **Input:** `arr[] = [5, 9, 7, 6]`  
> **Output:** `47`  
> **Explanation:**  
> All pairs XOR: `12, 2, 3, 14, 15, 1`.  
> **Sum:** $12 + 2 + 3 + 14 + 15 + 1 = \mathbf{47}$

### **Example 3**
> **Input:** `arr[] = [10]`  
> **Output:** `0`  
> **Explanation:** No pairs possible, so the sum is **0**.

---

## ⚙️ Constraints
- $1 \le n \le 10^5$
- $1 \le arr[i] \le 10^5$

---

## 🏢 Platform & Source
- **Problem Link:** [GeeksForGeeks - Sum of XOR of all pairs](https://www.geeksforgeeks.org/problems/sum-of-xor-of-all-pairs0723/1)
- **Company Tags:** `Amazon`, `Microsoft`, `Adobe` (Common Bitwise Patterns)

---
<p align="center">
  <b>Happy Coding! 🚀</b>
</p>
