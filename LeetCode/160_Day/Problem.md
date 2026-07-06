# [1288. Remove Covered Intervals](https://leetcode.com/problems/remove-covered-intervals/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 56.9%](https://img.shields.io/badge/Acceptance-56.9%25-blue?style=for-the-badge)
![Submissions: 286.7K](https://img.shields.io/badge/Submissions-286.7K-brightgreen?style=for-the-badge)
![Company Tags](https://img.shields.io/badge/Company%20Tags-Google-black?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an array `intervals` where `intervals[i] = [li, ri]` represent the interval `[li, ri)`, remove all intervals that are covered by another interval in the list.

The interval `[a, b)` is covered by the interval `[c, d)` if and only if:
$$c \le a \quad \text{and} \quad b \le d$$

Return the number of remaining intervals.

---

## 📌 Examples

### Example 1
**Input:**
```text
intervals = [[1,4],[3,6],[2,8]]
```
**Output:**
```text
2
```
**Explanation:**
Interval `[3,6]` is covered by `[2,8]`, therefore it is removed.

### Example 2
**Input:**
```text
intervals = [[1,4],[2,3]]
```
**Output:**
```text
1
```
**Explanation:**
Interval `[2,3]` is covered by `[1,4]`, therefore it is removed.

---

## 📐 Constraints

- $$1 \le \text{intervals.length} \le 1000$$
- $$\text{intervals}[i].\text{length} == 2$$
- $$0 \le l_i < r_i \le 10^5$$
- All the given intervals are **unique**.

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(N \log N)$$ |
| 💾 Auxiliary Space | $$O(1)$$ or $$O(N)$$ depending on sort implementation |

---

## 🏷️ Topic Tags

<div align="center">

![Array](https://img.shields.io/badge/Array-3498DB?style=for-the-badge)
![Sorting](https://img.shields.io/badge/Sorting-8E44AD?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../159_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../161_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
