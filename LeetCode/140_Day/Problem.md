# [3612. Process String with Special Operations I](https://leetcode.com/problems/process-string-with-special-operations-i/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 69.2%](https://img.shields.io/badge/Acceptance-69.2%25-blue?style=for-the-badge)
![Submissions: 152.4K](https://img.shields.io/badge/Submissions-152.4K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given a string `s` consisting of lowercase English letters and the special characters: `*`, `#`, and `%`.

Build a new string `result` by processing `s` according to the following rules from left to right:
- If the letter is a lowercase English letter, append it to `result`.
- A `*` removes the last character from `result`, if it exists.
- A `#` duplicates the current `result` and appends it to itself.
- A `%` reverses the current `result`.

Return the final string `result` after processing all characters in `s`.

---

## 📌 Examples

### Example 1

**Input:** `s = "a#b%*"`  
**Output:** `"ba"`  
**Explanation:**  

| $i$ | `s[i]` | Operation | Current `result` |
|:---:|:---:|:---|:---|
| 0 | `'a'` | Append `'a'` | `"a"` |
| 1 | `'#'` | Duplicate `result` | `"aa"` |
| 2 | `'b'` | Append `'b'` | `"aab"` |
| 3 | `'%'` | Reverse `result` | `"baa"` |
| 4 | `'*'` | Remove the last character | `"ba"` |

Thus, the final result is `"ba"`.

### Example 2

**Input:** `s = "z*#"`  
**Output:** `""`  
**Explanation:**  

| $i$ | `s[i]` | Operation | Current `result` |
|:---:|:---:|:---|:---|
| 0 | `'z'` | Append `'z'` | `"z"` |
| 1 | `'*'` | Remove the last character | `""` |
| 2 | `'#'` | Duplicate the string | `""` |

Thus, the final result is `""`.

---

## 📐 Constraints

- $$1 \le s.\text{length} \le 20$$
- `s` consists of only lowercase English letters and special characters `*`, `#`, and `%`.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
|:---:|:---|
| 🕐 Time | $O(n \cdot 2^n)$ in the worst case (e.g. all `#` operations), but since $n \le 20$, the output length is at most $2^{20} \approx 10^6$ and easily fits in memory. |
| 💾 Auxiliary Space | $O(2^n)$ to store the duplicated characters in the output string. |

---

## 🏷️ Topic Tags

<div align="center">

![String](https://img.shields.io/badge/String-0A9EDC?style=for-the-badge)
![Simulation](https://img.shields.io/badge/Simulation-6C3483?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../139_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../141_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
