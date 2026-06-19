# [143. Equalize All Prefix Sums](https://www.geeksforgeeks.org/problems/equalize-all-prefix-sums/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 69.73%](https://img.shields.io/badge/Accuracy-69.73%25-green?style=for-the-badge)
![Submissions: 20K+](https://img.shields.io/badge/Submissions-20K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a sorted array `arr[]`. For each `i` ($0 \le i \le n-1$), make all the elements of the array from index `0` to `i` equal, using the minimum number of operations.

In one operation you either increase or decrease the array element by `1`. Return an array that contains the minimum number of operations for each `i`, to accomplish the above task.

> [!NOTE]
> - For each index `i`, consider the original array without applying modifications made for previous indices.
> - Try to solve the problem using $O(1)$ extra space (excluding the resultant array).

---

## 📌 Examples

### Example 1
```text
Input: arr[] = [1, 6, 9, 12]
Output: [0, 5, 8, 14]
Explanation: 
- For i = 0, prefix [1] already has all equal elements, so operations = 0.
- For i = 1, make [1, 6] equal to 4, operations = |1 - 4| + |6 - 4| = 5.
- For i = 2, make [1, 6, 9] equal to 6, operations = |1 - 6| + |6 - 6| + |9 - 6| = 8.
- For i = 3, make [1, 6, 9, 12] equal to 8, operations = 7 + 2 + 1 + 4 = 14.
```

---

### Example 2
```text
Input: arr[] = [1, 1, 1, 7, 7, 10, 19]
Output: [0, 0, 0, 6, 12, 21, 33]
Explanation:
- For i = 0, prefix [1] already has equal elements, so operations = 0.
- For i = 1, prefix [1, 1] already has equal elements, so operations = 0.
- For i = 2, prefix [1, 1, 1] already has equal elements, so operations = 0.
- For i = 3, make [1, 1, 1, 7] equal to 1, operations = 6.
- For i = 4, make [1, 1, 1, 7, 7] equal to 1, operations = 12.
- For i = 5, make [1, 1, 1, 7, 7, 10] equal to 5, operations = 21.
- For i = 6, make [1, 1, 1, 7, 7, 10, 19] equal to 7, operations = 33.
```

---

## 📐 Constraints

- $$1 \le \text{arr.size()} \le 10^5$$
- $$-10^4 \le \text{arr}[i] \le 10^4$$
- Sum of $$n$$ over all test cases does not exceed $$10^6$$.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n)$$ |
| 💾 Auxiliary Space | $$O(n)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Arrays](https://img.shields.io/badge/Arrays-0A9EDC?style=for-the-badge)
![Sorting](https://img.shields.io/badge/Sorting-2C3E50?style=for-the-badge)
![Data Structures](https://img.shields.io/badge/Data%20Structures-E74C3C?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../142_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../144_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
