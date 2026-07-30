# [184. Maximum Subset XOR](https://www.geeksforgeeks.org/problems/maximum-subset-xor/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 28.93%](https://img.shields.io/badge/Accuracy-28.93%25-blue?style=for-the-badge)
![Submissions: 34K+](https://img.shields.io/badge/Submissions-34K%2B-purple?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Topics:-Arrays-blue?style=for-the-badge)
![Topic: Bit Magic](https://img.shields.io/badge/Bit_Magic-orange?style=for-the-badge)
![Company: Microsoft](https://img.shields.io/badge/Microsoft-black?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an array `arr[]`, choose any subset of elements (possibly all elements) such that the XOR of the chosen elements is maximized.

---

## 📌 Examples

**Example 1:**
- **Input:** `arr[] = [2, 4, 5]`
- **Output:** `7`
- **Explanation:** 
  The subset $\{2, 5\}$ has the maximum XOR value: $2 \oplus 5 = 7$.

**Example 2:**
- **Input:** `arr[] = [9, 8, 5]`
- **Output:** `13`
- **Explanation:** 
  The subset $\{8, 5\}$ has the maximum XOR value: $8 \oplus 5 = 13$.

---

## 📐 Constraints

- $1 \le arr.size() \le 10^5$
- $1 \le arr[i] \le 10^6$

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n \cdot \log(\max(arr[i])))$ |
| **Auxiliary Space** | $O(1)$ |

---

## 🏷️ Topic Tags

- Arrays
- Bit Magic

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../183_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../185_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
