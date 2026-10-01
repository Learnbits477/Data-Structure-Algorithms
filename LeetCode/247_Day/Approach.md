# 💡 Approach — Valid Parentheses

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-green?style=for-the-badge)
![Acceptance: 45.0%](https://img.shields.io/badge/Acceptance-45.0%25-orange?style=for-the-badge)
![Submissions: 18.3M+](https://img.shields.io/badge/Submissions-18.3M%2B-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/Topic-String-blue?style=for-the-badge)
![Topic: Stack](https://img.shields.io/badge/Stack-blue?style=for-the-badge)
![Topic: Bracket Sequences](https://img.shields.io/badge/Bracket%20Sequences-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — The "Expected Closing Bracket" Stack Pattern:**
> 1. **LIFO Matching**:
>    Because brackets can be nested arbitrarily, the most recently opened bracket must be the first one to be closed. A **Stack** naturally enforces this Last-In, First-Out order.
> 2. **Push Expected Closers Directly**:
>    Instead of pushing `'('`, `'{'`, `'['` and checking complex lookup tables on close brackets, whenever an opener appears, push its **matching closer** onto the stack:
>    - Encounter `'('` $\implies$ push `')'`
>    - Encounter `'{'` $\implies$ push `'}'`
>    - Encounter `'['` $\implies$ push `']'`
> 3. **Single Identity Comparison**:
>    When any closing bracket arrives, the validation condition becomes simply:
>    `!st.empty() && st.top() == c`
>    If this condition is violated at any point, the string is immediately invalid.
> 4. **Early Exit on Odd Length**:
>    A valid parentheses string must contain matched pairs; hence an odd length string can never be valid ($n \% 2 \ne 0 \implies \text{false}$).

---

## 🔩 Step-by-Step Breakdown

1. **Parity Check**:
   - If $s\text{.length}() \% 2 \ne 0$, return `false` immediately.

2. **Stack Initialization**:
   - Create a stack of characters `st`.
   - Alternatively, use a preallocated `vector<char>` or the string itself as a stack pointer to completely bypass heap reallocation overhead.

3. **Character Iteration**:
   - Traverse through each character $c$ in string $s$:
     - **Case 1: Opening Parenthesis `'('`**:
       Push `')'` to stack.
     - **Case 2: Opening Brace `'{'`**:
       Push `'}'` to stack.
     - **Case 3: Opening Bracket `'['`**:
       Push `']'` to stack.
     - **Case 4: Closing Parenthesis / Brace / Bracket**:
       - Check if stack is empty (indicates an extra closing bracket without an opener).
       - Check if `st.top() != c` (indicates mismatched bracket type or wrong ordering).
       - If either condition holds, return `false`.
       - Otherwise, pop the matched bracket `st.pop()`.

4. **Final Emptiness Check**:
   - After inspecting all characters in $s$, return `st.empty()`.
   - If the stack is empty, every bracket was properly matched and closed. If elements remain, some openers were never closed.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start["Start: isValid(s)"] --> LengthCheck{"s.length() % 2 != 0?"}
    LengthCheck -- "Yes (Odd length)" --> RetFalse1["Return false ❌"]
    LengthCheck -- "No" --> InitStack["Initialize Stack st"]
    InitStack --> LoopStart["For each char c in s"]
    
    LoopStart --> CheckOpener{"Is c an opening bracket?"}
    CheckOpener -- "'('" --> PushP["st.push(')')"] --> NextChar["Next Char"]
    CheckOpener -- "'{'" --> PushB["st.push('}')"] --> NextChar
    CheckOpener -- "'['" --> PushS["st.push(']')"] --> NextChar
    
    CheckOpener -- "No (Closing char)" --> CheckMatch{"st.empty() OR<br/>st.top() != c ?"}
    CheckMatch -- "Yes" --> RetFalse2["Return false ❌"]
    CheckMatch -- "No" --> PopStack["st.pop()"] --> NextChar
    
    NextChar --> MoreChars{"More characters?"}
    MoreChars -- "Yes" --> LoopStart
    MoreChars -- "No" --> FinalCheck{"st.empty()?"}
    FinalCheck -- "Yes" --> RetTrue["Return true ✅"]
    FinalCheck -- "No" --> RetFalse3["Return false (Unmatched openers) ❌"]
```

---

## 🏃‍♂️ Dry Run

### Tracing Example 4: $s = \text{"([])"}$

| Index $i$ | Character $c$ | Action Taken | Stack State (Bottom $\to$ Top) | Match Valid? |
| :---: | :---: | :--- | :---: | :---: |
| — | — | Initial state | `[]` | — |
| **0** | `'('` | Opener: push `')'` | `[ ')' ]` | ✅ |
| **1** | `'['` | Opener: push `']'` | `[ ')', ']' ]` | ✅ |
| **2** | `']'` | Closer: matches `st.top()` $\implies$ pop | `[ ')' ]` | ✅ |
| **3** | `')'` | Closer: matches `st.top()` $\implies$ pop | `[]` | ✅ |

- End of string reached.
- Stack is empty: $\implies$ **`true`**.

### Tracing Example 5: $s = \text{"([)]"}$

| Index $i$ | Character $c$ | Action Taken | Stack State (Bottom $\to$ Top) | Match Valid? |
| :---: | :---: | :--- | :---: | :---: |
| — | — | Initial state | `[]` | — |
| **0** | `'('` | Opener: push `')'` | `[ ')' ]` | ✅ |
| **1** | `'['` | Opener: push `']'` | `[ ')', ']' ]` | ✅ |
| **2** | `')'` | Closer: expected `']'`, found `')'` ($')' \ne ']'$) | `[ ')', ']' ]` | ❌ **Mismatch!** |

- Immediate exit: returns **`false`**.

---

## ⏱️ Complexity Analysis

| Metric | Complexity | Rationale |
| :--- | :---: | :--- |
| **Time Complexity** | $\mathcal{O}(n)$ | We scan each character of the string $s$ of length $n$ exactly once. Each stack push and pop operation takes $\mathcal{O}(1)$ time. Overall execution is strictly linear. |
| **Auxiliary Space** | $\mathcal{O}(n)$ | In the worst case (e.g., all opening brackets like `"(((((("`), the stack stores up to $n$ characters. With fast array allocation, space is tightly bounded. |

---

> *"The elegance of stack-based parsing lies in postponing verification: we record our exact expectations when entering a scope and validate them instantaneously upon exit."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../246_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../248_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
