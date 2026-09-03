# 💡 Approach — Max Adjacent Diffs Sum with 1 Replacements

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 45.37%](https://img.shields.io/badge/Accuracy-45.37%25-green?style=for-the-badge)
![Submissions: 4K+](https://img.shields.io/badge/Submissions-4K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Dynamic%20Programming%20%7C%20Arrays-blue?style=for-the-badge)

---

> [!TIP]
> **Core Dynamic Programming Insight — 2-State Transition:**
> - For every index $i$ ($0 \le i < n$), we make a binary choice:
>   - **State 0:** Keep $arr[i]$ as its original value $arr[i]$.
>   - **State 1:** Replace $arr[i]$ with $1$.
> - The absolute difference between consecutive elements $arr[i]$ and $arr[i-1]$ depends only on the state chosen for $arr[i-1]$ and $arr[i]$.
> - Let:
>   - `dp[i][0]` = Maximum sum of adjacent differences for prefix $arr[0 \dots i]$ where $arr[i]$ is **kept original**.
>   - `dp[i][1]` = Maximum sum of adjacent differences for prefix $arr[0 \dots i]$ where $arr[i]$ is **replaced with 1**.
> - **State Transitions ($1 \le i < n$):**
>   $$\begin{aligned}
>     \text{dp}[i][0] &= \max\Big(\text{dp}[i-1][0] + |arr[i] - arr[i-1]|, \; \text{dp}[i-1][1] + |arr[i] - 1|\Big) \\
>     \text{dp}[i][1] &= \max\Big(\text{dp}[i-1][0] + |1 - arr[i-1]|, \; \text{dp}[i-1][1] + |1 - 1|\Big)
>   \end{aligned}$$
> - **Space Optimization:**
>   Because the current step $i$ depends strictly on step $i-1$, we only need two variables (`prev0` and `prev1`) achieving $\mathcal{O}(1)$ auxiliary space.

---

## 🔩 Step-by-Step Breakdown

1. **Base Case Initialization**:
   - If array size $n \le 1$, adjacent differences cannot exist; return $0$.
   - For index $i = 0$:
     - `prev0 = 0` (arr[0] remains original)
     - `prev1 = 0` (arr[0] becomes 1)

2. **Dynamic Programming Iteration**:
   - For $i = 1$ to $n - 1$:
     - Compute `curr0 = max(prev0 + abs(arr[i] - arr[i-1]), prev1 + abs(arr[i] - 1))`
     - Compute `curr1 = max(prev0 + abs(1 - arr[i-1]), prev1 + 0)`
     - Update `prev0 = curr0`, `prev1 = curr1`.

3. **Final Result**:
   - The maximum total adjacent absolute difference is $\max(\text{prev0}, \text{prev1})$.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A["Start: maxDiffSum(arr)"] --> B{"arr.size() <= 1?"}
    B -- "Yes" --> C["Return 0"]
    B -- "No" --> D["Initialize prev0 = 0, prev1 = 0"]
    D --> E["For i = 1 to n - 1"]
    E --> F["curr0 = max(prev0 + |arr[i] - arr[i-1]|, prev1 + |arr[i] - 1|)"]
    F --> G["curr1 = max(prev0 + |1 - arr[i-1]|, prev1 + |1 - 1|)"]
    G --> H["prev0 = curr0<br/>prev1 = curr1"]
    H --> I{"More elements?"}
    I -- "Yes" --> E
    I -- "No" --> J["Return max(prev0, prev1)"]
```

---

## 🏃‍♂️ Dry Run

### Example: $arr = [3, 2, 1, 4, 5]$

| Index $i$ | $arr[i]$ | $arr[i-1]$ | `curr0` Calculation | `curr1` Calculation | `prev0` | `prev1` |
|:---:|:---:|:---:|:---|:---|:---:|:---:|
| **0** | $3$ | — | Base Case | Base Case | $0$ | $0$ |
| **1** | $2$ | $3$ | $\max(0 + |2-3|, 0 + |2-1|) = \max(1, 1) = 1$ | $\max(0 + |1-3|, 0 + 0) = \max(2, 0) = 2$ | $1$ | $2$ |
| **2** | $1$ | $2$ | $\max(1 + |1-2|, 2 + |1-1|) = \max(2, 2) = 2$ | $\max(1 + |1-2|, 2 + 0) = \max(2, 2) = 2$ | $2$ | $2$ |
| **3** | $4$ | $1$ | $\max(2 + |4-1|, 2 + |4-1|) = \max(5, 5) = 5$ | $\max(2 + |1-1|, 2 + 0) = \max(2, 2) = 2$ | $5$ | $2$ |
| **4** | $5$ | $4$ | $\max(5 + |5-4|, 2 + |5-1|) = \max(6, 6) = 6$ | $\max(5 + |1-4|, 2 + 0) = \max(8, 2) = 8$ | $6$ | **8** |

**Final Answer:** $\max(6, 8) = \mathbf{8}$ ✅ (Corresponding to modified array $[3, 1, 1, 4, 1]$).

---

## 📊 Complexity Analysis

| Complexity Metric | Estimation | Rationale |
| :--- | :---: | :--- |
| **Time Complexity** | $\mathcal{O}(n)$ | Single pass from $i = 1$ to $n-1$ performing constant number of $\mathcal{O}(1)$ arithmetic operations per step. |
| **Auxiliary Space** | $\mathcal{O}(1)$ | Only two rolling variables (`prev0` and `prev1`) are stored across iterations. |

---

> *"Dynamic programming is not about filling in tables; it's about smart recursion with memory."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../218_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../220_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
