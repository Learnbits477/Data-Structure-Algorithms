# [Max Circular Subarray Sum](https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1)

<div align="center">
  <a href="https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1"><strong>GFG Problem</strong></a> |
  <a href="./Solution.cpp"><strong>Solution.cpp</strong></a> |
  <a href="./Approach.md"><strong>Approach.md</strong></a> |
  <a href="./Main.cpp"><strong>Main.cpp</strong></a>
</div>

<br/>

## 📝 Problem Statement

You are given a circular array `arr[]` of integers. Find the maximum possible sum of a non-empty subarray. In a circular array, the subarray can start at the end and wrap around to the beginning.

Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.

<br/>

## 🎯 Examples

### **Example 1:**
```text
Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
Output: 22
Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
```

### **Example 2:**
```text
Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
Output: 23
Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].
```

### **Example 3:**
```text
Input: arr[] = [5, -2, 3, 4]
Output: 12
Explanation: The circular subarray [3, 4, 5] gives the maximum sum of 12.
```

<br/>

## ⚙️ Constraints

- $1 \le arr.size() \le 10^5$
- $-10^4 \le arr[i] \le 10^4$

<br/>

## 🧩 Problem Details
- **Difficulty:** Hard
- **Platform:** GeeksForGeeks
- **Tags:** Arrays, Kadane's Algorithm, Dynamic Programming
