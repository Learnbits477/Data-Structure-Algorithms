# [189. Pairs with Less Than K Diff](https://www.geeksforgeeks.org/problems/pairs-with-difference-less-than-k1348/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-green?style=for-the-badge)
![Accuracy: 33.07%](https://img.shields.io/badge/Accuracy-33.07%25-blue?style=for-the-badge)
![Submissions: 7K+](https://img.shields.io/badge/Submissions-7K+-purple?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Arrays-brightgreen?style=for-the-badge)
![Topic: Two Pointers](https://img.shields.io/badge/Two_Pointers-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-orange?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an array `arr[]` of positive integers and an integer `k`, find the total number of pairs of elements that have an absolute difference strictly less than `k`.

Note: Pair `(i, j)` is considered the same as `(j, i)`.

---

## 📌 Examples

**Example 1:**
- **Input:** `arr[] = [1, 10, 4, 2]`, `k = 3`
- **Output:** `2`
- **Explanation:** We have an array `arr[] = [1, 10, 4, 2]` and `k = 3`. We can make only two pairs with a difference of less than 3: `(1, 2)` and `(4, 2)`. So, the answer is `2`.

**Example 2:**
- **Input:** `arr[] = [2, 3, 4]`, `k = 5`
- **Output:** `3`
- **Explanation:** For the given array `arr[] = [2, 3, 4]` and `k = 5`, there are 3 valid pairs where the absolute difference between the pair's elements is less than 5. These pairs are `(2, 3)`, `(2, 4)`, and `(3, 4)`. Hence, the output is `3`.

---

## 📐 Constraints

- $1 \le arr.size() \le 10^5$
- $0 \le k \le 10^5$
- $1 \le arr[i] \le 10^5$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n \log n)$ |
| **Auxiliary Space** | $O(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../188_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../190_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
