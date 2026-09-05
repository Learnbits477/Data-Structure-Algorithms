# 3904. [Smallest Stable Index II](https://leetcode.com/problems/smallest-stable-index-ii/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 74.8%](https://img.shields.io/badge/Acceptance-74.8%25-green?style=for-the-badge)
![Submissions: 74.4K+](https://img.shields.io/badge/Submissions-74.4K%2B-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Array%20%7C%20Prefix%20Sum-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given an integer array `nums` of length `n` and an integer `k`.

For each index `i`, define its **instability score** as:
$$\text{instability score}(i) = \max(\text{nums}[0..i]) - \min(\text{nums}[i..n - 1])$$

In other words:
- $\max(\text{nums}[0..i])$ is the largest value among the elements from index $0$ to index $i$.
- $\min(\text{nums}[i..n - 1])$ is the smallest value among the elements from index $i$ to index $n - 1$.

An index $i$ is called **stable** if its instability score is less than or equal to $k$.

Return the **smallest stable index**. If no such index exists, return $-1$.

---

## 📌 Examples

**Example 1:**
```text
Input: nums = [5, 0, 1, 4], k = 3
Output: 3
Explanation:
- At index 0: max([5]) = 5, min([5, 0, 1, 4]) = 0 => score = 5 - 0 = 5.
- At index 1: max([5, 0]) = 5, min([0, 1, 4]) = 0 => score = 5 - 0 = 5.
- At index 2: max([5, 0, 1]) = 5, min([1, 4]) = 1 => score = 5 - 1 = 4.
- At index 3: max([5, 0, 1, 4]) = 5, min([4]) = 4 => score = 5 - 4 = 1.
This is the first index with an instability score <= 3. Thus, the answer is 3.
```

**Example 2:**
```text
Input: nums = [3, 2, 1], k = 1
Output: -1
Explanation:
- At index 0: 3 - 1 = 2.
- At index 1: 3 - 1 = 2.
- At index 2: 3 - 1 = 2.
None of these values is <= 1, so the answer is -1.
```

**Example 3:**
```text
Input: nums = [0], k = 0
Output: 0
Explanation:
At index 0: 0 - 0 = 0 <= 0. Therefore, the answer is 0.
```

---

## 📐 Constraints

- $1 \le n == \text{nums.length} \le 10^5$
- $0 \le \text{nums}[i] \le 10^9$
- $0 \le k \le 10^9$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../220_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../222_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
