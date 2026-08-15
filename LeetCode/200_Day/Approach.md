# 💡 Approach — Longest Subsequence With Non-Zero Bitwise XOR

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topics:-Array-blue?style=for-the-badge)
![Topic: Bit Manipulation](https://img.shields.io/badge/Bit_Manipulation-blue?style=for-the-badge)

---

## 💡 Core Insight

> [!TIP]
> **Core Insight:**  
> 1. If **all elements** in `nums` are `0`, then every non-empty subsequence has XOR `0`. No non-zero XOR subsequence exists $\implies$ return `0`.
> 2. Calculate the bitwise XOR of the **entire array** $\text{total\_XOR} = \text{nums}[0] \oplus \text{nums}[1] \oplus \dots \oplus \text{nums}[N-1]$.
>    - If $\text{total\_XOR} \neq 0$, the longest subsequence with non-zero XOR is the full array itself of length $N$.
> 3. If $\text{total\_XOR} == 0$ and at least one element $x > 0$ exists:
>    - Removing $x$ from the array leaves a subsequence of length $N - 1$.
>    - The XOR of this subsequence is $\text{total\_XOR} \oplus x = 0 \oplus x = x \neq 0$.
>    - Thus, the maximum length is $N - 1$.

---

## 🔩 Step-by-Step Breakdown

1. **Step 1: Compute Total XOR and Non-Zero Flag**:
   - Traverse `nums` once. Compute `total_XOR ^= num` and check if `num > 0`.
2. **Step 2: Case Analysis**:
   - If no non-zero element exists (all elements are 0), return `0`.
   - If `total_XOR != 0`, return `N`.
   - Else (`total_XOR == 0` and non-zero element exists), return `N - 1`.

---

## 🔍 Detailed Dry Run

### Example 1: `nums = [1, 2, 3]`

- `total_XOR = 1 ^ 2 ^ 3 = 0`
- Non-zero element exists (`1 > 0`)
- Since `total_XOR == 0`, answer is $N - 1 = 3 - 1 = 2$.

### Example 2: `nums = [2, 3, 4]`

- `total_XOR = 2 ^ 3 ^ 4 = 5 != 0`
- Since `total_XOR != 0`, answer is $N = 3$.

### Example 3: `nums = [0, 0, 0]`

- `total_XOR = 0`, no non-zero element exists.
- Output: `0`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A[Start: nums] --> B["Initialize total_XOR = 0, has_nonzero = false"]
    B --> C["Loop x in nums"]
    C --> D["total_XOR ^= x"]
    D --> E{"x > 0?"}
    E -- Yes --> F["has_nonzero = true"]
    E -- No --> G["Continue"]
    F --> H["End Loop"]
    G --> H
    H --> I{"has_nonzero is false?"}
    I -- Yes --> J["Return 0"]
    I -- No --> K{"total_XOR != 0?"}
    K -- Yes --> L["Return N"]
    K -- No --> M["Return N - 1"]
```

---

## 📊 Complexity Analysis

| Complexity | Resource | Details / Explanation |
| :--------: | :------: | --------------------- |
| **Time**   | $O(N)$   | Single linear scan over array `nums`. |
| **Space**  | $O(1)$   | Uses scalar variables `total_XOR` and `has_nonzero`. |

---

> *"If the total XOR cancels out to zero, dropping any non-zero element breaks the symmetry to yield a non-zero sum of length N - 1."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../199_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../201_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
