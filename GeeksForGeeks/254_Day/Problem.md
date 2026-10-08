# 254. [Maximum Frequency with K Increments](https://www.geeksforgeeks.org/problems/maximum-frequency-1662528911/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 56.04%](https://img.shields.io/badge/Accuracy-56.04%25-orange?style=for-the-badge)
![Submissions: 3K+](https://img.shields.io/badge/Submissions-3K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: Sliding Window](https://img.shields.io/badge/Topic-Sliding%20Window-blue?style=for-the-badge)
![Topic: Two Pointers](https://img.shields.io/badge/Two%20Pointers-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-blue?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Arrays-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Monotonic Sorting & Dynamic Sliding Window:**
> 1. **Greedy Target Alignment**:
>    Because we can only **increment** elements (add $+1$), to maximize frequency it is always optimal to choose an existing element in the array as the target value and elevate smaller elements up to it. In a sorted array, for any candidate subarray ending at index $R$, the target element is naturally $\text{arr}[R]$.
> 2. **Window Cost Formula**:
>    To make all elements in subarray $\text{arr}[L \dots R]$ equal to $\text{arr}[R]$, the required number of operations is:
>    $$\text{Cost} = (R - L + 1) \times \text{arr}[R] - \sum_{i=L}^{R} \text{arr}[i]$$
> 3. **Sliding Window Invariant**:
>    As $R$ expands to the right, the cost is monotonic non-decreasing. If $\text{Cost} > k$, we increment $L$ to shrink the window until the cost is $\le k$. The maximum window length $(R - L + 1)$ encountered across all valid positions gives the answer.

---

## 🧩 Problem Description

Given an integer array `arr[]` and an integer `k`. In one operation, you can choose an index and increment its value by `1`.

Find the maximum possible frequency of any element after performing at most `k` operations.

---

## 📌 Examples

**Example 1:**

```text
Input: arr[] = [2, 2, 4], k = 4
Output: 3
Explanation:
Apply two increment operations on index 0 and two operations on index 1 to make arr[] = [4, 4, 4].
The frequency of 4 is 3.
```

**Example 2:**

```text
Input: arr[] = [7, 7, 7, 7], k = 5
Output: 4
Explanation:
The frequency of 7 is already 4, so no operations are needed.
```

**Example 3:**

```text
Input: arr[] = [1, 4, 8, 13], k = 5
Output: 2
Explanation:
There are multiple options:
- Increment 1 to 4 using 3 operations: [4, 4, 8, 13], frequency of 4 is 2.
- Increment 4 to 8 using 4 operations: [1, 8, 8, 13], frequency of 8 is 2.
Max frequency possible with k = 5 is 2.
```

---

## 📐 Constraints

- $1 \le \text{arr.size()} \le 10^5$
- $1 \le \text{arr}[i] \le 10^6$
- $0 \le k \le 10^5$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \log n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

*Where $n$ represents the total number of elements in `arr[]`. Sorting dominates with $\mathcal{O}(n \log n)$, followed by an $\mathcal{O}(n)$ sliding window traversal.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../253_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../255_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
