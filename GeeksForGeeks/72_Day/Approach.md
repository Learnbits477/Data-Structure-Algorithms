# Approach - Intersection of Two Sorted Arrays

## Problem Analysis

The task is to find the **distinct** common elements between two **sorted** arrays. The result should also be in sorted order.

### Why use Two-Pointer?

Since both arrays are already sorted, we can leverage this property to find the intersection in a single pass. A `std::set` based approach would take $O(n \log n + m \log m)$ or $O(n+m)$ space and time, but two pointers allows us to do it in $O(n+m)$ time with $O(1)$ extra space (excluding the output vector).

## Theoretical Approach

1. Initialize two pointers, `i = 0` (for array `a`) and `j = 0` (for array `b`).
2. Initialize an empty result vector `result`.
3. While both pointers are within their respective array bounds:
    - If `a[i] == b[j]`:
        - This is a potential intersection element.
        - To ensure **distinct** elements, check if `result` is empty or if the last element added to `result` is different from `a[i]`.
        - If it's distinct, push `a[i]` into `result`.
        - Increment both `i` and `j`.
    - Else if `a[i] < b[j]`:
        - Since `a[i]` is smaller than the current element in `b`, it cannot exist further ahead in `b`.
        - Increment `i`.
    - Else (`a[i] > b[j]`):
        - Since `b[j]` is smaller than the current element in `a`, it cannot exist further ahead in `a`.
        - Increment `j`.
4. Return the `result`.

## Complexity Analysis

- **Time Complexity:** $O(n + m)$, where $n$ is the size of `a` and $m$ is the size of `b`.
- **Space Complexity:** $O(min(n, m))$ in the worst case to store the intersection elements.

## Why this works for duplicates?

By checking `result.back() != a[i]`, we skip any repeated elements that have already been included in the intersection. Since the arrays are sorted, all identical elements are adjacent, so checking the last added element is sufficient to maintain uniqueness.
