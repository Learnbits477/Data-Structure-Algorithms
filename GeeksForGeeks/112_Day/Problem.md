# [112. Minimum Multiplications to reach End](https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

--- 
## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 48.94%](https://img.shields.io/badge/Accuracy-48.94%25-blue?style=for-the-badge)
![Submissions: 203K+](https://img.shields.io/badge/Submissions-203K+-purple?style=for-the-badge)
![Topic: Graph](https://img.shields.io/badge/Topic-Graph-blue?style=for-the-badge)

---

## 🧩 Problem Description
Given two integers, `start` and `end`, along with an array of integers `arr[]`. In one operation, you can multiply the current value by any element from `arr[]`, and then take the result modulo $1000$ (or $100000$ in standard platform tests) to obtain a new value.

Find the minimum steps in which `end` can be achieved starting from `start`. If it is not possible to reach `end`, then return $-1$.

---

## 📌 Examples

**Example 1:**
- **Input:** `arr[] = [2, 5, 7]`, `start = 3`, `end = 30`
- **Output:** `2`
- **Explanation:** 
  - **Step 1:** $3 \times 2 = 6 \pmod{1000} = 6$
  - **Step 2:** $6 \times 5 = 30 \pmod{1000} = 30$

**Example 2:**
- **Input:** `arr[] = [3, 4, 65]`, `start = 7`, `end = 175`
- **Output:** `4`
- **Explanation:** 
  - **Step 1:** $7 \times 3 = 21 \pmod{1000} = 21$  
  - **Step 2:** $21 \times 3 = 63 \pmod{1000} = 63$  
  - **Step 3:** $63 \times 65 = 4095 \pmod{1000} = 95$  
  - **Step 4:** $95 \times 65 = 6175 \pmod{1000} = 175$ 

**Example 3:**
- **Input:** `arr[] = [2, 4]`, `start = 3`, `end = 5`
- **Output:** `-1`
- **Explanation:** Starting from $3$ and multiplying by $2$ or $4$ always produces even numbers after the first step. Since $5$ is odd, it can never be reached.

---

## 📐 Constraints
- $$1 \le \text{arr.size()} \le 10^3$$
- $$1 \le \text{arr}[i] \le 10^3$$
- $$0 \le \text{start}, \text{end} \le 10^3$$ (or up to $$10^5$$ on the official platform)

---

## ⏱️ Expected Complexities
| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $$O(N \times M)$$ |
| **Auxiliary Space** | $$O(M)$$ |

> Where $N$ is the number of elements in `arr[]` and $M$ is the modulo range (e.g. $1000$ or $100000$).

---

## 🏷️ Topic Tags
`Graph`, `Breadth-First Search`, `Queue`, `Data Structures`, `Algorithms`

--- 

<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../111_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../113_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
