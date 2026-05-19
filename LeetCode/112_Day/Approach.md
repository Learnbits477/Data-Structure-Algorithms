# 💡 Approach — Minimum Common Value

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 59.0%](https://img.shields.io/badge/Acceptance-59.0%25-blue?style=for-the-badge)
![Submissions: 585.8K](https://img.shields.io/badge/Submissions-585.8K-purple?style=for-the-badge)
![Topic: Two Pointers](https://img.shields.io/badge/Topic-Two%20Pointers-blue?style=for-the-badge)

---
> [!TIP]
> **Core Insight:** Since both arrays `nums1` and `nums2` are already sorted in non-decreasing order, we can use a **Two Pointers** approach. By placing one pointer at the start of each array:
> - If the pointed elements are equal, we've found our minimum common element because we are scanning from smallest to largest.
> - If one element is smaller, we increment its pointer to search for a potentially matching larger element.
>
> This allows us to find the minimum common value in a single linear pass of $O(N + M)$ time complexity and $O(1)$ auxiliary space.

---

## 🔩 Step-by-Step Breakdown
1. **Initialize Two Pointers:** Place index pointer `i` at the start of `nums1` and index pointer `j` at the start of `nums2`.
2. **Traverse and Compare:** Loop while both pointers are within their respective array boundaries (`i < nums1.size()` and `j < nums2.size()`).
3. **Handle Match:** If `nums1[i] == nums2[j]`, return the matching value immediately. Since we scan from left to right on sorted arrays, the first match we encounter is guaranteed to be the minimum common value.
4. **Advance Pointers:** If `nums1[i] < nums2[j]`, increment pointer `i` to look for a larger number in `nums1`. Otherwise, increment pointer `j` to look for a larger number in `nums2`.
5. **Return Default:** If the loop terminates without finding any match, return `-1`.

---

## 🔄 Mermaid Flowchart
```mermaid
flowchart TD
    A["Start"] --> B["Initialize pointers i = 0 and j = 0"]
    B --> C{"Is i < nums1.size and j < nums2.size?"}
    C -- No --> D["Return -1"]
    C -- Yes --> E{"Does nums1[i] == nums2[j]?"}
    E -- Yes --> F["Return nums1[i]"]
    E -- No --> G{"Is nums1[i] < nums2[j]?"}
    G -- Yes --> H["Increment i"]
    G -- No --> I["Increment j"]
    H --> C
    I --> C
```

---

## 📊 Complexity Analysis
| Type | Complexity | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $$O(N + M)$$ | We scan through both arrays at most once. Each step increments either pointer `i` or pointer `j`. |
| **Auxiliary Space** | $$O(1)$$ | We only use a constant amount of memory for the two index pointers `i` and `j`. |

---

> *"Efficiency is doing things right; effectiveness is doing the right things."*

---

<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../111_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../113_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
