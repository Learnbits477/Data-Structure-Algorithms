# [3867. Sum of GCD of Formed Pairs](https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/?envType=daily-question&envId=2026-07-12)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 70.9%](https://img.shields.io/badge/Acceptance-70.9%25-blue?style=for-the-badge)
![Submissions: 75.2K](https://img.shields.io/badge/Submissions-75.2K-brightgreen?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-orange?style=for-the-badge)
![Company: Amazon](https://img.shields.io/badge/Company-Amazon-black?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given an integer array `nums` of length `n`.

Construct an array `prefixGcd` where for each index `i`:
- Let $mx_i = \max(nums[0], nums[1], \dots, nums[i])$.
- $prefixGcd[i] = \gcd(nums[i], mx_i)$.

After constructing `prefixGcd`:
1. Sort `prefixGcd` in non-decreasing order.
2. Form pairs by taking the smallest unpaired element and the largest unpaired element.
3. Repeat this process until no more pairs can be formed.
4. For each formed pair, compute the GCD of the two elements.
5. If `n` is odd, the middle element in the `prefixGcd` array remains unpaired and should be ignored.

Return an integer denoting the sum of the GCD values of all formed pairs.

---

## 📌 Examples

### Example 1
**Input:**
```text
nums = [2, 6, 4]
```
**Output:**
```text
2
```
**Explanation:**
- Construct `prefixGcd`:
  - `i = 0`: $nums[0] = 2$, $mx_0 = 2 \implies prefixGcd[0] = \gcd(2, 2) = 2$
  - `i = 1`: $nums[1] = 6$, $mx_1 = 6 \implies prefixGcd[1] = \gcd(6, 6) = 6$
  - `i = 2`: $nums[2] = 4$, $mx_2 = 6 \implies prefixGcd[2] = \gcd(4, 6) = 2$
- `prefixGcd` = `[2, 6, 2]`. After sorting, it forms `[2, 2, 6]`.
- Pair the smallest and largest elements: $\gcd(2, 6) = 2$.
- The remaining middle element `2` is ignored. Thus, the sum is `2`.

### Example 2
**Input:**
```text
nums = [3, 6, 2, 8]
```
**Output:**
```text
5
```
**Explanation:**
- Construct `prefixGcd`:
  - `i = 0`: $nums[0] = 3$, $mx_0 = 3 \implies prefixGcd[0] = \gcd(3, 3) = 3$
  - `i = 1`: $nums[1] = 6$, $mx_1 = 6 \implies prefixGcd[1] = \gcd(6, 6) = 6$
  - `i = 2`: $nums[2] = 2$, $mx_2 = 6 \implies prefixGcd[2] = \gcd(2, 6) = 2$
  - `i = 3`: $nums[3] = 8$, $mx_3 = 8 \implies prefixGcd[3] = \gcd(8, 8) = 8$
- `prefixGcd` = `[3, 6, 2, 8]`. After sorting, it forms `[2, 3, 6, 8]`.
- Form pairs: $\gcd(2, 8) = 2$ and $\gcd(3, 6) = 3$. Thus, the sum is $2 + 3 = 5$.

---

## 📐 Constraints

- $$1 \le n = nums.length \le 10^5$$
- $$1 \le nums[i] \le 10^9$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n \log n + n \log(\max(nums)))$$ |
| 💾 Auxiliary Space | $$O(n)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-1ABC9C?style=for-the-badge)
![Math](https://img.shields.io/badge/Math-2ECC71?style=for-the-badge)
![Two Pointers](https://img.shields.io/badge/Two%20Pointers-3498DB?style=for-the-badge)
![Sorting](https://img.shields.io/badge/Sorting-E74C3C?style=for-the-badge)
![Number Theory](https://img.shields.io/badge/Number%20Theory-9B59B6?style=for-the-badge)

</div>

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../170_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../172_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
