# 2091. [Removing Minimum and Maximum From Array](https://leetcode.com/problems/removing-minimum-and-maximum-from-array/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 60.8%](https://img.shields.io/badge/Acceptance-60.8%25-green?style=for-the-badge)
![Submissions: 139.3K](https://img.shields.io/badge/Submissions-139.3K-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Array-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Greedy-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given a **0-indexed** array of distinct integers `nums`.

There is an element in `nums` that has the **lowest** value and an element that has the **highest** value. We call them the **minimum** and **maximum** respectively. Your goal is to remove both these elements from the array.

A deletion is defined as either removing an element from the **front** of the array or removing an element from the **back** of the array.

Return the **minimum number of deletions** it would take to remove both the minimum and maximum element from the array.

---

## 📌 Examples

**Example 1:**
```text
Input: nums = [2,10,7,5,4,1,8,6]
Output: 5
Explanation: 
The minimum element in the array is nums[5], which is 1.
The maximum element in the array is nums[1], which is 10.
We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
This results in 2 + 3 = 5 deletions, which is the minimum number possible.
```

**Example 2:**
```text
Input: nums = [0,-4,19,1,8,-2,-3,5]
Output: 3
Explanation: 
The minimum element in the array is nums[1], which is -4.
The maximum element in the array is nums[2], which is 19.
We can remove both the minimum and maximum by removing 3 elements from the front.
This results in only 3 deletions, which is the minimum number possible.
```

**Example 3:**
```text
Input: nums = [101]
Output: 1
Explanation: 
There is only one element in the array, which makes it both the minimum and maximum element.
We can remove it with 1 deletion.
```

---

## 📐 Constraints

- $1 \le \text{nums.length} \le 10^5$
- $-10^5 \le \text{nums}[i] \le 10^5$
- The integers in `nums` are **distinct**.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../214_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../216_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
