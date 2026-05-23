# 💡 Approach — Check if Array Is Sorted and Rotated

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 56.1%](https://img.shields.io/badge/Acceptance-56.1%25-blue?style=for-the-badge)
![Submissions: 1.6M](https://img.shields.io/badge/Submissions-1.6M-purple?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)

---

> [!TIP]
> **Core Insight:**  
> If an array is sorted and rotated (by any positions, including 0), it can have at most one "drop point" or "break point". A break point is defined as an index $i$ where `nums[i] > nums[i+1]`.
> 
> When treating the array circularly (meaning the next element of the last element `nums[n-1]` is the first element `nums[0]`), we check `nums[i] > nums[(i + 1) % n]`:
> - A perfectly sorted array with no rotation will have 0 break points (if all elements are equal) or 1 break point (specifically at the boundary where `nums[n-1] > nums[0]` is evaluated, since `nums[n-1] > nums[0]`).
> - A sorted and rotated array (with a rotation pivot $x > 0$) will have exactly 1 break point (at the pivot where the transition from the largest to the smallest element happens, and `nums[n-1] <= nums[0]` must hold).
> - If there are more than 1 break points, it means the array has multiple descents and thus cannot be represented as a sorted and rotated array.

---

## 🔩 Step-by-Step Breakdown

### Step 1: Initialize Count and Size
- Let `count = 0` keep track of the number of break points.
- Get the size of the array `n = nums.size()`.

### Step 2: Count Circular Break Points
- Iterate through the array from `i = 0` to `n - 1`.
- For each element, compare it to the next circular element: `nums[(i + 1) % n]`.
- If `nums[i] > nums[(i + 1) % n]`, increment `count`.

### Step 3: Verify Rotated Sorted Property
- If the count of break points is less than or equal to $1$, return `true`.
- Otherwise, return `false`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A([Start: vector<int>& nums]) --> B[Step 1: Initialize count = 0, n = nums.size]
    B --> C[Step 2: Loop i from 0 to n - 1]
    C --> D{"nums[i] > nums[(i + 1) % n]?"}
    D -- Yes --> E[Increment count]
    D -- No --> F[Continue]
    E --> F
    F --> G{i == n - 1?}
    G -- No --> C
    G -- Yes --> H{count <= 1?}
    H -- Yes --> I([Return true])
    H -- No --> J([Return false])
```

---

## 📊 Complexity Analysis

| Type | Complexity | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $O(n)$ | We perform a single pass traversal over the array of size $n$. |
| **Auxiliary Space** | $O(1)$ | No extra space is used; we only use constant memory for counters and size variables. |

---

> *"Simplicity is the ultimate sophistication."* — Leonardo da Vinci

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../115_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../117_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
