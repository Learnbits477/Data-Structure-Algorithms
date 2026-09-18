# [1520. Maximum Number of Non-Overlapping Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 45.5%](https://img.shields.io/badge/Acceptance-45.5%25-orange?style=for-the-badge)
![Submissions: 68.6K+](https://img.shields.io/badge/Submissions-68.6K%2B-blue?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Topic-Hash%20Table-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/String-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given a string `s` of lowercase English letters, you need to find the **maximum number of non-empty substrings** of `s` that meet the following conditions:

1. The substrings do not overlap, that is for any two substrings $s[i..j]$ and $s[x..y]$, either $j < x$ or $i > y$ is true.
2. A substring that contains a certain character $c$ must also contain **all occurrences** of $c$ in the entire string.

Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with **minimum total length**. It can be shown that there exists a unique solution of minimum total length.

Notice that you can return the substrings in any order.

---

## 📌 Examples

**Example 1:**

```text
Input: s = "adefaddaccc"
Output: ["e","f","ccc"]
Explanation:
The following are all the possible substrings that meet the conditions:
[
  "adefaddaccc",
  "adefadda",
  "ef",
  "e",
  "f",
  "ccc"
]
- If we choose the first string ("adefaddaccc"), we cannot choose anything else and we get only 1 substring.
- If we choose "adefadda", we are left with "ccc" which doesn't overlap, obtaining 2 substrings.
- Notice that "ef" can be split into two non-overlapping substrings "e" and "f".
Therefore, the optimal choice is ["e", "f", "ccc"] which gives us 3 substrings. No other solution of the same count with smaller total length exists.
```

**Example 2:**

```text
Input: s = "abbaccd"
Output: ["d","bb","cc"]
Explanation:
Notice that while the set of substrings ["d","abba","cc"] also has length 3, it is considered suboptimal since it has a larger total length (1 + 4 + 2 = 7 vs 1 + 2 + 2 = 5).
```

---

## 📐 Constraints

- $1 \le s\text{.length} \le 10^5$
- `s` contains only lowercase English letters.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

> Where $n$ is the length of string $s$. The alphabet size $\Sigma = 26$ is constant.

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../233_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../235_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
