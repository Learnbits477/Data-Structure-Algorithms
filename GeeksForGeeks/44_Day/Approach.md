# Minimum Number of K Consecutive Bit Flips

## Approach

We can use a sliding window with a queue or an array tracking the flip states. This prevents checking all `k` elements every time we perform a flip, avoiding a $O(N \cdot K)$ time complexity.

1. **State Tracking**: 
   - `flipped`: Tracks the current state of flips for the element at index `i`.
   - `isFlipped`: A boolean array of size `n` to remember if we flipped the subarray starting at a specific index.
   - `res`: Keeps count of the total operations (flips).

2. **Iteration**:
   - Iterate through each element in the array.
   - For an element at index `i`, if `i >= k`, we might move out of the range of a previous flip. We use `flipped ^= isFlipped[i - k]` to revert the effect of a flip that ends before `i`.
   - If `arr[i] == flipped`, it means the current element is effectively `0` and needs to be flipped.
     - If `i + k > n`, we don't have enough elements left to make a valid sequence of length `k`. This means the array cannot be satisfied, so we return `-1`.
     - Otherwise, we update our counters: record that a flip happens at index `i` (`isFlipped[i] = 1`), toggle the current `flipped` state (`flipped ^= 1`), and increment our result `res`.

3. **Return**:
   - Once the loop correctly finishes, return `res`, representing the minimum valid operations.

## Complexity
- **Time Complexity:** $O(N)$ where $N$ is the size of the array `arr`. We traverse the array exactly once.
- **Space Complexity:** $O(N)$ for the `isFlipped` array. This could be optimized to $O(K)$ using a queue, or even $O(1)$ by mutating the input array.
