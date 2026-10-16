# 262. [Successful Binary Searches Irrespective of Pivot](https://www.geeksforgeeks.org/problems/count-always-found/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 75.96%](https://img.shields.io/badge/Accuracy-75.96%25-orange?style=for-the-badge)
![Submissions: 504+](https://img.shields.io/badge/Submissions-504%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: Constructive Algo](https://img.shields.io/badge/Topic-Constructive%20Algo-blue?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Arrays-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Bilateral Partition Invariant (Prefix Max & Suffix Min):**
> 1. **Adversarial Pivot Freedom**:
>    At every step, the adversary may select *any* index $p \in [lo, hi]$ as the pivot. To guarantee reaching index $i$, no valid pivot choice can ever discard index $i$ from the search interval $[lo, hi]$.
> 2. **Left-Side Invariant**:
>    If any index $p < i$ has $arr[p] > arr[i]$, picking $p$ sets $hi = p - 1 < i$, permanently excluding $i$. Hence, $arr[i]$ must be strictly greater than *all* elements to its left:
>    $$arr[i] > \max_{0 \le j < i} arr[j]$$
> 3. **Right-Side Invariant**:
>    If any index $p > i$ has $arr[p] < arr[i]$, picking $p$ sets $lo = p + 1 > i$, permanently excluding $i$. Hence, $arr[i]$ must be strictly smaller than *all* elements to its right:
>    $$arr[i] < \min_{i < j < n} arr[j]$$
> 4. **Equivalence to Partition Points**:
>    An element is always found if and only if it acts as a valid QuickSort partition point (strictly greater than prefix maximum, strictly smaller than suffix minimum).

---

## 🧩 Problem Description

Given an array `arr[]` of `n` distinct integers (not necessarily sorted), consider the following search for a target:

1. Maintain a range `[lo, hi]`, initially `[0, n - 1]`.
2. At each step, pick any index `p` in `[lo, hi]` (not necessarily the middle) as pivot. If `arr[p] == target`, stop — found.
3. If `target < arr[p]`, set `hi = p - 1`; if `target > arr[p]`, set `lo = p + 1`. If `lo > hi`, stop — not found.

Count the number of indices `i` such that searching for `target = arr[i]` succeeds **no matter which pivot is chosen at every step** (i.e., for every possible sequence of pivot choices).

---

## 📌 Examples

**Example 1:**

```text
Input: arr[] = [3, 7, 9, 8, 15]
Output: 3
Explanation:
3, 7, and 15 (indices 0, 1, 4) are always found: every possible pivot comparison happens to steer the search toward them, no matter the order.
9 and 8 are not: e.g. if the first pivot picked is 8, searching for 9 gets pushed right and index 2 is lost forever; if the first pivot is 9, searching for 8 gets pushed left and index 3 is lost forever.
```

**Example 2:**

```text
Input: arr[] = [9, 4, 1, 10, 22, 23, 20]
Output: 1
Explanation:
Only 10 (index 3) is always found — every pivot, left or right, happens to steer toward it. Everything else can fail on some pivot order: e.g. picking 4 first pushes a search for 9 away permanently, and picking 20 first makes a search for 22 run off the end of the array entirely.
```

---

## 📐 Constraints

- $1 \le arr.size() \le 10^5$
- $1 \le arr[i] \le 10^6$
- All elements in `arr[]` are distinct.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

*A single prefix pass computes the running maximum from the left, while a suffix pass precomputes or maintains the minimum from the right. Every element is tested in $\mathcal{O}(1)$ time.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../261_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../263_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
