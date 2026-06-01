# 💡 Approach — Minimum Cost of Buying Candies With Discount

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Topic-Greedy-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Topic-Sorting-blue?style=for-the-badge)

> [!TIP]
> **Core Insight:** 
> To minimize the total cost, we want the most expensive candies to be the ones we get for free. Since we can only get a candy for free if its cost is less than or equal to the minimum of two bought candies, we should greedily buy the most expensive candies and claim the next most expensive candy as the free one. Sorting the array in descending order helps us pair up every two expensive candies and skip the third one!

## 🔩 Step-by-Step Breakdown

1. **Sort the Candies:** Sort the `cost` array in descending order so that the most expensive candies are at the beginning.
2. **Iterate Greedily:** Loop through the sorted array. For every three consecutive candies, the first two are bought, and the third one is taken for free.
3. **Accumulate Cost:** Add the cost of a candy to the total cost if its index (1-based) is not a multiple of 3. In 0-based indexing, this means adding `cost[i]` if `(i + 1) % 3 != 0`.
4. **Return Result:** Return the final accumulated total cost.

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A[Start] --> B[Sort cost array in descending order]
    B --> C[Initialize totalCost = 0, i = 0]
    C --> D{Is i < cost.length?}
    D -- Yes --> E{Is i + 1 a multiple of 3?}
    E -- Yes --> F[Skip candy, get it for free!]
    E -- No --> G[Add cost i to totalCost]
    F --> H[Increment i]
    G --> H
    H --> D
    D -- No --> I[Return totalCost]
    I --> J[End]
```

## 📊 Complexity Analysis

| Complexity | Measure | Reason |
|:---:|:---:|:---|
| **Time** | $O(n \log n)$ | Sorting the array dominates the time complexity. |
| **Space** | $O(1)$ | No extra auxiliary space is used other than variables (assuming in-place sorting). |

> *"Simplicity is the soul of efficiency."* — Austin Freeman

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../124_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../126_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
