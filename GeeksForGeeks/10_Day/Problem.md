# [Happiest Triplet](https://www.geeksforgeeks.org/problems/happiest-triplet2921/1)

<div align="center">
  <a href="https://www.geeksforgeeks.org/problems/happiest-triplet2921/1"><strong>Problem Link</strong></a> |
  <a href="./Solution.cpp"><strong>Solution.cpp</strong></a> |
  <a href="./Approach.md"><strong>Approach.md</strong></a> |
  <a href="./Main.cpp"><strong>Main.cpp</strong></a>
</div>

<br/>

## 📝 Problem Statement

You are given three arrays `a[]`, `b[]`, `c[]` of the same size. Find a triplet such that `(maximum - minimum)` in that triplet is the minimum of all the triplets. A triplet should be selected so that it should have one number from each of the three given arrays. This triplet is the happiest among all the possible triplets. Print the triplet in decreasing order.

**Note**: If there are 2 or more smallest difference triplets, then the one with the **smallest sum** of its elements should be displayed.

<br/>

## 🎯 Examples

### **Example 1:**
```text
Input:
a[] = [5, 2, 8]
b[] = [10, 7, 12]
c[] = [9, 14, 6]

Output: [7, 6, 5]

Explanation: The triplet [5, 7, 6] has difference (maximum - minimum) = (7 - 5) = 2 which is minimum of all triplets.
```

### **Example 2:**
```text
Input:
a[] = [15, 12, 18, 9]
b[] = [10, 17, 13, 8]
c[] = [14, 16, 11, 5]

Output: [11, 10, 9]

Explanation: Multiple triplets have the same minimum difference, and among them [11, 10, 9] has the smallest sum, so it is chosen.
```

<br/>

## ⚙️ Constraints

- $1 \le a.size(), b.size(), c.size() \le 10^5$
- $1 \le a[i], b[i], c[i] \le 10^5$

<br/>

## 🧩 Problem Details
- **Difficulty:** Medium
- **Tags:** Arrays, Sorting, Two Pointers (Three Pointers)
