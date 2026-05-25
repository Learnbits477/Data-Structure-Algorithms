# [118. Elements in the Range](https://www.geeksforgeeks.org/problems/elements-in-the-range2834/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata

![Difficulty: Basic](https://img.shields.io/badge/Difficulty-Basic-green?style=for-the-badge)
![Accuracy: 37.28%](https://img.shields.io/badge/Accuracy-37.28%25-blue?style=for-the-badge)
![Submissions: 86K+](https://img.shields.io/badge/Submissions-86K%2B-purple?style=for-the-badge)
![Points: 1](https://img.shields.io/badge/Points-1-orange?style=for-the-badge)

---

![Company Tags](https://img.shields.io/badge/Company%20Tags-Amazon-black?style=for-the-badge)

## 🧩 Problem Description

Given an array `arr[]` containing distinct positive integers, and two integers `start` and `end` defining a range. Determine if the array contains all elements within the inclusive range `[start, end]`.

Note: If the array contains all elements in the given range return `true` otherwise return `false`.

---

## 📌 Examples

### Example 1

**Input:** `start = 2`, `end = 5`, `arr[] = [1, 4, 5, 2, 7, 8, 3]`  
**Output:** `true`  
**Explanation:** All integers within the range `[2, 5]` are 2, 3, 4, and 5, and all of them are present in the array. Therefore, the answer is `true` for this test case.

### Example 2

**Input:** `start = 2`, `end = 6`, `arr[] = [1, 4, 5, 2, 7, 8, 3]`  
**Output:** `false`  
**Explanation:** The array does not contain 6; hence, it does not contain all the elements in the range `[2, 6]`. Therefore, the output is `false`.

---

## 📐 Constraints

- $1 \le \text{arr.size()} \le 10^5$
- $0 \le \text{arr}[i] \le 10^5$
- $0 \le \text{start} \le \text{end} \le 10^5$

---

## ⏱️ Expected Complexities

| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(1)$ |

---

## 🏷️ Topic Tags

- `Arrays`
- `Searching`
- `Sorting`
- `Data Structures`
- `Algorithms`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../117_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../119_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
