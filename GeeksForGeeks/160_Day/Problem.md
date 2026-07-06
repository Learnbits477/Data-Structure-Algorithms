# [160. Max Sum Path in Two Arrays](https://www.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 30.9%](https://img.shields.io/badge/Accuracy-30.9%25-green?style=for-the-badge)
![Submissions: 84K+](https://img.shields.io/badge/Submissions-84K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)
![Company Tags](https://img.shields.io/badge/Company%20Tags-Amazon-black?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given two sorted arrays of distinct integers in increasing order `a[]` and `b[]`, which may have some common elements, find the maximum sum of a path from the beginning of any array to the end of any array. You may switch from one array to the other only at common elements.

> [!NOTE]
> When switching, count the common element only once.

---

## 📌 Examples

### Example 1
**Input:**
```text
a[] = [2, 3, 7, 10, 12], b[] = [1, 5, 7, 8]
```
**Output:**
```text
35
```
**Explanation:**
The path will be $(1 + 5 + 7 + 10 + 12) = 35$, where $1$ and $5$ come from `b[]` and then $7$ is common so we switch to `a[]` and add $10$ and $12$.

### Example 2
**Input:**
```text
a[] = [1, 2, 3], b[] = [3, 4, 5]
```
**Output:**
```text
15
```
**Explanation:**
The path will be $(1 + 2 + 3 + 4 + 5) = 15$.

---

## 📐 Constraints

- $$1 \le a.size(), b.size() \le 10^4$$
- $$1 \le a[i], b[i] \le 10^5$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n + m)$$ |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Arrays](https://img.shields.io/badge/Arrays-3498DB?style=for-the-badge)
![Data Structures](https://img.shields.io/badge/Data%20Structures-F39C12?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../159_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../161_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
