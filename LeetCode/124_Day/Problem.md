# [2126. Destroying Asteroids](https://leetcode.com/problems/destroying-asteroids/description/?envType=daily-question&envId=2026-05-05)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance Rate: 54.3%](https://img.shields.io/badge/Acceptance%20Rate-54.3%25-orange?style=for-the-badge)
![Submissions: 135.7K+](https://img.shields.io/badge/Submissions-135.7K%2B-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blueviolet?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Topic-Greedy-blueviolet?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Topic-Sorting-blueviolet?style=for-the-badge)

## 🧩 Problem Description
You are given an integer `mass`, which represents the original mass of a planet. You are further given an integer array `asteroids`, where `asteroids[i]` is the mass of the $i^{th}$ asteroid.

You can arrange for the planet to collide with the asteroids in any arbitrary order. If the mass of the planet is greater than or equal to the mass of the asteroid, the asteroid is destroyed and the planet gains the mass of the asteroid. Otherwise, the planet is destroyed.

Return `true` if all asteroids can be destroyed. Otherwise, return `false`.

## 📌 Examples

**Example 1:**
> **Input:** `mass = 10, asteroids = [3,9,19,5,21]`
> **Output:** `true`
> **Explanation:** One way to order the asteroids is `[9,19,5,3,21]`:
> - The planet collides with the asteroid with a mass of 9. New planet mass: 10 + 9 = 19
> - The planet collides with the asteroid with a mass of 19. New planet mass: 19 + 19 = 38
> - The planet collides with the asteroid with a mass of 5. New planet mass: 38 + 5 = 43
> - The planet collides with the asteroid with a mass of 3. New planet mass: 43 + 3 = 46
> - The planet collides with the asteroid with a mass of 21. New planet mass: 46 + 21 = 67
> All asteroids are destroyed.

**Example 2:**
> **Input:** `mass = 5, asteroids = [4,9,23,4]`
> **Output:** `false`
> **Explanation:** 
> The planet cannot ever gain enough mass to destroy the asteroid with a mass of 23.
> After the planet destroys the other asteroids, it will have a mass of 5 + 4 + 9 + 4 = 22.
> This is less than 23, so a collision would not destroy the last asteroid.

## 📐 Constraints
- $$1 \leq \text{mass} \leq 10^5$$
- $$1 \leq \text{asteroids.length} \leq 10^5$$
- $$1 \leq \text{asteroids}[i] \leq 10^5$$

## ⏱️ Expected Complexities

| Complexity | Expected |
|:---|:---|
| **Time** | $$O(N \log N)$$ |
| **Auxiliary Space** | $$O(\log N)$$ or $$O(1)$$ |

## 🏷️ Topic Tags
`Array` `Greedy` `Sorting`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../123_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../125_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
