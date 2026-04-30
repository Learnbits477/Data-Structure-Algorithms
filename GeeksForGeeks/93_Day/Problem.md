# [Check if an Array is Max Heap](https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1)

<div align="center">
  <img src="https://img.shields.io/badge/Platform-GeeksForGeeks-2F8D46?style=for-the-badge&logo=geeksforgeeks&logoColor=white" alt="Platform">
  <img src="https://img.shields.io/badge/Difficulty-Easy-43A047?style=for-the-badge" alt="Difficulty: Easy">
  <img src="https://img.shields.io/badge/Accuracy-30.97%25-E53935?style=for-the-badge" alt="Accuracy: 30.97%">
  <img src="https://img.shields.io/badge/Submissions-95K%2B-1565C0?style=for-the-badge" alt="Submissions: 95K+">
  <img src="https://img.shields.io/badge/Points-2-6A1B9A?style=for-the-badge" alt="Points: 2">
</div>

---

## 🧩 Problem Statement

Given an array `arr[]`, determine whether it represents the **level-order traversal** of a valid **max heap**.

Return `true` if it does; otherwise, return `false`.

> **Max-Heap Property:** Every parent node must be **greater than or equal to** its children.

---

## 📌 Examples

**Example 1:**
```
Input : arr[] = [90, 15, 10, 7, 12, 2]
Output: true
Explanation: The array represents a valid max-heap tree.
             Each parent node is ≥ its children.

             Tree structure:
                      90
                    /    \
                  15      10
                 /  \    /
                7   12  2
```

**Example 2:**
```
Input : arr[] = [9, 15, 10, 7, 12, 11]
Output: false
Explanation: Does NOT satisfy the max-heap property.
             9 < 15 and 9 < 10, and 10 < 11 — violations exist.

             Tree structure:
                      9
                    /   \
                  15     10
                 /  \   /
                7   12 11
                       ↑ 10 < 11 ❌
```

---

## 📐 Constraints

| Parameter  | Bound                   |
|:-----------|:------------------------|
| `n`        | `1 ≤ n ≤ 10⁵`           |
| `arr[i]`   | `1 ≤ arr[i] ≤ 10⁵`      |

---

## 🔗 Related Files

| File | Description |
|:-----|:------------|
| [Approach.md](Approach.md) | Algorithm explanation & Mermaid diagram |
| [Solution.cpp](Solution.cpp) | Optimized O(N) C++ solution |
| [Main.cpp](Main.cpp) | Test driver with sample test cases |
