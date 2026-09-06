# 222. [Sum of Pairwise ANDs](https://www.geeksforgeeks.org/problems/sum-of-products5049/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 50.93%](https://img.shields.io/badge/Accuracy-50.93%25-orange?style=for-the-badge)
![Submissions: 45K+](https://img.shields.io/badge/Submissions-45K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Mathematics%20%7C%20Bit%20Magic-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an array `arr[]` of integers, calculate the sum of bitwise AND for all pairs of elements such that the first index is less than the second index ($i < j$).

$$\text{Total Sum} = \sum_{0 \le i < j < n} (\text{arr}[i] \ \& \ \text{arr}[j])$$

---

## 📌 Examples

**Example 1:**
```text
Input: arr = [5, 10, 15]
Output: 15
Explanation: 
Consider all pairs of elements where the first index is less than the second index (i < j):
- (5, 10)  -> 5 & 10  = 0
- (5, 15)  -> 5 & 15  = 5
- (10, 15) -> 10 & 15 = 10

Now, add all these results:
0 + 5 + 10 = 15
So, the total sum of bitwise ANDs for all such pairs is 15.
```

**Example 2:**
```text
Input: arr = [10, 20, 30, 40]
Output: 46
Explanation: 
Consider all pairs of elements where the first index is less than the second index (i < j):
- (10, 20) -> 10 & 20 = 0
- (10, 30) -> 10 & 30 = 10
- (10, 40) -> 10 & 40 = 8
- (20, 30) -> 20 & 30 = 20
- (20, 40) -> 20 & 40 = 0
- (30, 40) -> 30 & 40 = 8

Now, add all these results:
0 + 10 + 8 + 20 + 0 + 8 = 46
So, the total sum of bitwise ANDs for all such pairs is 46.
```

---

## 📐 Constraints

- $1 \le \text{arr.size()} \le 10^5$
- $1 \le \text{arr}[i] \le 10^8$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../221_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../223_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
