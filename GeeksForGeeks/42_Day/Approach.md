# Approach

## Intuition

The problem asks us to find the number of valid subarrays where the first element is the minimum. For a subarray starting at index `i`, it remains valid as long as all subsequent elements in the subarray are greater than or equal to `arr[i]`. The subarray becomes invalid as soon as we encounter an element strictly smaller than `arr[i]`. Thus, the number of valid subarrays starting at index `i` is exactly the distance to the next strictly smaller element.

## Method

We can efficiently find the "Next Smaller Element" for every element in the array using a **Monotonic Stack**.

1. Traverse the array from right to left.
2. Maintain a stack of indices such that the elements corresponding to these indices form a strictly increasing sequence from the bottom of the stack to the top.
3. For each element `arr[i]`, pop elements from the stack while the stack is not empty and the element at the top of the stack is greater than or equal to `arr[i]`.
4. After popping, if the stack is empty, it means there is no smaller element to the right, so the next smaller element is implicitly at the end of the array (at index `n`). If the stack is not empty, the top of the stack stores the index of the next strictly smaller element.
5. The number of valid subarrays starting at index `i` equals `next_smaller_index - i`. We add this to our total valid count.
6. Finally, push the current index `i` onto the stack for subsequent calculations.

## Complexity Analysis

- **Time Complexity:** $O(n)$, where $n$ is the size of the array. Each element is pushed onto the stack exactly once and popped at most once, making the stack operations amortized $O(1)$.
- **Space Complexity:** $O(n)$ in the worst case (e.g., an array sorted in strictly increasing order) for the monotonic stack to store indices.
