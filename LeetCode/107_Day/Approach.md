# 💡 Approach — Check if Array is Good

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---
## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 51.0%](https://img.shields.io/badge/Acceptance-51.0%25-orange?style=for-the-badge)
![Submissions: 154.3K+](https://img.shields.io/badge/Submissions-154.3K%2B-lightgrey?style=for-the-badge)
![Avg Time: 15m](https://img.shields.io/badge/Avg%20Time-15m-informational?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Topic-Array-blue?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Topic-Hash%20Table-blueviolet?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Topic-Sorting-yellow?style=for-the-badge)

---

> [!TIP]
> **Core Insight:** A "good" array must be exactly a permutation of `[1, 2, ..., n-1, n, n]`. 
> The maximum element $n$ directly dictates the expected size of the array ($n + 1$). 
> Instead of sorting, we can use a frequency map to count occurrences in $O(N)$ time and verify that elements $1$ to $n-1$ appear exactly once, and $n$ appears exactly twice.

---

## 🎯 Why Not Brute Force?

| Approach | Time | Notes |
|---|---|---|
| Sorting | $O(N \log N)$ | Sort the array and compare index by index. Simple but slightly slower. |
| **Frequency Array** ✅ | $O(N)$ | Optimal; uses an array to count frequencies in linear time. |

---

## 🔩 Step-by-Step Breakdown

### Step 1 — Find the Maximum Value
Determine the maximum element `max_val` in the array `nums`. This value acts as our $n$.

### Step 2 — Check the Size
A valid array based on $n$ must have exactly $n + 1$ elements.
- If `nums.size() != max_val + 1`, immediately return `false`.

### Step 3 — Build a Frequency Map
Create a frequency array (or vector) to count the occurrences of each element in `nums`.

### Step 4 — Verify Frequencies
Iterate from $i = 1$ to `max_val`:
- If $i < \text{max\_val}$ and `freq[i] != 1`, return `false`.
- If $i == \text{max\_val}$ and `freq[i] != 2`, return `false`.

If all checks pass, the array is a valid permutation and we return `true`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A([Start]) --> B["Find max_val in nums"]
    B --> C{"nums.size() == max_val + 1?"}
    C -- No --> D(["Return false"])
    C -- Yes --> E["Create frequency array freq"]
    E --> F["Count occurrences of each num"]
    F --> G["Loop i from 1 to max_val"]
    G --> H{"i == max_val?"}
    H -- No --> I{"freq[i] == 1?"}
    I -- No --> D
    I -- Yes --> J["Continue loop"]
    H -- Yes --> K{"freq[max_val] == 2?"}
    K -- No --> D
    K -- Yes --> L(["Return true"])
    J --> G
```

---

## 🖼️ Premium Visualization

```mermaid
flowchart LR
    subgraph Input["Input Array"]
        A["[1, 3, 3, 2]"]
    end

    subgraph Step1["Step 1: Extraction"]
        B["max_val = 3"]
        C["size = 4"]
    end

    subgraph Step2["Step 2: Size Validation"]
        D{"max_val + 1 == size?"}
        E["4 == 4 ✅"]
    end

    subgraph Step3["Step 3: Build Frequencies"]
        direction TB
        F["Num: 1 ➡️ Freq: 1"]
        G["Num: 2 ➡️ Freq: 1"]
        H["Num: 3 ➡️ Freq: 2"]
    end

    subgraph Step4["Step 4: Verify"]
        direction TB
        I["freq[1] == 1 ✅"]
        J["freq[2] == 1 ✅"]
        K["freq[3] == 2 ✅"]
    end

    A --> B & C
    B & C --> D
    D --> E
    E --> Step3
    F --> I
    G --> J
    H --> K
    I & J & K --> L(["Result: true 🏆"])
    
    style A fill:#2d3748,stroke:#4fd1c5,stroke-width:2px,color:#fff
    style B fill:#2b6cb0,color:#fff
    style C fill:#2b6cb0,color:#fff
    style E fill:#38a169,color:#fff
    style I fill:#38a169,color:#fff
    style J fill:#38a169,color:#fff
    style K fill:#38a169,color:#fff
    style L fill:#d69e2e,color:#fff,stroke:#ecc94b,stroke-width:4px
```

---

## 📊 Complexity Analysis

| Phase | Time | Space |
|---|---|---|
| Finding Maximum | $O(N)$ | $O(1)$ |
| Building Frequency | $O(N)$ | $O(N)$ to store frequencies |
| Verification | $O(N)$ | $O(1)$ |
| **Overall** | $O(N)$ | $O(N)$ |

> **Note:** Because $N \leq 100$ and $\text{nums}[i] \leq 200$, the frequency array requires negligible space, making this extremely efficient.

---

## ⚙️ Key Implementation Notes

1. **Size check is vital:** Arrays like `[3, 4, 4, 1, 2, 1]` might fail instantly on the length check, bypassing the need to even build the frequency map.
2. **Out of bounds:** If an element exceeds $n$ (our `max_val`), the size check implicitly protects us, or our frequency map handles it properly by setting an upper bound. 

---

> *"Data structures are the logic of space; algorithms are the logic of time."*  
> — **Anonymous**

---
<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../109_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../111_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
