# [166. Max Amount by Selling K Tickets](https://www.geeksforgeeks.org/problems/ticket-sellers3241/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 40.68%](https://img.shields.io/badge/Accuracy-40.68%25-green?style=for-the-badge)
![Submissions: 8K+](https://img.shields.io/badge/Submissions-8K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an integer array `arr[]`, where `arr[i]` denotes the number of tickets available with the $i$-th ticket seller.

The price of each ticket is equal to the number of tickets remaining with that seller at the time of sale. A seller can sell at most one ticket at a time, and after each sale, the price of the next ticket from that seller decreases by $1$.

All sellers are allowed to sell at most $k$ tickets in total. Find the maximum amount that can be earned by selling $k$ tickets. Return the answer modulo $10^9+7$.

---

## 📌 Examples

### Example 1
**Input:**
```text
arr[] = [4, 3, 6, 2, 4], k = 3
```
**Output:**
```text
15
```
**Explanation:**
One optimal sequence is to sell two tickets from the seller with 6 tickets (the price of the first would be 6 and the second 5) and one ticket from a seller with 4 tickets. This gives a total earning of $6 + 5 + 4 = 15$.

### Example 2
**Input:**
```text
arr[] = [5, 3, 5, 2, 4, 4], k = 2
```
**Output:**
```text
10
```
**Explanation:**
One optimal sequence is to sell one ticket each from the two sellers with 5 tickets, earning $5 + 5 = 10$.

---

## 📐 Constraints

- $$1 \le arr.size() \le 10^5$$
- $$1 \le arr[i], k \le 10^6$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(N \log N)$$ |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Arrays](https://img.shields.io/badge/Arrays-1ABC9C?style=for-the-badge)
![Data Structures](https://img.shields.io/badge/Data%20Structures-2ECC71?style=for-the-badge)
![Greedy](https://img.shields.io/badge/Greedy-3498DB?style=for-the-badge)
![Sorting](https://img.shields.io/badge/Sorting-9B59B6?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../165_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../167_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
