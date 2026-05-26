# 💡 Approach — Minimum Toogles to partition

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 52.89%](https://img.shields.io/badge/Accuracy-52.89%25-blue?style=for-the-badge)
![Submissions: 15K+](https://img.shields.io/badge/Submissions-15K%2B-purple?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)

---

> [!TIP]
> **Core Insight:**  
> A partitioned binary array must consist of all `0`s grouped together at the front, followed by all `1`s grouped together at the back.
>
> If we process the array from left to right, we can dynamically build the partition cost for the prefix `arr[0...i]`. At the current element `arr[i]`:
> 1. If it's `1`, it can easily be appended to a partitioned prefix without modifying its cost. We just increment our count of `1`s.
> 2. If it's `0`, we have a decision to make to keep the prefix partitioned:
>    - **Option A:** Toggle the current `0` to a `1` (which costs `toggles + 1`).
>    - **Option B:** Keep the current `0` as `0` and toggle all previously encountered `1`s to `0`s (which costs `oneCount`).
>
> By choosing `toggles = min(toggles + 1, oneCount)`, we guarantee the minimum toggles needed for the prefix ending at `i` in $O(1)$ time at each step.

---

## 🔩 Step-by-Step Breakdown

### Step 1: Initialize State Variables
- Initialize `oneCount = 0` to track the number of `1`s encountered.
- Initialize `toggles = 0` to track the minimum toggle cost to partition the prefix array.

### Step 2: Traverse the Array
- Loop through each element `arr[i]` of the array from index `0` to `n - 1`:
  - If `arr[i] == 1`, increment `oneCount`.
  - If `arr[i] == 0`, update `toggles` to the minimum of:
    - `toggles + 1` (flipping the current `0` to `1` so it belongs to the `1`s suffix).
    - `oneCount` (flipping all previous `1`s to `0`s so the entire prefix becomes `0`s).

### Step 3: Return the Result
- After traversing the entire array, return the value of `toggles`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start([Start]) --> Init["Initialize: oneCount = 0, toggles = 0"]
    Init --> LoopStart["Loop through array (i = 0 to n-1)"]
    LoopStart --> CheckVal{"arr[i] == 1?"}
    CheckVal -- Yes --> IncOne["oneCount++"]
    CheckVal -- No --> MinToggles["toggles = min(toggles + 1, oneCount)"]
    IncOne --> Next["Move to next element (i++)"]
    MinToggles --> Next
    Next --> CheckEnd{"i < n?"}
    CheckEnd -- Yes --> CheckVal
    CheckEnd -- No --> ReturnResult["Return toggles"]
    ReturnResult --> End([End])
```

---

## 📊 Complexity Analysis

| Type | Complexity | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $O(n)$ | We perform exactly one traversal over the array of size $n$, doing constant time $O(1)$ operations per element. |
| **Auxiliary Space** | $O(1)$ | No additional data structures are created; we only store a couple of scalar integer variables. |

---

> *"Dynamic programming is not about caching, it's about ordering state transitions to make the future independent of the past."* — **Anonymous**

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../118_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../120_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
