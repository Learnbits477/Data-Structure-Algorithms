# [Pairs with certain difference](https://www.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 63.41%](https://img.shields.io/badge/Accuracy-63.41%25-blue?style=for-the-badge)
![Submissions: 41K+](https://img.shields.io/badge/Submissions-41K+-blueviolet?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topic Tags: Arrays, DP](https://img.shields.io/badge/Topic_Tags-Arrays%20|%20DP-lightgrey?style=for-the-badge)

## 🧩 Problem Description

Given an array of integers and a number `k`, the task is the find maximum pair sum with the following conditions on the pairs.
- Pair difference should be less than `k`.
- Pairs should be disjoint. For example if `(x, y)` is a result pair, then neither `x` nor `y` should appear in any other result pair.
- Sum of `p` pairs means sum of `2p` elements in the result.
- If no valid pairs can be formed, return 0.

## 📌 Examples

**Example 1:**
```text
Input: arr[] = [3, 5, 10, 15, 17, 12, 9], K = 4
Output: 62
Explanation :
The valid disjoint pairs with difference less than K are:
(3, 5), (10, 12), (15, 17)
The maximum sum obtained from these pairs is:
3 + 5 + 10 + 12 + 15 + 17 = 62
An alternative pairing could be:
(3, 5), (9, 12), (15, 17)
However, this combination results in a smaller total sum, so it is not optimal.
```

**Example 2:**
```text
Input: arr[] = [5, 15, 10, 300], k = 12
Output: 25
Explanation: 
The valid disjoint pairs with difference less than k are:
(5, 10)
The maximum sum obtained from these pairs is:
5 + 10 = 15
An alternative pairing could be:
(10, 15)
However, this combination results in a larger total sum:
10 + 15 = 25. So this pairing is optimal.
```

## 📐 Constraints

- $$1 \leq \text{arr.size()} \leq 10^5$$
- $$0 \leq k \leq 10^5$$
- $$1 \leq \text{arr}[i] \leq 10^4$$

## ⏱️ Expected Complexities

| Complexity | Expected |
|:---|:---|
| **Time Complexity** | $$O(n \log n)$$ |
| **Space Complexity** | $$O(n)$$ |

## 🏷️ Topic Tags
`Arrays`, `Dynamic Programming`, `Data Structures`, `Algorithms`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../125_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../127_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
