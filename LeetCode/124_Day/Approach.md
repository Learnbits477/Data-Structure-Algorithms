# 💡 Approach — Destroying Asteroids

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Time Complexity: O(N log N)](https://img.shields.io/badge/Time%20Complexity-O(N%20log%20N)-blue?style=for-the-badge)
![Space Complexity: O(1)](https://img.shields.io/badge/Space%20Complexity-O(1)-blue?style=for-the-badge)

> [!TIP]
> **Core Insight:** To maximize the mass we can accumulate and ensure the destruction of all asteroids, we should always target the smallest available asteroids first. This greedy choice guarantees that if there's any valid order to destroy all asteroids, the sorted order will be one of them.

## 🔩 Step-by-Step Breakdown
1. **Initialize Variables:** Convert the initial `mass` to a `long long` integer. This is crucial because the sum of asteroid masses can easily exceed the maximum limit of a standard 32-bit integer, leading to overflow issues.
2. **Sort the Asteroids:** Sort the given `asteroids` array in ascending order.
3. **Simulate Collisions:** Iterate through the sorted `asteroids` array. 
   - If the current `mass` is greater than or equal to the current asteroid's mass, the planet destroys it, and we add its mass to our current `mass`.
   - If our current `mass` is strictly less than the asteroid's mass, we can't destroy it (nor any subsequent larger asteroids), so we return `false`.
4. **Return Result:** If the loop completes successfully, it means all asteroids were destroyed, so we return `true`.

## 🔄 Mermaid Flowchart
```mermaid
flowchart TD
    A[Start] --> B[Initialize current_mass = mass as long long]
    B --> C[Sort asteroids in ascending order]
    C --> D{Are there more asteroids?}
    D -- Yes --> E[Get next asteroid]
    E --> F{current_mass >= asteroid?}
    F -- Yes --> G[current_mass += asteroid]
    G --> D
    F -- No --> H[Return false]
    D -- No --> I[Return true]
    H --> J[End]
    I --> J
```

## 📊 Complexity Analysis

| Complexity | Analysis |
|:---|:---|
| **Time** | $\mathcal{O}(N \log N)$ — Sorting the array dominates the time complexity. The subsequent iteration takes $\mathcal{O}(N)$ time. |
| **Space** | $\mathcal{O}(1)$ or $\mathcal{O}(\log N)$ — Depending on the sorting algorithm used under the hood (e.g., IntroSort generally uses $\mathcal{O}(\log N)$ auxiliary stack space). No extra data structures are created. |

> *"First, solve the problem. Then, write the code."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../123_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../125_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
