# [3524. Find X Value of Array I](https://leetcode.com/problems/find-x-value-of-array-i/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 45.4%](https://img.shields.io/badge/Acceptance-45.4%25-orange?style=for-the-badge)
![Submissions: 39.4K+](https://img.shields.io/badge/Submissions-39.4K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Math-blue?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given an array of positive integers `nums`, and a positive integer `k`.

You are allowed to perform an operation once on `nums`, where in each operation you can remove any non-overlapping prefix and suffix from `nums` such that `nums` remains non-empty.

You need to find the **x-value** of `nums`, which is the number of ways to perform this operation so that the product of the remaining elements leaves a remainder of $x$ when divided by $k$.

Return an array `result` of size $k$ where `result[x]` is the **x-value** of `nums` for $0 \le x \le k - 1$.

- A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.
- A suffix of an array is a subarray that starts at any point within the array and extends to the end of the array.
- Note that the prefix and suffix to be chosen for the operation can be empty.

---

## 📌 Examples

**Example 1:**

```text
Input: nums = [1, 2, 3, 4, 5], k = 3
Output: [9, 2, 4]
Explanation:
For x = 0, the possible operations include all possible ways to remove non-overlapping prefix/suffix that do not remove nums[2] == 3.
For x = 1, the possible operations are:
  - Remove the empty prefix and the suffix [2, 3, 4, 5]. nums becomes [1].
  - Remove the prefix [1, 2, 3] and the suffix [5]. nums becomes [4].
For x = 2, the possible operations are:
  - Remove the empty prefix and the suffix [3, 4, 5]. nums becomes [1, 2].
  - Remove the prefix [1] and the suffix [3, 4, 5]. nums becomes [2].
  - Remove the prefix [1, 2, 3] and the empty suffix. nums becomes [4, 5].
  - Remove the prefix [1, 2, 3, 4] and the empty suffix. nums becomes [5].
```

**Example 2:**

```text
Input: nums = [1, 2, 4, 8, 16, 32], k = 4
Output: [18, 1, 2, 0]
Explanation:
For x = 0, the only operations that do not result in x = 0 are:
  - Remove the empty prefix and the suffix [4, 8, 16, 32]. nums becomes [1, 2].
  - Remove the empty prefix and the suffix [2, 4, 8, 16, 32]. nums becomes [1].
  - Remove the prefix [1] and the suffix [4, 8, 16, 32]. nums becomes [2].
For x = 1, the only possible operation is:
  - Remove the empty prefix and the suffix [2, 4, 8, 16, 32]. nums becomes [1].
For x = 2, the possible operations are:
  - Remove the empty prefix and the suffix [4, 8, 16, 32]. nums becomes [1, 2].
  - Remove the prefix [1] and the suffix [4, 8, 16, 32]. nums becomes [2].
For x = 3, there is no possible way to perform the operation.
```

**Example 3:**

```text
Input: nums = [1, 1, 2, 1, 1], k = 2
Output: [9, 6]
```

---

## 📐 Constraints

- $1 \le \text{nums}[i] \le 10^9$
- $1 \le \text{nums.length} \le 10^5$
- $1 \le k \le 5$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \cdot k)$ |
| **Auxiliary Space** | $\mathcal{O}(k)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../236_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../238_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
