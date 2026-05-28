# [121. Vertical Sum](https://www.geeksforgeeks.org/problems/vertical-sum/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 64.76%](https://img.shields.io/badge/Accuracy-64.76%25-blue?style=for-the-badge)
![Submissions: 54K+](https://img.shields.io/badge/Submissions-54K%2B-purple?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)

---

## 🧩 Problem Description

Given a binary tree having $n$ nodes, find the vertical sum of the nodes that are in the same vertical line. Return all sums through different vertical lines starting from the left-most vertical line to the right-most vertical line.

---

## 📌 Examples

### Example 1

**Input:**
```text
       1
    /    \
   2      3
  / \    / \
 4   5  6   7
```

**Output:** `4 2 12 3 7`

**Explanation:**
```text
Vertical Line Alignment:
   -2      -1       0       1       2    (Horizontal Distance)
   |       |        1       |       |
   |       2        |       3       |
   4       |      5 , 6     |       7
=========================================
   4       2       12       3       7    (Vertical Sums)
```

The tree has $5$ vertical lines:
- **Line 1 (Horizontal Distance = -2):** has only one node `4` $\Rightarrow$ vertical sum is $4$.
- **Line 2 (Horizontal Distance = -1):** has only one node `2` $\Rightarrow$ vertical sum is $2$.
- **Line 3 (Horizontal Distance = 0):** has three nodes: `1`, `5`, `6` $\Rightarrow$ vertical sum is $1 + 5 + 6 = 12$.
- **Line 4 (Horizontal Distance = 1):** has only one node `3` $\Rightarrow$ vertical sum is $3$.
- **Line 5 (Horizontal Distance = 2):** has only one node `7` $\Rightarrow$ vertical sum is $7$.

### Example 2

**Input:**
```text
          1
         /
        2
       /
      3
     /
    4
   /
  6
 /
7
```

**Output:** `7 6 4 3 2 1`

**Explanation:**
```text
Vertical Line Alignment:
   -5      -4      -3      -2      -1       0    (Horizontal Distance)
   7       |       |       |       |        |
   |       6       |       |       |        |
   |       |       4       |       |        |
   |       |       |       3       |        |
   |       |       |       |       2        |
   |       |       |       |       |        1
=================================================
   7       6       4       3       2        1    (Vertical Sums)
```

There are $6$ vertical lines, each having one node.
- **Line 1 (Horizontal Distance = -5):** node `7` $\Rightarrow$ sum is $7$.
- **Line 2 (Horizontal Distance = -4):** node `6` $\Rightarrow$ sum is $6$.
- **Line 3 (Horizontal Distance = -3):** node `4` $\Rightarrow$ sum is $4$.
- **Line 4 (Horizontal Distance = -2):** node `3` $\Rightarrow$ sum is $3$.
- **Line 5 (Horizontal Distance = -1):** node `2` $\Rightarrow$ sum is $2$.
- **Line 6 (Horizontal Distance = 0):** node `1` $\Rightarrow$ sum is $1$.

---

## 📐 Constraints

- $1 \le n \le 10^4$
- $1 \le \text{Node value} \le 10^5$

---

## ⏱️ Expected Complexities

| Complexity | Requirement |
| :--- | :--- |
| **Time Complexity** | $O(n \log k)$ or $O(n)$ |
| **Auxiliary Space** | $O(n)$ |

---

## 🏷️ Topic Tags

- `Tree`
- `Data Structures`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../120_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../122_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
