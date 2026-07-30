# [3014. Minimum Number of Pushes to Type Word I](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/?envType=daily-question&envId=2026-07-30)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 70.6%](https://img.shields.io/badge/Acceptance-70.6%25-blue?style=for-the-badge)
![Submissions: 102.2K](https://img.shields.io/badge/Submissions-102.2K-purple?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Topics:-Math-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/String-cyan?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given a string `word` containing distinct lowercase English letters.

Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key `2` is mapped with `["a","b","c"]`, we need to push the key one time to type `"a"`, two times to type `"b"`, and three times to type `"c"`.

It is allowed to remap the keys numbered `2` to `9` to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string `word`.

Return the minimum number of pushes needed to type `word` after remapping the keys.

An example mapping of letters to keys on a telephone keypad is given below. Note that `1`, `*`, `#`, and `0` do not map to any letters.

<div align="center">
  <img src="https://assets.leetcode.com/uploads/2023/12/26/keypaddesc.png" alt="Telephone Keypad Mapping" width="329" height="313">
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
  <img src="./keypadv1e2.png" alt="Keypad Mapping Example 2" width="329" height="313">
</div>

- **Input:** `word = "xycdefghij"`
- **Output:** `12`
- **Explanation:** 
  The remapped keypad given in the image provides the minimum cost.
  - `"x"` $\rightarrow$ one push on key `2`
  - `"y"` $\rightarrow$ two pushes on key `2`
  - `"c"` $\rightarrow$ one push on key `3`
  - `"d"` $\rightarrow$ two pushes on key `3`
  - `"e"` $\rightarrow$ one push on key `4`
  - `"f"` $\rightarrow$ one push on key `5`
  - `"g"` $\rightarrow$ one push on key `6`
  - `"h"` $\rightarrow$ one push on key `7`
  - `"i"` $\rightarrow$ one push on key `8`
  - `"j"` $\rightarrow$ one push on key `9`
  Total cost is $1 + 2 + 1 + 2 + 1 + 1 + 1 + 1 + 1 + 1 = 12$.
  It can be shown that no other mapping can provide a lower cost.

---

## 📐 Constraints

- $1 \le word.length \le 26$
- `word` consists of lowercase English letters.
- All letters in `word` are distinct.

---

## ⏱️ Expected Complexities

| Complexity | Expected |
| :--- | :--- |
| **Time Complexity** | $O(n)$ |
| **Auxiliary Space** | $O(1)$ |

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
