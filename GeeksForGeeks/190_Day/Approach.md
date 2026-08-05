# 💡 Approach — Subarrays with Sum in Range

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 48.76%](https://img.shields.io/badge/Accuracy-48.76%25-blue?style=for-the-badge)
![Submissions: 17K+](https://img.shields.io/badge/Submissions-17K+-purple?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Arrays-brightgreen?style=for-the-badge)
![Topic: Sliding Window](https://img.shields.io/badge/Sliding_Window-blue?style=for-the-badge)

</div>

---

## 🎯 Core Insight

> [!TIP]
> **Sliding Window + Inclusion-Exclusion Principle**
>
> 1. **Inclusion-Exclusion Principle:** Finding the number of subarrays with a sum in the range `[l, r]` is equivalent to:
>    $$\text{Count}(l, r) = \text{Count}(\text{sum} \le r) - \text{Count}(\text{sum} \le l - 1)$$
> 2. **Sliding Window (Two Pointers):** Since all array elements are positive ($arr[i] \ge 1$), the running prefix sums are monotonically increasing. This enables the use of a sliding window to count the number of subarrays with a sum $\le K$ in $O(n)$ time.
> 3. **Subarray Counting:** For any window `[start, end]` where `sum(arr[start..end]) <= K`, all contiguous subarrays ending at `end` and starting at any index from `start` to `end` are valid. The count of such subarrays is exactly `end - start + 1`.

---

## 🔩 Step-by-Step Breakdown

### Step 1: inclusion-exclusion setup
- Define a private helper function `countSubarraysWithSumAtMost(arr, limit)` that returns the count of subarrays whose sum is less than or equal to `limit`.
- If `limit < 0`, return `0`.

### Step 2: sliding window algorithm (`countSubarraysWithSumAtMost`)
- Initialize `count = 0`, `current_sum = 0`, and `start = 0`.
- Iterate the `end` pointer from `0` to `n - 1`:
  - Add the current element to `current_sum`: `current_sum += arr[end]`.
  - While `current_sum > limit` and `start <= end`, shrink the window from the left:
    - Subtract `arr[start]` from `current_sum`.
    - Increment `start`.
  - Add the number of valid subarrays ending at `end` to our accumulator: `count += (end - start + 1)`.

### Step 3: calculate final result
- Compute the count for `r`: `countSubarraysWithSumAtMost(arr, r)`.
- Compute the count for `l - 1`: `countSubarraysWithSumAtMost(arr, l - 1)`.
- Return the difference: `atMost(r) - atMost(l - 1)`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start(["Start: countSubarray(arr, l, r)"]) --> Split["Calculate: atMost(r) - atMost(l - 1)"]
    Split --> Helper["atMost(limit): Sliding Window"]
    Helper --> Init["Set count = 0, sum = 0, start = 0"]
    Init --> Loop["Loop end from 0 to n - 1"]
    Loop --> AddSum["sum += arr[end]"]
    AddSum --> CheckSum{"sum > limit?"}
    CheckSum -- Yes --> Shrink["sum -= arr[start], start++"]
    Shrink --> CheckSum
    CheckSum -- No --> AddCount["count += (end - start + 1)"]
    AddCount --> NextIter{"end < n - 1?"}
    NextIter -- Yes --> Loop
    NextIter -- No --> EndLimit["Return count"]
    EndLimit --> End(["Return atMost(r) - atMost(l - 1)"])
```

---

## 🧮 Dry Run

### Dry Run: Example 1
- **Input:** `arr = [1, 4, 6]`, `l = 3`, `r = 8`

#### Phase 1: `countSubarraysWithSumAtMost(arr, 8)`
- **Initialization:** `count = 0`, `current_sum = 0`, `start = 0`
- **end = 0 (`arr[0] = 1`):**
  - `current_sum = 1 <= 8`. No shrink.
  - `count += (0 - 0 + 1) = 1` (Subarrays: `[1]`)
- **end = 1 (`arr[1] = 4`):**
  - `current_sum = 5 <= 8`. No shrink.
  - `count += (1 - 0 + 1) = 2` (Subarrays: `[4]`, `[1, 4]`)
- **end = 2 (`arr[2] = 6`):**
  - `current_sum = 11 > 8`.
  - Shrink: `current_sum -= arr[0] (1) -> 10`. `start` becomes `1`.
  - Shrink: `current_sum -= arr[1] (4) -> 6`. `start` becomes `2`.
  - `current_sum = 6 <= 8`. Stop.
  - `count += (2 - 2 + 1) = 1` (Subarrays: `[6]`)
- **Result for limit 8:** `4`

#### Phase 2: `countSubarraysWithSumAtMost(arr, 2)`
- **Initialization:** `count = 0`, `current_sum = 0`, `start = 0`
- **end = 0 (`arr[0] = 1`):**
  - `current_sum = 1 <= 2`. No shrink.
  - `count += (0 - 0 + 1) = 1` (Subarrays: `[1]`)
- **end = 1 (`arr[1] = 4`):**
  - `current_sum = 5 > 2`.
  - Shrink: `current_sum -= arr[0] (1) -> 4`. `start` becomes `1`.
  - Shrink: `current_sum -= arr[1] (4) -> 0`. `start` becomes `2`.
  - `current_sum = 0 <= 2`. Stop.
  - `count += (1 - 2 + 1) = 0`
- **end = 2 (`arr[2] = 6`):**
  - `current_sum = 6 > 2`.
  - Shrink: `current_sum -= arr[2] (6) -> 0`. `start` becomes `3`.
  - `current_sum = 0 <= 2`. Stop.
  - `count += (2 - 3 + 1) = 0`
- **Result for limit 2:** `1`

#### Phase 3: Final Answer
- `atMost(8) - atMost(2) = 4 - 1 = 3`.
- **Result:** `3`

---

## 📊 Complexity Analysis

| Complexity | Analysis |
| :--- | :--- |
| **Time Complexity** | $O(n)$ because each element is visited at most twice (once by the `end` pointer and at most once by the `start` pointer) during each of the two calls to `countSubarraysWithSumAtMost`. |
| **Auxiliary Space** | $O(1)$ as we only maintain a few primitive counters and sum variables. |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../189_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../191_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
