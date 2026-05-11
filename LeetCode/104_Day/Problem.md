# [2553. Separate the Digits in an Array](https://leetcode.com/problems/separate-the-digits-in-an-array/?envType=daily-question&envId=2026-05-03)

| 📄 [Problem](Problem.md) | 💡 [Approach](Approach.md) | 🧠 [Solution](Solution.cpp) | 🚀 [Main](Main.cpp) |
|:---:|:---:|:---:|:---:|

---

## 📊 Metadata

| Field        | Details                         |
|--------------|---------------------------------|
| **Difficulty** | 🟢 Easy                        |
| **Acceptance** | 83.5% (142,615 / 170.8K)       |
| **Topics**     | Array, Simulation               |
| **Date**       | 2026-05-03 (Daily Question)     |

---

## 📝 Problem Description

Given an array of positive integers `nums`, return an array `answer` that consists of the **digits** of each integer in `nums` after separating them in the **same order** they appear in `nums`.

To **separate the digits** of an integer is to get all the digits it has in the same order.

> For example, for the integer `10921`, the separation of its digits is `[1, 0, 9, 2, 1]`.

---

## 🧪 Examples

**Example 1:**

```
Input:  nums = [13, 25, 83, 77]
Output: [1, 3, 2, 5, 8, 3, 7, 7]

Explanation:
  - Separation of 13  →  [1, 3]
  - Separation of 25  →  [2, 5]
  - Separation of 83  →  [8, 3]
  - Separation of 77  →  [7, 7]

  answer = [1, 3, 2, 5, 8, 3, 7, 7]
```

**Example 2:**

```
Input:  nums = [7, 1, 3, 9]
Output: [7, 1, 3, 9]

Explanation:
  Each integer is already a single digit, so separation is itself.
  answer = [7, 1, 3, 9]
```

---

## 📐 Constraints

$$1 \leq \text{nums.length} \leq 1000$$

$$1 \leq \text{nums}[i] \leq 10^5$$

---

| Happy Coding! 🚀
|:---:|
</div>
