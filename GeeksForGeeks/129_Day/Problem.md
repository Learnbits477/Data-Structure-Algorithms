# [Lexicographically smallest after removing k](https://www.geeksforgeeks.org/problems/lexicographically-smallest-after-removing-k/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 49.97%](https://img.shields.io/badge/Accuracy-49.97%25-green?style=for-the-badge)
![Submissions: 20K+](https://img.shields.io/badge/Submissions-20K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)

## 🧩 Problem Description
Given a string `s` consisting of `n` lowercase characters. Return the lexicographically smallest string after removing exactly `k` characters from the string. But you have to correct the value of `k`, i.e., if the length of the string is a power of 2, reduce `k` by half, else multiply `k` by 2. You can remove any `k` characters.

> **Note:** If it is not possible to remove `k` (the value of `k` after correction) characters or if the resulting string is empty return `-1`.

## 📌 Examples

**Example 1:**
> **Input:** s = "fooland", k = 2
> **Output:** "and"
> **Explanation:** As the size of the string = 7 which is not a power of 2, hence k = 4. After removing 4 characters from the given string, the lexicographically smallest string is "and".

**Example 2:**
> **Input:** s = "code", k = 4
> **Output:** "cd"
> **Explanation:** As the length of the string = 4, which is 2 to the power 2, hence k = 2. Hence, lexicographically smallest string after removal of 2 characters is "cd".

## 📐 Constraints
- $$1 \le n \le 10^5$$
- $$1 \le k \le 10^5$$

## ⏱️ Expected Complexities
| Parameter | Complexity |
|:---:|:---:|
| **Time Complexity** | $$O(n + k)$$ |
| **Auxiliary Space** | $$O(n)$$ |

## 🏷️ Topic Tags
`Strings` `Stack` `Data Structures`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../128_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../130_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
