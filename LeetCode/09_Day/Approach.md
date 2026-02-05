# Approach: Transformed Array

## Intuition

The problem asks us to find a new value for each element in the array based on a circular shift determined by the element's value. Since the array is circular, moving past the last element brings us back to the first, and moving before the first element brings us to the last. This cyclic behavior can be efficiently modeled using the modulo operator (`%`).

## Algorithm

1. Initialize a result array `res` of the same size as the input array `nums`.
2. Iterate through each index `i` from `0` to `n-1` (where `n` is the size of the array).
3. For each `i`, calculate the new index `target_index` after moving `nums[i]` steps.
   - The formula for the new index is `(i + nums[i])`.
   - Since the array is circular, we apply modulo `n`: `(i + nums[i]) % n`.
   - However, in C++, the modulo operator can return negative values if the operand is negative (e.g., `-2 % 5 = -2`). To handle this locally and ensure a positive index in the range `[0, n-1]`, we add `n` before taking the final modulo: `((i + nums[i]) % n + n) % n`.
4. Assign `nums[target_index]` to `res[i]`.
5. Return the `res` array.

## Code Structure

```cpp
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int target_index = ((i + nums[i]) % n + n) % n;
            res[i] = nums[target_index];
        }
        return res;
    }
};
```

## Complexity Analysis

- **Time Complexity:** O(n), where n is the number of elements in the array. We iterate through the array once.
- **Space Complexity:** O(n) to store the result array (or O(1) auxiliary space if we don't count the output).
