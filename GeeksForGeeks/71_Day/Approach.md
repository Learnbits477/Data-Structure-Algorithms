# Approach: Two Pointers Technique

## Intuition

The goal is to segregate 0s to the left and 1s to the right in a single pass ($O(N)$). Using a two-pointer approach, we can place one pointer at the start (`left`) and another at the end (`right`). We move the pointers toward each other, swapping elements only when a 1 is found on the left and a 0 is found on the right.

## Step-by-Step Logic

### 1. Initialization
We use two pointers:
- `left` starting at index `0`.
- `right` starting at index `n - 1`.

### 2. Move Pointers
While `left < right`:
- **Increment `left`** as long as `arr[left] == 0`. We don't need to move 0s that are already on the left.
- **Decrement `right`** as long as `arr[right] == 1`. We don't need to move 1s that are already on the right.

### 3. Swap and Advance
If `left < right` after the above movements, it means `arr[left]` is `1` and `arr[right]` is `0`. We swap them (or simply set `arr[left] = 0` and `arr[right] = 1` since we know their values) and then move both pointers further.

```cpp
while (left < right) {
    while (arr[left] == 0 && left < right) left++;
    while (arr[right] == 1 && left < right) right--;
    if (left < right) {
        arr[left] = 0;
        arr[right] = 1;
        left++;
        right--;
    }
}
```

## Complexity

- **Time Complexity:** $\mathcal{O}(N)$
  - We traverse the array once with two pointers.
- **Space Complexity:** $\mathcal{O}(1)$
  - We perform the segregation in-place without using extra storage.
