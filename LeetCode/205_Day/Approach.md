# 💡 Approach — Distribute Elements Into Two Arrays I

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-green?style=for-the-badge)
![Acceptance: 75.0%](https://img.shields.io/badge/Acceptance-75.0%25-brightgreen?style=for-the-badge)
![Submissions: 90.2K](https://img.shields.io/badge/Submissions-90.2K-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Array,_Simulation-blue?style=for-the-badge)

> [!TIP]
> **Core Insight:** This problem is a direct simulation of array operations:
> - Initialize `arr1` with `nums[0]` and `arr2` with `nums[1]`.
> - For every subsequent element `nums[i]` ($i \ge 2$), compare `arr1.back()` and `arr2.back()`.
> - Push `nums[i]` to `arr1` if `arr1.back() > arr2.back()`, otherwise push to `arr2`.
> - Concatenate `arr2` onto `arr1` and return.

## 🔩 Step-by-Step Breakdown

1. **Initialization**:
   - Create two vectors `arr1` and `arr2`.
   - Place `nums[0]` into `arr1` and `nums[1]` into `arr2`.

2. **Simulation**:
   - Loop $i$ from $2$ to $n - 1$:
     - If `arr1.back() > arr2.back()`: append `nums[i]` to `arr1`.
     - Else: append `nums[i]` to `arr2`.

3. **Concatenation**:
   - Append all elements of `arr2` to `arr1`.

4. **Return**:
   - Return `arr1` as the final result.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A["Start: nums"] --> B["arr1.push_back(nums[0])<br>arr2.push_back(nums[1])"]
    B --> C["Loop i from 2 to n - 1"]
    C --> D{"arr1.back() > arr2.back()?"}
    D -- Yes --> E["arr1.push_back(nums[i])"]
    D -- No --> F["arr2.push_back(nums[i])"]
    E --> G{"More elements?"}
    F --> G
    G -- Yes --> C
    G -- No --> H["Concatenate arr2 to arr1"]
    H --> I["End: Return arr1"]
```

---

## 🏃‍♂️ Dry Run

Let's trace **Example 2**: `nums = [5, 4, 3, 8]`

| Step | Current Element `nums[i]` | `arr1` | `arr2` | Comparison | Action |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | `nums[0] = 5` | `[5]` | `[]` | — | Push to `arr1` |
| 2 | `nums[1] = 4` | `[5]` | `[4]` | — | Push to `arr2` |
| 3 | `nums[2] = 3` | `[5]` | `[4]` | `5 > 4` (True) | Push `3` to `arr1` $\implies$ `[5, 3]` |
| 4 | `nums[3] = 8` | `[5, 3]` | `[4]` | `3 > 4` (False) | Push `8` to `arr2` $\implies$ `[4, 8]` |

**Concatenation:** `arr1 + arr2 = [5, 3, 4, 8]`.

---

## 📊 Complexity Analysis

| Complexity | Analysis |
| :---: | :--- |
| **Time** | $\mathcal{O}(n)$: We iterate through the array of length $n$ once, performing $\mathcal{O}(1)$ push operations, followed by an $\mathcal{O}(n)$ concatenation. |
| **Space** | $\mathcal{O}(n)$: Auxiliary space used by `arr1` and `arr2` to store all $n$ elements. |

> *"Simplicity is the soul of efficiency."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../204_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../206_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
