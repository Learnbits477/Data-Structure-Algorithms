# 206. [Transform String](https://www.geeksforgeeks.org/problems/transform-string5648/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 29.76%](https://img.shields.io/badge/Acceptance-29.76%25-green?style=for-the-badge)
![Submissions: 49K+](https://img.shields.io/badge/Submissions-49K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics:-Strings-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Hash-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Map-blue?style=for-the-badge)
![Company](https://img.shields.io/badge/Company-Directi-black?style=for-the-badge)

## 🧩 Problem Description

Given two strings `s1` and `s2`. Find the minimum number of steps required to transform string `s1` into string `s2`. The only allowed operation for the transformation is selecting a character from string `s1` and inserting it in the beginning of string `s1`.

If transformation is not possible, return `-1`.

## 📌 Examples

**Example 1:**
```text
Input: s1 = "abd", s2 = "bad"
Output: 1
Explanation: The conversion can take place in 1 operation: Pick 'b' and place it at the front.
```

**Example 2:**
```text
Input: s1 = "GeeksForGeeks", s2 = "ForGeeksGeeks"
Output: 3
Explanation: The conversion can take place in 3 operations:
1. Pick 'r' and place it at the front: s1 = "rGeeksFoGeeks"
2. Pick 'o' and place it at the front: s1 = "orGeeksFGeeks"
3. Pick 'F' and place it at the front: s1 = "ForGeeksGeeks"
```

## 📐 Constraints
- $1 \le s1.\text{length}(), s2.\text{length}() \le 10^4$
- `s1` and `s2` contain uppercase and lowercase English alphabets.

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time** | $\mathcal{O}(n)$ |
| **Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../205_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../207_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
