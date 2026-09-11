# 227. [Values with Equal Array Remainders](https://www.geeksforgeeks.org/problems/k-modulus-array-element0255/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 50.64%](https://img.shields.io/badge/Accuracy-50.64%25-orange?style=for-the-badge)
![Submissions: 2K+](https://img.shields.io/badge/Submissions-2K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Topic: Mathematics](https://img.shields.io/badge/Mathematics-blue?style=for-the-badge)
![Topic: Number Theory](https://img.shields.io/badge/Number%20Theory-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an integer array `arr[]`, count the number of positive integers $k$ such that all elements of the array leave the same remainder when divided by $k$.

If there are infinitely many such values of $k$, return `-1`.

---

## 📌 Examples

**Example 1:**

```text
Input: arr[] = [38, 6, 34]
Output: 3
Explanation: The values of k for which all elements leave the same remainder when divided by k are 1, 2, and 4.
- For k = 1, all elements leave remainder 0.
- For k = 2, all elements leave remainder 0.
- For k = 4, all elements leave remainder 2.
No other positive integer satisfies the required condition. Hence, the answer is 3.
```

**Example 2:**

```text
Input: arr[] = [3, 2]
Output: 1
Explanation: The only positive integer for which both elements leave the same remainder is 1, since both numbers leave remainder 0 when divided by 1.
```

**Example 3:**

```text
Input: arr[] = [5, 5, 5]
Output: -1
Explanation: All elements in the array are equal. Therefore, for every positive integer k, all elements leave the same remainder when divided by k. Since there are infinitely many such values of k, the answer is -1.
```

---

## 📐 Constraints

- $1 \le \text{arr.size()}, \text{arr}[i] \le 10^5$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n + \sqrt{g})$ where $g = \gcd(|arr[i] - arr[0]|)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../226_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../228_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
