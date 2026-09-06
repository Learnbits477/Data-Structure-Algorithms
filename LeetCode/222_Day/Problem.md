# 115. [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 53.2%](https://img.shields.io/badge/Acceptance-53.2%25-green?style=for-the-badge)
![Submissions: 1.5M+](https://img.shields.io/badge/Submissions-1.5M%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-String%20%7C%20Dynamic%20Programming-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given two strings `s` and `t`, return the number of **distinct subsequences** of `s` which equals `t`.

The test cases are generated so that the answer fits on a **32-bit signed integer**.

---

## 📌 Examples

**Example 1:**
```text
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s:
1. rab_bbit -> rabbit (deleting the 1st 'b')
2. rabb_bit -> rabbit (deleting the 2nd 'b')
3. rabbb_it -> rabbit (deleting the 3rd 'b')
```

**Example 2:**
```text
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s:
1. ba__gbag -> bag
2. ba___bag -> bag
3. _ab_gbag -> bag
4. _ab__bag -> bag
5. ___bgbag -> bag
```

---

## 📐 Constraints

- $1 \le s.\text{length}, t.\text{length} \le 1000$
- $s$ and $t$ consist of English letters.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(m \cdot n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../221_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../223_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
