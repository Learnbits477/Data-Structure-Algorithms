# 240. [Maximum Height Disc Stack](https://www.geeksforgeeks.org/problems/stacking-up-discs1315/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 36.87%](https://img.shields.io/badge/Accuracy-36.87%25-orange?style=for-the-badge)
![Submissions: 2K+](https://img.shields.io/badge/Submissions-2K%2B-blue?style=for-the-badge)
![Points: 8](https://img.shields.io/badge/Points-8-orange?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given two arrays `r[]` and `h[]` of size $n$, where `r[i]` and `h[i]` represent the radius and height of the $i^{\text{th}}$ circular disc, respectively.

A disc can be placed above another disc only if both its radius and height are strictly smaller than those of the disc below it.

Find the maximum possible height of a stack that can be formed using the given discs. Each disc can be used at most once.

---

## 📌 Examples

**Example 1:**

```text
Input: r[] = [5, 7, 3], h[] = [6, 5, 4]
Output: 10
Explanation:
The discs (3, 4) and (5, 6) form a valid stack:
Disc (3, 4) is placed above disc (5, 6) because both radius 3 < 5 and height 4 < 6.
Therefore, the maximum possible height is 4 + 6 = 10.
```

**Example 2:**

```text
Input: r[] = [3, 7], h[] = [7, 4]
Output: 7
Explanation:
Neither disc can be placed above the other because both required dimensions are not strictly smaller:
Radius 3 < 7, but height 7 > 4.
Therefore, the maximum possible height is 7 (using a single disc of height 7).
```

---

## 📐 Constraints

- $1 \le r.\text{size}(), h.\text{size}() \le 10^5$
- $1 \le r[i], h[i] \le 1000$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \log n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../239_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../241_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
