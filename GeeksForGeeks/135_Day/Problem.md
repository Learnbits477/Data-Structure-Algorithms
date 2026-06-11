# [135. Equal Point in Brackets](https://www.geeksforgeeks.org/problems/find-equal-point-in-string-of-brackets2542/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 40.8%](https://img.shields.io/badge/Accuracy-40.8%25-green?style=for-the-badge)
![Submissions: 34K+](https://img.shields.io/badge/Submissions-34K+-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topics: Strings](https://img.shields.io/badge/Topics-Strings-lightgrey?style=for-the-badge)

## 🧩 Problem Description
Given a string `s` of opening and closing brackets `'('` and `')'` only, find an equal point in the string. An equal point is a position `k` (0-based) such that the number of opening brackets before position `k` is equal to the number of closing brackets from position `k` to the end of the string. If multiple such points exist, return the first valid position.

The string can be split at any position from `0` to `n`, where `n` is the length of the string.
- If we split at `0`, it means there is an empty string on the left.
- If we split at `n`, it means there is an empty string on the right.

## 📌 Examples

**Example 1:**
```text
Input: s = "(())))("
Output: 4
Explanation: After split at index 4, the string splits into "(())" and "))(".
- Number of opening brackets in the first part is 2.
- Number of closing brackets in the second part is 2.
They are equal, hence 4 is the equal point.
```

**Example 2:**
```text
Input: s = "))"
Output: 2
Explanation: After split at index 2, the string splits into "))" and an empty string "".
- Number of opening brackets in the first part is 0.
- Number of closing brackets in the second part is 0.
They are equal, hence 2 is the equal point.
```

## 📐 Constraints
- $$1 \le \text{s.size()} \le 10^5$$
- The string contains only characters `'('` and `')'`.

## ⏱️ Expected Complexities
| Parameter | Complexity |
|:---:|:---:|
| **Time Complexity** | $$O(n)$$ |
| **Auxiliary Space** | $$O(1)$$ |

## 🏷️ Topic Tags
`Strings` `Arrays` `DataStructures`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../134_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../136_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
