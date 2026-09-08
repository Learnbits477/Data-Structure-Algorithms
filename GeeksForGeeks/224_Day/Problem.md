# 224. [Word in Grid - All Occurrences](https://www.geeksforgeeks.org/problems/find-the-string-in-grid0111/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 22.88%](https://img.shields.io/badge/Accuracy-22.88%25-orange?style=for-the-badge)
![Submissions: 86K+](https://img.shields.io/badge/Submissions-86K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Recursion%20%7C%20DFS%20%7C%20Matrix-blue?style=for-the-badge)
![Company](https://img.shields.io/badge/Company-Zoho%20%7C%20Flipkart%20%7C%20Amazon%20%7C%20Microsoft%20%7C%20Samsung%20%7C%20FactSet-blue?style=for-the-badge)

---

## 🧩 Problem Description

<div align="center">
  <img src="./word_in_grid.jpg" alt="Word in Grid - 8 Directions Search" width="650"/>
</div>

Given a 2D grid `mat[][]` of size $n \times m$ consisting of characters and a string `word`, find all starting positions where the word occurs in the grid.

The word can be formed from any cell by moving in any of the **8 directions** (2 horizontal, 2 vertical, and 4 diagonal) in a **straight line without changing direction**.

Each cell can be used at most once per occurrence.

Return all unique starting coordinates in **lexicographically smallest order** (i.e. sorted by row index, then column index).

---

## 📌 Examples

**Example 1:**

<div align="center">
  <img src="./example1.jpg" alt="Example 1 Grid - Word 'abe'" width="380"/>
</div>

```text
Input: 
mat = [
  ['a', 'b', 'a', 'b'],
  ['a', 'b', 'e', 'b'],
  ['e', 'b', 'e', 'b']
]
word = "abe"

Output: [[0, 0], [0, 2], [1, 0]]

Explanation: 
- From (0, 0), we find "abe" in the right-down diagonal direction (0,0) -> (1,1) -> (2,2).
- From (0, 2), we find "abe" in the left-down diagonal direction (0,2) -> (1,1) -> (2,0).
- From (1, 0), we find "abe" in the horizontally right direction (1,0) -> (1,1) -> (1,2).
```

**Example 2:**

<div align="center">
  <img src="./example2.jpg" alt="Example 2 Grid - Word 'GEEKS'" width="600"/>
</div>

```text
Input: 
mat = [
  ['G', 'E', 'E', 'K', 'S', 'F', 'O', 'R', 'G', 'E', 'E', 'K', 'S'],
  ['G', 'E', 'E', 'K', 'S', 'Q', 'U', 'I', 'Z', 'G', 'E', 'E', 'K'],
  ['I', 'D', 'E', 'Q', 'A', 'P', 'R', 'A', 'C', 'T', 'I', 'C', 'E']
]
word = "GEEKS"

Output: [[0, 0], [0, 8], [1, 0]]

Explanation: 
- From (0, 0), we find "GEEKS" horizontally right.
- From (0, 8), we find "GEEKS" horizontally right.
- From (1, 0), we find "GEEKS" horizontally right.
```

---

## 📐 Constraints

- $1 \le n, m \le 50$
- $1 \le |word| \le 20$
- `mat[i][j]` and `word` consist of English alphabets.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n \times m \times 8 \times |word|)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../223_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../225_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
