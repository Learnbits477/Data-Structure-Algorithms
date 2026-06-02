# 💡 Approach — Earliest Finish Time for Land and Water Rides I

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 67.0%](https://img.shields.io/badge/Acceptance-67.0%25-blue?style=for-the-badge)

> [!TIP]
> **Core Insight**
> Since the number of rides is small ($$n, m \leq 100$$), we can simply simulate taking every possible pair of land and water rides. For each pair, we evaluate two orderings: doing the land ride first, and doing the water ride first. We keep track of the minimum possible finish time across all combinations.

## 🔩 Step-by-Step Breakdown

1. **Initialize Minimum Finish Time:** Set `minFinishTime` to a very large value (e.g., `INT_MAX`) to track the best overall time.
2. **Iterate Land Rides:** Loop through each land ride using an index `i`.
3. **Iterate Water Rides:** Loop through each water ride using an index `j`.
4. **Calculate Land First Ordering:** For a chosen pair, if we take the land ride first, it finishes at `landStartTime[i] + landDuration[i]`. We can start the water ride at the maximum of this finish time and `waterStartTime[j]`. The total finish time is this start time plus `waterDuration[j]`.
5. **Calculate Water First Ordering:** If we take the water ride first, it finishes at `waterStartTime[j] + waterDuration[j]`. We can then start the land ride at the maximum of this finish time and `landStartTime[i]`. The total finish time is this start time plus `landDuration[i]`.
6. **Update Minimum:** Take the minimum of the two orderings, and use it to update our global `minFinishTime` if it's smaller.
7. **Return Result:** After iterating through all possible $n \times m$ pairs, return the absolute minimum finish time found.

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A[Start] --> B[Initialize minFinishTime = INT_MAX]
    B --> C[Loop i from 0 to n-1]
    C --> D{Is i < n?}
    D -- Yes --> E[Loop j from 0 to m-1]
    E --> F{Is j < m?}
    F -- Yes --> G[Calculate time: Land then Water]
    G --> H[Calculate time: Water then Land]
    H --> I[Update minFinishTime]
    I --> J[j = j + 1]
    J --> F
    F -- No --> K[i = i + 1]
    K --> C
    D -- No --> L[Return minFinishTime]
    L --> M[End]
```

## 📊 Complexity Analysis

| Complexity | Evaluation | Description |
|:---|:---|:---|
| **Time Complexity** | $$O(n \cdot m)$$ | There are $$n$$ land rides and $$m$$ water rides. Using two nested loops, we evaluate each of the $$n \times m$$ pairs exactly once. Evaluating the math for a pair takes $$O(1)$$ time. |
| **Space Complexity** | $$O(1)$$ | We only use a few constant extra integer variables to store start times, durations, and the running minimum. No extra data structures are required. |

> *"First, solve the problem. Then, write the code."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../125_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../127_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
