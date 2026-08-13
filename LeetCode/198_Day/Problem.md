# [Longest Substring of One Repeating Character](https://leetcode.com/problems/longest-substring-of-one-repeating-character/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance](https://img.shields.io/badge/Acceptance-46.9%25-orange?style=for-the-badge)
![Submissions](https://img.shields.io/badge/Submissions-30K-blue?style=for-the-badge)

![Topic: Segment Tree](https://img.shields.io/badge/Topics:-Segment_Tree-blue?style=for-the-badge)
![Topic: Ordered Set](https://img.shields.io/badge/Ordered_Set-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Array-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/String-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given a **0-indexed** string `s`. You are also given a **0-indexed** string `queryCharacters` of length `k` and a **0-indexed** array of integer indices `queryIndices` of length `k`, both of which are used to describe `k` queries.

The $i$-th query updates the character in `s` at index `queryIndices[i]` to the character `queryCharacters[i]`.

Return an array `lengths` of length `k` where `lengths[i]` is the length of the longest substring of `s` consisting of only one repeating character after the $i$-th query is performed.

---

## 📌 Examples

### Example 1

**Input:**
```text
s = "babacc"
queryCharacters = "bcb"
queryIndices = [1, 3, 3]
```

**Output:**
```text
[3, 3, 4]
```

**Explanation:**
- **1st query:** Updates `s` to `"bbbacc"`. The longest substring consisting of one repeating character is `"bbb"` with length $3$.
- **2nd query:** Updates `s` to `"bbbccc"`. The longest substring consisting of one repeating character can be `"bbb"` or `"ccc"` with length $3$.
- **3rd query:** Updates `s` to `"bbbbcc"`. The longest substring consisting of one repeating character is `"bbbb"` with length $4$.
Thus, we return `[3, 3, 4]`.

### Example 2

**Input:**
```text
s = "abyzz"
queryCharacters = "aa"
queryIndices = [2, 1]
```

**Output:**
```text
[2, 3]
```

**Explanation:**
- **1st query:** Updates `s` to `"abazz"`. The longest substring consisting of one repeating character is `"zz"` with length $2$.
- **2nd query:** Updates `s` to `"aaazz"`. The longest substring consisting of one repeating character is `"aaa"` with length $3$.
Thus, we return `[2, 3]`.

---

## 📐 Constraints

- $1 \le \text{s.length} \le 10^5$
- `s` consists of lowercase English letters.
- $k == \text{queryCharacters.length} == \text{queryIndices.length}$
- $1 \le k \le 10^5$
- `queryCharacters` consists of lowercase English letters.
- $0 \le \text{queryIndices}[i] < \text{s.length}$

---

## ⏱️ Expected Complexities

| Operation | Time Complexity | Space Complexity |
| :--- | :---: | :---: |
| Build Segment Tree | $O(N)$ | $O(N)$ |
| Point Update | $O(\log N)$ | $O(1)$ |
| Overall Complexity | $O(N + K \log N)$ | $O(N)$ |

---

## 🏷️ Topic Tags

- `Array`
- `String`
- `Segment Tree`
- `Ordered Set`

<br/>

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../197_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../199_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
