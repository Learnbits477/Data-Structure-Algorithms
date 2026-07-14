# [168. Smallest Non-Zero Number](https://www.geeksforgeeks.org/problems/find-smallest-non-zero-number4510/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 33.84%](https://img.shields.io/badge/Accuracy-33.84%25-green?style=for-the-badge)
![Submissions: 5K+](https://img.shields.io/badge/Submissions-5K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an array `arr[]`, find the smallest positive integer `x` such that when `x` is processed sequentially with each element of the array (from index $0$ to $n-1$), it never becomes negative (i.e. remains $\ge 0$), under the following conditions:

- If $x$ is greater than the current array element, $x$ is increased by the difference between $x$ and the array element:
  $$x = x + (x - arr[i]) = 2x - arr[i]$$
- If $x$ is less than or equal to the current array element, $x$ is decreased by the difference between the array element and $x$:
  $$x = x - (arr[i] - x) = 2x - arr[i]$$

---

## 📌 Examples

### Example 1
**Input:**
```text
arr[] = [3, 4, 3, 2, 4]
```
**Output:**
```text
4
```
**Explanation:**
Start with $x = 4$:
- For $arr[0] = 3$, $x$ becomes $5$.
- For $arr[1] = 4$, $x$ becomes $6$.
- For $arr[2] = 3$, $x$ becomes $9$.
- For $arr[3] = 2$, $x$ becomes $16$.
- For $arr[4] = 4$, $x$ becomes $28$.

$x$ remains non-negative throughout the process. If $x < 4$, it would become negative at some point.

### Example 2
**Input:**
```text
arr[] = [4, 4]
```
**Output:**
```text
3
```
**Explanation:**
Start with $x = 3$:
- For $arr[0] = 4$, $x$ becomes $2$.
- For $arr[1] = 4$, $x$ becomes $0$.

$x$ remains non-negative. If $x < 3$, it would become negative.

---

## 📐 Constraints

- $$1 \le arr.size() \le 10^6$$
- $$1 \le arr[i] \le 10^4$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(n)$$ |
| 💾 Auxiliary Space | $$O(1)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Arrays](https://img.shields.io/badge/Arrays-1ABC9C?style=for-the-badge)
![Data Structures](https://img.shields.io/badge/Data%20Structures-2ECC71?style=for-the-badge)

</div>

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../167_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../169_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
