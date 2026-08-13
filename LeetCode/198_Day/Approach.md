# 💡 Approach — Longest Substring of One Repeating Character

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata


## 📊 Metadata
![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance](https://img.shields.io/badge/Acceptance-46.9%25-orange?style=for-the-badge)
![Submissions](https://img.shields.io/badge/Submissions-30K-blue?style=for-the-badge)

![Topic: Segment Tree](https://img.shields.io/badge/Topics:-Segment_Tree-blue?style=for-the-badge)
![Topic: Ordered Set](https://img.shields.io/badge/Ordered_Set-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Array-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/String-blue?style=for-the-badge)
---

> [!TIP]
> **Core Insight:**
> A naive scan per update takes $O(N)$ leading to $O(N \cdot K)$ overall, which is too slow. To achieve logarithmic time per update, we can model the string using a **Segment Tree**. Each segment node keeps track of the longest repeating substring length within its bounds, as well as the longest repeating prefix and suffix sequences. When merging two adjacent segments, we check if the characters at the boundary match. If they do, the suffix of the left segment can merge with the prefix of the right segment, creating a new contiguous repeating substring across the boundary.

---

## 🔩 Step-by-Step Breakdown

### Step 1: Define the Node Structure
Each segment tree node stores the metadata of range $[L, R]$:
- `size`: length of the segment.
- `max_len`: maximum repeating substring length within the segment.
- `pref_char`: starting character of the segment.
- `pref_len`: length of the repeating prefix.
- `suff_char`: ending character of the segment.
- `suff_len`: length of the repeating suffix.

### Step 2: Implement the Node Merging Function
When merging `left` and `right` nodes:
1. `parent.size = left.size + right.size`
2. `parent.pref_char = left.pref_char`
3. If `left.pref_len == left.size` and `left.pref_char == right.pref_char`, the repeating prefix extends completely from the left segment into the right segment:
   - `parent.pref_len = left.size + right.pref_len`
   - Else, `parent.pref_len = left.pref_len`
4. `parent.suff_char = right.suff_char`
5. If `right.suff_len == right.size` and `right.suff_char == left.suff_char`, the repeating suffix extends completely from the right segment into the left segment:
   - `parent.suff_len = right.size + left.suff_len`
   - Else, `parent.suff_len = right.suff_len`
6. Calculate `parent.max_len` as the maximum of:
   - `left.max_len`
   - `right.max_len`
   - If `left.suff_char == right.pref_char`, the combined boundary length `left.suff_len + right.pref_len`.

### Step 3: Build the Segment Tree
Recursively divide the string into halves and initialize leaf nodes with `size = 1`, `max_len = 1`, and the corresponding character as both suffix and prefix. Merge them bottom-up.

### Step 4: Perform Point Updates
To update a character at index `idx` to `val`, traverse down to the corresponding leaf node in $O(\log N)$, modify it, and re-merge all ancestor nodes on the path back to the root.

### Step 5: Retrieve Query Results
After each update, the root node of the tree (`tree[1]`) immediately holds the global longest repeating substring length in its `max_len` field. We can query this in $O(1)$ time.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A["Start: Update s[idx] = val"] --> B["Traverse down Segment Tree to Leaf at idx"]
    B --> C["Update Leaf Node: size=1, max_len=1, chars=val"]
    C --> D["Recurse Backwards: Merge Left & Right Children"]
    D --> E{"Do Left Suffix and Right Prefix chars match?"}
    E -- Yes --> F["Combine boundary: boundary_len = left.suff_len + right.pref_len"]
    E -- No --> G["Set boundary_len = 0"]
    F --> H["parent.max_len = max(left.max_len, right.max_len, boundary_len)"]
    G --> H
    H --> I["Update Parent Prefix and Suffix extensions if they cover the whole child size"]
    I --> J["Return root.max_len as the Answer for Query"]
```

---

## 📊 Complexity Analysis

| Measure | Complexity | Details |
| :--- | :--- | :--- |
| **Time (Build)** | $O(N)$ | Tree contains $4N$ nodes, each built in $O(1)$ merge steps. |
| **Time (Update)** | $O(\log N)$ | Traverses a path from root to leaf of length $\log N$. |
| **Time (Query)** | $O(1)$ | Directly accesses the root node's `max_len` field. |
| **Space (Auxiliary)**| $O(N)$ | Tree size is bounded by $4N$ nodes, using negligible memory (~8 MB). |

---

> *"The art of programming is the art of organizing complexity, of mastering multitude and avoiding its confusion."* — Edsger W. Dijkstra

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../197_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../199_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
