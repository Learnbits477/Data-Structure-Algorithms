# [Sort by Set Bit Count](https://www.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1)

---
<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

## 📝 Problem Description

Given an array `arr[]` of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements. 

> [!IMPORTANT]
> **Stable Sort Requirement:** For integers having same number of set bits in their binary representation, sort according to their position in the original array.

---

## 📥 Example 1
**Input:** `arr[] = [5, 2, 3, 9, 4, 6, 7, 15, 32]`  
**Output:** `[15, 7, 5, 3, 9, 6, 2, 4, 32]`  
**Explanation:**  
- 15 (1111) -> 4 bits
- 7  (0111) -> 3 bits
- 5, 3, 9, 6 -> 2 bits
- 2, 4, 32 -> 1 bit

## 📥 Example 2
**Input:** `arr[] = [1, 2, 3, 4, 5, 6]`  
**Output:** `[3, 5, 6, 1, 2, 4]`  
**Explanation:**  
- 3, 5, 6 -> 2 bits
- 1, 2, 4 -> 1 bit

---

## 🛠️ Constraints
- $1 \le arr.size() \le 10^5$
- $1 \le arr[i] \le 10^6$

---

<div align="center">
Happy Coding! 🚀
Happy Coding! 🚀 <br>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Twitter%20%2F%20X-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
</div>
