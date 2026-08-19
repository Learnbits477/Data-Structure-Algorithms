# 1386. [Cinema Seat Allocation](https://leetcode.com/problems/cinema-seat-allocation/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 45.6%](https://img.shields.io/badge/Acceptance-45.6%25-brightgreen?style=for-the-badge)
![Submissions: 156.5K](https://img.shields.io/badge/Submissions-156.5K-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Array,_Hash_Table,_Greedy,_Bit_Manipulation-blue?style=for-the-badge)

## 🧩 Problem Description

<div align="center">
  <img src="https://assets.leetcode.com/uploads/2020/02/14/cinema_seats_1.png" alt="Cinema Seat Layout" width="500"/>
</div>

A cinema has `n` rows of seats, numbered from `1` to `n`. Each row has `10` seats, numbered from `1` to `10`.

You are given a 2D integer array `reservedSeats`, where `reservedSeats[i] = [rowi, seati]` means that seat `seati` in row `rowi` is already reserved.

A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:
- seats `2, 3, 4, 5`
- seats `4, 5, 6, 7`
- seats `6, 7, 8, 9`

A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.

Return an integer denoting the maximum number of four-person groups that can be assigned.

## 📌 Examples

### Example 1:

<div align="center">
  <img src="https://assets.leetcode.com/uploads/2020/02/14/cinema_seats_2.png" alt="Example 1 Seat Allocation" width="500"/>
</div>

```text
Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows an optimal allocation of four groups. Seats marked in blue are already reserved, and each set of four contiguous seats marked in orange is assigned to one group.
```

### Example 2:
```text
Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
Output: 2
```

### Example 3:
```text
Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
Output: 4
```

## 📐 Constraints
- $1 \le n \le 10^9$
- $1 \le \text{reservedSeats.length} \le \min(10 \times n, 10^4)$
- $\text{reservedSeats}[i] == [\text{row}_i, \text{seat}_i]$
- $1 \le \text{row}_i \le n$
- $1 \le \text{seat}_i \le 10$
- All $\text{reservedSeats}[i]$ are distinct.

## ⏱️ Expected Complexities
| Parameter | Complexity |
| :---: | :---: |
| **Time** | $\mathcal{O}(m)$ where $m = \text{reservedSeats.length}$ |
| **Space** | $\mathcal{O}(m)$ |
---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../203_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../205_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
