# [Max sum in the configuration](https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1)

<div align="center">
  <a href="https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1"><strong>Problem Link</strong></a> |
  <a href="./Solution.cpp"><strong>Solution.cpp</strong></a> |
  <a href="./Approach.md"><strong>Approach.md</strong></a> |
  <a href="./Main.cpp"><strong>Main.cpp</strong></a>
</div>

<br/>

## 📝 Problem Statement

Given an integer array `arr[]`. Find the maximum value of the sum of `i * arr[i]` for all `0 <= i <= arr.size() - 1`. The only operation allowed is to rotate (clockwise or counterclockwise) the array any number of times.

<br/>

## 🎯 Examples

### **Example 1:**
```text
Input: arr[] = [3, 1, 2, 8]
Output: 29
Explanation:
Out of all the possible configurations by rotating the elements:
arr[] = [3, 1, 2, 8], sum = 3*0 + 1*1 + 2*2 + 8*3 = 29.
This is the maximum.
```

### **Example 2:**
```text
Input: arr[] = [1, 2, 3]
Output: 8
Explanation:
Out of all the possible configurations by rotating the elements:
arr[] = [1, 2, 3], sum = 1*0 + 2*1 + 3*2 = 8.
This is the maximum.
```

### **Example 3:**
```text
Input: arr[] = [4, 13]
Output: 13
```

<br/>

## ⚙️ Constraints

- $1 \le arr.size() \le 10^4$
- $1 \le arr[i] \le 20$

<br/>

## 🧩 Problem Details
- **Difficulty:** Medium
- **Tags:** Arrays, Mathematical
