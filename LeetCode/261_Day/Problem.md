# 261. [Geek hates too many 1s](https://www.geeksforgeeks.org/problems/geek-hates-too-many-1s--170647/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 58.04%](https://img.shields.io/badge/Accuracy-58.04%25-orange?style=for-the-badge)
![Submissions: 21K+](https://img.shields.io/badge/Submissions-21K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: Bit Magic](https://img.shields.io/badge/Topic-Bit%20Magic-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Greedy MSB-to-LSB Scanning & Least-Penalty Bit Unsetting:**
> 1. **High-Order Preservation**:
>    Because higher-order bits contribute exponentially more to the value than lower-order bits ($2^k > \sum_{j=0}^{k-1} 2^j$), clearing any higher bit causes a strictly greater numerical penalty than clearing a lower bit.
> 2. **Rightmost Triplet Elimination**:
>    Whenever three consecutive set bits (`111`) appear during an MSB-to-LSB traversal (at bit indices $i, i-1, i-2$), clearing bit $i-2$ incurs the minimal loss ($2^{i-2}$) while immediately resolving the violation.
> 3. **Run Reset**:
>    Clearing the third consecutive bit resets the run length of consecutive set bits to $0$, ensuring that lower bits cannot inadvertently form invalid triplets with the cleared position.

---

## 🧩 Problem Description

Given a non-negative integer `n`, you can only change a set bit (`1`) to an unset bit (`0`).

Find the **maximum possible value** of `n` such that its binary representation does **not** contain three consecutive set bits (`111`) after performing zero or more allowed operations.

---

## 📌 Examples

**Example 1:**

```text
Input: n = 2
Output: 2
Explanation:
The binary representation of 2 is 10, which does not contain three consecutive set bits. Therefore, no change is required.
```

**Example 2:**

```text
Input: n = 7
Output: 6
Explanation:
The binary representation of 7 is 111, which contains three consecutive set bits.
Changing the rightmost set bit to 0 gives: 111 -> 110 (which is 6).
Thus, the maximum possible value is 6.
```

---

## 📐 Constraints

- $0 \le n \le 10^9$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(1)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

*Since $n \le 10^9 < 2^{30}$, we inspect at most 32 bits, requiring a constant number of bitwise operations with zero dynamic memory allocation.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../260_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../262_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
