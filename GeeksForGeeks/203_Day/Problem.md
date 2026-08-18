# 203. [Secret Cipher](https://www.geeksforgeeks.org/problems/secret-cipher--141631/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 36.4%](https://img.shields.io/badge/Acceptance-36.4%25-brightgreen?style=for-the-badge)
![Submissions: 7K+](https://img.shields.io/badge/Submissions-7K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Stack-blue?style=for-the-badge)

## 🧩 Problem Description
Geek wants to send a secret message to his friend Keeg. Instead of sending the original message directly, he encrypts it by inserting the character `*`.

Keeg decodes the message as follows:
1. Traverse the encoded string from left to right and initialize the original string as empty.
2. Whenever a normal character appears, append it to the current original string.
3. Whenever `*` is encountered, remove it and append all characters before it to the end of the current original string.
4. Repeat until no `*` remains.

Given the original string `s`, find the lexicographically smallest encrypted string that decodes to `s`.

## 📌 Examples

**Example 1:**
```text
Input: s = "ababcababcd"
Output: ab*c*d
Explanation: We can encrypt the string in following way: "ababcababcd" -> "ababc*d" -> "ab*c*d"
```

**Example 2:**
```text
Input: s = "zzzzzzz"
Output: z*z*z
Explanation: The string can be encrypted in 2 ways: "z*z*z" and "z**zzz". Out of the two "z*z*z" is smaller in length.
```

## 📐 Constraints
- $$1 \le |s| \le 10^5$$

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time** | $\mathcal{O}(n)$ |
| **Space** | $\mathcal{O}(n)$ |
---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../202_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../204_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
