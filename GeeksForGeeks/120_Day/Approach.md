# 💡 Approach — Wifi Range

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 51.63%](https://img.shields.io/badge/Accuracy-51.63%25-blue?style=for-the-badge)
![Submissions: 37K+](https://img.shields.io/badge/Submissions-37K%2B-purple?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)

---

> [!TIP]
> **Core Insight:**  
> To check if all rooms are covered in $O(n)$ time and $O(1)$ auxiliary space, we can process rooms from left to right while keeping track of the rightmost index covered so far (`maxCovered`).
>
> When we encounter a router at index `i` (where `s[i] == '1'`):
> 1. Its coverage spans from `i - x` to `i + x`.
> 2. For the array to be contiguous (no uncovered rooms), the left boundary of this router's coverage (`i - x`) must overlap with or be immediately adjacent to the current maximum covered index. Specifically, if `i - x > maxCovered + 1`, there is a gap that can never be covered by this or any subsequent routers to the right. In this case, we immediately return `false`.
> 3. Otherwise, we extend our coverage range to `max(maxCovered, i + x)`.
>
> Finally, after scanning the hostel, we check if the entire line of rooms is covered by validating if `maxCovered >= n - 1` (where $n$ is the length of string $s$).

---

## 🔩 Step-by-Step Breakdown

### Step 1: Initialize State Variables
- Determine $n$ as the length of the string `s`.
- Initialize `maxCovered = -1` to keep track of the rightmost index covered by a WiFi router so far.

### Step 2: Traverse the String
- Loop through each room index `i` from `0` to `n - 1`:
  - If `s[i] == '1'`, a router is present at room `i`:
    - Check if the router's left range boundary `i - x` leaves an uncovered gap. If `i - x > maxCovered + 1`, return `false`.
    - Otherwise, update `maxCovered = max(maxCovered, i + x)` to represent the new rightmost boundary covered.

### Step 3: Return the Final Check
- After the traversal, verify if the entire hostel of size $n$ is covered by checking if `maxCovered >= n - 1`. Return `true` if it is, and `false` otherwise.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start([Start]) --> Init["Initialize: n = s.length(), maxCovered = -1"]
    Init --> LoopStart["Loop through room index i = 0 to n-1"]
    LoopStart --> CheckVal{"s[i] == '1'?"}
    CheckVal -- Yes --> CheckGap{"i - x > maxCovered + 1?"}
    CheckGap -- Yes --> ReturnFalse["Return false"]
    CheckGap -- No --> UpdateCovered["maxCovered = max(maxCovered, i + x)"]
    UpdateCovered --> Next["Move to next room (i++)"]
    CheckVal -- No --> Next
    Next --> CheckEnd{"i < n?"}
    CheckEnd -- Yes --> CheckVal
    CheckEnd -- No --> FinalCheck{"maxCovered >= n - 1?"}
    FinalCheck -- Yes --> ReturnTrue["Return true"]
    FinalCheck -- No --> ReturnFalse
    ReturnFalse --> End([End])
    ReturnTrue --> End
```

---

## 📊 Complexity Analysis

| Type | Complexity | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $O(n)$ | We scan the string of length $n$ exactly once, doing $O(1)$ operations at each room. |
| **Auxiliary Space** | $O(1)$ | No additional structures or dynamic tables are allocated; we only maintain one integer variable `maxCovered`. |

---

> *"In the optimization of space and time, the simplest trackers often yield the most elegant bounds."* — **Anonymous**

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../119_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../121_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
