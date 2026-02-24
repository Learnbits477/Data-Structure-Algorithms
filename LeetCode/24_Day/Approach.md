# Approach — 761. Special Binary String

## Key Insight

A **special binary string** is essentially a valid parenthesis string where `1` = `(` and `0` = `)`. This structural analogy is very useful.

To get the **lexicographically largest** string, we want longer special substrings (more `1`s) to appear earlier. Since `1` > `0`, a string that starts with more `1`s is lexicographically larger.

---

## Strategy: Recursive Sort

### Observation

Any special binary string `s` can be decomposed into a **sequence of non-overlapping special substrings** at the top level. These segments can be **freely reordered** (since swapping adjacent special substrings is allowed, and we can do it repeatedly — like bubble sort).

So we can:

1. Split `s` into its top-level special substrings.
2. Recursively make each one lexicographically largest.
3. Sort them in **descending order** (so larger ones come first).
4. Concatenate back.

### Decomposition

Traverse `s` with a counter:

- Increment on `'1'`, decrement on `'0'`.
- Whenever the counter hits `0`, we've found a complete top-level special substring.

Each such segment has the form `1 [inner] 0`, where `[inner]` is also a special binary string — so we strip the first `1` and last `0`, recurse on the inner part, then rebuild.

---

## Algorithm

```
function makeLargestSpecial(s):
    count = 0, start = 0
    parts = []

    for i in range(len(s)):
        if s[i] == '1': count++
        else:           count--

        if count == 0:
            inner = makeLargestSpecial(s[start+1 .. i-1])
            parts.append("1" + inner + "0")
            start = i + 1

    sort parts in descending order
    return join(parts)
```

---

## Complexity

| Metric | Value                                               |
| ------ | --------------------------------------------------- |
| Time   | O(n² log n) in the worst case (sorting + recursion) |
| Space  | O(n) recursion stack                                |

---

## Example Walkthrough

**Input:** `"11011000"`

Top-level special substrings:

- Start at 0, counter hits 0 at index 7 → full string `"11011000"`.
  - Inner: `"101100"`
  - Recurse on `"101100"`:
    - Parts: `"10"` (→ `"10"`) and `"1100"` (→ `"1" + recurse("10") + "0"` = `"1100"`)
    - Sorted descending: `"1100"`, `"10"`
    - Result: `"110010"`
  - Reconstructed: `"1" + "110010" + "0"` = `"11100100"`

**Output:** `"11100100"` ✅
