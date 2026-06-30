# [145. Choose and Swap](https://www.geeksforgeeks.org/problems/choose-and-swap0531/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 22.67%](https://img.shields.io/badge/Accuracy-22.67%25-red?style=for-the-badge)
![Submissions: 96K+](https://img.shields.io/badge/Submissions-96K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a string $s$ of lowercase English letters, you can swap all occurrences of any two distinct characters at most once. Return the lexicographically smallest string after this operation.

---

## 📌 Examples

### Example 1
```text
Input: s = "ccad"
Output: "aacd"
Explanation: In "ccad", we choose 'a' and 'c'. After doing the replacement operation once, we get "aacd", which is the lexicographically smallest string possible.
```

---

### Example 2
```text
Input: s = "abba"
Output: "abba"
Explanation: In "abba", we can get "baab" after doing the replacement operation once for 'a' and 'b', but that is not lexicographically smaller than "abba". So, the answer is "abba".
```

---

## 📐 Constraints

- $$1 \le |s| \le 10^5$$
- $s$ consists only of lowercase English letters (`'a'` - `'z'`)

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n)$$ |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Greedy](https://img.shields.io/badge/Greedy-FF5722?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../144_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../146_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
