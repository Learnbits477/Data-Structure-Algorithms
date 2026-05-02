# [Maximize Number of 1's](https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1)

<div align="center">
  <a href="#"><strong>Problem Link</strong></a> |
  <a href="./Solution.cpp"><strong>Solution.cpp</strong></a> |
  <a href="./Approach.md"><strong>Approach.md</strong></a> |
  <a href="./Main.cpp"><strong>Main.cpp</strong></a>
</div>

<br/>

## 📝 Problem Statement

Given a binary array `arr[]` containing only `0`s and `1`s and an integer `k`, you are allowed to flip at most `k` `0`s to `1`s. Find the maximum number of consecutive `1`s that can be obtained in the array after performing the operation at most `k` times.

<br/>

## 🎯 Examples

### **Example 1:**
```text
Input: arr[] = [1, 0, 1], k = 1
Output: 3
Explanation: By flipping the zero at index 1, we get the longest subarray from index 0 to 2 containing all 1’s.
```

### **Example 2:**
```text
Input: arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2
Output: 5
Explanation: By flipping the zeroes at indices 4 and 6, we get the longest subarray from index 3 to 7 containing all 1’s.
```

### **Example 3:**
```text
Input: arr[] = [1, 1], k = 2
Output: 2
Explanation: Since the array is already having the max consecutive 1's, hence we dont need to perform any operation. Hence the answer is 2.
```

<br/>

## ⚙️ Constraints

- $1 \le arr.size() \le 10^5$
- $0 \le k \le arr.size()$
- $0 \le arr[i] \le 1$

<br/>

## 🧩 Problem Details
- **Difficulty:** Medium
- **Tags:** Arrays, Sliding Window, Two Pointers
