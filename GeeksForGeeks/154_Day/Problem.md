# [154. Minimum Insertions to Make Two Arrays Equal](https://www.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 27.85%](https://img.shields.io/badge/Accuracy-27.85%25-green?style=for-the-badge)
![Submissions: 22K+](https://img.shields.io/badge/Submissions-22K%2B-blue?style=for-the-badge)
![Points: 8](https://img.shields.io/badge/Points-8-yellow?style=for-the-badge)
![Company Tags](https://img.shields.io/badge/Company%20Tags-Google%20%7C%20Codenation-black?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given two arrays $a[\,]$ and $b[\,]$ of size $n$ and $m$ respectively, find the minimum number of insertions and deletions on the array $a[\,]$, required to make both the arrays identical.

> [!NOTE]
> Array $b[\,]$ is sorted and all its elements are distinct, operations can be performed at any index not necessarily at the end.

---

## 📌 Examples

### Example 1
**Input:**
```text
a[] = [1, 2, 5, 3, 1], b[] = [1, 3, 5]
```
**Output:**
```text
4
```
**Explanation:**
- Delete $2$ from $a$: $a[\,] = [1, 5, 3, 1]$
- Insert $3$ after $1$: $a[\,] = [1, 3, 5, 3, 1]$
- Delete the last two elements: $a[\,] = [1, 3, 5]$
- Total operations = $1 + 1 + 2 = 4$.

### Example 2
**Input:**
```text
a[] = [1, 4], b[] = [1, 4]
```
**Output:**
```text
0
```
**Explanation:**
Both the Arrays are already identical.

---

## 📐 Constraints

- $$1 \le n, m \le 10^5$$
- $$1 \le a[i], b[i] \le 10^5$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n \log n)$$ |
| 💾 Auxiliary Space | $$O(n)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Arrays](https://img.shields.io/badge/Arrays-3498DB?style=for-the-badge)
![Hash](https://img.shields.io/badge/Hash-F1C40F?style=for-the-badge)
![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-8E44AD?style=for-the-badge)
![Data Structures](https://img.shields.io/badge/Data%20Structures-E67E22?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../153_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../155_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
