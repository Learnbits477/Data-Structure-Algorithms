# Approach: Count Inversions using Merge Sort

To solve the "Count Inversions" problem efficiently, we can use the **Merge Sort** algorithm. The problem asks for the number of pairs $(i, j)$ such that $i < j$ and $arr[i] > arr[j]$. A naive solution using nested loops would take $O(N^2)$ time, which is too slow given the constraint $N \le 10^5$. Merge Sort allows us to solve this in $O(N \log N)$ time.

## Intuition

Merge Sort divides the array into two halves, sorts them recursively, and then merges the sorted halves. During the merge step, we can count inversions.

Let's say we are merging two sorted subarrays: `left` and `right`.

- `left` subarray indices: `[low, mid]`
- `right` subarray indices: `[mid+1, high]`

If we pick an element `arr[i]` from the `left` subarray and an element `arr[j]` from the `right` subarray, and we find that `arr[i] > arr[j]`.
Since the `left` subarray is sorted, all elements after `arr[i]` (i.e., from `i+1` to `mid`) will also be greater than `arr[j]`.
Therefore, for this particular `arr[j]`, the number of inversions it forms with elements in the `left` subarray is `(mid - i + 1)`.

## Algorithm

1. **Divide**: Recursively split the array into two halves until the size of each subarray is 1.
2. **Conquer (Merge and Count)**:
    - Sort and merge the two halves.
    - While merging, if `arr[i] > arr[j]` (where `i` is in the left half and `j` is in the right half), it means `arr[i]` and all elements after it in the left half are greater than `arr[j]`.
    - Add `(mid - i + 1)` to the inversion count.
    - Place `arr[j]` into the temporary sorted array and increment `j`.
    - If `arr[i] <= arr[j]`, there is no inversion with `arr[j]`. Place `arr[i]` into the temporary array and increment `i`.
3. **Base Case**: If the array has 1 or 0 elements, it is already sorted, and the inversion count is 0.

## Complexity Analysis

- **Time Complexity**: $O(N \log N)$ - This is the standard time complexity of Merge Sort.
- **Space Complexity**: $O(N)$ - We need a temporary array for the merge step.
