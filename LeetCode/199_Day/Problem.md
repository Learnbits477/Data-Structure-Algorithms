# [3090. Maximum Length Substring With Two Occurrences](https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-green?style=for-the-badge)
![Acceptance](https://img.shields.io/badge/Acceptance-67.4%25-orange?style=for-the-badge)
![Submissions](https://img.shields.io/badge/Submissions-112.2K-blue?style=for-the-badge)

![Topic: Hash Table](https://img.shields.io/badge/Topics:-Hash_Table-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/String-blue?style=for-the-badge)
![Topic: Sliding Window](https://img.shields.io/badge/Sliding_Window-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given a string `s`, return the maximum length of a substring such that it contains **at most two occurrences** of each character.

---

## 📌 Examples

### Example 1

**Input:**
```text
s = "bcbbbcba"
```

**Output:**
```text
4
```

**Explanation:**
The following substring has a length of 4 and contains at most two occurrences of each character: `"bcba"` (indices 4 to 7).


### Example 2

**Input:**
```text
s = "aaaa"
```

**Output:**
```text
2
```

**Explanation:**
The following substring has a length of 2 and contains at most two occurrences of each character: `"aa"`.


## 📐 Constraints

- $2 \le \text{s.length} \le 100$
- `s` consists only of lowercase English letters.

---

## ⏱️ Expected Complexities

| Operation | Time Complexity | Space Complexity |
| :--- | :---: | :---: |
| Sliding Window Scan | $O(N)$ | $O(1)$ |

---

<br/>

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../198_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../200_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
