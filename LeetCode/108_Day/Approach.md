# 💡 Approach — Find Minimum in Rotated Sorted Array

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 54.2%](https://img.shields.io/badge/Acceptance-54.2%25-blue?style=for-the-badge)
![Submissions: 5.6M](https://img.shields.io/badge/Submissions-5.6M-purple?style=for-the-badge)
![Topics: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topics: Binary Search](https://img.shields.io/badge/Topic-Binary%20Search-blue?style=for-the-badge)

---

## 🧩 Problem Description
> [!TIP]
> **Core Insight:** In a rotated sorted array, the minimum element is the only element that is smaller than its predecessor. Using binary search, we can identify which half of the array contains this "inflection point" by comparing the middle element with the rightmost element.

---
## 🔩 Step-by-Step Breakdown
1.  **Initialize Pointers:** Set `low` to 0 and `high` to $n - 1$.
2.  **Binary Search Loop:** While `low < high`:
    - Calculate `mid = low + (high - low) / 2`.
    - **Check Right Half:** If `nums[mid] > nums[high]`, the minimum element must be in the right half (excluding `mid`) because the "break" in sorted order occurs after `mid`. Update `low = mid + 1`.
    - **Check Left Half:** Otherwise, the minimum element is either at `mid` or in the left half. Update `high = mid`.
3.  **Return Result:** Once the loop terminates, `low` and `high` will converge at the minimum element's index. Return `nums[low]`.

---

## 🔄 Mermaid Flowchart
```mermaid
flowchart TD
    A[Start] --> B["Initialize low = 0, high = n-1"]
    B --> C{low < high?}
    C -- No --> D["Return nums[low]"]
    C -- Yes --> E["mid = low + (high - low) / 2"]
    E --> F{"nums[mid] > nums[high]?"}
    F -- Yes --> G[low = mid + 1]
    F -- No --> H[high = mid]
    G --> C
    H --> C
    D --> I[End]
```

---

## 📊 Complexity Analysis
| Type | Complexity | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $O(\log n)$ | Each iteration halves the search space using binary search. |
| **Space Complexity** | $O(1)$ | No extra space is used except for a few variables. |

---

> *"The only way to learn a new programming language is by writing programs in it."*

---

<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../107_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../109_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
