# [Min Swaps to Group All 1s Together](https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-group-all-1s-together2451/1)

<div align="center">
  <img src="https://img.shields.io/badge/Platform-GeeksForGeeks-2F8D46?style=for-the-badge&logo=geeksforgeeks&logoColor=white" alt="Platform">
  <img src="https://img.shields.io/badge/Difficulty-Medium-F9A825?style=for-the-badge" alt="Difficulty: Medium">
  <img src="https://img.shields.io/badge/Accuracy-40.3%25-E53935?style=for-the-badge" alt="Accuracy: 40.3%">
  <img src="https://img.shields.io/badge/Submissions-17K%2B-1565C0?style=for-the-badge" alt="Submissions: 17K+">
  <img src="https://img.shields.io/badge/Points-4-6A1B9A?style=for-the-badge" alt="Points: 4">
</div>

---

## 🧩 Problem Statement

You are given a **binary array** `arr[]` consisting only of `0`s and `1`s.  
Determine the **minimum number of swaps** required to group all the `1`s together in a **contiguous subarray**.

A swap operation allows you to choose any two indices `i` and `j` and exchange their values (i.e., `swap(arr[i], arr[j])`).

> If the array contains **no 1s**, return **`-1`**.

---

## 📌 Examples

**Example 1:**
```
Input : arr[] = [1, 0, 1, 0, 1]
Output: 1
Explanation: Swapping index 1 and 4 gives arr[] = [1, 1, 1, 0, 0].
             All 1s are now together with just 1 swap.
```

**Example 2:**
```
Input : arr[] = [1, 0, 1, 0, 1, 1]
Output: 1
Explanation: Swapping index 0 and 3 gives arr[] = [0, 0, 1, 1, 1, 1].
             All 1s are grouped together with 1 swap.
```

**Example 3:**
```
Input : arr[] = [0, 0, 0]
Output: -1
Explanation: No 1s are present in the array, so return -1.
```

---

## 📐 Constraints

| Parameter    | Bound                    |
|:-------------|:-------------------------|
| `arr.size()` | `1 ≤ arr.size() ≤ 10⁶`  |
| `arr[i]`     | `0 ≤ arr[i] ≤ 1`         |

---

## 🔗 Related Files

| File | Description |
|:-----|:------------|
| [Approach.md](Approach.md) | Algorithm explanation with Mermaid diagram |
| [Solution.cpp](Solution.cpp) | Optimized C++ solution |
| [Main.cpp](Main.cpp) | Test driver with sample cases |
