# 3568. [Minimum Moves to Clean the Classroom](https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 28.8%](https://img.shields.io/badge/Acceptance-28.8%25-green?style=for-the-badge)
![Submissions: 37.5K](https://img.shields.io/badge/Submissions-37.5K-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Breadth--First%20Search%20%7C%20Bitmask%20%7C%20Matrix-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given an $m \times n$ grid `classroom` where a student volunteer is tasked with cleaning up litter scattered around the room. Each cell in the grid is one of the following:
- `'S'`: Starting position of the student (exactly one).
- `'L'`: Litter that must be collected (once collected, the cell becomes empty, at most 10 `'L'` cells).
- `'R'`: Reset area that restores the student's energy to full capacity, regardless of their current energy level (can be used multiple times).
- `'X'`: Obstacle the student cannot pass through.
- `'.'`: Empty space.

You are also given an integer `energy`, representing the student's maximum energy capacity. The student starts with this energy from the starting position `'S'`.

Each move to an adjacent cell (up, down, left, or right) costs 1 unit of energy. If the energy reaches 0, the student can only continue if they are on a reset area `'R'`, which resets the energy to its maximum capacity `energy`.

Return the **minimum number of moves** required to collect all litter items, or `-1` if it's impossible.

---

## 📌 Examples

**Example 1:**
```text
Input: classroom = ["S.", "XL"], energy = 2
Output: 2
Explanation:
The student starts at cell (0, 0) with 2 units of energy.
Since cell (1, 0) contains an obstacle 'X', the student cannot move directly downward.
A valid sequence of moves to collect all litter is as follows:
Move 1: From (0, 0) → (0, 1) with 1 unit of energy used and 1 unit remaining.
Move 2: From (0, 1) → (1, 1) to collect the litter 'L'.
The student collects all the litter using 2 moves. Thus, the output is 2.
```

**Example 2:**
```text
Input: classroom = ["LS", "RL"], energy = 4
Output: 3
Explanation:
The student starts at cell (0, 1) with 4 units of energy.
A valid sequence of moves to collect all litter is as follows:
Move 1: From (0, 1) → (0, 0) to collect the first litter 'L' with 1 unit of energy used and 3 units remaining.
Move 2: From (0, 0) → (1, 0) to 'R' to reset and restore energy back to 4.
Move 3: From (1, 0) → (1, 1) to collect the second litter 'L'.
The student collects all the litter using 3 moves. Thus, the output is 3.
```

**Example 3:**
```text
Input: classroom = ["L.S", "RXL"], energy = 3
Output: -1
Explanation:
No valid path collects all 'L'.
```

---

## 📐 Constraints

- $1 \le m == \text{classroom.length} \le 20$
- $1 \le n == \text{classroom[i].length} \le 20$
- $\text{classroom}[i][j] \in \{'S', 'L', 'R', 'X', '.'\}$
- $1 \le \text{energy} \le 50$
- There is **exactly one** `'S'` in the grid.
- There are **at most 10** `'L'` cells in the grid.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(m \cdot n \cdot 2^K)$ where $K \le 10$ is the number of litter cells |
| **Auxiliary Space** | $\mathcal{O}(m \cdot n \cdot 2^K)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../216_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../218_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
