# [1840. Maximum Building Height](https://leetcode.com/problems/maximum-building-height/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 67.1%](https://img.shields.io/badge/Acceptance-67.1%25-blue?style=for-the-badge)
![Submissions: 123.6K](https://img.shields.io/badge/Submissions-123.6K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You want to build $$n$$ new buildings in a city. The new buildings will be built in a line and are labeled from $$1$$ to $$n$$.

However, there are city restrictions on the heights of the new buildings:

- The height of each building must be a non-negative integer.
- The height of the first building must be $$0$$.
- The height difference between any two adjacent buildings cannot exceed $$1$$.

Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array `restrictions` where `restrictions[i] = [id_i, maxHeight_i]` indicates that building `id_i` must have a height less than or equal to `maxHeight_i`.

It is guaranteed that each building will appear at most once in `restrictions`, and building $$1$$ will not be in `restrictions`.

Return *the maximum possible height of the tallest building*.

---

## 📌 Examples

### Example 1

**Input:** `n = 5, restrictions = [[2,1],[4,1]]`  
**Output:** `2`  
**Explanation:**  
We can build the buildings with heights `[0,1,2,1,2]`, and the tallest building has a height of `2`.

### Example 2

**Input:** `n = 6, restrictions = []`  
**Output:** `5`  
**Explanation:**  
We can build the buildings with heights `[0,1,2,3,4,5]`, and the tallest building has a height of `5`.

### Example 3

**Input:** `n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]`  
**Output:** `5`  
**Explanation:**  
We can build the buildings with heights `[0,1,2,3,3,4,4,5,4,3]`, and the tallest building has a height of `5`.

---

## 📐 Constraints

- $$2 \le n \le 10^9$$
- $$0 \le \text{restrictions.length} \le \min(n - 1, 10^5)$$
- $$2 \le id_i \le n$$
- $$id_i \text{ is unique.}$$
- $$0 \le \text{maxHeight}_i \le 10^9$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :--- |
| 🕐 Time | $$O(m \log m)$$ where $$m$$ is the number of restrictions. |
| 💾 Auxiliary Space | $$O(m)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-0A9EDC?style=for-the-badge)
![Math](https://img.shields.io/badge/Math-0A9EDC?style=for-the-badge)
![Binary Search](https://img.shields.io/badge/Binary%20Search-0A9EDC?style=for-the-badge)
![Two Pointers](https://img.shields.io/badge/Two%20Pointers-0A9EDC?style=for-the-badge)
![Greedy](https://img.shields.io/badge/Greedy-0A9EDC?style=for-the-badge)
![Sorting](https://img.shields.io/badge/Sorting-0A9EDC?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../143_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../145_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
