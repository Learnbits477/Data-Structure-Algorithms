# 💡 Approach — Search in Rotated Sorted Array

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 44.8%](https://img.shields.io/badge/Acceptance-44.8%25-blue?style=for-the-badge)
![Submissions: 10.1M](https://img.shields.io/badge/Submissions-10.1M-purple?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Binary Search](https://img.shields.io/badge/Topic-Binary%20Search-blue?style=for-the-badge)

---

> [!TIP]
> **Core Insight:**  
> When you divide a rotated sorted array at any index, **at least one of the two halves (left or right) will always be strictly sorted**.
> 
> By comparing the middle element with the boundary elements, we can determine:
> 1. Which half is sorted.
> 2. Whether the target lies within the boundaries of that sorted half.
> 
> This allows us to discard half of the search space at each step, maintaining the $O(\log n)$ logarithmic runtime complexity.

---

## 🔩 Step-by-Step Breakdown

### Step 1: Initialize Search Range
- Define the initial search boundaries: `low = 0` and `high = nums.size() - 1`.

### Step 2: Calculate Midpoint and Check Match
- While `low <= high`, calculate the middle index: `mid = low + (high - low) / 2`.
- If `nums[mid] == target`, immediately return the index `mid`.

### Step 3: Check If Left Half is Sorted
- If `nums[low] <= nums[mid]`, it means the left half `[low ... mid]` is sorted.
  - Determine if the target lies within this sorted range: `nums[low] <= target && target < nums[mid]`.
  - If it does, narrow the search space to the left half by setting `high = mid - 1`.
  - Otherwise, search in the right half by setting `low = mid + 1`.

### Step 4: Check If Right Half is Sorted
- Otherwise, the right half `[mid ... high]` must be sorted.
  - Determine if the target lies within this sorted range: `nums[mid] < target && target <= nums[high]`.
  - If it does, narrow the search space to the right half by setting `low = mid + 1`.
  - Otherwise, search in the left half by setting `high = mid - 1`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[Step 1: Set low = 0, high = n - 1]
    B --> C{"low <= high?"}
    C -- No --> D([Return -1])
    C -- Yes --> E[Step 2: Compute mid = low + high-low/2]
    E --> F{"nums[mid] == target?"}
    F -- Yes --> G([Return mid])
    F -- No --> H{"Step 3: Is left half sorted?<br>nums[low] <= nums[mid]"}
    H -- Yes --> I{"Is target in left sorted half?<br>nums[low] <= target < nums[mid]"}
    I -- Yes --> J[high = mid - 1]
    I -- No --> K[low = mid + 1]
    H -- No --> L{"Step 4: Is target in right sorted half?<br>nums[mid] < target <= nums[high]"}
    L -- Yes --> M[low = mid + 1]
    L -- No --> N[high = mid - 1]
    J --> C
    K --> C
    M --> C
    N --> C
```

---

## 📊 Complexity Analysis

| Type | Complexity | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $$O(\log n)$$ | At each step, we determine which half is sorted and cut the search space in half. |
| **Auxiliary Space** | $$O(1)$$ | The search is performed iteratively in-place without additional data structures. |

---

> *"Search not for the path, but make the search your path."* — Unknown

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../114_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../116_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
