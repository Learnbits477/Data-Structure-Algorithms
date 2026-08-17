# 💡 Approach — 1563. Stone Game V

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Topics:-Dynamic--Programming-blue?style=for-the-badge)
![Topic: Game Theory](https://img.shields.io/badge/Topics:-Game--Theory-blue?style=for-the-badge)
![Company Tags](https://img.shields.io/badge/Company%20Tags-Google%20%7C%20Amazon%20%7C%20Microsoft-black?style=for-the-badge)

---

<div align="center">
  <img src="./stone_game_v.jpg" alt="Stone Game V Visual Illustration" width="600"/>
</div>

---

## 💡 Core Insight

> [!TIP]
> **Optimal Substructure & Range DP:**  
> This game requires optimal partition decisions on contiguous subarrays of stones.
> Let `dp[i][j]` be the maximum score Alice can earn from the subarray `stoneValue[i..j]`.
> - Base Case: For a single stone ($i == j$), `dp[i][i] = 0` (no further splits possible).
> - Transition: For any range $[i, j]$, try all partition points $k$ ($i \le k < j$):
>   - Left sum = $sum(i, k)$, Right sum = $sum(k+1, j)$.
>   - If $sum_L < sum_R \implies score = sum_L + dp[i][k]$
>   - If $sum_R < sum_L \implies score = sum_R + dp[k+1][j]$
>   - If $sum_L == sum_R \implies score = sum_L + \max(dp[i][k], dp[k+1][j])$
> 
> Taking the maximum over all valid $k$ gives `dp[i][j]`.

---

## 🔩 Step-by-Step Breakdown

1. **Prefix Sum Precomputation**:
   - Construct array `pref` of size $N + 1$ such that `pref[r] - pref[l]` gives the sum of `stoneValue[l..r-1]` in $O(1)$ time.

2. **2D DP State Initialization**:
   - `dp[N][N]` initialized to `0`.

3. **Subarray Length Iteration**:
   - Outer loop `len` from 2 to $N$.
   - Inner loop start index `i` from 0 to $N - len$.
   - End index `j = i + len - 1`.

4. **Split Point Evaluation**:
   - For `k` from `i` to `j - 1`:
     - Calculate `leftSum = pref[k + 1] - pref[i]`.
     - Calculate `rightSum = pref[j + 1] - pref[k + 1]`.
     - Update `dp[i][j]` with the maximum achievable points based on Bob's rule.

5. **Result**:
   - `dp[0][N - 1]` contains Alice's maximum score for the entire array.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A[Start: stoneValue array of size N] --> B[Build prefix sum array pref]
    B --> C[Initialize dp table of size N x N with 0]
    C --> D["Loop len = 2 to N"]
    D --> E["Loop i = 0 to N - len (j = i + len - 1)"]
    E --> F["Loop k = i to j - 1"]
    F --> G["Compute leftSum and rightSum"]
    G --> H{"Compare leftSum vs rightSum"}
    H -- "leftSum < rightSum" --> I["dp[i][j] = max(dp[i][j], leftSum + dp[i][k])"]
    H -- "rightSum < leftSum" --> J["dp[i][j] = max(dp[i][j], rightSum + dp[k+1][j])"]
    H -- "Equal" --> K["dp[i][j] = max(dp[i][j], leftSum + max(dp[i][k], dp[k+1][j]))"]
    I --> L{Next k?}
    J --> L
    K --> L
    L -- Yes --> F
    L -- No --> M{Next i / len?}
    M -- Yes --> E
    M -- No --> N[Return dp[0][N-1]]
```

---

## 🔍 Detailed Dry Run

### Example: `stoneValue = [6, 2, 3, 4, 5, 5]`
- Prefix sum: `[0, 6, 8, 11, 15, 20, 25]`

| Range `[i, j]` | Partition $k$ | `leftSum` | `rightSum` | Option Score | `dp[i][j]` |
| :------------: | :-----------: | :-------: | :--------: | :----------: | :--------: |
| `[1, 2] ([2, 3])` | $k=1$ | 2 | 3 | $2 + dp[1][1] = 2$ | **2** |
| `[2, 3] ([3, 4])` | $k=2$ | 3 | 4 | $3 + dp[2][2] = 3$ | **3** |
| `[4, 5] ([5, 5])` | $k=4$ | 5 | 5 | $5 + \max(0, 0) = 5$ | **5** |
| `[0, 5]` | $k=2$ (`[6,2,3]` vs `[4,5,5]`) | 11 | 14 | $11 + dp[0][2] = 11 + 7 = 18$ | **18** |

- **Output:** `18`

---

## 📊 Complexity Analysis

| Complexity | Resource | Details / Explanation |
| :--------: | :------: | --------------------- |
| **Time**   | $O(N^3)$ | $O(N^2)$ states with an $O(N)$ split loop per state. (Can be optimized to $O(N^2)$ with monotonic queues/pointers). |
| **Space**  | $O(N^2)$ | 2D dynamic programming table of size $N \times N$. |

---

> *"Divide-and-conquer game theory problems naturally translate into interval DP state transitions."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../201_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../203_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
