# [153. Maximize Dot Product](https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 13.27%](https://img.shields.io/badge/Accuracy-13.27%25-green?style=for-the-badge)
![Submissions: 69K+](https://img.shields.io/badge/Submissions-69K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)
![Company Tags](https://img.shields.io/badge/Company%20Tags-Directi-black?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given two arrays $a[\,]$ and $b[\,]$ of positive integers of size $n$ and $m$ respectively, where $m \le n$. You are allowed to insert zeros anywhere into the second array $b$ so that its length becomes equal to $n$.

The dot product of two arrays of equal length $n$ is defined as:  
$$a[0] \cdot b[0] + a[1] \cdot b[1] + \dots + a[n-1] \cdot b[n-1]$$

Return the **maximum possible dot product** of the two arrays.

---

## 📌 Examples

### Example 1
**Input:**
```text
a[] = [2, 3, 1, 7, 8], b[] = [3, 6, 7]
```
**Output:**
```text
107
```
**Explanation:**
Maximum dot product is obtained after inserting $0$ at the first and third positions in array $b$.  
Therefore $b$ becomes `[0, 3, 0, 6, 7]`.  
Maximum dot product = $2 \cdot 0 + 3 \cdot 3 + 1 \cdot 0 + 7 \cdot 6 + 8 \cdot 7 = 107$.

### Example 2
**Input:**
```text
a[] = [1, 2, 3], b[] = [4]
```
**Output:**
```text
12
```
**Explanation:**
Maximum dot product is obtained after inserting $0$ at the first and second positions in array $b$.  
Therefore $b$ becomes `[0, 0, 4]`.  
Maximum dot product = $1 \cdot 0 + 2 \cdot 0 + 3 \cdot 4 = 12$.

---

## 📐 Constraints

- $$1 \le m \le n \le 10^3$$
- $$1 \le a[i], b[i] \le 10^3$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n \times m)$$ |
| 💾 Auxiliary Space | $$O(n \times m)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-8E44AD?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../152_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../154_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
