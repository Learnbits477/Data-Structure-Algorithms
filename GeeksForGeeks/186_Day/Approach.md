# 💡 Approach — Max After m Range Increments

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 49.92%](https://img.shields.io/badge/Accuracy-49.92%25-blue?style=for-the-badge)
![Submissions: 14K+](https://img.shields.io/badge/Submissions-14K+-purple?style=for-the-badge)
![Topic: Prefix Sum](https://img.shields.io/badge/Topics:-Prefix_Sum-blue?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Arrays-cyan?style=for-the-badge)
![Company: FactSet](https://img.shields.io/badge/Companies:-FactSet-orange?style=for-the-badge)

</div>

---

## 🎯 Core Insight

> [!TIP]
> **Difference Array (Sweep-line) Algorithm**
>
> 1. **Avoid Brute Force:** Running each of the $m$ increment operations from index $a_i$ to $b_i$ takes $\mathcal{O}(n \cdot m)$ time, which will result in TLE (Time Limit Exceeded) for $10^6$ constraints.
> 2. **Constant-time Updates:** We can represent range updates in $\mathcal{O}(1)$ using a **difference array** `diff` of size $n+1$:
>    - For each range update $(a_i, b_i, k_i)$, we perform:
>      - `diff[a_i] += k_i`
>      - `diff[b_i + 1] -= k_i` (if $b_i + 1 < n$)
> 3. **Linear Reconstruction:** After processing all $m$ operations, we compute the prefix sum of `diff` to reconstruct the actual elements of the array.
> 4. **Find Max:** Maintain a running maximum value while calculating prefix sums to identify the maximum value in the final array.

---

## 🔩 Step-by-Step Breakdown

### Step 1: Initialize Difference Array
- Create a difference array `diff` of size $n + 1$, initialized to all zeros.

### Step 2: Apply Range Operations
- For each operation $i$ from $0$ to $m-1$:
  - Add $k[i]$ to `diff[a[i]]`.
  - Subtract $k[i]$ from `diff[b[i] + 1]` if $b[i] + 1 < n$.

### Step 3: Compute Prefix Sums
- Initialize `maxVal = 0` and `currentVal = 0`.
- Traverse indices $i$ from $0$ to $n-1$:
  - Add `diff[i]` to `currentVal`.
  - Update `maxVal = max(maxVal, currentVal)`.

### Step 4: Return Max Value
- Return `maxVal` cast to `int` (matching GeeksForGeeks method signature).

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start(["Start: findMax(n, a, b, k)"]) --> InitDiff["Initialize diff[n+1] = 0"]
    InitDiff --> LoopOps["Loop i from 0 to m-1"]
    LoopOps --> AddStart["diff[a[i]] += k[i]"]
    AddStart --> CheckEnd{"Is b[i] + 1 < n?"}
    CheckEnd -- Yes --> SubEnd["diff[b[i] + 1] -= k[i]"]
    CheckEnd -- No --> NextOp["i++"]
    SubEnd --> NextOp
    NextOp --> CheckLoop{"Is i < m?"}
    CheckLoop -- Yes --> LoopOps
    CheckLoop -- No --> InitReconstruct["Initialize maxVal = 0\ncurrentVal = 0\nj = 0"]
    InitReconstruct --> LoopSum{"Is j < n?"}
    LoopSum -- Yes --> CalcSum["currentVal += diff[j]"]
    CalcSum --> UpdateMax["maxVal = max(maxVal, currentVal)"]
    UpdateMax --> IncrementJ["j++"]
    IncrementJ --> LoopSum
    LoopSum -- No --> ReturnResult["Return (int)maxVal"]
    ReturnResult --> End(["End"])
```

---

## 🧮 Dry Run

### Dry Run: Example 1
- **Input:** $n = 5$, $a = [0, 1, 2]$, $b = [1, 4, 3]$, $k = [100, 100, 100]$
- **Initialization:** `diff = [0, 0, 0, 0, 0, 0]`

#### Phase 1: Applying Difference Operations

| Op Index | Range `[a, b]` | Increment Value `k` | Action on `diff` | Resulting `diff` array |
| :---: | :---: | :---: | :---: | :--- |
| **0** | `[0, 1]` | 100 | `diff[0] += 100`, `diff[2] -= 100` | `[100, 0, -100, 0, 0, 0]` |
| **1** | `[1, 4]` | 100 | `diff[1] += 100`, `diff[5] -= 100` (ignored, $\ge n$) | `[100, 100, -100, 0, 0, 0]` |
| **2** | `[2, 3]` | 100 | `diff[2] += 100`, `diff[4] -= 100` | `[100, 100, 0, 0, -100, 0]` |

#### Phase 2: Prefix Sum and Finding Max

| Index `j` | `diff[j]` | `currentVal` | `maxVal` |
| :---: | :---: | :---: | :---: |
| **0** | 100 | 100 | 100 |
| **1** | 100 | 200 | **200** (Max) |
| **2** | 0 | 200 | 200 |
| **3** | 0 | 200 | 200 |
| **4** | -100 | 100 | 200 |

- **Result:** Maximum value is **200**.

---

## 📊 Complexity Analysis

| Complexity | Analysis |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(n + m)$ where $n$ is the array size and $m$ is the number of operations. We iterate through the $m$ operations in $\mathcal{O}(m)$ time and reconstruct the array of size $n$ in $\mathcal{O}(n)$ time. |
| **Auxiliary Space** | $\mathcal{O}(n)$ space to store the difference array of size $n + 1$. |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../185_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../187_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
