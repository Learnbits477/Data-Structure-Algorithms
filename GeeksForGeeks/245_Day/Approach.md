# 💡 Approach — Steps by Knight

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 37.32%](https://img.shields.io/badge/Accuracy-37.32%25-orange?style=for-the-badge)
![Submissions: 140K+](https://img.shields.io/badge/Submissions-140K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Company: Flipkart](https://img.shields.io/badge/Companies:-Flipkart-red?style=for-the-badge)
![Company: Amazon](https://img.shields.io/badge/Amazon-red?style=for-the-badge)
![Company: Microsoft](https://img.shields.io/badge/Microsoft-red?style=for-the-badge)
![Company: Goldman Sachs](https://img.shields.io/badge/Goldman%20Sachs-red?style=for-the-badge)
![Topic: Graph](https://img.shields.io/badge/Topic-Graph-blue?style=for-the-badge)
![Topic: BFS](https://img.shields.io/badge/BFS-blue?style=for-the-badge)
![Topic: Queue](https://img.shields.io/badge/Queue-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Breadth-First Search (BFS) on Unweighted Grid Graphs:**
> 1. **Shortest Path in Unweighted Graph**:
>    Every legal move made by a Knight has an equal edge weight of $1$. In any graph with uniform edge weights, **Breadth-First Search (BFS)** is mathematically proven to discover the shortest path to every node first.
> 2. **State Space Representation**:
>    The $n \times n$ chessboard represents an implicit undirected graph with $V = n^2$ vertices (cells) and up to $8 \cdot n^2$ edges.
> 3. **Level-Order Expansion**:
>    By expanding level-by-level (where level $k$ contains all chessboard cells reachable in exactly $k$ knight moves), the first time the target cell $(x_t, y_t)$ is generated or popped, the current level count is strictly the minimum possible steps.
> 4. **Pruning & Visited Tracking**:
>    To avoid redundant cycles and infinite loops, a 2D boolean array `visited[n + 1][n + 1]` ensures each cell enters the BFS queue at most once.

---

## 🔩 Step-by-Step Breakdown

1. **Identity & Base Case**:
   - If the knight's starting position equals the target position $(startX == targetX \land startY == targetY)$, return $0$ immediately without any traversal.

2. **Knight Movement Offsets**:
   - Precompute the $8$ allowable L-shaped movement offsets:
     $$\Delta x = [-2, -2, -1, -1, 1, 1, 2, 2]$$
     $$\Delta y = [-1, 1, -2, 2, -2, 2, -1, 1]$$

3. **Queue & Visited Initialization**:
   - Allocate `visited[n + 1][n + 1]` initialized to `false` (using 1-based indexing).
   - Initialize a standard FIFO `queue<pair<int, int>> q`.
   - Push `(startX, startY)` into `q` and mark `visited[startX][startY] = true`.
   - Initialize step counter `steps = 0`.

4. **Level-Order BFS Traversal**:
   - While `!q.empty()`:
     - Increment `steps` by $1$.
     - Cache current layer size: `levelSize = q.size()`.
     - Process all nodes in the current layer:
       - Pop `(currX, currY)`.
       - For each direction $d \in [0, 7]$:
         - Calculate $nextX = currX + \Delta x[d]$ and $nextY = currY + \Delta y[d]$.
         - **Target Check**: If $(nextX == targetX \land nextY == targetY)$, return `steps`.
         - **Validity Check**: If $1 \le nextX \le n$ and $1 \le nextY \le n$ and `!visited[nextX][nextY]`:
           - Mark `visited[nextX][nextY] = true`.
           - Enqueue `(nextX, nextY)`.

5. **Exhaustion / Unreachable**:
   - If the queue empties without reaching the target cell, return $-1$.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start["Start: minStepToReachTarget(knightPos, targetPos, n)"] --> CheckSame{"knightPos == targetPos?"}
    CheckSame -- "Yes" --> RetZero["Return 0 🏁"]
    CheckSame -- "No" --> InitBFS["Initialize visited[n+1][n+1] = false<br/>Queue q.push(knightPos)<br/>visited[startX][startY] = true<br/>steps = 0"]

    InitBFS --> QueueCheck{"Is Queue Empty?"}
    QueueCheck -- "Yes" --> RetUnreach["Return -1 (Unreachable) ⏹️"]

    QueueCheck -- "No" --> LayerInc["steps++<br/>levelSize = q.size()"]
    LayerInc --> LoopLayer["Process levelSize nodes"]

    LoopLayer --> PopNode["Pop (currX, currY) from Queue"]
    PopNode --> DirLoop["Iterate 8 Knight moves (d = 0..7)"]

    DirLoop --> CalcNext["nextX = currX + dx[d]<br/>nextY = currY + dy[d]"]
    CalcNext --> CheckTarget{"nextX == targetX &&<br/>nextY == targetY?"}

    CheckTarget -- "Yes" --> RetSteps["Return steps 🏁"]
    CheckTarget -- "No" --> CheckBounds{"1 <= nextX, nextY <= n &&<br/>!visited[nextX][nextY]?"}

    CheckBounds -- "Yes" --> PushNext["visited[nextX][nextY] = true<br/>q.push({nextX, nextY})"]
    CheckBounds -- "No" --> NextDir["Check next move direction"]
    PushNext --> NextDir

    NextDir --> MoreDirs{"More moves for current cell?"}
    MoreDirs -- "Yes" --> DirLoop
    MoreDirs -- "No" --> MoreLayerNodes{"More nodes in current layer?"}

    MoreLayerNodes -- "Yes" --> LoopLayer
    MoreLayerNodes -- "No" --> QueueCheck
```

---

## 🏃‍♂️ Dry Run

### Tracing Example 2: $n = 6$, `knightPos = [1, 3]`, `targetPos = [5, 1]`

```text
Chessboard Representation (6 x 6):
       Col 1   Col 2   Col 3   Col 4   Col 5   Col 6
Row 1:   .       .     [START]   .       .       .
Row 2:   .       .       .       .       .       .
Row 3:   .     (Step 1)  .       .       .       .
Row 4:   .       .       .       .       .       .
Row 5: [TARGET]  .       .       .       .       .
Row 6:   .       .       .       .       .       .
```

| Step / Level | Current Node `(x, y)` | Evaluated Move `(nx, ny)` | Status | Action |
|:---:|:---:|:---:|:---:|:---|
| **0** | `(1, 3)` | — | Root | Enqueue `(1, 3)`, `visited = true` |
| **Level 1** | `(1, 3)` | `(3, 2)` | Valid | Enqueue `(3, 2)` |
| | `(1, 3)` | `(3, 4)` | Valid | Enqueue `(3, 4)` |
| | `(1, 3)` | `(2, 1)`, `(2, 5)` | Valid | Enqueue `(2, 1)`, `(2, 5)` |
| **Level 2** | `(3, 2)` | `(5, 1)` | **Target Matched!** | **Return steps = 2** 🏁 |

**Path Found:** $(1, 3) \to (3, 2) \to (5, 1)$ in **2 steps**.

---

## ⏱️ Complexity Analysis

| Metric | Estimation | Rationale |
| :--- | :---: | :--- |
| **Time Complexity** | $\mathcal{O}(n^2)$ | In the worst case, every square on the $n \times n$ chessboard enters and exits the queue at most once. For each square, exactly $8$ moves are evaluated in $\mathcal{O}(1)$ time. Overall operations $\le 8 \cdot n^2$. |
| **Auxiliary Space** | $\mathcal{O}(n^2)$ | The 2D `visited` table requires $(n + 1) \times (n + 1)$ booleans. The BFS queue holds at most the frontier perimeter $\mathcal{O}(n)$ at any single level. |

---

> *"In an unweighted state space, Breadth-First Search radiates like ripples on water, guaranteeing the shortest path at first touch."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../244_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../246_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
