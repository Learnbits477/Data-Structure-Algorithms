# 235. [Min Cost To Make Two Strings Identical](https://www.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical1107/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 52.29%](https://img.shields.io/badge/Accuracy-52.29%25-orange?style=for-the-badge)
![Submissions: 39K+](https://img.shields.io/badge/Submissions-39K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Strings](https://img.shields.io/badge/Strings-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given two strings `s1` and `s2`, and two integers `costS1` and `costS2`, where `costS1` is the cost of deleting one character from `s1` and `costS2` is the cost of deleting one character from `s2`, find the minimum cost required to make the two strings identical.

You can delete any number of characters from either string, but the order of the remaining characters must be preserved.

---

## 📌 Examples

**Example 1:**

```text
Input: s1 = "abcd", s2 = "acdb", costS1 = 10, costS2 = 20
Output: 30
Explanation:
Delete 'b' from both strings to obtain "acd".
Cost to delete 'b' from s1 = 10
Cost to delete 'b' from s2 = 20
The total cost is 10 + 20 = 30.
```

**Example 2:**

```text
Input: s1 = "ef", s2 = "gh", costS1 = 10, costS2 = 20
Output: 60
Explanation:
The two strings have no common characters, so delete all characters from both strings.
The total cost is (2 × 10) + (2 × 20) = 20 + 40 = 60.
```

---

## 📐 Constraints

- $1 \le |s1|, |s2| \le 1000$
- $1 \le costS1, costS2 \le 10^5$
- All characters in $s1$ and $s2$ are lowercase English letters.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(|s1| \times |s2|)$ |
| **Auxiliary Space** | $\mathcal{O}(\min(|s1|, |s2|))$ |

> Where $|s1|$ and $|s2|$ are the lengths of strings $s1$ and $s2$ respectively.

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../234_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../236_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
