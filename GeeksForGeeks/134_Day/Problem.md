# [134. Binary Searchable Count](https://www.geeksforgeeks.org/problems/binary-searchable-elements/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 50.0%](https://img.shields.io/badge/Accuracy-50.0%25-green?style=for-the-badge)
![Submissions: 10K+](https://img.shields.io/badge/Submissions-10K+-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topics: Greedy](https://img.shields.io/badge/Topics-Greedy-lightgrey?style=for-the-badge)

## 🧩 Problem Description
Given an array `arr[]` consisting of $n$ distinct integers, find the maximum count of integers that are binary searchable in the given array. Binary searchable elements are determined using the standard Binary Search implementation described below.

Initially $l$ is `0` and $r$ is `size of array - 1`.
While ($l \le r$), compute $mid$ as $\lfloor (l + r)/2 \rfloor$ and compare with the element at $mid$.
If the target element is same as `arr[mid]`, return `true`. Else if `arr[mid]` is smaller, change $l = mid + 1$, else change $r = mid - 1$.

### Example Trace:
In `arr[] = [2, 1, 3, 4, 6, 5]`, the element `5` is not binary searchable. During Binary Search, the search eventually reaches the subarray containing `6`, and since $6 > 5$, the search moves left ($r = mid - 1$), causing the element `5` to be skipped.
In `arr[] = [2, 1, 3, 4, 5, 6]`, the element `5` is binary searchable because the standard Binary Search process eventually reaches and finds `5`.

## 📌 Examples

**Example 1:**
```text
Input: arr[] = [1, 3, 2]
Output: 2
Explanation: arr[0] (1) and arr[1] (3) can be found.
```

**Example 2:**
```text
Input: arr[] = [2, 1, 3, 5, 4, 6]
Output: 4
Explanation: arr[0] (2), arr[2] (3), arr[4] (4), and arr[5] (6) can be found.
```

## 📐 Constraints
- $$1 \le n \le 10^5$$
- $$1 \le \text{arr}[i] \le 10^5$$

## ⏱️ Expected Complexities
| Parameter | Complexity |
|:---:|:---:|
| **Time Complexity** | $$O(n)$$ |
| **Auxiliary Space** | $$O(\log n)$$ |

## 🏷️ Topic Tags
`GreedyAlgorithms`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../133_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../135_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
