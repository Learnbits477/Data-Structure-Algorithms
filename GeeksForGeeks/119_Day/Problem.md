# [119. Minimum Toogles to partition](https://www.geeksforgeeks.org/problems/minimum-toogles-to-partition0135/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 52.89%](https://img.shields.io/badge/Accuracy-52.89%25-blue?style=for-the-badge)
![Submissions: 15K+](https://img.shields.io/badge/Submissions-15K%2B-purple?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)

---

## 🧩 Problem Description

Given an array `arr[]` containing only `0`s and `1`s, find the minimum number of toggles (changing a `0` to `1` or a `1` to `0`) required to partition the array such that all `0`s appear before all `1`s.

---

## 📌 Examples

### Example 1

**Input:** `arr[] = [1, 0, 1, 1, 0]`  
**Output:** `2`  
**Explanation:** By toggling the first `1` to `0` and the last `0` to `1`, the array becomes `[0, 0, 1, 1, 1]`, which is partitioned (all `0`s appear before all `1`s). This requires `2` toggles.

### Example 2

**Input:** `arr[] = [0, 1, 0, 0, 1, 1, 1]`  
**Output:** `1`  
**Explanation:** By toggling the `1` at index 1 to `0`, the array becomes `[0, 0, 0, 0, 1, 1, 1]`, which is partitioned. This requires `1` toggle.

---

## 📐 Constraints

- $1 \le \text{arr.size()} \le 10^5$
- $0 \le \text{arr}[i] \le 1$

---

## ⏱️ Expected Complexities

| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(1)$ |

---

## 🏷️ Topic Tags

- `Arrays`
- `Dynamic Programming`
- `Algorithms`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../118_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../120_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
