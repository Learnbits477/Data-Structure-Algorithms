# [Search for Subarray](https://www.geeksforgeeks.org/problems/search-for-subarray/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 46.14%](https://img.shields.io/badge/Accuracy-46.14%25-orange?style=for-the-badge)
![Submissions: 3K+](https://img.shields.io/badge/Submissions-3K%2B-lightgrey?style=for-the-badge)
![Points: 8](https://img.shields.io/badge/Points-8-yellow?style=for-the-badge)
![Avg Time: 25m](https://img.shields.io/badge/Avg%20Time-25m-informational?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Topic: KMP Algorithm](https://img.shields.io/badge/Topic-KMP%20Algorithm-blueviolet?style=for-the-badge)

---

## 🧩 Problem Description

You are given two integer arrays `a[]` and `b[]`. Return all the starting indexes of all the occurrences of `b[]` as a subarray in `a[]`.

---

## 📌 Examples

### Example 1

```text
Input: 
  a[] = [2, 4, 1, 0, 4, 1, 1]
  b[] = [4, 1]

Output: [1, 4]

Explanation: 
  b[] occurs as a subarray in a[] from index 1 to 2 and from index 4 to 5.
```

### Example 2

```text
Input: 
  a[] = [2, 4, 1, 0, 0, 3]
  b[] = [0]

Output: [3, 4]

Explanation: 
  b[] occurs as a subarray in a[] from index 3 to 3 and from index 4 to 4.
```

### Example 3

```text
Input: 
  a[] = [1, 3, 5, 3, 0]
  b[] = [1, 3, 0]

Output: []

Explanation: 
  There is no subarray occurs as b[] in a[].
```

---

## 📐 Constraints

$$1 \leq \text{a.size()} \leq 10^6$$

$$1 \leq \text{b.size()} \leq \text{a.size()}$$

$$0 \leq b[i], a[i] \leq 10^4$$

---

## ⏱️ Expected Complexities

| Metric          | Complexity   |
|-----------------|--------------|
| Time Complexity | $O(N + M)$   |
| Auxiliary Space | $O(M)$       |

---

## 🏷️ Topic Tags

`Arrays` &nbsp; `Strings` &nbsp; `Pattern Matching` &nbsp; `KMP Algorithm`

---
<div align="center">
Happy Coding! 🚀 <br>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Twitter%20%2F%20X-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
</div>
