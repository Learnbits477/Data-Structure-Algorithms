# 216. [Minimum Cost for n Characters](https://www.geeksforgeeks.org/problems/minimum-time1238/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 48.62%](https://img.shields.io/badge/Accuracy-48.62%25-green?style=for-the-badge)
![Submissions: 10K+](https://img.shields.io/badge/Submissions-10K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Dynamic%20Programming-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given four integers `n`, `i`, `d`, and `c`, where:
- `i` is the cost of inserting a single character,
- `d` is the cost of deleting the last character,
- `c` is the cost of copying the entire current string and pasting it immediately (thereby doubling its length).

Find the **minimum cost** required to obtain exactly `n` characters on the screen. Initially, the screen is empty.

---

## 📌 Examples

**Example 1:**
```text
Input: n = 9, i = 1, d = 2, c = 1
Output: 5
Explanation: 
Perform the following operations:
1. Insert (1 character)   -> Cost: 1
2. Insert (2 characters)  -> Cost: 1
3. Copy-paste (4 characters) -> Cost: 1
4. Copy-paste (8 characters) -> Cost: 1
5. Insert (9 characters)  -> Cost: 1
Total cost = 1 + 1 + 1 + 1 + 1 = 5.
```

**Example 2:**
```text
Input: n = 9, i = 10, d = 1, c = 1
Output: 17
Explanation: 
Perform the following operations:
1. Insert (1 character)       -> Cost: 10
2. Copy-paste (2 characters)  -> Cost: 1
3. Copy-paste (4 characters)  -> Cost: 1
4. Delete (3 characters)      -> Cost: 1
5. Copy-paste (6 characters)  -> Cost: 1
6. Delete (5 characters)      -> Cost: 1
7. Copy-paste (10 characters) -> Cost: 1
8. Delete (9 characters)      -> Cost: 1
Total cost = 10 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 17.
Since insertion is expensive, it is cheaper to use copy-paste operations and adjust the length using deletions.
```

---

## 📐 Constraints

- $1 \le n \le 10^6$
- $1 \le i, d, c \le 100$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../215_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../217_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
