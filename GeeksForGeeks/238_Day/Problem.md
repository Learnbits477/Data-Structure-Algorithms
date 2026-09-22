# 238. [Longest Matching in Dictionary with Removals](https://www.geeksforgeeks.org/problems/find-largest-word-in-dictionary2430/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 43.54%](https://img.shields.io/badge/Accuracy-43.54%25-orange?style=for-the-badge)
![Submissions: 24K+](https://img.shields.io/badge/Submissions-24K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Company: Walmart](https://img.shields.io/badge/Company-Walmart-red?style=for-the-badge)
![Company: Google](https://img.shields.io/badge/Google-red?style=for-the-badge)
![Topic: Strings](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given a lowercase string `s` and a dictionary `d[]` containing lowercase words, find the longest word in the dictionary that can be obtained by deleting some characters from `s` without changing the order of the remaining characters.

> **Note:** If multiple words have the same maximum length, return the lexicographically smallest one. If no valid word exists, return an empty string `""`.

---

## 📌 Examples

**Example 1:**

```text
Input: d = ["ale", "apple", "monkey", "plea"], s = "abpcplea"
Output: "apple"
Explanation:
After deleting "b", "c", "a", s becomes "apple" which is present in d.
Words "ale", "apple", and "plea" can all be formed from s.
"apple" has length 5, whereas "ale" and "plea" have lengths 3 and 4 respectively.
Hence, "apple" is the longest valid word.
```

**Example 2:**

```text
Input: d = ["a", "b", "c"], s = "abpcplea"
Output: "a"
Explanation:
After deleting "b", "p", "c", "p", "l", "e", "a", s becomes "a" which is present in d.
All words "a", "b", and "c" can be formed and have the same maximum length of 1.
"a" is lexicographically smallest, so the output is "a".
```

---

## 📐 Constraints

- $1 \le |s| \le 5 \times 10^5$
- $1 \le n \le 10^4$ (where $n$ is the number of words in dictionary `d`)
- $1 \le m \le 100$ (where $m$ is the length of each word in `d`)
- `s` and all words in `d[]` consist only of lowercase English letters.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(|s| + n \times m \times \log|s|)$ |
| **Auxiliary Space** | $\mathcal{O}(|s|)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../237_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../239_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
