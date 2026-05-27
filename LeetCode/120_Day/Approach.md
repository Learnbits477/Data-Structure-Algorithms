# 💡 Approach — Count the Number of Special Characters II

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 51.1%](https://img.shields.io/badge/Acceptance-51.1%25-blue?style=for-the-badge)
![Submissions: 135.8K](https://img.shields.io/badge/Submissions-135.8K-purple?style=for-the-badge)
![Topics: Hash Table](https://img.shields.io/badge/Topics-Hash%20Table-orange?style=for-the-badge)

---

> [!TIP]
> **Core Insight:**  
> To determine if all lowercase occurrences of a character appear before its first uppercase occurrence, we only need to compare two key indices for that character:
> 1. The **last** index at which the lowercase version of the letter appears (`last_lower`).
> 2. The **first** index at which the uppercase version of the letter appears (`first_upper`).
>
> If the last lowercase occurrence is positioned before the first uppercase occurrence (i.e., `last_lower < first_upper`), it mathematically guarantees that *every* lowercase occurrence of that letter appears before the first uppercase occurrence of that letter.
>
> Since there are only 26 English letters, we can store these indices in two fixed-size arrays of size 26. This allows us to achieve $O(n)$ time complexity and $O(1)$ auxiliary space.

---

## 🔩 Step-by-Step Breakdown

### Step 1: Initialize Trackers
- Allocate two integer arrays, `last_lower` and `first_upper`, each of size 26 initialized to `-1`. These will store the indices of the respective occurrences of each character.

### Step 2: Traverse the String
- Iterate through each character `word[i]` at index `i` of the string `word`:
  - If `word[i]` is lowercase (`'a'` to `'z'`), update the last seen index:
    $$\text{last\_lower}[\text{word}[i] - \text{'a'}] = i$$
  - If `word[i]` is uppercase (`'A'` to `'Z'`), record its first occurrence:
    - Only update if the index is unset (i.e., equal to `-1`):
      $$\text{first\_upper}[\text{word}[i] - \text{'A'}] = i$$

### Step 3: Count Special Characters
- Initialize a `count = 0`.
- Loop through the 26 characters (0 to 25):
  - Check if the character has appeared in both cases:
    $$\text{last\_lower}[i] \neq -1 \quad \text{and} \quad \text{first\_upper}[i] \neq -1$$
  - Check if the last lowercase occurrence is before the first uppercase occurrence:
    $$\text{last\_lower}[i] < \text{first\_upper}[i]$$
  - If both conditions are satisfied, increment `count`.
- Return the final `count`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start([Start]) --> Init["Initialize arrays: last_lower(26, -1), first_upper(26, -1)"]
    Init --> LoopStart["Loop through string index i = 0 to n-1"]
    LoopStart --> CheckCase{"Is word[i] lowercase?"}
    CheckCase -- Yes --> UpdateLower["last_lower[word[i] - 'a'] = i"]
    CheckCase -- No --> CheckFirstUpper{"first_upper[word[i] - 'A'] == -1?"}
    CheckFirstUpper -- Yes --> UpdateUpper["first_upper[word[i] - 'A'] = i"]
    CheckFirstUpper -- No --> Next["Move to next character (i++)"]
    UpdateLower --> Next
    UpdateUpper --> Next
    Next --> CheckEnd{"i < n?"}
    CheckEnd -- Yes --> CheckCase
    CheckEnd -- No --> InitCount["Initialize: count = 0, ch = 0"]
    InitCount --> CheckCh{"ch < 26?"}
    CheckCh -- Yes --> VerifySpecial{"last_lower[ch] != -1 && first_upper[ch] != -1 && last_lower[ch] < first_upper[ch]?"}
    VerifySpecial -- Yes --> IncCount["count++"]
    VerifySpecial -- No --> NextCh["ch++"]
    IncCount --> NextCh
    NextCh --> CheckCh
    CheckCh -- No --> ReturnResult["Return count"]
    ReturnResult --> End([End])
```

---

## 📊 Complexity Analysis

| Type | Complexity | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $O(n)$ | We scan the string of length $n$ exactly once, followed by a constant iteration loop of size 26. |
| **Auxiliary Space** | $O(1)$ | We use two arrays of fixed size 26 to store tracking indices, which consumes constant memory. |

---

> *"The essence of efficient string processing is to distill sequential records into static properties of the alphabet."* — **Anonymous**

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../119_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../121_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
