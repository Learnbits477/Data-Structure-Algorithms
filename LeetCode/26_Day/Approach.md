# Approach: Sliding Window + Hash Set

## Intuition

There are exactly `2^k` binary codes of length `k`. We need to check whether all of them appear as substrings in `s`.

Instead of enumerating all `2^k` possible codes and searching for each, we can slide a window of size `k` across `s`, collect all unique substrings of length `k` in a hash set, and then check if the set size equals `2^k`.

---

## Algorithm

1. If `s.length() < k`, return `false` immediately (not enough characters).
2. Use an `unordered_set<string>` to store every unique substring of length `k`.
3. Slide a window from index `0` to `s.length() - k`:
   - Insert `s.substr(i, k)` into the set.
4. Return `true` if `set.size() == (1 << k)` (i.e., `2^k`).

---

## Complexity Analysis

| Metric           | Value                                                  |
| ---------------- | ------------------------------------------------------ |
| Time Complexity  | O(n \* k) — n windows, each substring has length k     |
| Space Complexity | O(2^k \* k) — at most 2^k substrings, each of length k |

> **Note:** Since `k <= 20`, `2^k <= 1,048,576` which is manageable.

---

## Example Walkthrough

```
s = "00110110", k = 2

Windows: "00", "01", "11", "10", "01", "11", "10"
Unique set: {"00", "01", "11", "10"}  → size = 4 = 2^2 ✓
Output: true
```
