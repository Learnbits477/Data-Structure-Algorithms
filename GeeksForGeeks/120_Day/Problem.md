# [120. Wifi Range](https://www.geeksforgeeks.org/problems/wifi-range--170647/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 51.63%](https://img.shields.io/badge/Accuracy-51.63%25-blue?style=for-the-badge)
![Submissions: 37K+](https://img.shields.io/badge/Submissions-37K%2B-purple?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)

---

## 🧩 Problem Description

There are $n$ rooms in a straight line in Geekland State University's hostel. You are given a binary string $s$ of length $n$, where `s[i] = '1'` means there is a WiFi router in the $i$-th room, and `s[i] = '0'` means there is no WiFi in that room.

Each WiFi router has a range of $x$, meaning it can cover up to $x$ rooms to its left and $x$ rooms to its right.

Given $x$ and $s$, determine whether all rooms are covered by at least one WiFi router. Return `true` if all rooms are covered; otherwise, return `false`.

---

## 📌 Examples

### Example 1

**Input:** `x = 0`, `s = "010"`  
**Output:** `false`  
**Explanation:** Since the range is 0, so Wifi is only accessible in second room while 1st & 3rd room have no wifi. Therefore answer is false for this test case.

### Example 2

**Input:** `x = 1`, `s = "10010"`  
**Output:** `true`  
**Explanation:** 
- Index 0: WiFi is available.
- Index 1: Since the range of the 0th index is 1, WiFi is available here.
- Index 2: Since the range of the 3rd index is 1, WiFi is also available here.
- Index 3: WiFi is available.
- Index 4: The range of the 3rd index covers this position.  
So, all the rooms have WiFi. Therefore, the answer is true for this test case.

---

## 📐 Constraints

- $1 \le n \le 10^5$
- $0 \le x \le 10^5$

---

## ⏱️ Expected Complexities

| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(1)$ |

---

## 🏷️ Topic Tags

- `Strings`
- `Data Structures`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../119_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../121_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
