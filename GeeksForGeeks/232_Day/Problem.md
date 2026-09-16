# 232. [Dominant Pairs](https://www.geeksforgeeks.org/problems/dominant-pairs/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 50.57%](https://img.shields.io/badge/Accuracy-50.57%25-orange?style=for-the-badge)
![Submissions: 38K+](https://img.shields.io/badge/Submissions-38K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topic: Two Pointers](https://img.shields.io/badge/Topic-Two%20Pointers-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an even-sized integer array `arr[]`, count the number of **dominant pairs**.

A pair of indices $(i, j)$ is called **dominant** if all of the following conditions hold:
- $0 \le i < \dfrac{\text{arr.size}()}{2}$
- $\dfrac{\text{arr.size}()}{2} \le j < \text{arr.size}()$
- $\text{arr}[i] \ge 5 \times \text{arr}[j]$

Return the total number of dominant pairs.

> **Note:** $0$-based indexing is used.

---

## 📌 Examples

**Example 1:**

```text
Input: arr[] = [10, 2, 2, 1]
Output: 2
Explanation:
First half: [10, 2], Second half: [2, 1].
So valid two pairs are:
- {0, 2}: arr[0] = 10 >= 5 × arr[2] = 5 × 2 = 10
- {0, 3}: arr[0] = 10 >= 5 × arr[3] = 5 × 1 = 5
```

**Example 2:**

```text
Input: arr[] = [10, 8, 2, 1, 1, 2]
Output: 5
Explanation:
First half: [10, 8, 2], Second half: [1, 1, 2].
So valid five pairs are:
- {0, 3}: arr[0] = 10 >= 5 × arr[3] = 5 × 1 = 5
- {0, 4}: arr[0] = 10 >= 5 × arr[4] = 5 × 1 = 5
- {0, 5}: arr[0] = 10 >= 5 × arr[5] = 5 × 2 = 10
- {1, 3}: arr[1] = 8  >= 5 × arr[3] = 5 × 1 = 5
- {1, 4}: arr[1] = 8  >= 5 × arr[4] = 5 × 1 = 5
```

---

## 📐 Constraints

- $1 \le \text{arr.size}() \le 10^4$
- $-10^4 \le \text{arr}[i] \le 10^4$
- $\text{arr.size}()$ is even.
- The sum of $\text{arr.size}()$ over all test cases won't exceed $10^6$.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \log n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../231_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../233_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
