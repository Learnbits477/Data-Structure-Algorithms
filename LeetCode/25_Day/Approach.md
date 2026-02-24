# Approach: Prime Number of Set Bits in Binary Representation

## Intuition

For every number in `[left, right]`:

1. Count the number of set bits (1s in binary) using `__builtin_popcount()`.
2. Check if that count is a **prime number**.
3. If yes, increment the result counter.

Since `right <= 10^6 < 2^20`, the maximum number of set bits is **20**.  
So we only need to check if the bit count is among the primes ≤ 20:  
`{2, 3, 5, 7, 11, 13, 17, 19}`

---

## Key Insight — Bitmask Trick

We can store all primes up to 20 in a **bitmask**:

```
Primes: 2, 3, 5, 7, 11, 13, 17, 19
Bitmask = (1<<2)|(1<<3)|(1<<5)|(1<<7)|(1<<11)|(1<<13)|(1<<17)|(1<<19)
        = 0b10101000010100101100 = 665772
```

To check if `k` is prime: `(primeMask >> k) & 1`

This avoids writing a separate `isPrime()` function.

---

## Algorithm

```
count = 0
for num from left to right:
    bits = popcount(num)
    if (primeMask >> bits) & 1:
        count++
return count
```

---

## Complexity Analysis

|           | Complexity                     |
| --------- | ------------------------------ |
| **Time**  | O((right - left) × log(right)) |
| **Space** | O(1)                           |

- At most `10^4` numbers, each needing at most 20-bit popcount → very fast.

---

## Dry Run

**Input:** `left = 6, right = 10`

| num | binary | set bits | prime? |
| --- | ------ | -------- | ------ |
| 6   | 110    | 2        | ✅ Yes |
| 7   | 111    | 3        | ✅ Yes |
| 8   | 1000   | 1        | ❌ No  |
| 9   | 1001   | 2        | ✅ Yes |
| 10  | 1010   | 2        | ✅ Yes |

**Output:** `4` ✅
