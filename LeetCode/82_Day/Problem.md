# [1855. Maximum Distance Between a Pair of Values](https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/)

## 📌 Problem Overview

**Difficulty:** Medium  
**Topics:** Array, Two Pointers, Binary Search  

You are given two **non-increasing** 0-indexed integer arrays `nums1` and `nums2`.

A pair of indices `(i, j)`, where `0 <= i < nums1.length` and `0 <= j < nums2.length`, is **valid** if both `i <= j` and `nums1[i] <= nums2[j]`. The **distance** of the pair is `j - i`.

Return the maximum distance of any valid pair `(i, j)`. If there are no valid pairs, return `0`.

An array `arr` is **non-increasing** if `arr[i-1] >= arr[i]` for every `1 <= i < arr.length`.

---

## 📝 Examples

### **Example 1**
**Input:** 
```text
nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
```
**Output:** 
```text
2
```
**Explanation:** 
The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
The maximum distance is 2 with pair (2,4).

### **Example 2**
**Input:** 
```text
nums1 = [2,2,2], nums2 = [10,10,1]
```
**Output:** 
```text
1
```
**Explanation:** 
The valid pairs are (0,0), (0,1), and (1,1).
The maximum distance is 1 with pair (0,1).

### **Example 3**
**Input:** 
```text
nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
```
**Output:** 
```text
2
```
**Explanation:** 
The valid pairs are (2,2), (2,3), (2,4), (3,3), and (3,4).
The maximum distance is 2 with pair (2,4).

---

## ⚙️ Constraints

*   $1 \le nums1.length, nums2.length \le 10^5$
*   $1 \le nums1[i], nums2[j] \le 10^5$
*   Both `nums1` and `nums2` are **non-increasing**.

---

## 🔗 Source
[LeetCode - Maximum Distance Between a Pair of Values](https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/)
