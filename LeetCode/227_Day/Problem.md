# 3483. [Unique 3-Digit Even Numbers](https://leetcode.com/problems/unique-3-digit-even-numbers/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 72.2%](https://img.shields.io/badge/Acceptance-72.2%25-brightgreen?style=for-the-badge)
![Submissions: 86.5K+](https://img.shields.io/badge/Submissions-86.5K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Topic-Hash%20Table-blue?style=for-the-badge)
![Topic: Enumeration](https://img.shields.io/badge/Topic-Enumeration-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given an array of digits called `digits`. Your task is to determine the number of **distinct** three-digit even numbers that can be formed using these digits.

**Note:**
- Each copy of a digit can only be used **once** per number.
- There may **not** be leading zeros (i.e., numbers must be in the range $[100, 999]$).

---

## 📌 Examples

**Example 1:**

```text
Input: digits = [1,2,3,4]
Output: 12
Explanation: The 12 distinct 3-digit even numbers that can be formed are:
124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, and 432.
Note that 222 cannot be formed because there is only 1 copy of the digit 2.
```

**Example 2:**

```text
Input: digits = [0,2,2]
Output: 2
Explanation: The only 3-digit even numbers that can be formed are 202 and 220.
Note that the digit 2 can be used twice because it appears twice in the array.
```

**Example 3:**

```text
Input: digits = [6,6,6]
Output: 1
Explanation: Only 666 can be formed.
```

**Example 4:**

```text
Input: digits = [1,3,5]
Output: 0
Explanation: No even 3-digit numbers can be formed.
```

---

## 📐 Constraints

- $3 \le \text{digits.length} \le 10$
- $0 \le \text{digits}[i] \le 9$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(N^3)$ or $\mathcal{O}(1)$ since $N \le 10$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../226_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../228_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
