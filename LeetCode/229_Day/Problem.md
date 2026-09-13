# [835. Image Overlap](https://leetcode.com/problems/image-overlap/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 66.3%](https://img.shields.io/badge/Acceptance-66.3%25-orange?style=for-the-badge)
![Submissions: 193.3K+](https://img.shields.io/badge/Submissions-193.3K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Matrix](https://img.shields.io/badge/Topic-Matrix-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given two images, `img1` and `img2`, represented as binary, square matrices of size $n \times n$. A binary matrix has only `0`s and `1`s as values.

We translate one image however we choose by sliding all the `1` bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the **overlap** by counting the number of positions that have a `1` in **both** images.

Note also that a translation does **not** include any kind of rotation. Any `1` bits that are translated outside of the matrix borders are erased.

Return the **largest possible overlap**.

---

## 📌 Examples

**Example 1:**

```text
Input: img1 = [[1,1,0],
               [0,1,0],
               [0,1,0]], 
       img2 = [[0,0,0],
               [0,1,1],
               [0,0,1]]
Output: 3
Explanation: We translate img1 to right by 1 unit and down by 1 unit.
The number of positions that have a 1 in both images is 3.
```

**Example 2:**

```text
Input: img1 = [[1]], img2 = [[1]]
Output: 1
```

**Example 3:**

```text
Input: img1 = [[0]], img2 = [[0]]
Output: 0
```

---

## 📐 Constraints

- $n == \text{img1.length} == \text{img1}[i].\text{length}$
- $n == \text{img2.length} == \text{img2}[i].\text{length}$
- $1 \le n \le 30$
- $\text{img1}[i][j]$ is either `0` or `1`.
- $\text{img2}[i][j]$ is either `0` or `1`.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(M_1 \cdot M_2 + n^2)$ |
| **Auxiliary Space** | $\mathcal{O}(M_1 + M_2 + n^2)$ |

*(where $M_1, M_2 \le n^2$ are the counts of `1` bits in `img1` and `img2` respectively)*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../228_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../230_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
