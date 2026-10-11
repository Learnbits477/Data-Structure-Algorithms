# 257. [Sort Two Parts Sorted](https://www.geeksforgeeks.org/problems/sort-the-half-sorted2157/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 50.0%](https://img.shields.io/badge/Accuracy-50.0%25-orange?style=for-the-badge)
![Submissions: 13K+](https://img.shields.io/badge/Submissions-13K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topic: Two-Pointer](https://img.shields.io/badge/Topic-Two--Pointer-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Two Pointers Merge Over Half-Sorted Subarrays:**
> 1. **Discontinuity Detection**:
>    Because the array is guaranteed to consist of two individually sorted segments, there exists at most one inversion break point $i$ where $arr[i] > arr[i + 1]$.
> 2. **Two Sorted Subarrays**:
>    The break point cleanly partitions the array into $arr[0 \dots mid]$ and $arr[mid + 1 \dots n - 1]$. If no such inversion exists ($mid = -1$), the array is already sorted.
> 3. **Linear Merge Routine**:
>    Just like the merge step in Merge Sort, two pointers running across both partitions can merge all elements into a fully sorted sequence in $\mathcal{O}(n)$ time and $\mathcal{O}(n)$ auxiliary space.

---

## 🧩 Problem Description

Given an integer array `arr[]` where the two parts around a break point are individually sorted, merge them into a single sorted array. The break point can be anywhere in the array, including at the beginning or end.

---

## 📌 Examples

**Example 1:**

```text
Input: arr[] = [2, 3, 8, -1, 7, 10]
Output: [-1, 2, 3, 7, 8, 10]
Explanation: [2, 3, 8] and [-1, 7, 10] are sorted in the original array. The overall sorted version is [-1, 2, 3, 7, 8, 10].
```

**Example 2:**

```text
Input: arr[] = [-4, 6, 9, -1, 3]
Output: [-4, -1, 3, 6, 9]
Explanation: [-4, 6, 9] and [-1, 3] are sorted in the original array. The overall sorted version is [-4, -1, 3, 6, 9].
```

**Example 3:**

```text
Input: arr[] = [10, 20, 30]
Output: [10, 20, 30]
Explanation: One part is empty and the other part is the whole array which is already sorted.
```

---

## 📐 Constraints

- $1 \le arr.\text{size}() \le 10^6$
- $-10^5 \le arr[i] \le 10^5$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

*Where $n$ is the number of elements in the array. Finding the break point takes $\mathcal{O}(n)$ time, and merging the two sorted subarrays takes $\mathcal{O}(n)$ time with an auxiliary buffer.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../256_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../258_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
