# [113. Product Pair](https://www.geeksforgeeks.org/problems/equal-to-product3836/1)

<div align="center">
| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
- **Difficulty:** Medium
- **Acceptance:** 17.34%
- **Submissions:** 90K+
- **Developer Profile:** [![Pankaj Kumar](https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white)](https://x.com/PankajB42550)
- **Badges:**
  ![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
  ![Acceptance: 17.34%](https://img.shields.io/badge/Acceptance-17.34%25-orange?style=for-the-badge)
  ![Submissions: 90K+](https://img.shields.io/badge/Submissions-90K%2B-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an integer array `arr[]` and an integer `target`, determine whether there exists a pair of elements in the array whose product is equal to `target`.

Return `true` if such a pair exists; otherwise, return `false`.

---

## 📌 Examples

### Example 1
**Input:**
```text
arr[] = [10, 20, 9, 40]
target = 400
```
**Output:** `true`  
**Explanation:** As $10 \times 40 = 400$, the answer is `true`.

### Example 2
**Input:**
```text
arr[] = [-10, 20, 9, -40]
target = 30
```
**Output:** `false`  
**Explanation:** No pair exists with product $30$.

### Example 3
**Input:**
```text
arr[] = [-10, 0, 9, -40]
target = 0
```
**Output:** `true`  
**Explanation:** As $-10 \times 0 = 0$, the answer is `true`.

---

## 📐 Constraints

- $2 \le \text{arr.size()} \le 10^5$
- $-10^8 \le \text{arr}[i] \le 10^8$
- $-10^{18} \le \text{target} \le 10^{18}$

---

## ⏱️ Expected Complexities

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(N)$ |
| **Space Complexity** | $\mathcal{O}(N)$ |

---

## 🏷️ Topic Tags
- `Arrays`
- `Hash`
- `Data Structures`

---

<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../112_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../114_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
