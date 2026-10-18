# [1569. Number of Ways to Reorder Array to Get Same BST](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 60.6%](https://img.shields.io/badge/Acceptance-60.6%25-brightgreen?style=for-the-badge)
![Submissions: 89.9K+](https://img.shields.io/badge/Submissions-89.9K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Array-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Math-blue?style=for-the-badge)
![Topic: Divide and Conquer](https://img.shields.io/badge/Divide%20and%20Conquer-blue?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-blue?style=for-the-badge)
![Topic: Tree](https://img.shields.io/badge/Tree-blue?style=for-the-badge)
![Topic: Binary Search Tree](https://img.shields.io/badge/Binary%20Search%20Tree-blue?style=for-the-badge)
![Topic: Combinatorics](https://img.shields.io/badge/Combinatorics-blue?style=for-the-badge)
![Topic: Fermat's Little Theorem](https://img.shields.io/badge/Fermat's%20Little%20Theorem-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — BST Structural Partitioning & Combinatorial Interleaving:**
> 1. **Root Invariance**:
>    In any valid BST construction from sequential insertion, the very first element `nums[0]` is unconditionally established as the root of the current subtree.
> 2. **Subtree Separation**:
>    All elements strictly smaller than `nums[0]` belong to the left subtree, and all elements strictly larger belong to the right subtree. Within each partition, their mutual relative order in `nums` completely determines their nested recursive BST topology.
> 3. **Interleaving Independence**:
>    Elements destined for the left subtree and elements destined for the right subtree can appear in any interleaved order relative to one another, provided their own internal relative sequences are preserved and the root remains in front.
> 4. **Binomial Multiplier**:
>    Given $L$ left elements and $R$ right elements, the number of ways to pick $L$ slots out of $(L + R)$ total positions is given by the combination $\binom{L + R}{L}$.
> 5. **Subproblem Recurrence**:
>    $$\text{ways}(nums) = \binom{L + R}{L} \times \text{ways}(\text{left}) \times \text{ways}(\text{right}) \pmod{10^9 + 7}$$
> 6. **Excluding Original Permutation**:
>    Since the problem asks for the number of *reorderings* (other permutations), the final answer is $(\text{ways}(nums) - 1 + \text{MOD}) \pmod{\text{MOD}}$.

---

## 🧩 Problem Description

Given an array `nums` that represents a permutation of integers from $1$ to $n$. We are going to construct a binary search tree (BST) by inserting the elements of `nums` in order into an initially empty BST. Find the number of different ways to reorder `nums` so that the constructed BST is identical to that formed from the original array `nums`.

For example, given `nums = [2, 1, 3]`, we will have $2$ as the root, $1$ as a left child, and $3$ as a right child. The array `[2, 3, 1]` also yields the same BST but `[3, 2, 1]` yields a different BST.

Return *the number of ways to reorder `nums` such that the BST formed is identical to the original BST formed from `nums`*.

Since the answer may be very large, return it **modulo** $10^9 + 7$.

---

## 📌 Examples

**Example 1:**

```text
Input: nums = [2, 1, 3]
Output: 1
Explanation:
We can reorder nums to be [2, 3, 1] which will yield the same BST.
There are no other ways to reorder nums which will yield the same BST.
```

**Example 2:**

```text
Input: nums = [3, 4, 5, 1, 2]
Output: 5
Explanation:
The following 5 arrays will yield the same BST:
[3, 1, 2, 4, 5]
[3, 1, 4, 2, 5]
[3, 1, 4, 5, 2]
[3, 4, 1, 2, 5]
[3, 4, 1, 5, 2]
```

**Example 3:**

```text
Input: nums = [1, 2, 3]
Output: 0
Explanation:
There are no other orderings of nums that will yield the same BST.
```

---

## 📐 Constraints

- $1 \le nums.length \le 1000$
- $1 \le nums[i] \le nums.length$
- All integers in `nums` are **distinct**.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n^2)$ |
| **Auxiliary Space** | $\mathcal{O}(n^2)$ |

*Precomputing Pascal's triangle for binomial coefficients up to $n = 1000$ takes $\mathcal{O}(n^2)$ time and space. The divide-and-conquer recursion partitions the array in at most $\mathcal{O}(n^2)$ operations in the worst case (skewed tree) and $\mathcal{O}(n \log n)$ in the balanced case.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../263_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../265_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
