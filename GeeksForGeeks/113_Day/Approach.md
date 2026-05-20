# 💡 Approach — Product Pair

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
| :------------------------: | :--------------------------: | :---------------------------: | :-------------------: |

</div>

# 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 17.34%](https://img.shields.io/badge/Acceptance-17.34%25-orange?style=for-the-badge)
![Submissions: 90K+](https://img.shields.io/badge/Submissions-90K%2B-blue?style=for-the-badge)
---

> [!TIP]
> **Core Insight:**  
> To find two numbers $a$ and $b$ such that $a \times b = \text{target}$ in $\mathcal{O}(N)$ time:
>
> 1. If $\text{target} = 0$, we only need to verify if the array contains at least one $0$. Since the array size is $\ge 2$, any $0$ can pair with another element to yield a product of $0$.
> 2. If $\text{target} \ne 0$, we can iterate through the array and use a hash set to keep track of elements we've already visited. For each non-zero element $x$, we check if $\text{target}$ is divisible by $x$. If it is, and the complement $\text{target} / x$ has already been seen, we've found our pair!

---

## 🔩 Step-by-Step Breakdown

### Step 1: Special Case for Target = 0

- If the `target` is `0`, iterate through `arr` to check if `0` is present.
- Since $\text{arr.size()} \ge 2$, any $0$ present can be paired with any other element at a different index to produce a product of $0$.
- If `0` is found, return `true`, else return `false`.

### Step 2: Hashing Setup for Target ≠ 0

- Initialize an `unordered_set<long long> seen` to store previously visited elements.

### Step 3: Iterate and Match

- For each element `num` in the array `arr`:
  - If `num == 0`, skip it (since $0 \times y = 0 \ne \text{target}$).
  - Check if `target % num == 0`.
  - If yes, calculate `complement = target / num`.
  - Check if `seen` contains `complement`. If it does, return `true`.
  - Insert `num` into `seen` to make it available for future comparisons.

### Step 4: Fallback

- If the loop terminates without finding any matching pair, return `false`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A([Start]) --> B{target == 0?}
    B -- Yes --> C[Search for 0 in arr]
    C --> D{Is 0 present?}
    D -- Yes --> E([Return true])
    D -- No --> F([Return false])

    B -- No --> G[Initialize seen set]
    G --> H[Iterate num in arr]
    H --> I{num == 0?}
    I -- Yes --> J[Skip num] --> H
    I -- No --> K{target % num == 0?}
    K -- Yes --> L{seen contains target / num?}
    L -- Yes --> M([Return true])
    L -- No --> N[Insert num into seen] --> H
    K -- No --> N
    H -- Done iterating --> O([Return false])
```

---

## 📊 Complexity Analysis

| Type                 | Complexity       | Rationale                                                                                                     |
| :------------------- | :--------------- | :------------------------------------------------------------------------------------------------------------ |
| **Time Complexity**  | $\mathcal{O}(N)$ | We perform a single pass through the array. Hash set insertions and lookups take $\mathcal{O}(1)$ on average. |
| **Space Complexity** | $\mathcal{O}(N)$ | In the worst case, we store up to $N$ unique elements in the hash set.                                        |

---

> _"The only way to learn a new programming language is by writing programs in it."_ — Dennis Ritchie

---

<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../112_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../114_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
