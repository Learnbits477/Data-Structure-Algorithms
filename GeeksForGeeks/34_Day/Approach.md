# Trapping Rain Water

## Problem Syntax

We are given an array `arr` of size `n` representing the height of blocks. We need to compute the total amount of water that can be trapped between these blocks during the rainy season. Each block has a width of 1.

## Approach: Two Pointers Approach

1. **Initialize Pointers and Variables:**
    - Set `left = 0` (pointing to the start of the array).
    - Set `right = n - 1` (pointing to the end of the array).
    - Initialize variables `l_max = 0` (to keep track of the maximum height on the left) and `r_max = 0` (to keep track of the maximum height on the right).
    - Initialize `total_water = 0` to accumulate the total trapped water.

2. **Iterate and Calculate:**
    - Use a `while` loop that runs as long as `left < right`:
      - **Condition 1: `arr[left] <= arr[right]`**
        - We process from the left side.
        - If `arr[left] < l_max`: Water can be trapped above the current block. Add `l_max - arr[left]` to `total_water`.
        - Else (`arr[left] >= l_max`): Update `l_max = arr[left]`. No water can be trapped above this block.
        - Move the `left` pointer to the right (`left++`).
      - **Condition 2: `arr[left] > arr[right]`**
        - We process from the right side.
        - If `arr[right] < r_max`: Water can be trapped above the current block. Add `r_max - arr[right]` to `total_water`.
        - Else (`arr[right] >= r_max`): Update `r_max = arr[right]`. No water can be trapped above this block.
        - Move the `right` pointer to the left (`right--`).

3. **Return:**
    - After the loop finishes traversing all elements, return `total_water`.

### Time and Space Complexity

- **Time Complexity:** $\mathcal{O}(n)$, where $n$ is the number of elements in the `arr` array. We traverse the array exactly once using the two pointers.
- **Space Complexity:** $\mathcal{O}(1)$, as we only use a few extra variables for pointers and maximum values.
