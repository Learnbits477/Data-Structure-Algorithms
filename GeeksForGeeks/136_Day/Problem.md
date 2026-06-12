# [136. Check Repeated Substring with K Replacements](https://www.geeksforgeeks.org/problems/check-if-a-string-is-repetition-of-its-substring-of-k-length3302/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 53.15%](https://img.shields.io/badge/Accuracy-53.15%25-green?style=for-the-badge)
![Submissions: 46K+](https://img.shields.io/badge/Submissions-46K+-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topics: Strings & Map](https://img.shields.io/badge/Topics-Strings%20%26%20Map-lightgrey?style=for-the-badge)

## 🧩 Problem Description
Given a string `s` and an integer `k`, check if it is possible to convert `s` to a string that is a repetition of a substring with `k` characters, else return `false` (`0`). In order to convert, we can replace one substring of length `k` with any `k` characters.

> [!NOTE]
> In one operation, you can replace any substring of length `k` whose starting index `i` (0-based) satisfies `i % k == 0` with any sequence of `k` characters.

## 📌 Examples

**Example 1:**
```text
Input: s = "abcbedabcabc", k = 3
Output: true
Explanation: Replace "bed" with "abc" so that the whole string becomes repetition of "abc".
```

**Example 2:**
```text
Input: s = "bdac", k = 2
Output: true
Explanation: The string can be divided into substrings of length k: ["bd", "ac"]. 
Since there are exactly two substrings and both are different, we can make them identical by replacing one substring with the other. Hence, the result is true.
```

**Example 3:**
```text
Input: s = "abcdabcd", k = 2
Output: false
Explanation: Since we are allowed to change only one instance, we cannot convert.
```

## 📐 Constraints
- $$2 \le k \le \text{s.size()} \le 10^5$$

## ⏱️ Expected Complexities
| Parameter | Complexity |
|:---:|:---:|
| **Time Complexity** | $$O(n)$$ |
| **Auxiliary Space** | $$O(n)$$ |

## 🏷️ Topic Tags
`Strings` `Map` `Data Structures`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../135_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../137_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
