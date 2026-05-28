# 2707. Extra Characters in a String

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 38.3%](https://img.shields.io/badge/Acceptance-38.3%25-blue?style=for-the-badge)
![Submissions: 45.3K](https://img.shields.io/badge/Submissions-45.3K-purple?style=for-the-badge)

---

## 🧩 Problem Description

You are given two arrays of strings `wordsContainer` and `wordsQuery`.

For each `wordsQuery[i]`, you need to find a string from `wordsContainer` that has the longest common suffix with `wordsQuery[i]`. If there are two or more strings in `wordsContainer` that share the longest common suffix, find the string that is the smallest in length. If there are two or more such strings that have the same smallest length, find the one that occurred earlier in `wordsContainer`.

Return an array of integers `ans`, where `ans[i]` is the index of the string in `wordsContainer` that has the longest common suffix with `wordsQuery[i]`.

---

## 📌 Examples

### Example 1

**Input:** `wordsContainer = ["abcd","bcd","xbcd"]`, `wordsQuery = ["cd","bcd","xyz"]`  
**Output:** `[1,1,1]`  
**Explanation:**  
Let's look at each `wordsQuery[i]` separately:
- For `wordsQuery[0] = "cd"`, strings from `wordsContainer` that share the longest common suffix `"cd"` are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
- For `wordsQuery[1] = "bcd"`, strings from `wordsContainer` that share the longest common suffix `"bcd"` are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
- For `wordsQuery[2] = "xyz"`, there is no string from `wordsContainer` that shares a common suffix. Hence the longest common suffix is `""`, which is shared with strings at index 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.

### Example 2

**Input:** `wordsContainer = ["abcdefgh","poiuygh","ghghgh"]`, `wordsQuery = ["gh","acbfgh","acbfegh"]`  
**Output:** `[2,0,2]`  
**Explanation:**  
Let's look at each `wordsQuery[i]` separately:
- For `wordsQuery[0] = "gh"`, strings from `wordsContainer` that share the longest common suffix `"gh"` are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.
- For `wordsQuery[1] = "acbfgh"`, only the string at index 0 shares the longest common suffix `"fgh"`. Hence it is the answer, even though the string at index 2 is shorter.
- For `wordsQuery[2] = "acbfegh"`, strings from `wordsContainer` that share the longest common suffix `"gh"` are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.

---

## 📐 Constraints

- $1 \le \text{wordsContainer.length}, \text{wordsQuery.length} \le 10^4$
- $1 \le \text{wordsContainer}[i].length \le 5 \cdot 10^3$
- $1 \le \text{wordsQuery}[i].length \le 5 \cdot 10^3$
- `wordsContainer[i]` consists only of lowercase English letters.
- `wordsQuery[i]` consists only of lowercase English letters.
- Sum of `wordsContainer[i].length` is at most $5 \cdot 10^5$.
- Sum of `wordsQuery[i].length` is at most $5 \cdot 10^5$.

---

## ⏱️ Expected Complexities

| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $O(\sum |W_{\text{container}}| + \sum |W_{\text{query}}|)$ |
| **Auxiliary Space** | $O(\sum |W_{\text{container}}| \cdot 26)$ |

---

## 🏷️ Topic Tags

- `Array`
- `String`
- `Trie`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../120_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../122_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
