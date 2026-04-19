# [Flip Bits (Flip to Maximize 1s)](https://www.geeksforgeeks.org/problems/flip-bits0240/1)

---
**Difficulty:** Medium | **Accuracy:** 23.15% | **Submissions:** 63K+ | **Points:** 4

---

## Problem Description
Given an array `arr[]` consisting of 0’s and 1’s. A flip operation involves changing all 0's to 1's and all 1's to 0's within a contiguous subarray. Formally, select a range `(l, r)` in the array `arr[]`, such that `(0 ≤ l ≤ r < n)` holds and flip the elements in this range.

Return the **maximum number of 1's** you can get in the array after doing at most **1 flip operation**.

### Examples

**Example 1:**
- **Input:** `arr[] = [1, 0, 0, 1, 0]`
- **Output:** `4`
- **Explanation:** By flipping the subarray from index 1 to 2 (`[0, 0]`), the array becomes `[1, 1, 1, 1, 0]`. This results in a total of 4 ones, which is the maximum possible after at most one flip.

**Example 2:**
- **Input:** `arr[] = [1, 0, 0, 1, 0, 0, 1]`
- **Output:** `6`
- **Explanation:** By flipping the subarray from index 1 to 5 (`[0, 0, 1, 0, 0]`), the array becomes `[1, 1, 1, 0, 1, 1, 1]`. This results in a total of 6 ones, which is the maximum possible after at most one flip.

### Visual Representation
| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Initial** | 1 | **0** | **0** | **1** | **0** | **0** | 1 |
| **Flip (1,5)**| 1 | **1** | **1** | **0** | **1** | **1** | 1 |

**Total 1s after flip:** 6

### Constraints
- $1 \le n \le 10^6$
- $0 \le arr[i] \le 1$

---

### [ Problem Link : Flip Bits to Maximize 1's ](https://www.geeksforgeeks.org/problems/flip-bits0240/1)
