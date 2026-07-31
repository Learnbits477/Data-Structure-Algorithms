# [3016. Minimum Number of Pushes to Type Word II](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/?envType=daily-question&envId=2026-07-28)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 81.1%](https://img.shields.io/badge/Acceptance-81.1%25-blue?style=for-the-badge)
![Submissions: 267K](https://img.shields.io/badge/Submissions-267K-purple?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Topics:-Hash_Table-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/String-cyan?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-brightgreen?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-orange?style=for-the-badge)
![Topic: Counting](https://img.shields.io/badge/Counting-violet?style=for-the-badge)
![Contest: Weekly Contest 381](https://img.shields.io/badge/Contest-Weekly_Contest_381-lightgrey?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given a string `word` containing lowercase English letters.

Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key `2` is mapped with `["a","b","c"]`, we need to push the key one time to type `"a"`, two times to type `"b"`, and three times to type `"c"`.

It is allowed to remap the keys numbered `2` to `9` to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string `word`.

Return the minimum number of pushes needed to type `word` after remapping the keys.

An example mapping of letters to keys on a telephone keypad is given below. Note that `1`, `*`, `#`, and `0` do not map to any letters.

<div align="center">
  <img src="./keypaddesc.png" alt="Telephone Keypad Mapping" width="329" height="313">
</div>

---

## 📌 Examples

**Example 1:**

<div align="center">
  <img src="./keypadv1e1.png" alt="Keypad Mapping Example 1" width="329" height="313">
</div>

- **Input:** `word = "abcde"`
- **Output:** `5`
- **Explanation:** 
  The remapped keypad given in the image provides the minimum cost.
  - `"a"` $\rightarrow$ one push on key `2`
  - `"b"` $\rightarrow$ one push on key `3`
  - `"c"` $\rightarrow$ one push on key `4`
  - `"d"` $\rightarrow$ one push on key `5`
  - `"e"` $\rightarrow$ one push on key `6`
  Total cost is $1 + 1 + 1 + 1 + 1 = 5$.
  It can be shown that no other mapping can provide a lower cost.

**Example 2:**

<div align="center">
  <img src="./keypadv2e1.png" alt="Keypad Mapping Example 2" width="329" height="313">
</div>

- **Input:** `word = "xyzxyzxyzxyz"`
- **Output:** `12`
- **Explanation:** 
  The remapped keypad given in the image provides the minimum cost.
  - `"x"` $\rightarrow$ one push on key `2`
  - `"y"` $\rightarrow$ one push on key `3`
  - `"z"` $\rightarrow$ one push on key `4`
  Total cost is $1 \times 4 + 1 \times 4 + 1 \times 4 = 12$.
  It can be shown that no other mapping can provide a lower cost.
  Note that key `9` is not mapped to any letter: it is not necessary to map letters to every key, but to map all the letters.

**Example 3:**
- **Input:** `word = "aabbccddeeffgghhiiiiii"`
- **Output:** `24`
- **Explanation:** 
  The remapped keypad provides the minimum cost:
  - `"a"`, `"b"`, `"c"`, `"d"`, `"e"`, `"f"`, `"g"` $\rightarrow$ one push each on keys `2` to `8`
  - `"i"` $\rightarrow$ one push on key `9`
  - `"h"` $\rightarrow$ two pushes on key `9`
  Total cost is $1 \times 2 + 1 \times 2 + 1 \times 2 + 1 \times 2 + 1 \times 2 + 1 \times 2 + 1 \times 2 + 2 \times 2 + 6 \times 1 = 24$.

---

## 📐 Constraints

- $1 \le word.length \le 10^5$
- `word` consists of lowercase English letters.

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../184_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../186_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
