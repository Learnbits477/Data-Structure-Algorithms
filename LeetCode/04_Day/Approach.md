# Approach: Binary Search (Manual Implementation)

## Intuition

The problem asks us to find the smallest character in the sorted array `letters` that is strictly greater than `target`. Since the array is sorted, we can use **Binary Search** to efficiently find this element.

We implement binary search manually to find the first index where the character is strictly greater than the `target`.

## Algorithm

1.  **Initialize Pointers**:
    - `left` = 0
    - `right` = `letters.size() - 1`

2.  **Binary Search Loop**:
    - While `left <= right`:
      - Calculate `mid = left + (right - left) / 2`.
      - If `letters[mid] <= target`:
        - This means the candidate answer must be to the right. We move `left` to `mid + 1`.
      - Else (`letters[mid] > target`):
        - This could be our answer, but there might be a smaller valid character to the left. We move `right` to `mid - 1` to search the left half.
    - The `left` pointer will end up pointing to the smallest character greater than `target`.

3.  **Wrap Around**:
    - If `left` reaches `letters.size()`, it means all characters in the array are less than or equal to `target`.
    - The problem states to return the first character (`letters[0]`) in this case.
    - Otherwise, return `letters[left]`.

## Complexity Analysis

- **Time Complexity**: $O(\log N)$, where $N$ is the length of `letters`, as we halve the search space in each iteration.
- **Space Complexity**: $O(1)$, as we only use a few variables (`left`, `right`, `mid`).

## Code Structure

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
         int left = 0;
        int right = letters.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // If left exceeds the array bounds, return the first character
        if (left >= letters.size()) {
            return letters[0];
        } else {
            return letters[left];
        }
    }
};
```
