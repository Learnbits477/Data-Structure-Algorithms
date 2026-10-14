# 259. [Adding Ones](https://www.geeksforgeeks.org/problems/adding-ones3628/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 48.06%](https://img.shields.io/badge/Accuracy-48.06%25-orange?style=for-the-badge)
![Submissions: 57K+](https://img.shields.io/badge/Submissions-57K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Topic: Prefix Sum](https://img.shields.io/badge/Prefix%20Sum-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Difference Array & Prefix Sum Propagation:**
> 1. **Suffix Update Invariant**:
>    For each value $j \in \text{updates}$, the operation requires adding $+1$ to every element $arr[i]$ satisfying $i \ge j$ (1-based), which corresponds to indices $[j - 1, n - 1]$ in $0$-based representation.
> 2. **Boundary Frequency Counting**:
>    Instead of iterating across the entire range $[j - 1, n - 1]$ for every update (which yields $\mathcal{O}(n \times k)$ worst-case time), treat $arr$ as a difference array. Each update at $j$ simply increments the starting index $arr[j - 1]$ by $1$. Because each update extends until the end of the array, no negative cancellation $(-1)$ is needed at any upper boundary.
> 3. **Single-Pass Prefix Accumulation**:
>    A single forward pass accumulating running prefix sums propagates all increments to subsequent indices in $\mathcal{O}(n + k)$ overall time and $\mathcal{O}(1)$ auxiliary space.

---

## 🧩 Problem Description

Consider an array `arr[]` of size `n`, initially containing all zeros. You are also given an array `updates[]` of `k` positive integers.

For each value `j` in `updates[]`, add $1$ to every element `arr[i]` whose index satisfies $i \ge j$.

The indices in `updates[]` are **1-based**.

Perform all the updates and return the modified `arr[]`.

---

## 📌 Examples

**Example 1:**

```text
Input: n = 3, updates[] = [1, 1, 2, 3]
Output: [2, 3, 4]
Explanation:
Initially, arr[] = [0, 0, 0].
After the first update 1, the array becomes [1, 1, 1].
After the second update 1, it becomes [2, 2, 2].
The update 2 increments all elements from index 2 onward, giving [2, 3, 3].
Finally, the update 3 increments the element at index 3, resulting in [2, 3, 4].
```

**Example 2:**

```text
Input: n = 2, updates[] = [1, 1, 1]
Output: [3, 3]
Explanation:
Initially the array is [0, 0].
After the first 1, it becomes [1, 1].
After the second 1, it becomes [2, 2].
After the third 1, it becomes [3, 3].
```

---

## 📐 Constraints

- $1 \le n, \text{updates.size}() \le 10^5$
- $1 \le \text{updates}[i] \le n$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n + k)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

*Where $n$ is the size of the target array and $k$ is the number of updates. We process $k$ updates in $\mathcal{O}(k)$ time and perform a single prefix sweep in $\mathcal{O}(n)$ time, using no extra memory beyond the returned array.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../258_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../260_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
