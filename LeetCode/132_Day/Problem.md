# [2161. Partition Array According to Given Pivot](https://leetcode.com/problems/partition-array-according-to-given-pivot/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 90.5%](https://img.shields.io/badge/Acceptance-90.5%25-green?style=for-the-badge)
![Submissions: 437.5K](https://img.shields.io/badge/Submissions-437.5K-blue?style=for-the-badge)
![Topics: Array | Two Pointers | Simulation](https://img.shields.io/badge/Topics-Array%20%7C%20Two%20Pointers%20%7C%20Simulation-lightgrey?style=for-the-badge)

## 🧩 Problem Description
You are given a **0-indexed** integer array `nums` and an integer `pivot`. Rearrange `nums` such that the following conditions are satisfied:

1. Every element less than `pivot` appears before every element greater than `pivot`.
2. Every element equal to `pivot` appears in between the elements less than and greater than `pivot`.
3. The relative order of the elements less than `pivot` and the elements greater than `pivot` is maintained.
   - More formally, consider every $p_i$, $p_j$ where $p_i$ is the new position of the $i$-th element and $p_j$ is the new position of the $j$-th element. If $i < j$ and both elements are smaller (or larger) than `pivot`, then $p_i < p_j$.

Return `nums` after the rearrangement.

## 📌 Examples

**Example 1:**
```text
Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]
Explanation: 
The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.
```

**Example 2:**
```text
Input: nums = [-3,4,3,2], pivot = 2
Output: [-3,2,4,3]
Explanation: 
The element -3 is less than the pivot so it is on the left side of the array.
The elements 4 and 3 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [-3] and [4, 3] are the respective orderings.
```

## 📐 Constraints
- $$1 \le nums.length \le 10^5$$
- $$-10^6 \le nums[i] \le 10^6$$
- `pivot` equals to an element of `nums`.

## ⏱️ Expected Complexities
| Parameter | Complexity |
|:---:|:---:|
| **Time Complexity** | $$O(N)$$ |
| **Auxiliary Space** | $$O(1)$$ |

## 🏷️ Topic Tags
`Array`, `Two Pointers`, `Simulation`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../131_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../133_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
