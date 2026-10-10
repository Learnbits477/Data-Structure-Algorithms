# [2333. Minimum Sum of Squared Difference](https://leetcode.com/problems/minimum-sum-of-squared-difference/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 34.6%](https://img.shields.io/badge/Acceptance-34.6%25-orange?style=for-the-badge)
![Submissions: 112.3K+](https://img.shields.io/badge/Submissions-112.3K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Binary Search](https://img.shields.io/badge/Binary%20Search-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-blue?style=for-the-badge)
![Topic: Heap](https://img.shields.io/badge/Heap-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Convexity & Greedy Largest-Difference Reduction:**
> 1. **Unified Modification Budget**:
>    Modifying $nums1[i]$ by $\pm 1$ or $nums2[i]$ by $\mp 1$ has an identical effect on reducing $|nums1[i] - nums2[i]|$. Hence, the separate operation allowances merge into a single unified budget:
>    $$k = k_1 + k_2$$
> 2. **Strict Convexity of Squares**:
>    The reduction in squared difference from decrementing an absolute difference $x \to x - 1$ is:
>    $$(x)^2 - (x - 1)^2 = 2x - 1$$
>    Because $2x - 1$ increases strictly with $x$, decrementing larger differences yields strictly greater improvements. Thus, it is always globally optimal to reduce the largest difference available.
> 3. **Bucket / Frequency Array Optimization**:
>    Since elements satisfy $0 \le nums1[i], nums2[i] \le 10^5$, the maximum difference $M = \max(|nums1[i] - nums2[i]|) \le 10^5$. Instead of a slow $\mathcal{O}(k \log n)$ heap, we use a frequency bucket array over range $[0, 10^5]$. Sweeping downwards from $M$ to $1$ reduces all values in $\mathcal{O}(n + M)$ time.

---

## 🧩 Problem Description

You are given two positive 0-indexed integer arrays `nums1` and `nums2`, both of length `n`.

The **sum of squared difference** of arrays `nums1` and `nums2` is defined as the sum of $(nums1[i] - nums2[i])^2$ for each $0 \le i < n$.

You are also given two positive integers `k1` and `k2`. You can modify any of the elements of `nums1` by `+1` or `-1` at most `k1` times. Similarly, you can modify any of the elements of `nums2` by `+1` or `-1` at most `k2` times.

Return the **minimum sum of squared difference** after modifying array `nums1` at most `k1` times and modifying array `nums2` at most `k2` times.

> **Note**: You are allowed to modify the array elements to become negative integers.

---

## 📌 Examples

**Example 1:**

```text
Input: nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
Output: 579
Explanation:
The elements in nums1 and nums2 cannot be modified because k1 = 0 and k2 = 0.
The sum of square difference will be:
(1 - 2)^2 + (2 - 10)^2 + (3 - 20)^2 + (4 - 19)^2
= (-1)^2 + (-8)^2 + (-17)^2 + (-15)^2
= 1 + 64 + 289 + 225 = 579.
```

**Example 2:**

```text
Input: nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
Output: 43
Explanation:
One way to obtain the minimum sum of square difference is:
- Increase nums1[0] once: nums1 becomes [2,4,10,12]
- Increase nums2[2] once: nums2 becomes [5,8,7,9]
The minimum sum of square difference will be:
(2 - 5)^2 + (4 - 8)^2 + (10 - 7)^2 + (12 - 9)^2
= (-3)^2 + (-4)^2 + 3^2 + 3^2
= 9 + 16 + 9 + 9 = 43.
Note that there are other ways to modify elements, but no sum is smaller than 43.
```

---

## 📐 Constraints

- $n == nums1.\text{length} == nums2.\text{length}$
- $1 \le n \le 10^5$
- $0 \le nums1[i], nums2[i] \le 10^5$
- $0 \le k_1, k_2 \le 10^9$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n + M)$ |
| **Auxiliary Space** | $\mathcal{O}(M)$ |

*Where $n$ is the number of elements and $M = \max(|nums1[i] - nums2[i]|) \le 10^5$. Populating differences takes $\mathcal{O}(n)$ and descending bucket reduction sweeps over at most $M$ values.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../255_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../257_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
