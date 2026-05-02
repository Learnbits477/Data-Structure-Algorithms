# [Maximum Product Subarray](https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1)

<div align="center">
  <a href="https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1"><strong>Problem Link</strong></a> |
  <a href="./Solution.cpp"><strong>Solution.cpp</strong></a> |
  <a href="./Approach.md"><strong>Approach.md</strong></a> |
  <a href="./Main.cpp"><strong>Main.cpp</strong></a>
</div>

<br/>

## 📝 Problem Statement

Given an array `arr[]` that contains positive and negative integers (may contain `0` as well). Find the maximum product that we can get in a subarray of `arr[]`.

**Note:** It is guaranteed that the answer fits in a 32-bit integer.

<br/>

## 🎯 Examples

### **Example 1:**
```text
Input: arr[] = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is [6, -3, -10] with product = 6 * (-3) * (-10) = 180.
```

### **Example 2:**
```text
Input: arr[] = [-1, -3, -10, 0, 6]
Output: 30
Explanation: The subarray with maximum product is [-3, -10] with product = (-3) * (-10) = 30.
```

### **Example 3:**
```text
Input: arr[] = [2, 3, 4]
Output: 24
Explanation: For an array with all positive elements, the result is product of all elements.
```

<br/>

## ⚙️ Constraints

- $1 \le arr.size() \le 10^6$
- $-10 \le arr[i] \le 10$

<br/>

## 🧩 Problem Details
- **Difficulty:** Medium
- **Tags:** Arrays, Dynamic Programming
