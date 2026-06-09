# [133. Seating Arrangement](https://www.geeksforgeeks.org/problems/seating-arrangement--170647/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 49.85%](https://img.shields.io/badge/Accuracy-49.85%25-green?style=for-the-badge)
![Submissions: 51K+](https://img.shields.io/badge/Submissions-51K+-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topics: Arrays | Greedy](https://img.shields.io/badge/Topics-Arrays%20%7C%20Greedy-lightgrey?style=for-the-badge)

## 🧩 Problem Description
Given an integer $k$ representing the number of people to be seated and an array `seats[]`, where `0` denotes an empty seat and `1` denotes an occupied seat.

Determine whether it is possible to seat all $k$ people such that no two occupied seats are adjacent (including newly seated people).

## 📌 Examples

**Example 1:**
```text
Input: k = 2, seats[] = [0, 0, 1, 0, 0, 0, 1]
Output: true
Explanation: The two people can sit at index 0 and 4.
```

**Example 2:**
```text
Input: k = 1, seats[] = [0, 1, 0]
Output: false
Explanation: There is no way to get a seat for one person.
```

## 📐 Constraints
- $$0 \le k \le 10^5$$
- $$1 \le \text{seats.size()} \le 10^5$$
- $$\text{seats}[i] == 0 \text{ or } \text{seats}[i] == 1$$

## ⏱️ Expected Complexities
| Parameter | Complexity |
|:---:|:---:|
| **Time Complexity** | $$O(m)$$ |
| **Auxiliary Space** | $$O(1)$$ |

## 🏷️ Topic Tags
`Arrays`, `Greedy`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../132_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../134_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
