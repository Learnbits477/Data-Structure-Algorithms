# [Max After m Range Increments](https://www.geeksforgeeks.org/problems/max-value-after-m-range-operation4300/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 49.92%](https://img.shields.io/badge/Accuracy-49.92%25-blue?style=for-the-badge)
![Submissions: 14K+](https://img.shields.io/badge/Submissions-14K+-purple?style=for-the-badge)
![Topic: Prefix Sum](https://img.shields.io/badge/Topics:-Prefix_Sum-blue?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Arrays-cyan?style=for-the-badge)
![Topic: Mathematical](https://img.shields.io/badge/Mathematical-brightgreen?style=for-the-badge)
![Company: FactSet](https://img.shields.io/badge/Companies:-FactSet-orange?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given three arrays `a[]`, `b[]`, and `k[]`, representing $m$ range increment operations on an array `arr[]` of size $n$, where all elements of `arr[]` are initially 0.

`Increment(a[i], b[i], k[i])` adds `k[i]` to each element `arr[j]` such that `a[i] <= j <= b[i]` (index in range from `a[i]` to `b[i]`).

After performing all the given operations, find the maximum value present in the array.

---

## 📌 Examples

**Example 1:**
- **Input:** `n = 5`, `a[] = [0, 1, 2]`, `b[] = [1, 4, 3]`, `k[] = [100, 100, 100]`
- **Output:** `200`
- **Explanation:** 
  Initially, `arr = [0, 0, 0, 0, 0]`
  - After the first operation: `arr = [100, 100, 0, 0, 0]`
  - After the second operation: `arr = [100, 200, 100, 100, 100]`
  - After the third operation: `arr = [100, 200, 200, 200, 100]`
  The maximum element after all operations is `200`.

**Example 2:**
- **Input:** `n = 4`, `a[] = [1, 0, 3]`, `b[] = [2, 0, 3]`, `k[] = [603, 286, 882]`
- **Output:** `882`
- **Explanation:** 
  Initially, `arr = [0, 0, 0, 0]`
  - After the first operation: `arr = [0, 603, 603, 0]`
  - After the second operation: `arr = [286, 603, 603, 0]`
  - After the third operation: `arr = [286, 603, 603, 882]`
  The maximum element after all operations is `882`.

---

## 📐 Constraints

- $1 \le n \le 10^6$
- $1 \le a.size() = b.size() = k.size() = m \le 10^6$
- $0 \le a_i \le b_i \le n - 1$
- $0 \le k_i \le 10^6$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n + m)$ |
| **Auxiliary Space** | $O(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../185_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../187_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
