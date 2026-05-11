# [Palindrome Pairs](https://www.geeksforgeeks.org/problems/palindrome-pairs/1)

| 📄 [Problem](Problem.md) | 💡 [Approach](Approach.md) | 🧠 [Solution](Solution.cpp) | 🚀 [Main](Main.cpp) |
|:---:|:---:|:---:|:---:|

---

**Difficulty**: Hard &nbsp;|&nbsp; **Accuracy**: 31.71% &nbsp;|&nbsp; **Submissions**: 23K+ &nbsp;|&nbsp; **Points**: 8

---

## Problem Statement

Given an array `arr[]` of `n` strings, determine whether there exists a pair of indices `(i, j)` such that:

- `i ≠ j`
- The concatenation `arr[i] + arr[j]` forms a **palindrome**

Return `true` if such a pair exists, otherwise return `false`.

> A string is a palindrome if it reads the same forward and backward.

---

## Examples

**Example 1**

```
Input  : arr[] = ["geekf", "geeks", "or", "keeg", "abc", "bc"]
Output : true
Reason : arr[0] + arr[3] = "geekf" + "keeg" = "geekfkeeg" → palindrome
```

**Example 2**

```
Input  : arr[] = ["abc", "xyxcba", "geekst", "or", "bc"]
Output : true
Reason : arr[0] + arr[1] = "abc" + "xyxcba" = "abcxyxcba" → palindrome
```

**Example 3**

```
Input  : arr[] = ["aa"]
Output : false
Reason : Only one string present, no valid pair (i ≠ j) possible
```

---

## Constraints

$$1 \leq n \leq 2 \times 10^4$$

$$1 \leq |arr[i]| \leq 10$$

---

| Happy Coding! 🚀 |
|:---:|
