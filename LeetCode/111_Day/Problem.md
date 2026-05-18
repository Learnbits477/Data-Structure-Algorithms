# [111. Maximum Sum Problem](https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

--- 
## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 57.09%](https://img.shields.io/badge/Accuracy-57.09%25-blue?style=for-the-badge)
![Submissions: 66K+](https://img.shields.io/badge/Submissions-66K+-purple?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-blue?style=for-the-badge)

---

## 🧩 Problem Description
Given a number $n$, find its maximum sum value with 3 recursive breaks described below:

1. Break $n$ into three parts: $\lfloor n/2 \rfloor$, $\lfloor n/3 \rfloor$, and $\lfloor n/4 \rfloor$ (consider only the integer part or floor value).
2. Each number obtained in this process can be divided further recursively. 
3. At every step, we can take the maximum of the current value of $n$ or the sum of the maximum values obtained through the recursive process.
4. It is possible that we don't divide the number at all and choose it as the final answer.

---

## 📌 Examples

**Example 1:**
- **Input:** `n = 12`
- **Output:** `13`
- **Explanation:** 
  - Break $n = 12$ in three parts: `[12/2, 12/3, 12/4] = [6, 4, 3]`.
  - The current sum is: $(6 + 4 + 3) = 13$.
  - Further breaking $6$, $4$, and $3$ into parts will produce sums less than or equal to $6$, $4$, and $3$ respectively.
  - So, the maximum sum we can get is $13$.

**Example 2:**
- **Input:** `n = 24`
- **Output:** `27`
- **Explanation:** 
  - Break $n = 24$ in three parts: `[24/2, 24/3, 24/4] = [12, 8, 6]`.
  - The current sum is: $(12 + 8 + 6) = 26$.
  - However, recursively breaking $12$ would produce the value $13$.
  - So, our maximum sum is: $13 + 8 + 6 = 27$.

---

## 📐 Constraints
- $$0 \le n \le 10^6$$

---

## ⏱️ Expected Complexities
| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $$O(n)$$ |
| **Auxiliary Space** | $$O(n)$$ |

---

## 🏷️ Topic Tags
`Dynamic Programming`, `Recursion`, `Algorithms`

--- 

<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../110_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../112_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
