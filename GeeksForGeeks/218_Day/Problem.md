# [Unoccupied Computers](https://www.geeksforgeeks.org/problems/unoccupied-computers-1646661078/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 47.62%](https://img.shields.io/badge/Accuracy-47.62%25-green?style=for-the-badge)
![Submissions: 6K+](https://img.shields.io/badge/Submissions-6K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Hash%20%7C%20Simulation%20%7C%20Strings-blue?style=for-the-badge)

---

## 🧩 Problem Description

A cafe has $n$ computers. The customer events are represented by a string $s$ of uppercase English letters, where each distinct letter appears exactly twice:
- The **first occurrence** denotes the customer's **arrival**.
- The **second occurrence** denotes the customer's **departure**.

A customer is assigned a computer only if one is available at the time of arrival, otherwise the customer is **rejected** and does not use a computer.

Return the **number of customers who could not be assigned a computer upon arrival**.

---

## 📌 Examples

**Example 1:**
```text
Input: n = 3, s = "GACCBDDBAGEE"
Output: 1
Explanation: 
- 'G' arrives, gets computer 1 (occupied = 1)
- 'A' arrives, gets computer 2 (occupied = 2)
- 'C' arrives, gets computer 3 (occupied = 3)
- 'C' departs, frees computer 3 (occupied = 2)
- 'B' arrives, gets computer 3 (occupied = 3)
- 'D' arrives, all computers occupied -> D is rejected (rejected count = 1)
- 'D' departs, had no computer, ignored
- 'B' departs, frees computer 3 (occupied = 2)
- 'A' departs, frees computer 2 (occupied = 1)
- 'G' departs, frees computer 1 (occupied = 0)
- 'E' arrives, gets computer 1 (occupied = 1)
- 'E' departs, frees computer 1 (occupied = 0)
Only customer 'D' will not be able to get any computer. So the answer is 1.
```

**Example 2:**
```text
Input: n = 1, s = "ABCBAC"
Output: 2
Explanation: 
- 'A' arrives, gets computer 1 (occupied = 1)
- 'B' arrives, computer occupied -> B is rejected (rejected count = 1)
- 'C' arrives, computer occupied -> C is rejected (rejected count = 2)
- 'B' departs, ignored
- 'A' departs, frees computer 1 (occupied = 0)
- 'C' departs, ignored
Customers 'B' and 'C' will not be able to get any computers. So the answer is 2.
```

---

## 📐 Constraints

- $1 \le n \le 26$
- $1 \le |s| \le 52$
- $s$ consists of uppercase English letters and each distinct letter occurs exactly $2$ times.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(|s|)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../217_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../219_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
