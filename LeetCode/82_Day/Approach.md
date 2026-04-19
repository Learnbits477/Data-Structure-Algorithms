# 🚀 Approach - Maximum Distance Between a Pair of Values

## 💡 Intuition
Given two non-increasing (descending) arrays `nums1` and `nums2`, we need to find the maximum $j - i$ such that $i \le j$ and $nums1[i] \le nums2[j]$.

Since both arrays are sorted in descending order:
1. If $nums1[i] \le nums2[j]$, then for the same $i$, increasing $j$ might still satisfy the condition because $nums2$ decreases. This suggests we can expand the window.
2. If $nums1[i] > nums2[j]$, then $nums2[j]$ is too small for $nums1[i]$. Since $nums2$ only gets smaller as $j$ increases, no $j' > j$ will work for this specific $i$. We must increment $i$.

This monotonic property allows for a highly efficient **Two-Pointer** approach.

---

## 🛠️ Step-by-Step Logic (Two-Pointers)

1.  Initialize two pointers: `i = 0` (for `nums1`) and `j = 0` (for `nums2`).
2.  Initialize `maxDist = 0`.
3.  While `i < nums1.size()` and `j < nums2.size()`:
    -   If `nums1[i] <= nums2[j]`:
        -   If `i <= j`, update `maxDist = max(maxDist, j - i)`.
        -   Increment `j` (try to find a larger distance).
    -   Else:
        -   Increment `i` (looking for a smaller value in `nums1`).
4.  Return `maxDist`.

---

## 📊 Visual Representation

```mermaid
flowchart LR
    Start([Start]) --> Init["i = 0, j = 0, maxDist = 0"]
    Init --> Loop{"i < Len1 AND j < Len2"}
    Loop -- No --> End([Return maxDist])
    Loop -- Yes --> Compare{"nums1[i] <= nums2[j]"}
    Compare -- Yes --> Valid{"i <= j"}
    Valid -- Yes --> Update["maxDist = max(maxDist, j - i)"]
    Update --> IncJ["j++"]
    Valid -- No --> IncJ
    Compare -- No --> IncI["i++"]
    IncJ --> Loop
    IncI --> Loop
