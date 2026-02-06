# Approach: Sorting and Three Pointers

## Intuition

We want to minimize `max(a, b, c) - min(a, b, c)`. We can achieve this by sorting the arrays and using a sliding window-like approach with three pointers.

## Algorithm

1. **Sort** `a`, `b`, and `c`.
2. Initialize three pointers `i = 0`, `j = 0`, `k = 0`.
3. Initialize `min_diff` to infinity and `min_sum` to infinity.
4. Loop while `i < n`, `j < n`, `k < n`:
    - Let `val_a = a[i]`, `val_b = b[j]`, `val_c = c[k]`.
    - Find `current_max` and `current_min`.
    - `current_diff = current_max - current_min`.
    - `current_sum = val_a + val_b + val_c`.
    - **Update Logic**:
        - If `current_diff < min_diff`:
            - Update `min_diff = current_diff`.
            - Update `min_sum = current_sum`.
            - Store the triplet.
        - Else if `current_diff == min_diff`:
            - If `current_sum < min_sum`:
                - Update `min_sum = current_sum`.
                - Store the triplet.
    - **Advance Pointer**: Increment the pointer associated with `current_min` to potentially decrease the difference (by increasing the min value).
5. Return the stored triplet sorted in descending order.

## Complexity Analysis

- **Time Complexity**: $O(N \log N)$ for sorting.
- **Space Complexity**: $O(1)$.
