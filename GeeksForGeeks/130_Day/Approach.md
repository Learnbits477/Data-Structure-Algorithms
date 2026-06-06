# 💡 Approach — Non-Attacking Black and White Knights

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 51.2%](https://img.shields.io/badge/Accuracy-51.2%25-green?style=for-the-badge)
![Submissions: 32K+](https://img.shields.io/badge/Submissions-32K+-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topics: Backtracking, Algorithms](https://img.shields.io/badge/Topics-Backtracking%20%7C%20Algorithms-lightgrey?style=for-the-badge)

> [!TIP]
> **Core Insight:** 
> Instead of using an $O(n \times m)$ simulation to manually count non-attacking positions, we can optimize the approach to mathematical combinatorics in $O(1)$ time. Calculate the *total possible placements* for two knights and subtract the *attacking placements*.
> - Total placements = `Total Squares × (Total Squares - 1)`
> - Attacking placements = `4 × (n - 1) × (m - 2) + 4 × (n - 2) × (m - 1)`

## 🔩 Step-by-Step Breakdown
1. **Calculate Total Squares:** Find the total number of squares on the chessboard, which is `n * m`.
2. **Calculate Total Placements:** The first knight can be placed on any of the `n * m` squares, and the second knight can be placed on any of the remaining `(n * m) - 1` squares. Total ways = `(n * m) * (n * m - 1)`.
3. **Calculate Attacking Configurations:** 
   - A knight's attack range forms a `2×3` or a `3×2` bounding box on the board.
   - Number of horizontal L-shapes (`2×3` grids) on an `n×m` board is `(n - 1) * (m - 2)`. In each such grid, there are 2 attacking pairs (4 permutations).
   - Number of vertical L-shapes (`3×2` grids) on an `n×m` board is `(n - 2) * (m - 1)`. In each such grid, there are 2 attacking pairs (4 permutations).
   - Total attacking placements = `4 * (n - 1) * (m - 2) + 4 * (n - 2) * (m - 1)`.
4. **Compute Valid Ways:** Subtract the attacking configurations from the total possible placements: `totalWays - attackingWays`.

## 🔄 Mermaid Flowchart
```mermaid
flowchart TD
    A[Start] --> B[Calculate Total Squares: T = n * m]
    B --> C[Calculate Total Ways: T * T - 1]
    C --> D{Are dimensions enough for attacks?}
    D -- Yes --> E[Calculate 2x3 bounds: 4 * n-1 * m-2]
    D -- Yes --> F[Calculate 3x2 bounds: 4 * n-2 * m-1]
    E --> G[Total Attacking = Sum of bounds]
    F --> G
    D -- No --> H[Total Attacking = 0]
    G --> I[Valid Ways = Total Ways - Total Attacking]
    H --> I
    I --> J[Return Valid Ways]
    J --> K[End]
```

## 📊 Complexity Analysis
| Complexity | Analysis |
|:---:|:---|
| **Time Complexity** | $$O(1)$$ — We use a direct mathematical formula instead of the expected $O(n \times m)$ loops, computing the result in constant time. |
| **Auxiliary Space** | $$O(1)$$ — No additional memory bounds are allocated. |

> *"The best way to write secure and reliable applications is to write code that is impossible to execute in any other way than what the developer intended."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../129_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../131_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
