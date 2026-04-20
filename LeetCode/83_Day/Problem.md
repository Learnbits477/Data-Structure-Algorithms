# [2078. Two Furthest Houses With Different Colors](https://leetcode.com/problems/two-furthest-houses-with-different-colors/)

## 📌 Problem Overview

There are **n** houses evenly lined up on the street, each painted with a color. You are given a **0-indexed** integer array `colors` where `colors[i]` represents the color of the $i^{th}$ house.

Return the **maximum distance** between two houses with **different colors**.

> [!NOTE]
> The distance between the $i^{th}$ and $j^{th}$ houses is $|i - j|$.

---

### 📥 Examples

**Example 1:**
- **Input:** `colors = [1,1,1,6,1,1,1]`
- **Output:** `3`
- **Explanation:** Furthest two houses with different colors are house 0 (color 1) and house 3 (color 6). Distance = $|0 - 3| = 3$.

**Example 2:**
- **Input:** `colors = [1,8,3,8,3]`
- **Output:** `4`
- **Explanation:** Furthest two houses with different colors are house 0 (color 1) and house 4 (color 3). Distance = $|0 - 4| = 4$.

**Example 3:**
- **Input:** `colors = [0,1]`
- **Output:** `1`
- **Explanation:** Furthest houses are 0 and 1. Distance = $1$.

---

### 🚩 Constraints
- $n == colors.length$
- $2 \le n \le 100$
- $0 \le colors[i] \le 100$
- At least two houses have different colors.

### 🛠️ Expected Complexity
- **Time Complexity:** $O(n)$
- **Space Complexity:** $O(1)$
