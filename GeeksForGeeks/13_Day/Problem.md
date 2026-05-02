# [Find Kth Rotation](https://www.geeksforgeeks.org/problems/find-kth-rotation5407/1)

<div align="center">
  <a href="https://www.geeksforgeeks.org/problems/find-kth-rotation5407/1"><strong>Problem Link</strong></a> |
  <a href="./Solution.cpp"><strong>Solution.cpp</strong></a> |
  <a href="./Approach.md"><strong>Approach.md</strong></a> |
  <a href="./Main.cpp"><strong>Main.cpp</strong></a>
</div>

<br/>

## 📝 Problem Statement

Given an increasing sorted rotated array `arr[]` of distinct integers. The array is right-rotated `k` times. Find the value of `k`.

Let's suppose we have an array `arr[] = [2, 4, 6, 9]`, if we rotate it by `2` times it will look like this:
- After 1st Rotation : `[9, 2, 4, 6]`
- After 2nd Rotation : `[6, 9, 2, 4]`

<br/>

## 🎯 Examples

### **Example 1:**
```text
Input: arr[] = [5, 1, 2, 3, 4]
Output: 1
Explanation: The given array is [5, 1, 2, 3, 4]. The original sorted array is [1, 2, 3, 4, 5]. We can see that the array was rotated 1 time to the right.
```

### **Example 2:**
```text
Input: arr = [1, 2, 3, 4, 5]
Output: 0
Explanation: The given array is not rotated.
```

<br/>

## ⚙️ Constraints

- $1 \le arr.size() \le 10^5$
- $1 \le arr[i] \le 10^7$

<br/>

## 🧩 Problem Details
- **Difficulty:** Easy
- **Tags:** Arrays, Binary Search
