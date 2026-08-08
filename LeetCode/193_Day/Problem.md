# [3302. Find the Lexicographically Smallest Valid Sequence](https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/description/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 24.3%](https://img.shields.io/badge/Acceptance-24.3%25-blue?style=for-the-badge)
![Submissions: 37.2K](https://img.shields.io/badge/Submissions-37.2K-lightgrey?style=for-the-badge)
![Topic: Two Pointers](https://img.shields.io/badge/Topics-Two_Pointers-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/String-blue?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic_Programming-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given two strings `word1` and `word2`.

A string `x` is called **almost equal** to `y` if you can change at most one character in `x` to make it identical to `y`.

A sequence of indices `seq` is called **valid** if:
- The indices are sorted in ascending order.
- Concatenating the characters at these indices in `word1` in the same order results in a string that is almost equal to `word2`.

Return an array of size `word2.length` representing the lexicographically smallest valid sequence of indices. If no such sequence of indices exists, return an empty array.

*Note that the answer must represent the lexicographically smallest array, not the corresponding string formed by those indices.*

---

## 📌 Examples

**Example 1:**
- **Input:** `word1 = "vbcca"`, `word2 = "abc"`
- **Output:** `[0,1,2]`
- **Explanation:**
  The lexicographically smallest valid sequence of indices is `[0, 1, 2]`:
  - Change `word1[0]` to 'a'.
  - `word1[1]` is already 'b'.
  - `word1[2]` is already 'c'.

**Example 2:**
- **Input:** `word1 = "bacdc"`, `word2 = "abc"`
- **Output:** `[1,2,4]`
- **Explanation:**
  The lexicographically smallest valid sequence of indices is `[1, 2, 4]`:
  - `word1[1]` is already 'a'.
  - Change `word1[2]` to 'b'.
  - `word1[4]` is already 'c'.

**Example 3:**
- **Input:** `word1 = "aaaaaa"`, `word2 = "aaabc"`
- **Output:** `[]`
- **Explanation:**
  There is no valid sequence of indices.

**Example 4:**
- **Input:** `word1 = "abc"`, `word2 = "ab"`
- **Output:** `[0,1]`

---

## 📐 Constraints

- $$1 \le \text{word2.length} < \text{word1.length} \le 3 \cdot 10^5$$
- `word1` and `word2` consist only of lowercase English letters.

---

## ⏱️ Expected Complexities

| Time Complexity | Space Complexity |
| :---: | :---: |
| $$O(N + M)$$ | $$O(M)$$ |

---

## 🏷️ Topic Tags

- `Two Pointers`
- `String`
- `Dynamic Programming`
- `Greedy`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../192_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../194_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
