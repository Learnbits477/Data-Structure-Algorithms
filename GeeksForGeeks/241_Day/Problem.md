# 241. [Box Stacking](https://www.geeksforgeeks.org/problems/box-stacking/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 41.0%](https://img.shields.io/badge/Accuracy-41.0%25-orange?style=for-the-badge)
![Submissions: 36K+](https://img.shields.io/badge/Submissions-36K%2B-blue?style=for-the-badge)
![Points: 8](https://img.shields.io/badge/Points-8-orange?style=for-the-badge)
![Company: Amazon](https://img.shields.io/badge/Company-Amazon-red?style=for-the-badge)
![Company: Microsoft](https://img.shields.io/badge/Microsoft-red?style=for-the-badge)
![Company: Codenation](https://img.shields.io/badge/Codenation-red?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given three arrays `height[]`, `width[]`, and `length[]` of size $n$, where `height[i]`, `width[i]`, and `length[i]` represent the dimensions of the $i^{\text{th}}$ box, find the maximum possible height of a stack formed using these boxes.

- A box can be rotated so that any of its dimensions becomes its height.
- A box can be placed on top of another only if both dimensions of its base are strictly smaller than those of the box below.
- Multiple instances of the same box can be used.

---

## 📌 Examples

**Example 1:**

```text
Input: height[] = [4, 1, 4, 10], width[] = [6, 2, 5, 12], length[] = [7, 3, 6, 32]
Output: 60
Explanation:
One possible arrangement of the boxes from bottom to top is:
- Box 4 with base (12, 32) and height 10
- Box 4 rotated with base (10, 12) and height 32
- Box 1 with base (6, 7) and height 4
- Box 3 with base (5, 6) and height 4
- Box 3 rotated with base (4, 5) and height 6
- Box 2 with base (2, 3) and height 1
- Box 2 rotated with base (1, 2) and height 3
Total height: 10 + 32 + 4 + 4 + 6 + 1 + 3 = 60.
No other combination of boxes produces a height greater than this.
```

**Example 2:**

```text
Input: height[] = [1, 4, 3], width[] = [2, 5, 4], length[] = [3, 6, 1]
Output: 15
Explanation:
One possible arrangement of the boxes from bottom to top is:
- Box 2 with base (5, 6) and height 4
- Box 2 rotated with base (4, 5) and height 6
- Box 1 with base (2, 3) and height 1
- Box 3 with base (1, 4) and height 3
- Box 1 rotated with base (1, 2) and height 1
Hence, the total height of this stack is 4 + 6 + 1 + 1 + 3 = 15.
No other combination of boxes produces a height greater than this.
```

---

## 📐 Constraints

- $1 \le \text{height.size}(), \text{width.size}(), \text{length.size}() \le 100$
- $1 \le \text{height}[i], \text{width}[i], \text{length}[i] \le 10^6$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n^2)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../240_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../242_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
