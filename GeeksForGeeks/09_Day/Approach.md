# Approach: Maximize Number of 1's

## Intuition

The problem asks for the maximum length of a subarray of 1s obtainable by flipping at most `k` 0s. This is equivalent to finding the maximum length subarray with at most `k` zeros.

We can use the **Sliding Window** technique to solve this efficiently. The window `[left, right]` will maintain the property that the count of zeros inside it is less than or equal to `k`.

## Algorithm

1. Initialize `left = 0`, `zeros = 0`, and `max_len = 0`.
2. Iterate `right` from `0` to `n-1`:
   - If `arr[right]` is `0`, increment `zeros`.
   - if `zeros` becomes greater than `k`:
     - While `zeros > k`:
       - If `arr[left]` is `0`, decrement `zeros`.
       - Increment `left`.
   - Update `max_len = max(max_len, right - left + 1)`.
3. Return `max_len`.

## Code Structure

```cpp
class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        int left = 0, right = 0;
        int zeros = 0;
        int max_len = 0;
        int n = arr.size();
        
        while(right < n) {
            if(arr[right] == 0) {
                zeros++;
            }
            
            while(zeros > k) {
                if(arr[left] == 0) {
                    zeros--;
                }
                left++;
            }
            
            max_len = max(max_len, right - left + 1);
            right++;
        }
        
        return max_len;
    }
};
```

## Complexity Analysis

- **Time Complexity:** O(n). Each element is visited at most twice (once by `right`, once by `left`).
- **Space Complexity:** O(1). We use only a few extra variables.
