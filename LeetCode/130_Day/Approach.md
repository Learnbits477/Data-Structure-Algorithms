# 💡 Approach — Left and Right Sum Differences

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 88.4%](https://img.shields.io/badge/Acceptance-88.4%25-green?style=for-the-badge)
![Submissions: 281K](https://img.shields.io/badge/Submissions-281K-blue?style=for-the-badge)
![Topics: Array, Prefix Sum](https://img.shields.io/badge/Topics-Array%20%7C%20Prefix%20Sum-lightgrey?style=for-the-badge)

> [!TIP]
> **Core Insight:** 
> Instead of creating two separate prefix/suffix arrays taking $O(n)$ space, we can compute the total sum of the array and track `leftSum` and `rightSum` dynamically in a single pass. This optimizes the space complexity to $O(1)$!

## 🔩 Step-by-Step Breakdown
1. **Calculate Total Sum:** Iterate through the array to find the total sum. Initially, `rightSum` will be equal to this total sum, and `leftSum` will be $0$.
2. **Initialize Answer Array:** Create an answer vector `ans` of the same size as `nums`.
3. **Iterate and Compute Differences:** For each element at index `i`:
   - First, subtract `nums[i]` from `rightSum` (because `rightSum[i]` only includes elements *strictly* to the right).
   - Calculate the absolute difference `|leftSum - rightSum|` and store it in `answer[i]`.
   - Finally, add `nums[i]` to `leftSum` so it's ready for the next iteration (index `i + 1`).
4. **Return Result:** Once the loop completes, return the generated `answer` array.

## 🔄 Mermaid Flowchart
```mermaid
flowchart TD
    A[Start] --> B[Calculate Total Sum: rightSum = sum]
    B --> C[Initialize leftSum = 0]
    C --> D[Loop i from 0 to n-1]
    D --> E[Subtract nums i from rightSum]
    E --> F[Calculate ans i = abs_diff leftSum, rightSum]
    F --> G[Add nums i to leftSum]
    G --> H{More elements?}
    H -- Yes --> D
    H -- No --> I[Return ans Array]
    I --> J[End]
```

## 📊 Complexity Analysis
| Complexity | Analysis |
|:---:|:---|
| **Time Complexity** | $$O(n)$$ — We traverse the array twice: once to find the total sum, and once to compute the differences. |
| **Auxiliary Space** | $$O(1)$$ — We use two variables (`leftSum` and `rightSum`) instead of tracking prefix arrays. (Ignoring the required output array). |

> *"Simplicity is prerequisite for reliability."* — Edsger W. Dijkstra

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
