# 239. [Pyramid Array with Reduce Operations](https://www.geeksforgeeks.org/problems/pyramid-form3044/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 38.97%](https://img.shields.io/badge/Accuracy-38.97%25-orange?style=for-the-badge)
![Submissions: 2K+](https://img.shields.io/badge/Submissions-2K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Arrays-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an array `arr[]` consisting of stones, where `arr[i]` represents the height of the $i^{\text{th}}$ stone.

You need to transform the stones into a pyramid by **only reducing** the heights of the stones. Reducing the height of a stone by $1$ costs $1$ unit, and stones cannot be increased or moved.

A valid pyramid consists of a contiguous subarray whose heights follow the pattern:
$$1, 2, 3, \dots, x - 1, x, x - 1, \dots, 2, 1$$
for some positive integer $x$.

Every stone outside this subarray must have a height of $0$.

Find the minimum total cost required to build a pyramid. It is guaranteed that at least one valid pyramid can always be formed.

---

## 📌 Examples

**Example 1:**

```text
Input: arr[] = [1, 2, 3, 4, 2, 1]
Output: 4
Explanation:
We can obtain the array [1, 2, 3, 2, 1, 0] by subtracting 2 out of 4, 1 out of 2, and 1 out of 1.
In total, we will subtract 2 + 1 + 1 = 4.
The resulting array forms a pyramid with peak height x = 3 centered at index 2.
```

**Example 2:**

```text
Input: arr[] = [1, 2, 1]
Output: 0
Explanation:
The array is already in pyramid form [1, 2, 1] with peak height x = 2.
No reductions are needed, so the cost is 0.
```

---

## 📐 Constraints

- $1 \le \text{arr.size()} \le 10^5$
- $1 \le \text{arr}[i] \le 10^5$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../238_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../240_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
