# [1358. Number of Substrings Containing All Three Characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 64.5%](https://img.shields.io/badge/Acceptance-64.5%25-blue?style=for-the-badge)
![Submissions: 110.2K](https://img.shields.io/badge/Submissions-110.2K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a string `s` consisting only of characters *a*, *b* and *c*.

Return the number of substrings containing **at least** one occurrence of all these characters *a*, *b* and *c*.

---

## 📌 Examples

### Example 1

**Input:** `s = "abcabc"`  
**Output:** `10`  
**Explanation:** The substrings containing at least one occurrence of the characters `a`, `b` and `c` are:
- `abc` (starting from index 0)
- `abca` (starting from index 0)
- `abcab` (starting from index 0)
- `abcabc` (starting from index 0)
- `bca` (starting from index 1)
- `bcab` (starting from index 1)
- `bcabc` (starting from index 1)
- `cab` (starting from index 2)
- `cabc` (starting from index 2)
- `abc` (starting from index 3)

Total count of such substrings is 10.

### Example 2

**Input:** `s = "aaacb"`  
**Output:** `3`  
**Explanation:** The substrings containing at least one occurrence of the characters `a`, `b` and `c` are:
- `aaacb` (starting from index 0)
- `aacb` (starting from index 1)
- `acb` (starting from index 2)

### Example 3

**Input:** `s = "abc"`  
**Output:** `1`  

---

## 📐 Constraints

- $$3 \le s.length \le 5 \times 10^4$$
- `s` only consists of characters `a`, `b` and `c`.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :--- |
| 🕐 Time | $$O(n)$$ where $$n$$ is the size of string `s`. |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![String](https://img.shields.io/badge/String-0A9EDC?style=for-the-badge)
![Sliding Window](https://img.shields.io/badge/Sliding%20Window-0A9EDC?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../153_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../155_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
