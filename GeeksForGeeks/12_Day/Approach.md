# Approach: Maximum Product Subarray

## Intuition

The problem asks for the maximum product of a contiguous subarray. Unlike the Maximum Sum Subarray problem (Kadane's Algorithm), here the product of two negative numbers is positive. This means a very small negative number (large in magnitude) could later become a very large positive number if multiplied by another negative number.

Therefore, we need to keep track of both the **maximum product** (positive) and the **minimum product** (negative) ending at the current position.

## Algorithm

1. Initialize `maxSoFar`, `minSoFar`, and `result` with the first element of the array.
2. Iterate through the array starting from the second element.
3. For each element `arr[i]`:
    - If `arr[i]` is negative, swap `maxSoFar` and `minSoFar`. This is because multiplying a negative number by the maximum product (which might be positive) makes it smaller, and multiplying by the minimum product (which might be negative) makes it larger (positive).
    - Update `maxSoFar` to be the maximum of the current element itself or the product of the current element and the previous `maxSoFar`.
    - Update `minSoFar` to be the minimum of the current element itself or the product of the current element and the previous `minSoFar`.
    - Update `result` with the maximum of `result` and `maxSoFar`.
4. Return `result`.

## Time Complexity

- **O(N)**: We pass through the array once.

## Space Complexity

- **O(1)**: We use only a constant amount of extra space.
