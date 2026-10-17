# [3551. Minimum Swaps to Sort by Digit Sum](https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 52.1%](https://img.shields.io/badge/Acceptance-52.1%25-orange?style=for-the-badge)
![Submissions: 58.1K+](https://img.shields.io/badge/Submissions-58.1K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Hash%20Table-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Permutation Cycle Decomposition & Custom Comparator:**
> 1. **Target Sorting Mapping**:
>    Each distinct number $x \in nums$ maps to a primary key $\text{digitSum}(x)$ and secondary key $x$. Sorting by this criteria defines the target index $P[i]$ where the element originally located at index $i$ must eventually reside.
> 2. **Cycle Graph Representation**:
>    Any arbitrary rearrangement of distinct elements forms a directed permutation graph where directed edges connect each element's current position to its desired position: $u \to \text{target}(u)$.
> 3. **Minimum Swaps Equivalence**:
>    Since swapping two elements in a cycle splits it into two smaller cycles, a cycle containing $L$ elements requires strictly $L - 1$ swaps to resolve. Thus, the minimum total swaps equals:
>    $$\sum (L_i - 1) = N - C$$
>    where $N$ is the number of elements and $C$ is the number of disjoint cycles in the permutation.

---

## 🧩 Problem Description

You are given an array `nums` of distinct positive integers. You need to sort the array in increasing order based on the sum of the digits of each number. If two numbers have the same digit sum, the smaller number appears first in the sorted order.

Return the **minimum number of swaps** required to rearrange `nums` into this sorted order.

A **swap** is defined as exchanging the values at two distinct positions in the array.

---

## 📌 Examples

**Example 1:**

```text
Input: nums = [37, 100]
Output: 1
Explanation:
Compute the digit sum for each integer: [3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]
Sort the integers based on digit sum: [100, 37]. Swap 37 with 100 to obtain the sorted order.
Thus, the minimum number of swaps required to rearrange nums is 1.
```

**Example 2:**

```text
Input: nums = [22, 14, 33, 7]
Output: 0
Explanation:
Compute the digit sum for each integer: [2 + 2 = 4, 1 + 4 = 5, 3 + 3 = 6, 7 = 7] → [4, 5, 6, 7]
Sort the integers based on digit sum: [22, 14, 33, 7]. The array is already sorted.
Thus, the minimum number of swaps required to rearrange nums is 0.
```

**Example 3:**

```text
Input: nums = [18, 43, 34, 16]
Output: 2
Explanation:
Compute the digit sum for each integer: [1 + 8 = 9, 4 + 3 = 7, 3 + 4 = 7, 1 + 6 = 7] → [9, 7, 7, 7]
Sort the integers based on digit sum: [16, 34, 43, 18]. Swap 18 with 16, and swap 43 with 34 to obtain the sorted order.
Thus, the minimum number of swaps required to rearrange nums is 2.
```

---

## 📐 Constraints

- $1 \le nums.length \le 10^5$
- $1 \le nums[i] \le 10^9$
- `nums` consists of **distinct positive integers**.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \log n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

*Computing digit sums takes $\mathcal{O}(n \log_{10}(\max(nums)))$ time. Sorting $n$ indexed elements takes $\mathcal{O}(n \log n)$ time. Finding disjoint permutation cycles using a visited array takes linear $\mathcal{O}(n)$ time.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../262_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../264_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
