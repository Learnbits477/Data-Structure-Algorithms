# Approach — 868. Binary Gap

## Intuition

We need to find the **maximum distance** between two consecutive `1` bits in the binary representation of `n`. A simple single-pass scan of bits does the trick: track the position of the **last seen `1`**, and whenever we see a new `1`, compute the gap.

---

## Algorithm

1. Initialize `last = -1` (position of the previous `1` bit) and `ans = 0`.
2. Iterate over bit positions `i` from `0` to `30`:
   - If bit `i` of `n` is set (`n >> i & 1 == 1`):
     - If `last != -1`, update `ans = max(ans, i - last)`.
     - Set `last = i`.
3. Return `ans`.

---

## Complexity

|           | Value                               |
| --------- | ----------------------------------- |
| **Time**  | O(log n) — at most 30 bit positions |
| **Space** | O(1) — only a few variables         |

---

## Dry Run

### n = 22 → binary `10110`

| Bit position | Bit value |  last  |      ans      |
| :----------: | :-------: | :----: | :-----------: |
|      0       |     0     |   -1   |       0       |
|      1       |     1     | -1 → 1 |       0       |
|      2       |     1     | 1 → 2  | max(0, 2-1)=1 |
|      3       |     0     |   2    |       1       |
|      4       |     1     | 2 → 4  | max(1, 4-2)=2 |

**Result: 2** ✅

### n = 8 → binary `1000`

Only one `1` bit at position 3 → no adjacent pair → **Result: 0** ✅

### n = 5 → binary `101`

| Bit position | Bit value |  last  |      ans      |
| :----------: | :-------: | :----: | :-----------: |
|      0       |     1     | -1 → 0 |       0       |
|      1       |     0     |   0    |       0       |
|      2       |     1     | 0 → 2  | max(0, 2-0)=2 |

**Result: 2** ✅
