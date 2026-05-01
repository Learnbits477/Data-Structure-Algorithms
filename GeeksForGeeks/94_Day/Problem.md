# [Kth Largest Element in a Stream](https://www.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1)

<div align="center">
  <img src="https://img.shields.io/badge/Platform-GeeksForGeeks-2F8D46?style=for-the-badge&logo=geeksforgeeks&logoColor=white" alt="Platform">
  <img src="https://img.shields.io/badge/Difficulty-Medium-F9A825?style=for-the-badge" alt="Difficulty: Medium">
  <img src="https://img.shields.io/badge/Accuracy-31.59%25-E53935?style=for-the-badge" alt="Accuracy: 31.59%">
  <img src="https://img.shields.io/badge/Submissions-93K%2B-1565C0?style=for-the-badge" alt="Submissions: 93K+">
  <img src="https://img.shields.io/badge/Points-4-6A1B9A?style=for-the-badge" alt="Points: 4">
  <img src="https://img.shields.io/badge/Avg%20Time-20m-00838F?style=for-the-badge" alt="Avg Time: 20m">
</div>

---

## 🧩 Problem Statement

Given an input stream `arr[]` of `n` integers, find the **Kth largest element** *(not Kth largest unique element)* after the insertion of each element in the stream.

If the Kth largest element **doesn't exist** for a particular insertion, the answer for that step is **`-1`**.

Return a **list of size n**, where each element represents the Kth largest value after the corresponding insertion.

---

## 📌 Examples

**Example 1:**
```
Input : arr[] = [1, 2, 3, 4, 5, 6],  k = 4
Output: [-1, -1, -1, 1, 2, 3]

Explanation:
  After inserting 1 → stream = [1]          → 4th largest doesn't exist → -1
  After inserting 2 → stream = [1, 2]       → 4th largest doesn't exist → -1
  After inserting 3 → stream = [1, 2, 3]    → 4th largest doesn't exist → -1
  After inserting 4 → stream = [1, 2, 3, 4] → 4th largest = 1
  After inserting 5 → stream = [1,2,3,4,5]  → 4th largest = 2
  After inserting 6 → stream = [1,2,3,4,5,6]→ 4th largest = 3
```

**Example 2:**
```
Input : arr[] = [3, 2, 1, 3, 3],  k = 2
Output: [-1, 2, 2, 3, 3]

Explanation:
  After inserting 3 → stream = [3]           → 2nd largest doesn't exist → -1
  After inserting 2 → stream = [3, 2]        → 2nd largest = 2
  After inserting 1 → stream = [3, 2, 1]     → 2nd largest = 2
  After inserting 3 → stream = [3, 2, 1, 3]  → 2nd largest = 3
  After inserting 3 → stream = [3,2,1,3,3]   → 2nd largest = 3
```

---

## 📐 Constraints

| Parameter | Bound                |
|:----------|:---------------------|
| `k`       | `1 ≤ k ≤ n`          |
| `n`       | `1 ≤ n ≤ 10⁵`        |
| `arr[i]`  | `1 ≤ arr[i] ≤ 10⁵`   |

---

## 🔗 Related Files

| File | Description |
|:-----|:------------|
| [Approach.md](Approach.md) | Algorithm explanation & Mermaid diagram |
| [Solution.cpp](Solution.cpp) | Optimized O(N log K) Min-Heap C++ solution |
| [Main.cpp](Main.cpp) | Test driver with sample test cases |
