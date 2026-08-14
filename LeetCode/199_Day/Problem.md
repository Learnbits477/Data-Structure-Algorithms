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

#### 🧮 Dry Run Trace for Example 1:
- `right = 0 ('b')`: window = `"b"`, frequencies = `{b:1}`, `max_len = 1`
- `right = 1 ('c')`: window = `"bc"`, frequencies = `{b:1, c:1}`, `max_len = 2`
- `right = 2 ('b')`: window = `"bcb"`, frequencies = `{b:2, c:1}`, `max_len = 3`
- `right = 3 ('b')`: frequencies = `{b:3, c:1}` ❌ (`b` > 2). Shrink `left` from 0 to 1. window = `"cbb"`, frequencies = `{b:2, c:1}`, `max_len = 3`
- `right = 4 ('b')`: frequencies = `{b:3, c:1}` ❌. Shrink `left` from 1 to 3. window = `"bb"`, frequencies = `{b:2, c:0}`, `max_len = 3`
- `right = 5 ('c')`: window = `"bbc"`, frequencies = `{b:2, c:1}`, `max_len = 3`
- `right = 6 ('b')`: frequencies = `{b:3, c:1}` ❌. Shrink `left` from 3 to 4. window = `"bcb"`, frequencies = `{b:2, c:1}`, `max_len = 3`
- `right = 7 ('a')`: window = `"bcba"`, frequencies = `{b:2, c:1, a:1}`, `max_len = 4` ✅

---

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

#### 🧮 Dry Run Trace for Example 2:
- `right = 0 ('a')`: window = `"a"`, `freq[a] = 1`, `max_len = 1`
- `right = 1 ('a')`: window = `"aa"`, `freq[a] = 2`, `max_len = 2`
- `right = 2 ('a')`: `freq[a] = 3` ❌ > 2. Shrink `left` to 1 -> window = `"aa"`, `freq[a] = 2`, `max_len = 2`
- `right = 3 ('a')`: `freq[a] = 3` ❌ > 2. Shrink `left` to 2 -> window = `"aa"`, `freq[a] = 2`, `max_len = 2` ✅

---

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
