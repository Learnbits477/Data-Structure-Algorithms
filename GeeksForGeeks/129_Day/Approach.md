# 💡 Approach — Lexicographically smallest after removing k

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Topic: Strings](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Topic: Stack](https://img.shields.io/badge/Topic-Stack-brightgreen?style=for-the-badge)

> [!TIP]
> **Core Insight:**  
> To form the lexicographically smallest string after removing exactly `k` characters, we can maintain a monotonic stack. If a character is smaller than the character at the top of the stack, and we still need to remove characters, we should pop the stack. First, we correctly adjust the value of `k` as per the problem constraints.

## 🔩 Step-by-Step Breakdown

1.  **Length Check & `k` Adjustment**:
    -   Find the length of string `s`, denoted as `n`.
    -   Check if `n` is a power of `2` using bitwise operations (`(n & (n - 1)) == 0`).
    -   If it is a power of `2`, halve `k` (`k /= 2`). Otherwise, double `k` (`k *= 2`).
2.  **Feasibility Check**:
    -   If the adjusted `k` is greater than or equal to `n`, it implies we need to remove all or more characters than present in `s`, which results in an empty string. Return `"-1"`.
3.  **Monotonic Stack Construction**:
    -   Iterate through each character `c` of the string `s`.
    -   While the stack (or a resultant string functioning as a stack) is not empty, `k > 0`, and the top element is strictly greater than `c`, pop the top element and decrement `k`.
    -   Push `c` onto the stack.
4.  **Remove Remaining Characters**:
    -   After iterating, if `k > 0`, pop the remaining characters from the end of the stack because the characters are now in non-decreasing order.
5.  **Final Checks**:
    -   Return the resulting string. If the resultant string is empty after all deletions, return `"-1"`.

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A["Start"] --> B{"Is n power of 2?"}
    B -- "Yes" --> C["k = k / 2"]
    B -- "No" --> D["k = k * 2"]
    C --> E{"Is k >= n?"}
    D --> E
    E -- "Yes" --> F["Return -1"]
    E -- "No" --> G["Initialize Empty String/Stack"]
    G --> H["Iterate over characters of s"]
    H --> I{"k > 0 AND stack top > current char?"}
    I -- "Yes" --> J["Pop stack, k--"]
    J --> I
    I -- "No" --> K["Push current char"]
    K --> L{"More characters?"}
    L -- "Yes" --> H
    L -- "No" --> M{"Is k > 0?"}
    M -- "Yes" --> N["Pop stack, k--"]
    N --> M
    M -- "No" --> O{"Is stack empty?"}
    O -- "Yes" --> P["Return -1"]
    O -- "No" --> Q["Return Stack contents"]
    P --> R["End"]
    Q --> R
    F --> R
```

## 📊 Complexity Analysis

| Measure | Complexity | Explanation |
|:---:|:---:|:---|
| **Time Complexity** | $$O(n + k)$$ | We traverse the string once $O(n)$, and each character is pushed and popped at most once. Remaining deletions take $O(k)$ time. |
| **Space Complexity** | $$O(n)$$ | We use a string or a stack to store the answer which takes $O(n)$ space in the worst-case scenario. |

> *"Simplicity is the soul of efficiency."* — Austin Freeman

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../128_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../130_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
