# [3614. Process String with Special Operations II](https://leetcode.com/problems/process-string-with-special-operations-ii/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 20.7%](https://img.shields.io/badge/Acceptance-20.7%25-blue?style=for-the-badge)
![Submissions: 76.8K](https://img.shields.io/badge/Submissions-76.8K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given a string `s` consisting of lowercase English letters and the special characters: `*`, `#`, and `%`.

You are also given an integer `k`.

Build a new string `result` by processing `s` according to the following rules from left to right:
- If the letter is a lowercase English letter, append it to `result`.
- A `*` removes the last character from `result`, if it exists.
- A `#` duplicates the current `result` and appends it to itself.
- A `%` reverses the current `result`.

Return the $k$-th character of the final string `result`. If `k` is out of the bounds of `result`, return `'.'`.

---

## 📌 Examples

### Example 1

**Input:** `s = "a#b%*", k = 1`  
**Output:** `"a"`  
**Explanation:**  

| $i$ | `s[i]` | Operation | Current `result` |
|:---:|:---:|:---|:---|
| 0 | `'a'` | Append `'a'` | `"a"` |
| 1 | `'#'` | Duplicate `result` | `"aa"` |
| 2 | `'b'` | Append `'b'` | `"aab"` |
| 3 | `'%'` | Reverse `result` | `"baa"` |
| 4 | `'*'` | Remove the last character | `"ba"` |

The final result is `"ba"`. The character at index $k = 1$ is `'a'`.

---

### Example 2

**Input:** `s = "cd%#*#", k = 3`  
**Output:** `"d"`  
**Explanation:**  

| $i$ | `s[i]` | Operation | Current `result` |
|:---:|:---:|:---|:---|
| 0 | `'c'` | Append `'c'` | `"c"` |
| 1 | `'d'` | Append `'d'` | `"cd"` |
| 2 | `'%'` | Reverse `result` | `"dc"` |
| 3 | `'#'` | Duplicate `result` | `"dcdc"` |
| 4 | `'*'` | Remove the last character | `"dcd"` |
| 5 | `'#'` | Duplicate `result` | `"dcddcd"` |

The final result is `"dcddcd"`. The character at index $k = 3$ is `'d'`.

---

### Example 3

**Input:** `s = "z*#", k = 0`  
**Output:** `"."`  
**Explanation:**  

| $i$ | `s[i]` | Operation | Current `result` |
|:---:|:---:|:---|:---|
| 0 | `'z'` | Append `'z'` | `"z"` |
| 1 | `'*'` | Remove the last character | `""` |
| 2 | `'#'` | Duplicate the string | `""` |

The final result is `""`. Since index $k = 0$ is out of bounds, the output is `'.'`.

---

## 📐 Constraints

- $$1 \le s.\text{length} \le 10^5$$
- `s` consists of only lowercase English letters and special characters `*`, `#`, and `%`.
- $$0 \le k \le 10^{15}$$
- The length of `result` after processing `s` will not exceed $$10^{15}$$.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
|:---:|:---|
| 🕐 Time | $$O(s.\text{length})$$ |
| 💾 Auxiliary Space | $$O(s.\text{length})$$ |

---

## 🏷️ Topic Tags

<div align="center">

![String](https://img.shields.io/badge/String-0A9EDC?style=for-the-badge)
![Simulation](https://img.shields.io/badge/Simulation-6C3483?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../140_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../142_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
