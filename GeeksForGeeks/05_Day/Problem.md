# [Maximum of all subarrays of size k](https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1)

<div align="center">
  <a href="https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1"><strong>GFG Problem</strong></a> |
  <a href="./Solution.cpp"><strong>Solution.cpp</strong></a> |
  <a href="./Approach.md"><strong>Approach.md</strong></a> |
  <a href="./Main.cpp"><strong>Main.cpp</strong></a>
</div>

<br/>

## 📝 Problem Statement

Given an array `arr[]` of positive integers and an integer `k`. You have to find the maximum value for each contiguous subarray of size `k`. Return an array of maximum values corresponding to each contiguous subarray.

<br/>

## 🎯 Examples

### **Example 1:**
```text
Input: arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3
Output: [3, 3, 4, 5, 5, 5, 6]
Explanation:
1st contiguous subarray [1, 2, 3], max = 3
2nd contiguous subarray [2, 3, 1], max = 3
3rd contiguous subarray [3, 1, 4], max = 4
4th contiguous subarray [1, 4, 5], max = 5
5th contiguous subarray [4, 5, 2], max = 5
6th contiguous subarray [5, 2, 3], max = 5
7th contiguous subarray [2, 3, 6], max = 6
```

### **Example 2:**
```text
Input: arr[] = [5, 1, 3, 4, 2], k = 1
Output: [5, 1, 3, 4, 2]
Explanation: When k = 1, each element in the array is its own subarray, so the output is simply the same array.
```

<br/>

## ⚙️ Constraints

- $1 \le arr.size() \le 10^6$
- $1 \le k \le arr.size()$
- $0 \le arr[i] \le 10^9$

<br/>

## 🧩 Problem Details
- **Difficulty:** Medium
- **Platform:** GeeksForGeeks
- **Tags:** Arrays, Queue, Sliding Window, Data Structures
