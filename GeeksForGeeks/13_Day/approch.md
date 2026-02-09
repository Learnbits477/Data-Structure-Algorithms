# Approach: Find Kth Rotation

## Intuition

The number of times a sorted array is rotated is equal to the index of the minimum element in the array. Since the array is sorted and rotated, we can use Binary Search to find the minimum element in O(log N) time.

## Algorithm

1. Initialize `low = 0` and `high = n - 1`.
2. While `low < high`:
   - Calculate `mid = low + (high - low) / 2`.
   - If `arr[mid] > arr[high]`, it means the minimum element is in the right half (unsorted part). So, set `low = mid + 1`.
   - Otherwise, the minimum element is in the left half or is `mid` itself. So, set `high = mid`.
3. The loop terminates when `low == high`, and `low` (or `high`) will be the index of the minimum element, which is our answer.

## Complexity Analysis

- **Time Complexity:** O(log N) due to Binary Search.
- **Space Complexity:** O(1) as we use constant extra space.
