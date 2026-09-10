# 226. [Pairs with Given GCD and LCM](https://www.geeksforgeeks.org/problems/possible-pairs1550/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 41.76%](https://img.shields.io/badge/Accuracy-41.76%25-orange?style=for-the-badge)
![Submissions: 2K+](https://img.shields.io/badge/Submissions-2K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topic: Mathematics](https://img.shields.io/badge/Topic-Mathematics-blue?style=for-the-badge)
![Topic: Factorization](https://img.shields.io/badge/Factorization-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given two integers `x` and `y` representing the **GCD** and **LCM** of two unknown positive integers `a` and `b`, count the number of valid pairs `(a, b)` satisfying these conditions. 

**Note:** `(a, b)` and `(b, a)` are counted as distinct pairs when $a \neq b$.

---

## 📌 Examples

**Example 1:**

```text
Input: x = 2, y = 12
Output: 4
Explanation: The valid pairs are (2, 12), (4, 6), (6, 4), and (12, 2), since each pair has GCD = 2 and LCM = 12.
```

**Example 2:**

```text
Input: x = 6, y = 4
Output: 0
Explanation: LCM must always be a multiple of GCD. Since y is not divisible by x (4 % 6 != 0), no valid pair exists.
```

---

## 📐 Constraints

- $1 \le x, y \le 10^4$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(\sqrt{n} \log n)$ where $n = \frac{y}{x}$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---


<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../225_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../227_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
