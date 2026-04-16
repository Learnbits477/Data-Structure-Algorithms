# [3488. Closest Equal Element Queries](https://leetcode.com/problems/closest-equal-element-queries/description/?envType=daily-question&envId=2026-04-15)

> **Difficulty:** 🟡 Medium &nbsp;|&nbsp; **Topic:** Array, Hash Map, Binary Search &nbsp;|&nbsp; **Source:** [LeetCode #3488](https://leetcode.com/problems/closest-equal-element-queries/description/?envType=daily-question&envId=2026-04-15)

---

## 📜 Problem Statement

You are given a **circular array** `nums` and an array `queries`.

For each query `i`, find:
> The **minimum distance** between the element at index `queries[i]` and any **other** index `j` in the circular array, where `nums[j] == nums[queries[i]]`.  
> If no such index exists, return **`-1`** for that query.

Return an array `answer` of the same size as `queries`.

A **circular array** means the end connects back to the start:
- Going right from index `i` → `(i + 1) % n`
- Going left from index `i` → `(i - 1 + n) % n`
- Circular distance between indices `i` and `j`:
  ```
  dist = min(|i - j|,  n - |i - j|)
  ```

---

## 🔢 Examples

### Example 1
```
Input:  nums = [1,3,1,4,1,3,2],  queries = [0,3,5]
Output: [2,-1,3]

  Query 0 → idx=0, nums[0]=1
    Other 1s at indices {2, 4}
    dist(0,2) = min(2, 5) = 2
    dist(0,4) = min(4, 3) = 3
    Answer = 2 ✅

  Query 1 → idx=3, nums[3]=4
    No other 4 exists → -1 ✅

  Query 2 → idx=5, nums[5]=3
    Other 3 at index {1}
    dist(5,1) = min(4, 3) = 3  (circular: 5→6→0→1)
    Answer = 3 ✅
```

### Example 2
```
Input:  nums = [1,2,3,4],  queries = [0,1,2,3]
Output: [-1,-1,-1,-1]

  Every element is unique → no duplicate → -1 for all ✅
```

---

## 📐 Constraints

| Parameter | Bound |
|-----------|-------|
| `queries.length` | `1 ≤ q ≤ n` |
| `nums.length` | `1 ≤ n ≤ 10⁵` |
| `nums[i]` | `1 ≤ nums[i] ≤ 10⁶` |
| `queries[i]` | `0 ≤ queries[i] < n` |
