# [2574. Left and Right Sum Differences](https://leetcode.com/problems/left-and-right-sum-differences/description/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 88.4%](https://img.shields.io/badge/Acceptance-88.4%25-green?style=for-the-badge)
![Submissions: 281K](https://img.shields.io/badge/Submissions-281K-blue?style=for-the-badge)
![Topics: Array, Prefix Sum](https://img.shields.io/badge/Topics-Array%20%7C%20Prefix%20Sum-lightgrey?style=for-the-badge)

## 🧩 Problem Description
You are given a **0-indexed** integer array `nums` of size `n`.

Define two arrays `leftSum` and `rightSum` where:
- `leftSum[i]` is the sum of elements to the left of the index `i` in the array `nums`. If there is no such element, `leftSum[i] = 0`.
- `rightSum[i]` is the sum of elements to the right of the index `i` in the array `nums`. If there is no such element, `rightSum[i] = 0`.

Return an integer array `answer` of size `n` where `answer[i] = |leftSum[i] - rightSum[i]|`.

## 📌 Examples

**Example 1:**
```text
Input: nums = [10,4,8,3]
Output: [15,1,11,22]
Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
```

**Example 2:**
```text
Input: nums = [1]
Output: [0]
Explanation: The array leftSum is [0] and the array rightSum is [0].
The array answer is [|0 - 0|] = [0].
```

## 📐 Constraints
- $$1 \le \text{nums.length} \le 1000$$
- $$1 \le \text{nums}[i] \le 10^5$$

## ⏱️ Expected Complexities
| Parameter | Complexity |
|:---:|:---:|
| **Time Complexity** | $$O(n)$$ |
| **Auxiliary Space** | $$O(1)$$ |

## 🏷️ Topic Tags
`Array`, `Prefix Sum`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../129_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../131_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
