# Approach

## Intuition

The problem requires us to move all zeroes securely to the end array while maintaining the relative order of all non-zero elements. Since the problem explicitly states that we need to perform this operation **in-place** without using extra space, we can think of a two-pointer approach to keep track of the zeroes and non-zero elements.

## Algorithm

1. Initialize a pointer `j = 0` which represents the position where the next non-zero element should be placed.
2. Iterate through the array `arr` with a pointer `i` from `0` to `n-1`.
3. If we find a non-zero element (`arr[i] != 0`), we swap the elements at index `i` and `j` (`swap(arr[i], arr[j])`).
4. Increment the pointer `j` whenever a non-zero element is encountered and swapped.
5. If `arr[i] == 0`, we simply skip it without doing anything since it needs to be pushed to the right. As `j` stays at the first `0` index, sequential zeroes won't increase `j`, allowing the subsequent non-zeroes to overwrite the first `0` appropriately and move zeroes gradually to the right.

## Complexity

- **Time Complexity:** $O(N)$, where $N$ is the length of the given array. We are iterating the array exactly once. The time complexity for the swap operation is $O(1)$. Thus the total time taken is $O(N)$.
- **Space Complexity:** $O(1)$. Since we are modifying the original array in-place, we are using $O(1)$ constant auxiliary space.
