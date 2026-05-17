# [110. Make the array beautiful](https://www.geeksforgeeks.org/problems/make-the-array-beautiful--170647/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

--- 
## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 49.96%](https://img.shields.io/badge/Accuracy-49.96%25-blue?style=for-the-badge)
![Submissions: 71K+](https://img.shields.io/badge/Submissions-71K+-purple?style=for-the-badge)
![Topic: Stack](https://img.shields.io/badge/Topic-Stack-blue?style=for-the-badge)

---

## 🧩 Problem Description
Given an array of negative and non-negative integers. You need to make the array beautiful.

An array is beautiful if two adjacent integers, `arr[i]` and `arr[i+1]` are either negative or positive. You can do the following operation any number of times until the array becomes beautiful.

If two adjacent elements are different i.e. one of them is negative and the other is positive, **remove them**.

Return the beautiful array after performing the above operation.

> [!NOTE]
> - An empty array is also a beautiful array.
> - There can be multiple beautiful output arrays. For consistency with the test cases, **scan the array from left to right** for removing two adjacent elements.

---

## 📌 Examples

**Example 1:**
- **Input:** `arr[] = [4, 2, -2, 1]`
- **Output:** `[4, 1]`
- **Explanation:** 
  - At indices 1 and 2, `2` (non-negative) and `-2` (negative) have different signs, so they are removed.
  - The array becomes `[4, 1]`.
  - In `[4, 1]`, both `4` and `1` are non-negative, which is beautiful.

**Example 2:**
- **Input:** `arr[] = [2, -2, -1, 1]`
- **Output:** `[]`
- **Explanation:** 
  - At indices 0 and 1, `2` and `-2` have different signs, so they are removed.
  - The array becomes `[-1, 1]`.
  - Now `-1` and `1` have different signs, so they are also removed.
  - The final array is empty `[]`.

---

## 📐 Constraints
- $$1 \le \text{arr.size()} \le 10^5$$
- $$-10^5 \le \text{arr}[i] \le 10^5$$

---

## ⏱️ Expected Complexities
| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $$O(n)$$ |
| **Auxiliary Space** | $$O(n)$$ |

---

## 🏷️ Topic Tags
`Stack`, `Array`, `Data Structures`

--- 

<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../109_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../111_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
