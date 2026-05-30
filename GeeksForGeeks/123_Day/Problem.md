# [123. Replace with XOR of Adjacent](https://www.geeksforgeeks.org/problems/replace-with-xor-of-adjacent/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 75.8%](https://img.shields.io/badge/Accuracy-75.8%25-yellow?style=for-the-badge)
![Submissions: 66K+](https://img.shields.io/badge/Submissions-66K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)

![Topic: Arrays](https://img.shields.io/badge/Topic-Arrays-blueviolet?style=for-the-badge)
![Topic: Bit Magic](https://img.shields.io/badge/Topic-Bit%20Magic-red?style=for-the-badge)
![Topic: Data Structures](https://img.shields.io/badge/Topic-Data%20Structures-teal?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given an array `arr[]` of `n` integers, replace each element with the **XOR of its adjacent elements**.

- For the **first** element: `arr[0] = arr[0] ^ arr[1]`
- For the **last** element: `arr[n-1] = arr[n-2] ^ arr[n-1]`
- For **all other** elements: `arr[i] = arr[i-1] ^ arr[i+1]`

> **Note:** All XOR operations are computed using the **original** values of the array (not the modified ones).

---

## 📌 Examples

### Example 1

**Input:**
```
arr[] = [2, 1, 4, 7]
```

**Output:**
```
[3, 6, 6, 3]
```

**Explanation:**
| Index | Operation              | Result |
|:-----:|:----------------------:|:------:|
| 0     | `arr[0] ^ arr[1]` = `2 ^ 1` | `3`  |
| 1     | `arr[0] ^ arr[2]` = `2 ^ 4` | `6`  |
| 2     | `arr[1] ^ arr[3]` = `1 ^ 7` | `6`  |
| 3     | `arr[2] ^ arr[3]` = `4 ^ 7` | `3`  |

Updated array: `[3, 6, 6, 3]`

---

### Example 2

**Input:**
```
arr[] = [5, 9, 2, 6, 7]
```

**Output:**
```
[12, 7, 15, 5, 1]
```

**Explanation:**
| Index | Operation               | Result |
|:-----:|:-----------------------:|:------:|
| 0     | `arr[0] ^ arr[1]` = `5 ^ 9`  | `12` |
| 1     | `arr[0] ^ arr[2]` = `5 ^ 2`  | `7`  |
| 2     | `arr[1] ^ arr[3]` = `9 ^ 6`  | `15` |
| 3     | `arr[2] ^ arr[4]` = `2 ^ 7`  | `5`  |
| 4     | `arr[3] ^ arr[4]` = `6 ^ 7`  | `1`  |

Updated array: `[12, 7, 15, 5, 1]`

---

## 📐 Constraints

$$2 \leq n \leq 10^5$$

$$1 \leq arr[i] \leq 10^7$$

---

## ⏱️ Expected Complexities

| Complexity       | Bound  |
|:----------------:|:------:|
| **Time**         | `O(n)` |
| **Auxiliary Space** | `O(1)` |

---

## 🏷️ Topic Tags

`Arrays` · `Bit Magic` · `Data Structures`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../122_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../124_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
