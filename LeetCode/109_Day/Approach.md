# 💡 Approach — Find Minimum in Rotated Sorted Array II

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 45.0%](https://img.shields.io/badge/Acceptance-45.0%25-blue?style=for-the-badge)
![Submissions: 1.4M](https://img.shields.io/badge/Submissions-1.4M-purple?style=for-the-badge)

---

> [!TIP]
> **Core Insight:** In a rotated sorted array, the minimum element is the only one where the previous element is greater than it. With duplicates, if `nums[mid] == nums[high]`, we cannot determine which side the minimum lies on, so we safely decrement `high` to narrow the search space.

---

## 🔩 Step-by-Step Breakdown
1. **Initialize Pointers:** Set `low = 0` and `high = n - 1`.
2. **Binary Search Loop:** While `low < high`:
   - Calculate `mid = low + (high - low) / 2`.
   - **Case 1:** If `nums[mid] > nums[high]`, the minimum must be in the right half (excluding `mid`). Set `low = mid + 1`.
   - **Case 2:** If `nums[mid] < nums[high]`, the minimum is either at `mid` or in the left half. Set `high = mid`.
   - **Case 3 (Duplicates):** If `nums[mid] == nums[high]`, we don't know the side. Safely decrement `high` to reduce search space.
3. **Return Result:** When the loop terminates, `low` points to the minimum element.

---

## 🔄 Mermaid Flowchart
```mermaid
flowchart TD
    A[Start] --> B["low = 0, high = n-1"]
    B --> C{"low < high?"}
    C -- No --> D["Return nums[low]"]
    C -- Yes --> E["mid = low + (high-low)/2"]
    E --> F{"nums[mid] vs nums[high]"}
    F -- ">" --> G["low = mid + 1"]
    F -- "<" --> H["high = mid"]
    F -- "==" --> I["high--"]
    G --> C
    H --> C
    I --> C
```

---

## 📊 Complexity Analysis
| Type | Complexity | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $$O(\log n)$$ | Average case is logarithmic. In the worst case (all elements same), it degrades to $$O(n)$$. |
| **Auxiliary Space** | $$O(1)$$ | Only a few variables are used. |

---

> *"Optimization is not about doing things faster, but about doing fewer unnecessary things."*

---

<div align="center">
  <h3>Happy Coding! 🚀</h3>
<a href="../108_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../110_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
