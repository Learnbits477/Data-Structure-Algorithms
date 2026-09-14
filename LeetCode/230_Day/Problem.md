# [836. Rectangle Overlap](https://leetcode.com/problems/rectangle-overlap/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 47.4%](https://img.shields.io/badge/Acceptance-47.4%25-orange?style=for-the-badge)
![Submissions: 411.8K+](https://img.shields.io/badge/Submissions-411.8K%2B-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Topic:-Math-blue?style=for-the-badge)
![Topic: Geometry](https://img.shields.io/badge/Geometry-blue?style=for-the-badge)

---

## 🧩 Problem Description

An axis-aligned rectangle is represented as a list `[x1, y1, x2, y2]`, where `(x1, y1)` is the coordinate of its bottom-left corner, and `(x2, y2)` is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.

Two rectangles overlap if the **area of their intersection is positive**. To be clear, two rectangles that only touch at the corner or edges do **not** overlap.

Given two axis-aligned rectangles `rec1` and `rec2`, return `true` if they overlap, otherwise return `false`.

---

## 📌 Examples

**Example 1:**

```text
Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true
Explanation: The intersection region is [1,1,2,2], which has a positive area of 1.
```

**Example 2:**

```text
Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output: false
Explanation: The two rectangles touch along the edge x = 1, but do not overlap (intersection area is 0).
```

**Example 3:**

```text
Input: rec1 = [0,0,1,1], rec2 = [2,2,3,3]
Output: false
Explanation: The rectangles do not intersect at all.
```

---

## 📐 Constraints

- $\text{rec1.length} == 4$
- $\text{rec2.length} == 4$
- $-10^9 \le \text{rec1}[i], \text{rec2}[i] \le 10^9$
- `rec1` and `rec2` represent a valid rectangle with a **non-zero area** (i.e., $\text{rec1}[0] < \text{rec1}[2]$ and $\text{rec1}[1] < \text{rec1}[3]$).

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(1)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../229_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../231_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
