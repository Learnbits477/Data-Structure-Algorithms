# 💡 Approach — LeetCode 1406: Stone Game III

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 64.1%](https://img.shields.io/badge/Acceptance-64.1%25-blue?style=for-the-badge)
![Submissions: 192.8K](https://img.shields.io/badge/Submissions-192.8K-purple?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topics:-Array-blue?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Math-cyan?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic_Programming-brightgreen?style=for-the-badge)
![Topic: Game Theory](https://img.shields.io/badge/Game_Theory-orange?style=for-the-badge)

</div>

---

## 🎯 Core Insights

This problem can be modeled as a classic game-theory game played on a row of stones. Because the players play optimally, we can use **Dynamic Programming (DP)**.

### 1. State Definition
Let $dp[i]$ represent the **maximum relative score** (Current Player's Score - Opponent's Score) that the player whose turn it is can achieve starting from index $i$ to the end of the array.

### 2. Transition Relation
At index $i$, the current player has up to three choices:
- **Take 1 stone:** The player gets value `stoneValue[i]`. The opponent plays optimally from index $i+1$, achieving a relative score of $dp[i+1]$. The current player's relative score becomes:
  $$stoneValue[i] - dp[i+1]$$
- **Take 2 stones:** The player gets value `stoneValue[i] + stoneValue[i+1]`. The opponent plays optimally from index $i+2$, achieving a relative score of $dp[i+2]$. The current player's relative score becomes:
  $$(stoneValue[i] + stoneValue[i+1]) - dp[i+2]$$
- **Take 3 stones:** The player gets value `stoneValue[i] + stoneValue[i+1] + stoneValue[i+2]`. The opponent plays optimally from index $i+3$, achieving a relative score of $dp[i+3]$. The current player's relative score becomes:
  $$(stoneValue[i] + stoneValue[i+1] + stoneValue[i+2]) - dp[i+3]$$

Since the current player plays optimally, they will choose the option that maximizes their relative score:
$$dp[i] = \max \begin{cases}
stoneValue[i] - dp[i+1] \\
stoneValue[i] + stoneValue[i+1] - dp[i+2] & \text{(if } i+1 < n\text{)} \\
stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3] & \text{(if } i+2 < n\text{)}
\end{cases}$$

### 3. Space Optimization to $O(1)$
To compute $dp[i]$, we only need the values of $dp[i+1]$, $dp[i+2]$, and $dp[i+3]$.
We can maintain just three variables (`dp1`, `dp2`, `dp3`) to store these states. This reduces the auxiliary space complexity from $O(n)$ to $O(1)$.

### 4. Game Result Determination
- If $dp[0] > 0$, Alice (who goes first) can achieve a strictly greater score than Bob, so Alice wins: return `"Alice"`.
- If $dp[0] < 0$, Bob wins: return `"Bob"`.
- If $dp[0] == 0$, the game ends in a draw: return `"Tie"`.

---

## 🔩 Step-by-Step Breakdown

### Step 1: Initialize DP State Variables
- Let `dp1 = 0`, `dp2 = 0`, `dp3 = 0`. These represent $dp[n]$, $dp[n+1]$, and $dp[n+2]$ respectively.

### Step 2: Backward DP Loop
- Loop `i` from $n-1$ down to $0$:
  - Initialize `current_sum = 0` and `max_val = INT_MIN`.
  - Try taking $1$ stone: `current_sum += stoneValue[i]`, and update `max_val = max(max_val, current_sum - dp1)`.
  - Try taking $2$ stones (if $i+1 < n$): `current_sum += stoneValue[i+1]`, and update `max_val = max(max_val, current_sum - dp2)`.
  - Try taking $3$ stones (if $i+2 < n$): `current_sum += stoneValue[i+2]`, and update `max_val = max(max_val, current_sum - dp3)`.
  - Shift DP states: `dp3 = dp2`, `dp2 = dp1`, `dp1 = max_val`.

### Step 3: Return Game Winner
- Analyze the final relative score `dp1` (which represents $dp[0]$):
  - Return `"Alice"` if `dp1 > 0`.
  - Return `"Bob"` if `dp1 < 0`.
  - Return `"Tie"` if `dp1 == 0`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start(["Start: stoneGameIII(stoneValue)"]) --> Init["Set dp1 = 0, dp2 = 0, dp3 = 0\nSet n = stoneValue.size()"]
    Init --> Loop["Loop i from n - 1 down to 0"]
    Loop --> Take1["current_sum = stoneValue[i]\nmax_val = current_sum - dp1"]
    Take1 --> Check2{"i + 1 < n?"}
    Check2 -- Yes --> Take2["current_sum += stoneValue[i+1]\nmax_val = max(max_val, current_sum - dp2)"]
    Check2 -- No --> Check3
    Take2 --> Check3{"i + 2 < n?"}
    Check3 -- Yes --> Take3["current_sum += stoneValue[i+2]\nmax_val = max(max_val, current_sum - dp3)"]
    Check3 -- No --> Shift
    Take3 --> Shift["dp3 = dp2\ndp2 = dp1\ndp1 = max_val"]
    Shift --> NextIter{"i > 0?"}
    NextIter -- Yes --> Loop
    NextIter -- No --> Evaluate["Check dp1"]
    Evaluate --> Alice{"dp1 > 0?"}
    Alice -- Yes --> RetAlice["Return 'Alice'"]
    Alice -- No --> Bob{"dp1 < 0?"}
    Bob -- Yes --> RetBob["Return 'Bob'"]
    Bob -- No --> RetTie["Return 'Tie'"]
```

---

## 🧮 Dry Run

### Dry Run: Example 1
- **Input:** `stoneValue = [1, 2, 3, 7]`

#### Phase 1: Initialization
- `dp1 = 0`, `dp2 = 0`, `dp3 = 0`

#### Phase 2: DP Updates
- **$i = 3$ (value $7$):**
  - Take 1: `current_sum = 7`, `max_val = 7 - 0 = 7`.
  - Shift: `dp3 = 0`, `dp2 = 0`, `dp1 = 7`.
- **$i = 2$ (value $3$):**
  - Take 1: `current_sum = 3`, `max_val = 3 - 7 = -4`.
  - Take 2: `current_sum = 3 + 7 = 10`, `max_val = max(-4, 10 - 0) = 10`.
  - Shift: `dp3 = 0`, `dp2 = 7`, `dp1 = 10`.
- **$i = 1$ (value $2$):**
  - Take 1: `current_sum = 2`, `max_val = 2 - 10 = -8`.
  - Take 2: `current_sum = 2 + 3 = 5`, `max_val = max(-8, 5 - 7) = -2`.
  - Take 3: `current_sum = 2 + 3 + 7 = 12`, `max_val = max(-2, 12 - 0) = 12`.
  - Shift: `dp3 = 7`, `dp2 = 10`, `dp1 = 12`.
- **$i = 0$ (value $1$):**
  - Take 1: `current_sum = 1`, `max_val = 1 - 12 = -11`.
  - Take 2: `current_sum = 1 + 2 = 3`, `max_val = max(-11, 3 - 10) = -7`.
  - Take 3: `current_sum = 1 + 2 + 3 = 6`, `max_val = max(-7, 6 - 7) = -1`.
  - Shift: `dp3 = 10`, `dp2 = 12`, `dp1 = -1`.

#### Phase 3: Result
- Since `dp1 = -1 < 0`, we return `"Bob"`.

---

## 📊 Complexity Analysis

| Complexity | Analysis |
| :--- | :--- |
| **Time Complexity** | $O(n)$ because we iterate from the end to the start of the array of size $n$ exactly once. |
| **Auxiliary Space** | $O(1)$ since we only store three DP state variables. |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../187_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../189_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
