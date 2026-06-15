# [139. Minimum Cost to Fill Given Weight in a Bag](https://www.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 25.56%](https://img.shields.io/badge/Accuracy-25.56%25-red?style=for-the-badge)
![Submissions: 80K+](https://img.shields.io/badge/Submissions-80K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🧩 Problem Description

Given a bag of size **w kg** and an array `cost[]` representing the costs of orange packets of different weights, find the **minimum total cost** to buy **exactly w kg** of oranges.

- `cost[i]` represents the cost of an **(i+1) kg** packet of orange.
- `cost[i] = -1` means that the **(i+1) kg** packet is **unavailable**.
- There is an **infinite supply** of all available packet types (unbounded).
- If it is **not possible** to buy exactly `w` kg of oranges, return **-1**.

---

## 📌 Examples

### Example 1
```
Input:  cost[] = [20, 10, 4, 50, 100], w = 5
Output: 14
```
**Explanation:** The minimum cost is **14** by purchasing:
- A **2 kg** packet costing **10**
- A **3 kg** packet costing **4**

Total = 10 + 4 = **14**

---

### Example 2
```
Input:  cost[] = [-1, -1, 4, 3, -1], w = 5
Output: -1
```
**Explanation:** Available packets are only **3 kg** (cost 4) and **4 kg** (cost 3).
No combination of 3 kg and 4 kg packets can sum to exactly **5 kg**, so the answer is **-1**.

---

## 📐 Constraints

$$1 \leq \text{cost.size()},\ w \leq 2 \times 10^3$$

$$1 \leq \text{cost}[i] \leq 10^5$$

> `cost[i] = -1` indicates the packet of size `(i+1)` kg is unavailable.

---

## ⏱️ Expected Complexities

| Complexity       | Bound          |
|:----------------:|:--------------:|
| 🕐 Time          | $O(n \times w)$ |
| 💾 Auxiliary Space | $O(n \times w)$ |

---

## 🏷️ Topic Tags

<div align="center">

![Dynamic Programming](https://img.shields.io/badge/Dynamic%20Programming-0A9EDC?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-6C3483?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../138_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../140_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
