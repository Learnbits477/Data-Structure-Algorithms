# 💡 Approach — Find the Lexicographically Smallest Valid Sequence

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 24.3%](https://img.shields.io/badge/Acceptance-24.3%25-blue?style=for-the-badge)
![Submissions: 37.2K](https://img.shields.io/badge/Submissions-37.2K-lightgrey?style=for-the-badge)
![Topic: Two Pointers](https://img.shields.io/badge/Topics-Two_Pointers-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/String-blue?style=for-the-badge)
![Topic: Dynamic Programming](https://img.shields.io/badge/Dynamic_Programming-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)

---

> [!TIP]
> **Core Insight:**
> To find the lexicographically smallest sequence of indices, we want to match each character of `word2` at the earliest possible index in `word1`. If we make a mismatch replacement, we must ensure that the remaining suffix of `word2` can be matched perfectly (0 changes) in the remaining part of `word1`. Precomputing the rightmost matching indices of suffixes of `word2` in `word1` enables $O(1)$ verification for any mismatch replacement.

---

## 🔩 Step-by-Step Breakdown

1. **Precompute Suffix Array**:
   - We construct a `suffix` array of size `m + 1`, where `suffix[j]` represents the maximum index in `word1` where the suffix `word2[j...m-1]` can be matched as a subsequence with zero mismatches.
   - We initialize `suffix[m] = n` as a sentinel value.
   - We traverse `word2` from right to left (`j = m-1` down to `0`), matching characters against `word1` from right to left using a pointer `idx`.

2. **Greedy Matching with Two Pointers**:
   - We iterate through `word2` (`j = 0` to `m-1`), tracking the index in `word1` using `i` (starting from `prev_idx + 1`).
   - If `word1[i] == word2[j]`, we have an exact match. We store `i` in our results, update `prev_idx = i`, and proceed to the next character `j + 1`.
   - If `word1[i] != word2[j]`, we can greedily change `word1[i]` to match `word2[j]` only if:
     - We haven't used our mismatch budget yet (`!changed`).
     - The rest of `word2` (from `j + 1`) can be matched with 0 changes at indices after `i`. This is valid if `suffix[j + 1] > i`.
     - If both conditions hold, we change the character, set `changed = true`, record the index, update `prev_idx = i`, and move to `j + 1`.
   - If neither condition is met, we increment `i` to look for a later match.
   - If we reach the end of `word1` without matching `word2[j]`, it means no valid sequence exists; we return `{}`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start([Start]) --> Precompute["Precompute suffix array"]
    Precompute --> InitVars["Initialize: prev_idx = -1, changed = false, j = 0"]
    InitVars --> CheckJ{"j < m ?"}
    
    CheckJ -- Yes --> SetI["Set i = prev_idx + 1"]
    CheckJ -- No --> Valid["Return indices"]
    
    SetI --> CheckI{"i < n ?"}
    CheckI -- Yes --> CheckMatch{"word1(i) == word2(j) ?"}
    CheckI -- No --> ReturnEmpty["Return empty array"]
    
    CheckMatch -- Yes --> Match["Record index i, prev_idx = i, j = j + 1"]
    CheckMatch -- No --> CheckChange{"!changed and suffix(j+1) > i ?"}
    
    CheckChange -- Yes --> Change["Record index i, prev_idx = i, changed = true, j = j + 1"]
    CheckChange -- No --> IncI["i = i + 1"]
    
    Match --> CheckJ
    Change --> CheckJ
    IncI --> CheckI
```

---

## 📊 Complexity Analysis

| Complexity | Resource | Details |
| :---: | :---: | :--- |
| **Time Complexity** | $O(N + M)$ | The suffix array construction takes $O(N)$ time. The greedy two-pointer matching traversal advances `i` and `j` linearly, taking at most $O(N)$ time. |
| **Space Complexity** | $O(M)$ | The space required is for the suffix array of size $M + 1$ and the output indices array. |

---

> *"The translation of a complex state space into a simple suffix validation is the essence of optimal greedy design."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../192_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../194_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
