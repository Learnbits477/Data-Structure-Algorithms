# [146. Dam of Candies](https://www.geeksforgeeks.org/problems/dam-of-candies--141631/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 39.48%](https://img.shields.io/badge/Accuracy-39.48%25-green?style=for-the-badge)
![Submissions: 27K+](https://img.shields.io/badge/Submissions-27K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)
![Company Tags](https://img.shields.io/badge/Company%20Tags-Amazon-black?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an integer array `height[]`, where `height[i]` represents the height of the $i$-th bar arranged in a row, find the maximum rectangular area that can be formed by selecting any two bars. The area is calculated based on the original positions of the selected bars.

The area formed between two bars at indices `left` and `right` (where `left < right`) is:
$$\text{Area} = \min(\text{height}[\text{left}], \text{height}[\text{right}]) \times (\text{right} - \text{left} - 1)$$

---

## 📌 Examples

### Example 1
```text
Input: height[] = [2, 5, 4, 3, 7]
Output: 10
Explanation: The maximum rectangular area is formed by selecting the bars of heights 5 (index 1) and 7 (index 4).
There are 2 bars between them (indices 2 and 3), so the area is:
min(5, 7) × 2 = 10
```

---

### Example 2
```text
Input: height[] = [1, 3, 4]
Output: 1
Explanation: Selecting bars 1 (index 0) and 4 (index 2) gives one bar between them, so the area is:
min(1, 4) × 1 = 1
```

---

## 📐 Constraints

- $$1 \le \text{height.size()} \le 10^5$$
- $$1 \le \text{height}[i] \le 10^4$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n)$$ |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Two Pointer Algorithm](https://img.shields.io/badge/Two%20Pointer%20Algorithm-007ACC?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../145_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../147_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
