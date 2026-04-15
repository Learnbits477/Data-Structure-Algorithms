# 2515. Shortest Distance to Target String in a Circular Array

> **Difficulty:** 🟢 Easy &nbsp;|&nbsp; **Topic:** Array, String &nbsp;|&nbsp; **Source:** [LeetCode #2515](https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/?envType=daily-question&envId=2026-04-15)

---

## 📜 Problem Statement

You are given a **0-indexed circular string array** `words` and a string `target`.

A **circular array** means the array's end connects to its beginning:
- **Next** element of `words[i]` → `words[(i + 1) % n]`
- **Previous** element of `words[i]` → `words[(i - 1 + n) % n]`

Starting from `startIndex`, you can move to either the **next** or **previous** word with **1 step** at a time.

Return the **shortest distance** needed to reach the string `target`.  
If `target` does not exist in `words`, return **`-1`**.

---

## 🔢 Examples

### Example 1
```
Input:  words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1
Output: 1

Explanation:
  From index 1 → move LEFT  1 step  → index 0  ("hello") ✅
  From index 1 → move LEFT  2 steps → index 4  ("hello") ✅
  From index 1 → move RIGHT 3 steps → index 4  ("hello") ✅
  From index 1 → move RIGHT 4 steps → index 0  ("hello") ✅
  Shortest = 1
```

### Example 2
```
Input:  words = ["a","b","leetcode"], target = "leetcode", startIndex = 0
Output: 1 (1 step left wraps to index 2)
```

### Example 3
```
Input:  words = ["i","eat","leetcode"], target = "ate", startIndex = 0
Output: -1  ("ate" not found)
```

---

## 📐 Constraints

| Parameter | Bound |
|-----------|-------|
| `words.length` | `1 ≤ n ≤ 100` |
| `words[i].length` | `1 ≤ len ≤ 100` |
| Characters | lowercase English letters only |
| `startIndex` | `0 ≤ startIndex < n` |
