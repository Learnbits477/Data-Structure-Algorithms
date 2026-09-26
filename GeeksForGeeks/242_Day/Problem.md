# 242. [Minimum Cost Pizza Selection](https://www.geeksforgeeks.org/problems/pizza-mania0155/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 51.11%](https://img.shields.io/badge/Accuracy-51.11%25-orange?style=for-the-badge)
![Submissions: 4K+](https://img.shields.io/badge/Submissions-4K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given the area of Small, Medium, and Large pizzas as $s$, $m$, and $l$ units, and their respective costs as $cs$, $cm$, and $cl$, find the minimum amount of money required to buy pizzas whose total area is **at least** $x$.

You may buy any number of pizzas of each type (unbounded selection).

---

## 📌 Examples

**Example 1:**

```text
Input: x = 16, s = 3, m = 6, l = 9, cs = 50, cm = 150, cl = 300
Output: 300
Explanation:
We want at least 16 sq. units of Pizza.
- One unit of each s, m, and l = 3 + 6 + 9 = 18 sq units, Cost = 50 + 150 + 300 = 500.
- 6 units of s = 18 sq units, Cost = 6 * 50 = 300.
- 2 units of l = 18 sq units, Cost = 2 * 300 = 600.
Of all possible arrangements, the minimum cost is Rs. 300.
```

**Example 2:**

```text
Input: x = 10, s = 1, m = 3, l = 10, cs = 10, cm = 20, cl = 50
Output: 50
Explanation:
Of all the arrangements possible:
- 10 units of s: Cost = 10 * 10 = 100 (area 10)
- 4 units of m: Cost = 4 * 20 = 80 (area 12)
- 3 units of m + 1 unit of s: Cost = 3 * 20 + 10 = 70 (area 10)
- 1 unit of l: Cost = 1 * 50 = 50 (area 10)
Minimum Cost is Rs. 50.
```

---

## 📐 Constraints

- $1 \le x \le 500$
- $1 \le s \le m \le l \le 100$
- $1 \le cs \le cm \le cl \le 100$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(x)$ |
| **Auxiliary Space** | $\mathcal{O}(x)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../241_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../243_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
