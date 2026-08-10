# 195. [High Effort vs Low Effort](https://www.geeksforgeeks.org/problems/high-effort-vs-low-effort0213/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 51.79%](https://img.shields.io/badge/Accuracy-51.79%25-blue?style=for-the-badge)
![Submissions: 7K+](https://img.shields.io/badge/Submissions-7K+-purple?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given two integer arrays $h[]$ and $l[]$, where $h[i]$ and $l[i]$ denote the number of tasks that can be completed on the $i$-th day by performing a high-effort task and a low-effort task, respectively.

For each day, you may choose exactly one of the following:
1. Perform no task.
2. Perform a low-effort task.
3. Perform a high-effort task, which can only be performed on the first day or if no task was performed on the previous day.

Return the maximum total number of tasks that can be completed over all days.

---

## 📌 Examples

**Example 1:**
- **Input:** $h[] = [2, 8, 1]$, $l[] = [1, 2, 1]$
- **Output:** `9`
- **Explanation:** Pick the high-effort task on day 1 (value 8) and the low-effort task on day 2 (value 1) or low-effort on day 0 (value 1) and high-effort on day 1 (value 8). Total $= 8 + 1 = 9$.

**Example 2:**
- **Input:** $h[] = [3, 6, 8, 7, 6]$, $l[] = [1, 5, 4, 5, 3]$
- **Output:** `20`
- **Explanation:** Pick the high-effort task on day 0 (value 3) and low-effort tasks on all remaining days (values 5, 4, 5, 3). Total $= 3 + 5 + 4 + 5 + 3 = 20$.

---

## 📐 Constraints

- $1 \le h.size() \le 10^5$
- $0 \le h[i] \le 10^3$
- $1 \le l.size() \le 10^5$
- $0 \le l[i] \le 10^3$
- $l.size() = h.size()$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../194_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../196_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
