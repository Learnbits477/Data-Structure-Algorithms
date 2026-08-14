# 💡 Approach — Subset Sum on Generated Sequence

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Topics:-Greedy-blue?style=for-the-badge)

---

## 💡 Core Insight

> [!TIP]
> **Core Insight:**  
> The numbers written on the paper form a **superincreasing sequence**, where each element $P_k$ is strictly greater than the sum of all preceding elements ($P_k > P_0 + P_1 + \dots + P_{k-1}$).  
> Because each term grows at least exponentially ($P_k \ge s \cdot 2^k$), the sequence exceeds $x$ in at most $\approx 63$ steps.  
> For any superincreasing sequence, the **Greedy Choice** is optimal: iterate backwards from the largest element $\le x$, and if $x \ge P_k$, subtract $P_k$ from $x$. If $x$ becomes $0$, then $x$ can be formed by a subset!

---

## 🔩 Step-by-Step Breakdown

1. **Generate Sequence Terms up to $x$**:
   - Start with initial paper term $P_0 = s$ and running paper sum `current_sum = s`.
   - For each child's assigned value `arr[i]`:
     - Calculate `next_val = current_sum + arr[i]`.
     - If `next_val > x` or `current_sum > x`, stop generating (to avoid unnecessary iterations and 64-bit integer overflow).
     - Otherwise, add `next_val` to sequence $P$ and update `current_sum += next_val`.

2. **Greedy Subset Selection**:
   - Process the generated terms in sequence $P$ from right to left (largest to smallest).
   - For each term $P[i]$:
     - If $x \ge P[i]$, pick $P[i]$ and update $x = x - P[i]$.

3. **Check Result**:
   - If $x == 0$, return `true` (or `1`).
   - Otherwise, return `false` (or `0`).

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A[Start] --> B["Initialize P = [s], current_sum = s"]
    B --> C{"i < N and current_sum <= x?"}
    C -- Yes --> D["next_val = current_sum + arr[i]"]
    D --> E{"next_val > x?"}
    E -- No --> F["P.push_back(next_val)<br/>current_sum += next_val"]
    F --> G["i = i + 1"] --> C
    E -- Yes --> H["Break Loop"]
    C -- No --> H
    H --> I["Iterate P from end to start (i = P.size()-1 down to 0)"]
    I --> J{"x >= P[i]?"}
    J -- Yes --> K["x = x - P[i]"]
    J -- No --> L["Skip P[i]"]
    K --> M{"More elements in P?"}
    L --> M
    M -- Yes --> I
    M -- No --> N{"x == 0?"}
    N -- Yes --> O["Return 1 (true)"]
    N -- No --> P_res["Return 0 (false)"]
```

---

## 📊 Complexity Analysis

| Complexity | Resource | Details / Explanation |
| :--------: | :------: | --------------------- |
| **Time**   | $O(\min(N, \log X))$ | The sequence grows exponentially, generating at most $\approx 63$ terms before exceeding $X$. Iterating over $P$ takes $O(\log X)$ steps. |
| **Space**  | $O(\min(N, \log X))$ | Auxiliary vector $P$ stores at most $\approx 63$ terms ($O(\log X)$ space). |

---

> *"When each step outgrows the sum of its past, greedy choices from the future guarantee the optimal path."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../198_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../200_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
