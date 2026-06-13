# 💡 Approach — Weighted Sum Simulation

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

## 📊 Metadata
- **Difficulty:** ![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
- **Acceptance Rate:** ![Acceptance: 86.9%](https://img.shields.io/badge/Acceptance-86.9%25-brightgreen?style=for-the-badge)
- **Submissions:** ![Submissions: 66.1K](https://img.shields.io/badge/Submissions-66.1K-blue?style=for-the-badge)
- **Topics:** ![Topics: Array](https://img.shields.io/badge/Array-blueviolet?style=for-the-badge) ![Topics: String](https://img.shields.io/badge/String-blueviolet?style=for-the-badge) ![Topics: Simulation](https://img.shields.io/badge/Simulation-blueviolet?style=for-the-badge)

---

## 💡 Core Insight
> [!TIP]
> **Core Insight:**  
> 1. **Word-by-Word Character Weight Summing**: Every character $c$ has a mapped weight. We can retrieve the weight using `weights[c - 'a']`. For each word, its total weight is the sum of weights of its characters.
> 2. **Modular Arithmetic**: Calculating the index using `total_weight % 26` wraps the weight into the range $[0, 25]$.
> 3. **Reverse Alphabetical Mapping**: A standard alphabetical mapping starts at `'a'` (index 0) and ends at `'z'` (index 25). The reverse alphabetical order maps $0 \rightarrow \text{'z'}$, $1 \rightarrow \text{'y'}$, $\dots$, $25 \rightarrow \text{'a'}$.
>    - The mapped character is simply:
>      $$\text{mapped\_char} = \text{'z'} - (\text{weight} \pmod{26})$$

---

## 🔩 Step-by-Step Breakdown

### Step 1: Iterate over each word
- Start by initializing an empty result string `ans`.
- Loop through each word in the input array `words`.

### Step 2: Calculate word weight
- For each word, initialize `weight = 0`.
- Iterate through each character `c` of the word and accumulate its weight:
  $$\text{weight} += \text{weights}[c - \text{'a'}]$$

### Step 3: Map weight modulo 26
- Compute the remainder of the total weight divided by $26$:
  $$\text{rem} = \text{weight} \pmod{26}$$
- Map the remainder to the reverse alphabetical character:
  $$\text{mapped\_char} = \text{'z'} - \text{rem}$$

### Step 4: Accumulate and return
- Append `mapped_char` to `ans`.
- Once all words are processed, return the final concatenated string `ans`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start([Start]) --> InitAns[Initialize empty result string ans]
    InitAns --> LoopWords{For each word in words}
    LoopWords -- Yes --> InitWeight[Initialize weight = 0]
    InitWeight --> LoopChars{For each char c in word}
    LoopChars -- Yes --> AddWeight["weight += weights[c - 'a']"]
    AddWeight --> LoopChars
    LoopChars -- No --> Modulo[rem = weight % 26]
    Modulo --> MapChar[mapped_char = 'z' - rem]
    MapChar --> AppendAns[ans += mapped_char]
    AppendAns --> LoopWords
    LoopWords -- No --> ReturnAns[Return ans]
    ReturnAns --> End([End])
```

---

## 📊 Complexity Analysis

| Complexity | Analysis |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(L)$, where $L$ is the sum of the lengths of all strings in `words`. We process each character of every word exactly once to compute its weight. |
| **Space Complexity** | $\mathcal{O}(1)$ auxiliary space (excluding the output string space), since we only use a few integer variables (`weight`, `rem`) for calculation. |

---

> *"Simplicity is the soul of efficiency, and clear mappings guide us through complex transformations."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../136_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../138_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
