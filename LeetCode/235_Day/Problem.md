# [1401. Circle and Rectangle Overlapping](https://leetcode.com/problems/circle-and-rectangle-overlapping/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 63.3%](https://img.shields.io/badge/Acceptance-63.3%25-orange?style=for-the-badge)
![Submissions: 111.5K+](https://img.shields.io/badge/Submissions-111.5K%2B-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Topic: Geometry](https://img.shields.io/badge/Geometry-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given a circle represented as `(radius, xCenter, yCenter)` and an axis-aligned rectangle represented as `(x1, y1, x2, y2)`, where `(x1, y1)` are the coordinates of the bottom-left corner, and `(x2, y2)` are the coordinates of the top-right corner of the rectangle.

Return `true` if the circle and rectangle are overlapped otherwise return `false`. In other words, check if there is any point $(x_i, y_i)$ that belongs to the circle and the rectangle at the same time.

---

## 📌 Examples

**Example 1:**

```text
Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
Output: true
Explanation:
Circle and rectangle share the point (1, 0).
The Euclidean distance from circle center (0, 0) to nearest rectangle point (1, 0) is 1, which equals the radius 1.
```

**Example 2:**

```text
Input: radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
Output: false
Explanation:
The closest point on the rectangle to (1, 1) is (1, -1).
Distance = sqrt((1 - 1)^2 + (1 - (-1))^2) = sqrt(0 + 4) = 2.
Since 2 > radius (1), the shapes do not overlap.
```

**Example 3:**

```text
Input: radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
Output: true
Explanation:
Circle and rectangle overlap over the entire top-left quadrant of the circle.
```

---

## 📐 Constraints

- $1 \le \text{radius} \le 2000$
- $-10^4 \le \text{xCenter}, \text{yCenter} \le 10^4$
- $-10^4 \le x_1 < x_2 \le 10^4$
- $-10^4 \le y_1 < y_2 \le 10^4$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(1)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../234_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../236_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
