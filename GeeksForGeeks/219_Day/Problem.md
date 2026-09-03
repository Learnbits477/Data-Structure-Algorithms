# 219. [Max Adjacent Diffs Sum with 1 Replacements](https://www.geeksforgeeks.org/problems/modify-array-to-maximize-sum-of-adjacent-differences1729/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 45.37%](https://img.shields.io/badge/Accuracy-45.37%25-green?style=for-the-badge)
![Submissions: 4K+](https://img.shields.io/badge/Submissions-4K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Dynamic%20Programming%20%7C%20Arrays-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an integer array `arr[]`, you are allowed to replace any elements with $1$. Find the **maximum sum of absolute differences between consecutive elements** after any number of modifications.

---

## 📌 Examples

**Example 1:**
```text
Input: arr[] = [3, 2, 1, 4, 5]
Output: 8
Explanation: 
Modify the array as arr[] = [3, 1, 1, 4, 1].
Sum = |1 - 3| + |1 - 1| + |4 - 1| + |1 - 4| = 2 + 0 + 3 + 3 = 8, which is the maximum possible.
```

**Example 2:**
```text
Input: arr[] = [1, 5]
Output: 4
Explanation: 
No modification needed. 
Sum = |5 - 1| = 4.
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
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../218_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../220_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
