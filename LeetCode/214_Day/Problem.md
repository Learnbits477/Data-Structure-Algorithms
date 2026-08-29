# 2948. [Make Lexicographically Smallest Array by Swapping Elements](https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 63.6%](https://img.shields.io/badge/Acceptance-63.6%25-green?style=for-the-badge)
![Submissions: 217.3K](https://img.shields.io/badge/Submissions-217.3K-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Array-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Union--Find-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/-Sorting-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given a **0-indexed** array of positive integers `nums` and a positive integer `limit`.

In one operation, you can choose any two indices `i` and `j` and swap `nums[i]` and `nums[j]` if:
$$|nums[i] - nums[j]| \le limit$$

Return the **lexicographically smallest** array that can be obtained by performing the operation any number of times.

An array `a` is **lexicographically smaller** than an array `b` if in the first position where `a` and `b` differ, array `a` has an element that is less than the corresponding element in `b`. For example, the array `[2, 10, 3]` is lexicographically smaller than the array `[10, 2, 3]` because they differ at index `0` and `2 < 10`.

---

## 📌 Examples

**Example 1:**
```text
Input: nums = [1,5,3,9,8], limit = 2
Output: [1,3,5,8,9]
Explanation: Apply the operation 2 times:
- Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
- Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
We cannot obtain a lexicographically smaller array by applying any more operations.
```

**Example 2:**
```text
Input: nums = [1,7,6,18,2,1], limit = 3
Output: [1,6,7,18,1,2]
Explanation: Apply the operation 3 times:
- Swap nums[1] with nums[2]. The array becomes [1,6,7,18,2,1]
- Swap nums[0] with nums[4]. The array becomes [2,6,7,18,1,1]
- Swap nums[0] with nums[5]. The array becomes [1,6,7,18,1,2]
We cannot obtain a lexicographically smaller array by applying any more operations.
```

**Example 3:**
```text
Input: nums = [1,7,28,19,10], limit = 3
Output: [1,7,28,19,10]
Explanation: [1,7,28,19,10] is the lexicographically smallest array we can obtain because we cannot apply the operation on any two indices.
```

---

## 📐 Constraints

- $1 \le \text{nums.length} \le 10^5$
- $1 \le \text{nums}[i] \le 10^9$
- $1 \le \text{limit} \le 10^9$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \log n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../213_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../215_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
