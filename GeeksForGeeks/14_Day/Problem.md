# [Koko Eating Bananas](https://www.geeksforgeeks.org/problems/koko-eating-bananas1553/1)

<div align="center">
  <a href="https://www.geeksforgeeks.org/problems/koko-eating-bananas1553/1"><strong>Problem Link</strong></a> |
  <a href="./Solution.cpp"><strong>Solution.cpp</strong></a> |
  <a href="./Approach.md"><strong>Approach.md</strong></a> |
  <a href="./Main.cpp"><strong>Main.cpp</strong></a>
</div>

<br/>

## 📝 Problem Statement

Koko is given an array `arr[]`, where each element represents a pile of bananas. She has exactly `k` hours to eat all the bananas.

Each hour, Koko can choose one pile and eat up to `s` bananas from it.
- If the pile has at least `s` bananas, she eats exactly `s` bananas.
- If the pile has fewer than `s` bananas, she eats the entire pile in that hour.

Koko can only eat from one pile per hour.

Your task is to find the **minimum value of s** (bananas per hour) such that Koko can finish all the piles within `k` hours.

<br/>

## 🎯 Examples

### **Example 1:**
```text
Input: arr[] = [5, 10, 3], k = 4
Output: 5
Explanation: If Koko eats at the rate of 5 bananas per hour:
First pile of 5 bananas will be finished in 1 hour.
Second pile of 10 bananas will be finished in 2 hours.
Third pile of 3 bananas will be finished in 1 hour.
Therefore, Koko can finish all piles of bananas in 1 + 2 + 1 = 4 hours.
```

### **Example 2:**
```text
Input: arr[] = [5, 10, 15, 20], k = 7
Output: 10
Explanation: If Koko eats at the rate of 10 bananas per hour, it will take 6 hours to finish all the piles.
```

<br/>

## ⚙️ Constraints

- $1 \le arr.size() \le k \le 10^6$
- $1 \le arr[i] \le 10^6$

<br/>

## 🧩 Problem Details
- **Difficulty:** Medium
- **Tags:** Arrays, Binary Search
