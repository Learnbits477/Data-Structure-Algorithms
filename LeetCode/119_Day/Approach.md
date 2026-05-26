# 💡 Approach — Count the Number of Special Characters I

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

---

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 73.0%](https://img.shields.io/badge/Acceptance-73.0%25-blue?style=for-the-badge)
![Submissions: 148K](https://img.shields.io/badge/Submissions-148K-purple?style=for-the-badge)
![Topics: Hash Table](https://img.shields.io/badge/Topics-Hash%20Table-orange?style=for-the-badge)

---

> [!TIP]
> **Core Insight:**  
> To determine if a letter is "special", we need to check if it appears both in its lowercase and uppercase form within the string.
> 
> Since there are only 26 English alphabetic characters, we can maintain two lookup frequency tables (or boolean flags):
> 1. One table tracks which lowercase letters (`'a'` to `'z'`) have been seen.
> 2. The other table tracks which uppercase letters (`'A'` to `'Z'`) have been seen.
> 
> After scanning the entire string, we simply count the alphabet positions that have `true` marked in both lookup tables. This results in $O(n)$ time complexity and a constant $O(1)$ auxiliary space complexity.

---

## 🔩 Step-by-Step Breakdown

### Step 1: Initialize Frequency or Presence Trackers
- Declare two boolean arrays/vectors `lower` and `upper` of size 26, initialized to `false`. These arrays correspond to letters `'a'` through `'z'` and `'A'` through `'Z'` respectively.

### Step 2: Mark Character Presence
- Iterate through each character `c` in the string `word`:
  - If `c` is a lowercase letter (i.e. `c >= 'a' && c <= 'z'`), set `lower[c - 'a'] = true`.
  - If `c` is an uppercase letter (i.e. `c >= 'A' && c <= 'Z'`), set `upper[c - 'A'] = true`.

### Step 3: Count and Return Special Characters
- Initialize a counter `specialCount = 0`.
- Loop through index `i` from `0` to `25` (corresponding to alphabet letters A-Z):
  - If both `lower[i]` and `upper[i]` are `true`, increment `specialCount`.
- Return the final value of `specialCount`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start([Start]) --> Init["Initialize lower(26, false), upper(26, false)"]
    Init --> LoopStart["Loop through each character c in word"]
    LoopStart --> CheckCase{"Is c lowercase?"}
    CheckCase -- Yes --> MarkLower["lower[c - 'a'] = true"]
    CheckCase -- No --> MarkUpper["upper[c - 'A'] = true"]
    MarkLower --> NextChar["Next Character"]
    MarkUpper --> NextChar
    NextChar --> CheckEnd{"More characters?"}
    CheckEnd -- Yes --> CheckCase
    CheckEnd -- No --> LoopCount["Loop i from 0 to 25"]
    LoopCount --> CheckBoth{"lower[i] && upper[i]?"}
    CheckBoth -- Yes --> IncCount["specialCount++"]
    CheckBoth -- No --> NextIndex["Next Index (i++)"]
    IncCount --> NextIndex
    NextIndex --> CheckLoopEnd{"i < 26?"}
    CheckLoopEnd -- Yes --> CheckBoth
    CheckLoopEnd -- No --> ReturnResult["Return specialCount"]
    ReturnResult --> End([End])
```

---

## 📊 Complexity Analysis

| Type | Complexity | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $O(n)$ | We iterate through the string of length $n$ once, performing constant $O(1)$ lookup operations. After that, we perform a fixed loop of $26$ iterations. |
| **Auxiliary Space** | $O(1)$ | We use two boolean vectors of size 26, which consume a constant amount of memory independent of the input size. |

---

> *"The details are not the details. They make the design."* — **Charles Eames**

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../118_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../120_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
