# [137. Binary Strings with Equal Sum of Two Halves](https://www.geeksforgeeks.org/problems/count-even-length1907/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 41.34%](https://img.shields.io/badge/Accuracy-41.34%25-green?style=for-the-badge)
![Submissions: 25K+](https://img.shields.io/badge/Submissions-25K+-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topics: Algorithms & Combinatorics](https://img.shields.io/badge/Topics-Algorithms%20%26%20Combinatorics-lightgrey?style=for-the-badge)

## 🧩 Problem Description
Given a number $$n$$, find count of all binary sequences of length $$2n$$ such that the sum of the first $$n$$ bits is the same as the sum of the last $$n$$ bits.

> [!NOTE]
> Since the answer can be very large, return the answer modulo $$10^9+7$$.

## 📌 Examples

**Example 1:**
```text
Input: n = 2
Output: 6
Explanation: There are 6 sequences of length 2*n, the sequences are 0101, 0110, 1010, 1001, 0000 and 1111.
```

**Example 2:**
```text
Input: n = 1
Output: 2
Explanation: There are 2 sequences of length 2*n, the sequences are 00 and 11.
```

## 📐 Constraints
- $$1 \le n \le 10^5$$

## ⏱️ Expected Complexities
| Parameter | Complexity |
|:---:|:---:|
| **Time Complexity** | $$O(n \log n)$$ |
| **Auxiliary Space** | $$O(1)$$ |

## 🏷️ Topic Tags
`Algorithms` `Mathematical` `Modular Arithmetic` `Combinatorics`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../136_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../138_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
