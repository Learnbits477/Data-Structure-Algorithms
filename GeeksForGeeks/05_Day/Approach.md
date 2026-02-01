# Approach: Sliding Window Maximum using Deque

## Intuition

To find the maximum element in every contiguous subarray of size `k`, we can maintain a window that slides from left to right. A naive approach would be to iterate through each window and find the maximum, which takes $O(k)$ for each window, resulting in a total time complexity of $O(N*k)$. This is inefficient given $N \le 10^6$.

We need a way to get the maximum in $O(1)$ time for each window step. We can use a **Deque (Doubly Ended Queue)** to store indices of useful elements.
A "useful" element is one that is:

1. Within the current window.
2. Potentially a maximum for the current or future windows.

## Algorithm

1. Create a `deque` to store indices of array elements.
2. Iterate through the array `arr` from `i = 0` to `n-1`:
   - **Remove outgoing elements:** If the element at the front of the deque is out of the current window range (i.e., `deque.front() <= i - k`), remove it.
   - **Maintain decreasing order:** While the deque is not empty and the current element `arr[i]` is greater than or equal to the element at the back of the deque (`arr[deque.back()]`), remove the back element. These smaller elements are no longer useful because `arr[i]` is larger and appears later (so it will cover their window span).
   - **Add current element:** Push the current index `i` to the back of the deque.
   - **Record answer:** If we have processed at least `k` elements (i.e., `i >= k - 1`), the front of the deque contains the index of the maximum element for the current window. Add `arr[deque.front()]` to the result.

## Complexity Analysis

- **Time Complexity:** $O(N)$. Each element is added to the deque once and removed at most once.
- **Space Complexity:** $O(k)$. The deque stores at most `k` indices.

## Example Walkthrough

**Input:** `arr = [1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3`

- **i=0 (val=1):** Deque: `[0]`
- **i=1 (val=2):** `2 > 1`, pop 0. Push 1. Deque: `[1]`
- **i=2 (val=3):** `3 > 2`, pop 1. Push 2. Deque: `[2]`. Window `[0..2]`. Max: `arr[2]=3`. Result: `[3]`
- **i=3 (val=1):** Push 3. Deque: `[2, 3]`. Window `[1..3]`. Max: `arr[2]=3`. Result: `[3, 3]`
- **i=4 (val=4):** `4 > 1`, pop 3. `4 > 3`, pop 2. Push 4. Deque: `[4]`. Window `[2..4]`. Max: `arr[4]=4`. Result: `[3, 3, 4]`
- **i=5 (val=5):** `5 > 4`, pop 4. Push 5. Deque: `[5]`. Window `[3..5]`. Max: `arr[5]=5`. Result: `[3, 3, 4, 5]`
- **i=6 (val=2):** Push 6. Deque: `[5, 6]`. Window `[4..6]`. Max: `arr[5]=5`. Result: `[3, 3, 4, 5, 5]`
- **i=7 (val=3):** `3 > 2`, pop 6. Push 7. Deque: `[5, 7]`. Window `[5..7]`. Max: `arr[5]=5`. Result: `[3, 3, 4, 5, 5, 5]`
- **i=8 (val=6):** `6 > 3`, pop 7. `6 > 5`, pop 5. Push 8. Deque: `[8]`. Window `[6..8]`. Max: `arr[8]=6`. Result: `[3, 3, 4, 5, 5, 5, 6]`

**Final Output:** `[3, 3, 4, 5, 5, 5, 6]`
