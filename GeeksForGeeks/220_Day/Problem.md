# 220. [Bird and Maximum Fruit Gathering](https://www.geeksforgeeks.org/problems/bird-and-maximum-fruit-gathering--170645/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-green?style=for-the-badge)
![Accuracy: 49.12%](https://img.shields.io/badge/Accuracy-49.12%25-green?style=for-the-badge)
![Submissions: 2K+](https://img.shields.io/badge/Submissions-2K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Company](https://img.shields.io/badge/Company-Facebook-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Arrays%20%7C%20Sliding%20Window-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an array `arr[]` representing the fruit values of trees arranged in a circle and an integer `m`, find the maximum total fruits the bird can collect by visiting at most `m` trees.

- The bird can start from any tree and move to a neighboring tree.
- The first and last trees are also considered neighbors (circular arrangement).
- The bird collects the fruit value of every tree it visits.

---

## 📌 Examples

**Example 1:**
```text
Input: arr[] = [2, 1, 3, 5, 0, 1, 4], m = 3
Output: 9
Explanation: 
The bird can start from the second tree and visit the second, third, and fourth trees.
The total fruit value collected is 1 + 3 + 5 = 9.
```

**Example 2:**
```text
Input: arr[] = [1, 6, 2, 5, 3, 4], m = 2
Output: 8
Explanation: 
The bird can start from the second tree and visit the second and third trees, collecting 6 + 2 = 8.
It can also start from the fourth tree and visit the fourth and fifth trees, collecting 5 + 3 = 8.
The maximum total fruit value is 8.
```

**Example 3:**
```text
Input: arr[] = [7, 2, 1, 3, 4], m = 2
Output: 11
Explanation: 
The bird can start from the fifth tree and visit the fifth and first trees, collecting 4 + 7 = 11.
These trees are neighbors because the trees are arranged in a circle.
The maximum total fruit value is 11.
```

---

## 📐 Constraints

- $1 \le \text{arr.size()}, m \le 10^6$
- $0 \le \text{arr}[i] \le 10^6$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../219_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../221_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
