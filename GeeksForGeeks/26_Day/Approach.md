# Approach – Count Subarrays with given XOR

## Intuition

We want to count subarrays whose XOR equals `k`.

A brute-force approach checks every pair `(i, j)` – O(n²) or O(n³). We can do much better using **prefix XOR** and a **hash map**, achieving **O(n)** time.

---

## Algorithm: Prefix XOR + Hash Map (O(n) time, O(n) space)

### Key Observation

Let `prefXOR[i]` = XOR of `arr[0..i]`.

XOR of subarray `arr[l..r]` = `prefXOR[r] XOR prefXOR[l-1]`.

We want: `prefXOR[r] XOR prefXOR[l-1] == k`

⟹ `prefXOR[l-1] == prefXOR[r] XOR k`

So for each index `r`, we need to count how many previous prefix XOR values equal `prefXOR[r] XOR k`.

### Steps

1. Initialize `freq` map with `{0: 1}` (empty prefix has XOR = 0).
2. Maintain `curXOR = 0`.
3. For each element `arr[i]`:
   - `curXOR ^= arr[i]`
   - `target = curXOR ^ k`
   - Add `freq[target]` to the answer (subarrays ending at `i` with XOR = k).
   - Increment `freq[curXOR]`.
4. Return the answer.

### Dry Run on Example 1

```
arr = [4, 2, 2, 6, 4], k = 6
freq = {0:1}, curXOR = 0, ans = 0

i=0: curXOR = 4, target = 4^6 = 2, freq[2]=0, ans=0, freq={0:1,4:1}
i=1: curXOR = 6, target = 6^6 = 0, freq[0]=1, ans=1, freq={0:1,4:1,6:1}
i=2: curXOR = 4, target = 4^6 = 2, freq[2]=0, ans=1, freq={0:1,4:2,6:1}
i=3: curXOR = 2, target = 2^6 = 4, freq[4]=2, ans=3, freq={0:1,4:2,6:1,2:1}
i=4: curXOR = 6, target = 6^6 = 0, freq[0]=1, ans=4, freq={0:1,4:2,6:2,2:1}

Answer = 4 ✓
```

### Dry Run on Example 2

```
arr = [5, 6, 7, 8, 9], k = 5
freq = {0:1}, curXOR = 0, ans = 0

i=0: curXOR=5,  target=5^5=0, freq[0]=1, ans=1
i=1: curXOR=3,  target=3^5=6, freq[6]=0, ans=1
i=2: curXOR=4,  target=4^5=1, freq[1]=0, ans=1
i=3: curXOR=12, target=12^5=9, freq[9]=0, ans=1
i=4: curXOR=5,  target=5^5=0, freq[0]=1, ans=2

Answer = 2 ✓
```

---

## Complexity

| Metric | Value |
| ------ | ----- |
| Time   | O(n)  |
| Space  | O(n)  |

---

## Alternative: Brute Force (O(n²))

- For every pair `(l, r)`, compute XOR of `arr[l..r]` and check if it equals `k`.
- Works but is too slow for `n = 10^5`.
