# [1871. Jump Game VII](https://leetcode.com/problems/jump-game-vii/description/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 31.5%](https://img.shields.io/badge/Acceptance-31.5%25-blue?style=for-the-badge)
![Submissions: 330.2K](https://img.shields.io/badge/Submissions-330.2K-purple?style=for-the-badge)
![Points: 3](https://img.shields.io/badge/Points-3-orange?style=for-the-badge)

---

![Company Tags](https://img.shields.io/badge/Company%20Tags-Amazon%20%7C%20Google%20%7C%20Adobe-black?style=for-the-badge)

---

## 🧩 Problem Description

You are given a **0-indexed** binary string `s` and two integers `minJump` and `maxJump`. In the beginning, you are standing at index `0`, which is equal to `'0'`. You can move from index `i` to index `j` if the following conditions are fulfilled:

- `i + minJump <= j <= min(i + maxJump, s.length - 1)`, and
- `s[j] == '0'`.

Return `true` if you can reach index `s.length - 1` in `s`, or `false` otherwise.

---

## 📌 Examples

### Example 1

**Input:** `s = "011010"`, `minJump = 2`, `maxJump = 3`  
**Output:** `true`  
**Explanation:**  
- In the first step, move from index 0 to index 3. 
- In the second step, move from index 3 to index 5.

### Example 2

**Input:** `s = "01101110"`, `minJump = 2`, `maxJump = 3`  
**Output:** `false`  
**Explanation:** Index 7 is `'0'`, but it cannot be reached from any reachable index.

---

## 📐 Constraints

- $2 \le \text{s.length} \le 10^5$
- `s[i]` is either `'0'` or `'1'`.
- `s[0] == '0'`
- $1 \le \text{minJump} \le \text{maxJump} < \text{s.length}$

---

## ⏱️ Expected Complexities

| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(n)$ |

---

## 🏷️ Topic Tags

- `Two Pointers`
- `String`
- `Dynamic Programming`
- `Sliding Window`
- `Algorithms`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../117_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../119_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
