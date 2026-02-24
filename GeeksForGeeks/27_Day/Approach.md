# Approach: Hash Set

## Intuition

We need all **distinct** elements from both arrays combined. A hash set (`unordered_set`) naturally eliminates duplicates — inserting all elements from both arrays into a set gives us exactly the union.

---

## Algorithm

1. Create an `unordered_set<int> st`.
2. Insert every element of `a[]` into the set.
3. Insert every element of `b[]` into the set.
4. Copy the set contents into a `vector<int>` and return it.

The driver code will sort and print the result.

---

## Complexity Analysis

| Metric           | Value                                                 |
| ---------------- | ----------------------------------------------------- |
| Time Complexity  | O(n + m) average — n = size of a[], m = size of b[]   |
| Space Complexity | O(n + m) — set stores at most n + m distinct elements |

---

## Example Walkthrough

```
a = [1, 2, 3, 2, 1], b = [3, 2, 2, 3, 3, 2]

After inserting a[]: set = {1, 2, 3}
After inserting b[]: set = {1, 2, 3}   (3, 2 already present)

Result vector: [1, 2, 3]  ✓
```
