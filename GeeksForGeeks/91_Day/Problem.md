# [Longest Repeating Character Replacement](https://www.geeksforgeeks.org/problems/longest-repeating-character-replacement/1)

<div align="center">
  <img src="https://img.shields.io/badge/Difficulty-Medium-yellow.svg?style=for-the-badge&logo=geeksforgeeks" alt="Difficulty">
  <img src="https://img.shields.io/badge/Accuracy-50.04%25-green.svg?style=for-the-badge" alt="Accuracy">
</div>

## Problem Statement

Given a string `s` of length `n` consisting of uppercase English letters and an integer `k`, you are allowed to perform at most `k` operations. In each operation, you can change any character of the string to any other uppercase English letter.

Determine the length of the longest substring that can be transformed into a string with all identical characters after performing at most `k` such operations.

### Examples:

**Example 1:**
```
Input: s = "ABBA", k = 2 
Output: 4 
Explanation: The string "ABBA" can be fully converted into the same character using at most 2 changes. By replacing both 'A' with 'B', it becomes "BBBB". Hence, the maximum length is 4.
```

**Example 2:**
```
Input: s = "ADBD", k = 1
Output: 3
Explanation: In the string "ADBD", we can make at most 1 change. By changing 'B' to 'D', the string becomes "ADDD", which contains a substring "DDD" of length 3.
```

### Constraints:
- $1 \le n, k \le 10^5$
- `s` consists of only uppercase English letters.

## Related Files
- [Approach & Explanation](Approach.md)
- [C++ Solution](Solution.cpp)
- [Test Driver](Main.cpp)
