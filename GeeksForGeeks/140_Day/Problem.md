# [140. Construct List using XOR Queries](https://www.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 50.86%](https://img.shields.io/badge/Accuracy-50.86%25-green?style=for-the-badge)
![Submissions: 42K+](https://img.shields.io/badge/Submissions-42K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

![Company Tags](https://img.shields.io/badge/Company%20Tags-Amazon%20|%20Google-black?style=for-the-badge)

---

## 🧩 Problem Description

There is an array that initially contains only a single value, `0`. 

Given a list of queries `queries[][]` of size `q`, where each query is of one of the following types:
- `0 x`: Insert `x` into the array.
- `1 x`: Replace every element `a` in the array with `a ^ x`, where `^` denotes the bitwise XOR operator.

Return the array in sorted order after performing all the queries.

---

## 📌 Examples

### Example 1
```
Input: q = 5, queries[] = [[0, 6], [0, 3], [0, 2], [1, 4], [1, 5]]
Output: [1, 2, 3, 7]
```
**Explanation:**
- `[0]` (initial value)
- `[0, 6]` (add 6 to list)
- `[0, 6, 3]` (add 3 to list)
- `[0, 6, 3, 2]` (add 2 to list)
- `[4, 2, 7, 6]` (XOR each element by 4)
- `[1, 7, 2, 3]` (XOR each element by 5)

The sorted list after performing all the queries is `[1, 2, 3, 7]`.

---

### Example 2
```
Input: q = 3, queries[] = [[0, 2], [1, 3], [0, 5]]
Output : [1, 3, 5]
```
**Explanation:**
- `[0]` (initial value)
- `[0, 2]` (add 2 to list)
- `[3, 1]` (XOR each element by 3)
- `[3, 1, 5]` (add 5 to list)

The sorted list after performing all the queries is `[1, 3, 5]`.

---

## 📐 Constraints

$$1 \leq q \leq 10^5$$

$$0 \leq x \leq 10^9$$

---

## ⏱️ Expected Complexities

| Complexity       | Bound          |
|:----------------:|:--------------:|
| 🕐 Time          | $O(q \log q)$   |
| 💾 Auxiliary Space | $O(q)$         |

---

## 🏷️ Topic Tags

<div align="center">

![Arrays](https://img.shields.io/badge/Arrays-0A9EDC?style=for-the-badge)
![Bit Magic](https://img.shields.io/badge/Bit%20Magic-6C3483?style=for-the-badge)
![Data Structures](https://img.shields.io/badge/Data%20Structures-2C3E50?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../139_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../141_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
