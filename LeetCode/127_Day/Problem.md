# [3635. Earliest Finish Time for Land and Water Rides II](https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/description/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 47.0%](https://img.shields.io/badge/Acceptance-47.0%25-green?style=for-the-badge)
![Submissions: 24.5K+](https://img.shields.io/badge/Submissions-24.5K+-blue?style=for-the-badge)
![Topics: Greedy, Array](https://img.shields.io/badge/Topics-Greedy%2C%20Array-red?style=for-the-badge)

## 🧩 Problem Description
You are given two categories of theme park attractions: land rides and water rides.

**Land rides**
- `landStartTime[i]` – the earliest time the `i`-th land ride can be boarded.
- `landDuration[i]` – how long the `i`-th land ride lasts.

**Water rides**
- `waterStartTime[j]` – the earliest time the `j`-th water ride can be boarded.
- `waterDuration[j]` – how long the `j`-th water ride lasts.

A tourist must experience exactly one ride from each category, in either order.
- A ride may be started at its opening time or any later moment.
- If a ride is started at time `t`, it finishes at time `t + duration`.
- Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.

Return the earliest possible time at which the tourist can finish both rides.

## 📌 Examples

**Example 1:**
> **Input:** `landStartTime = [2,8], landDuration = [4,1], waterStartTime = [6], waterDuration = [3]`
> **Output:** `9`
> **Explanation:**
> Plan A (land ride 0 → water ride 0): Start land ride 0 at time 2. Finish at 6. Water ride 0 opens at 6. Start immediately at 6, finish at 9.
> Plan B (water ride 0 → land ride 1): Start water ride 0 at 6. Finish at 9. Land ride 1 opens at 8. Start at 9, finish at 10.
> Plan A gives the earliest finish time of 9.

**Example 2:**
> **Input:** `landStartTime = [5], landDuration = [3], waterStartTime = [1], waterDuration = [10]`
> **Output:** `14`
> **Explanation:**
> Plan A (water ride 0 → land ride 0): Start water ride 0 at 1. Finish at 11. Land ride 0 opened at 5. Start immediately at 11 and finish at 14.
> Plan B (land ride 0 → water ride 0): Start land ride 0 at 5. Finish at 8. Water ride 0 opened at 1. Start immediately at 8 and finish at 18.
> Plan A provides the earliest finish time of 14.

## 📐 Constraints
- $$1 \le n, m \le 5 \cdot 10^4$$
- `landStartTime.length == landDuration.length == n`
- `waterStartTime.length == waterDuration.length == m`
- $$1 \le landStartTime[i], landDuration[i], waterStartTime[j], waterDuration[j] \le 10^5$$

## ⏱️ Expected Complexities
| Complexity | Time |
|:---:|:---:|
| **Time** | $$O(N + M)$$ |
| **Auxiliary Space** | $$O(1)$$ |

## 🏷️ Topic Tags
`Array`, `Greedy`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../126_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../128_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
