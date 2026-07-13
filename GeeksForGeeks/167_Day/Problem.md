# [167. Rearrange the Array](https://www.geeksforgeeks.org/problems/rearrange-the-array-1639032648/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 38.08%](https://img.shields.io/badge/Accuracy-38.08%25-green?style=for-the-badge)
![Submissions: 5K+](https://img.shields.io/badge/Submissions-5K%2B-blue?style=for-the-badge)
![Points: 8](https://img.shields.io/badge/Points-8-yellow?style=for-the-badge)
![Company Tags](https://img.shields.io/badge/Company%20Tags-Flipkart-black?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Consider an array $a[] = [1, 2, 3, \dots, n]$ and a permutation $b[]$ of size $n$ containing all integers from $1$ to $n$ exactly once.

The array $b[]$ defines a rearrangement operation.
During a single operation, every element at position $i$ in $a[]$ moves to position $b[i]$ (1-based indexing).
We must do at least one operation on $a[]$.

Find the minimum number of operations required for all elements to return to their original positions simultaneously, i.e., for $a[]$ to become: $[1, 2, 3, \dots, n]$ again.

> [!NOTE]
> The answer can be large, so return the answer modulo $10^9+7$.

---

## 📌 Examples

### Example 1
**Input:**
```text
b[] = [1, 2, 3]
```
**Output:**
```text
1
```
**Explanation:**
Initially, $a[] = [1, 2, 3]$ and $b[] = [1, 2, 3]$.  
After one operation:  
- $a[1] = 1$ goes to position $1$ as $b[1] = 1$.  
- $a[2] = 2$ goes to position $2$ as $b[2] = 2$.  
- $a[3] = 3$ goes to position $3$ as $b[3] = 3$.  
So, now $a[]$ becomes $[1, 2, 3]$.  
All elements remain at their original positions. Hence, the answer is $1$.

### Example 2
**Input:**
```text
b[] = [2, 3, 1, 5, 4]
```
**Output:**
```text
6
```
**Explanation:**
The sequence of arrays obtained after each operation is:
- **Initially:** $[1, 2, 3, 4, 5]$
- **Operation 1:** $[3, 1, 2, 5, 4]$
- **Operation 2:** $[2, 3, 1, 4, 5]$
- **Operation 3:** $[1, 2, 3, 5, 4]$
- **Operation 4:** $[3, 1, 2, 4, 5]$
- **Operation 5:** $[2, 3, 1, 5, 4]$
- **Operation 6:** $[1, 2, 3, 4, 5]$

After $6$ operations, all elements return to their original positions simultaneously. Therefore, the answer is $6$.

---

## 📐 Constraints

- $$1 \le n \le 10^4$$
- $$a.size() = b.size() = n$$
- $$b[]$$ is a permutation of integers from $$1$$ to $$n$$.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n \log n)$$ or $$O(n \sqrt{n})$$ |
| 💾 Auxiliary Space | $$O(n)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![DFS](https://img.shields.io/badge/DFS-1ABC9C?style=for-the-badge)
![Prime Number](https://img.shields.io/badge/Prime%20Number-2ECC71?style=for-the-badge)
![LCS](https://img.shields.io/badge/LCS-3498DB?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-9B59B6?style=for-the-badge)

</div>



<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../166_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../168_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
