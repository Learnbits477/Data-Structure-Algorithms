# 209. [Count Prefix-Balanced Binary Strings](https://www.geeksforgeeks.org/problems/geek-and-his-binary-strings1951/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 44.17%](https://img.shields.io/badge/Acceptance-44.17%25-green?style=for-the-badge)
![Submissions: 16K+](https://img.shields.io/badge/Submissions-16K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Dynamic%20Programming-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Catalan%20Numbers-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Combinatorics-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an integer `n`, count the number of binary strings of length $2 \times n$ that contain exactly `n` ones and `n` zeros such that every prefix of the string contains at least as many ones as zeros. 

Since the answer can be very large, return it modulo $10^9 + 7$.

---

## 📌 Examples

**Example 1:**
```text
Input: n = 2
Output: 2
Explanation: 
The valid binary strings of length 4 containing two 1's and two 0's are:
1. "1100" -> Prefixes: "1" (1>=0), "11" (2>=0), "110" (2>=1), "1100" (2>=2)  [Valid]
2. "1010" -> Prefixes: "1" (1>=0), "10" (1>=1), "101" (2>=1), "1010" (2>=2)  [Valid]
Total valid strings = 2.
```

**Example 2:**
```text
Input: n = 3
Output: 5
Explanation: 
The 5 valid binary strings of length 6 containing three 1's and three 0's are:
1. "111000"
2. "110100"
3. "110010"
4. "101100"
5. "101010"
Total valid strings = 5.
```

---

## 📐 Constraints
- $1 \le n \le 1000$

---

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time** | $\mathcal{O}(n^2)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../208_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../210_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
