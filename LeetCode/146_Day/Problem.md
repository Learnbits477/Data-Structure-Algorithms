# [1189. Maximum Number of Balloons](https://leetcode.com/problems/maximum-number-of-balloons/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 60.3%](https://img.shields.io/badge/Acceptance-60.3%25-blue?style=for-the-badge)
![Submissions: 300.2K](https://img.shields.io/badge/Submissions-300.2K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a string `text`, you want to use the characters of `text` to form as many instances of the word **"balloon"** as possible.

You can use each character in `text` **at most once**. Return the maximum number of instances that can be formed.

---

## 📌 Examples

### Example 1

**Input:** `text = "nlaebolko"`  
**Output:** `1`  
**Explanation:** We can form one instance of "balloon" using the characters: `b`, `a`, `l` (2), `o` (2), and `n`.

### Example 2

**Input:** `text = "loonbalxballpoon"`  
**Output:** `2`  
**Explanation:** We can form two instances of "balloon" using the characters.

### Example 3

**Input:** `text = "leetcode"`  
**Output:** `0`  
**Explanation:** We cannot form any instance of "balloon" since characters like `b`, `a`, `l`, `o`, `n` are missing or insufficient.

---

## 📐 Constraints

- $$1 \le text.length \le 10^4$$
- `text` consists of lowercase English letters only.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :--- |
| 🕐 Time | $$O(n)$$ where $$n$$ is the length of `text`. |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Hash Table](https://img.shields.io/badge/Hash%20Table-0A9EDC?style=for-the-badge)
![String](https://img.shields.io/badge/String-0A9EDC?style=for-the-badge)
![Counting](https://img.shields.io/badge/Counting-0A9EDC?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../145_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../147_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
