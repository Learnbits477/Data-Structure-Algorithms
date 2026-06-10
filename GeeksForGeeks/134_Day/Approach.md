# 💡 Approach — Binary Searchable Count

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 50.0%](https://img.shields.io/badge/Accuracy-50.0%25-green?style=for-the-badge)
![Submissions: 10K+](https://img.shields.io/badge/Submissions-10K+-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topics: Greedy](https://img.shields.io/badge/Topics-Greedy-lightgrey?style=for-the-badge)

> [!TIP]
> **Core Insight:**
> A standard binary search algorithm partition-paths can be modeled as traversing a **Binary Search Tree (BST)**.
> During the binary search for any target element $T$, at each step, we look at $mid$.
> - If $T < arr[mid]$, we must search the left half; hence $T$ must be smaller than $arr[mid]$.
> - If $T > arr[mid]$, we must search the right half; hence $T$ must be larger than $arr[mid]$.
> 
> Instead of executing binary search for every element separately (which takes $$O(n \log n)$$), we can propagate constraints downwards in a single $O(n)$ preorder-like traversal.
> For any range $[l, r]$ with inherited value constraints $[min\_val, max\_val]$:
> - The element at $mid$ is searchable if and only if $min\_val \le arr[mid] \le max\_val$.
> - For the left subarray $[l, mid-1]$, all elements must be smaller than $arr[mid]$, so the upper bound becomes $\min(max\_val, arr[mid] - 1)$.
> - For the right subarray $[mid+1, r]$, all elements must be greater than $arr[mid]$, so the lower bound becomes $\max(min\_val, arr[mid] + 1)$.

## 🔩 Step-by-Step Breakdown

1. **Step 1: Initialize recursive search**
   - We start the recursion with `solve(0, n - 1, INT_MIN, INT_MAX)` to cover the entire array with no initial value restrictions.

2. **Step 2: Check constraints for `arr[mid]`**
   - For the current interval $[l, r]$ and constraints $[min\_val, max\_val]$:
   - Calculate $mid = l + (r - l) / 2$.
   - If `min_val <= arr[mid] && arr[mid] <= max_val`, then `arr[mid]` is searchable. We increment our answer count.

3. **Step 3: Recursive search for left and right halves with updated constraints**
   - Recursively call `solve` for the left half: `l` to `mid - 1`, updating the maximum permissible value to `min(max_val, arr[mid] - 1)`.
   - Recursively call `solve` for the right half: `mid + 1` to `r`, updating the minimum permissible value to `max(min_val, arr[mid] + 1)`.

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A[Start: binarySearchable] --> B[Initialize count = 0]
    B --> C["Call solve(arr, 0, n - 1, INT_MIN, INT_MAX)"]
    C --> D{"l > r?"}
    D -- Yes --> E[Return]
    D -- No --> F["Calculate mid = l + (r - l) / 2"]
    F --> G{"min_val <= arr[mid] <= max_val?"}
    G -- Yes --> H[Increment count]
    G -- No --> I[Do nothing]
    H --> J["solve(arr, l, mid - 1, min_val, min(max_val, arr[mid] - 1))"]
    I --> J
    J --> K["solve(arr, mid + 1, r, max(min_val, arr[mid] + 1), max_val)"]
    K --> E
```

## 📊 Complexity Analysis

| Complexity | Analysis |
|:---:|:---|
| **Time Complexity** | $$O(n)$$ — Every element in the array is visited exactly once as the pivot `mid` of some subtree. |
| **Auxiliary Space** | $$O(\log n)$$ — The recursion stack depth is bounded by the height of the binary search tree, which is $$O(\log n)$$. |

> *"Simplicity is the ultimate sophistication." — Leonardo da Vinci*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../133_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../135_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
