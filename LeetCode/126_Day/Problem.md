# [3633. Earliest Finish Time for Land and Water Rides I](https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 67.0%](https://img.shields.io/badge/Acceptance-67.0%25-blue?style=for-the-badge)
![Submissions: 55K+](https://img.shields.io/badge/Submissions-55K+-blueviolet?style=for-the-badge)
![Topics: Array, Greedy](https://img.shields.io/badge/Topic_Tags-Array%20|%20Greedy-lightgrey?style=for-the-badge)

## 🧩 Problem Description

You are given two categories of theme park attractions: land rides and water rides.

**Land rides**
- `landStartTime[i]` – the earliest time the $i^{th}$ land ride can be boarded.
- `landDuration[i]` – how long the $i^{th}$ land ride lasts.

**Water rides**
- `waterStartTime[j]` – the earliest time the $j^{th}$ water ride can be boarded.
- `waterDuration[j]` – how long the $j^{th}$ water ride lasts.

A tourist must experience exactly one ride from each category, in either order.
- A ride may be started at its opening time or any later moment.
- If a ride is started at time $t$, it finishes at time $t + \text{duration}$.
- Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.

Return the earliest possible time at which the tourist can finish both rides.

## 📌 Examples

**Example 1:**
```text
Input: landStartTime = [2,8], landDuration = [4,1], waterStartTime = [6], waterDuration = [3]
Output: 9
Explanation:
Plan A (land ride 0 → water ride 0):
Start land ride 0 at time landStartTime[0] = 2. Finish at 2 + landDuration[0] = 6.
Water ride 0 opens at time waterStartTime[0] = 6. Start immediately at 6, finish at 6 + waterDuration[0] = 9.
Plan B (water ride 0 → land ride 1):
Start water ride 0 at time waterStartTime[0] = 6. Finish at 6 + waterDuration[0] = 9.
Land ride 1 opens at landStartTime[1] = 8. Start at time 9, finish at 9 + landDuration[1] = 10.
Plan C (land ride 1 → water ride 0):
Start land ride 1 at time landStartTime[1] = 8. Finish at 8 + landDuration[1] = 9.
Water ride 0 opened at waterStartTime[0] = 6. Start at time 9, finish at 9 + waterDuration[0] = 12.
Plan D (water ride 0 → land ride 0):
Start water ride 0 at time waterStartTime[0] = 6. Finish at 6 + waterDuration[0] = 9.
Land ride 0 opened at landStartTime[0] = 2. Start at time 9, finish at 9 + landDuration[0] = 13.
Plan A gives the earliest finish time of 9.
```

**Example 2:**
```text
Input: landStartTime = [5], landDuration = [3], waterStartTime = [1], waterDuration = [10]
Output: 14
Explanation:
Plan A (water ride 0 → land ride 0):
Start water ride 0 at time waterStartTime[0] = 1. Finish at 1 + waterDuration[0] = 11.
Land ride 0 opened at landStartTime[0] = 5. Start immediately at 11 and finish at 11 + landDuration[0] = 14.
Plan B (land ride 0 → water ride 0):
Start land ride 0 at time landStartTime[0] = 5. Finish at 5 + landDuration[0] = 8.
Water ride 0 opened at waterStartTime[0] = 1. Start immediately at 8 and finish at 8 + waterDuration[0] = 18.
Plan A provides the earliest finish time of 14.
```

## 📐 Constraints

- $$1 \leq n, m \leq 100$$
- $$\text{landStartTime.length} == \text{landDuration.length} == n$$
- $$\text{waterStartTime.length} == \text{waterDuration.length} == m$$
- $$1 \leq \text{landStartTime}[i], \text{landDuration}[i], \text{waterStartTime}[j], \text{waterDuration}[j] \leq 1000$$

## ⏱️ Expected Complexities

| Complexity | Expected |
|:---|:---|
| **Time Complexity** | $$O(n \cdot m)$$ |
| **Space Complexity** | $$O(1)$$ |

## 🏷️ Topic Tags
`Array`, `Two Pointers`, `Binary Search`, `Greedy`, `Sorting`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../125_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../127_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
