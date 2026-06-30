# [147. Maximum Number of People Defeated](https://www.geeksforgeeks.org/problems/killing-spree3020/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 48.32%](https://img.shields.io/badge/Accuracy-48.32%25-green?style=for-the-badge)
![Submissions: 28K+](https://img.shields.io/badge/Submissions-28K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

There are infinitely many people standing in a row, indexed from $1$. The strength of the person at index $i$ is $i^2$.

Given a strength $p$, determine the maximum number of people that can be defeated. A person with strength $x$ can be defeated only if $p \ge x$, after which the strength $p$ decreases by $x$.

---

## 📌 Examples

### Example 1
```text
Input: p = 14
Output: 3
Explanation: The strengths of the first few people are 1, 4, 9, 16, ....
Defeating the first three people consumes 1 + 4 + 9 = 14 strength, leaving 0.
Therefore, the maximum number of people that can be defeated is 3.
```

---

### Example 2
```text
Input: p = 10
Output: 2
Explanation: After defeating people with strengths 1 and 4, the remaining strength is 5,
which is less than the next required strength 9.
```

---

## 📐 Constraints

- $$1 \le p \le 3 \times 10^8$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(\log n)$$ |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Mathematical](https://img.shields.io/badge/Mathematical-007ACC?style=for-the-badge)
![Divide and Conquer](https://img.shields.io/badge/Divide%20and%20Conquer-8E44AD?style=for-the-badge)
![Binary Search](https://img.shields.io/badge/Binary%20Search-FF5722?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../146_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../148_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
