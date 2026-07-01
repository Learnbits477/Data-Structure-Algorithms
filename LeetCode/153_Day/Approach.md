# 💡 Approach — Number of Strings That Appear as Substrings in Word

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 80.5%](https://img.shields.io/badge/Acceptance-80.5%25-blue?style=for-the-badge)
![Submissions: 120.3K](https://img.shields.io/badge/Submissions-120.3K-brightgreen?style=for-the-badge)

</div>

---

## 🎯 Core Insight

> [!TIP]
> **Linear Substring Search:**
> Since the constraints on `patterns.length`, `patterns[i].length`, and `word.length` are all extremely small ($$\le 100$$), a simple linear check for each pattern inside `word` is highly efficient. In C++, `std::string::find` uses highly optimized searches which run in $$O(\text{pattern.length} \times \text{word.length})$$ in the worst case (or faster using modern compiler optimizations).

---

## 🔩 Step-by-Step Breakdown

**Step 1: Initialize Count**
- Initialize a counter `ans = 0`.

**Step 2: Search Substrings**
- Loop through each `pattern` in the `patterns` array:
  - Perform a substring search using `word.find(pattern)`.
  - If the search result is not equal to `std::string::npos` (meaning the pattern was found in `word`), increment `ans` by 1.

**Step 3: Return Result**
- Return the final count `ans`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A([Start]) --> B["Initialize ans = 0"]
    B --> C["Loop through each pattern in patterns"]
    C --> D{"word.find(pattern) != string::npos?"}
    D -- Yes --> E["ans = ans + 1"]
    D -- No --> F["Keep ans unchanged"]
    E --> G{"Has next pattern?"}
    F --> G
    G -- Yes --> C
    G -- No --> H["Return ans"]
    H --> I([End])
```

---

## 🧮 Dry Run — Example 1

Input: `patterns = ["a", "abc", "bc", "d"]`, `word = "abc"`

### Execution

| Step | Pattern | `word.find(pattern)` Result | Condition: Found? | `ans` Update |
| :---: | :---: | :---: | :---: | :---: |
| **Start** | — | — | — | `0` |
| **1** | `"a"` | `0` (index where `"a"` starts) | True | `1` |
| **2** | `"abc"` | `0` (index where `"abc"` starts) | True | `2` |
| **3** | `"bc"` | `1` (index where `"bc"` starts) | True | `3` |
| **4** | `"d"` | `std::string::npos` (not found) | False | `3` |

**Final Output:** `3` ✅

---

## 📊 Complexity Analysis

| Metric | Complexity | Reasoning |
| :---: | :---: | :--- |
| 🕐 Time | $$O(m \cdot l \cdot w)$$ | We iterate over $$m$$ patterns. For each pattern of max length $$l$$, searching it in `word` of length $$w$$ takes $$O(l \cdot w)$$ time in the worst case. |
| 💾 Space | $$O(1)$$ | We only use a constant number of counter variables, requiring no auxiliary storage. |

---

> *"The simplicity of searching within a word lies in matching character by character until the pattern emerges."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../152_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../154_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
